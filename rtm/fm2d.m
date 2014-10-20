function [data,snapshot] = fm2d(v,model,dx,nt,dt)
%
% model(nz,nx)      model vector
% v(nz,nx)          velocity model
% nx                number of horizontal samples
% nz                number of depth samples
% nt                numer of time samples
% dx                horizontal distance per sample
% dz                depth distance per sample
% dt                time difference per sample

% add grid points for boundary condition
%model = [repmat(model(:,1),1,20), model, repmat(model(:,end),1,20)];
%model(end+20,:) = model(end,:);

%v = [repmat(v(:,1),1,20), v, repmat(v(:,end),1,20)];
%v(end+20,:) = v(end,:);
%% Initialize storage
[nz,nx] = size(model);
data = zeros(nx,nt);
fdm  = zeros(nz,nx,3);

%% Boundary Absorbing Model
iz = 1:20;
boundary = (exp(-( (0.015*(20-iz)).^2 ) )).^10;
boundary = boundary';

%% Forward-Time Modeling
fdm(:,:,2) = model;
data(:,1)  = model(1,:);

% finite difference coefficients
a = (v*dt/dx).^2;    % wave equation coefficient
b = 2-4*a;

% common indicies
iz   = 2:(nz-1);     % interior z
ix   = 2:(nx-1);     % interior x
izb  = 1:nz-20;      % boundary z

try
    snapshot = zeros(nz,nx,nt);
catch
    bufnt = floor(nt/((nz*nx*nt*8)/(4*1024^3)));
    buffer = zeros(nz,nx,bufnt);
    itcnt = 1;
    snapshot = diskArray('VariableName','rtm2d','SizeOfArray',[nz nx nt],'Writable',true);
end

for it = 2:nt
    % finite differencing on interior
    fdm(iz,ix,3) = b(iz,ix).*fdm(iz,ix,2) - fdm(iz,ix,1) + ...
        a(iz,ix).*(fdm(iz,ix+1,2) + fdm(iz,ix-1,2) + ...
        fdm(iz+1,ix,2) + fdm(iz-1,ix,2));
    
    % finite differencing at ix = 1 and ix = nx (surface, bottom)
    fdm(iz,1,3) = b(iz,1).*fdm(iz,1,2) - fdm(iz,1,1) + ...
        a(iz,1).*(fdm(iz,2,2) + fdm(iz+1,1,2) + fdm(iz-1,1,2));
    fdm(iz,nx,3) = b(iz,nx).*fdm(iz,nx,2) - fdm(iz,nx,1) + ...
        a(iz,nx).*(fdm(iz,nx-1,2) + fdm(iz+1,nx,2) + ...
        fdm(iz-1,nx,2));
    
    % finite differencing at iz = 1 and iz = nz (z boundaries)
    fdm(1,ix,3) = b(1,ix).*fdm(1,ix,2) -  fdm(1,ix,1) + ...
        a(1,ix).*(fdm(2,ix,2) + fdm(1,ix+1,2) + fdm(1,ix-1,2));
    fdm(nz,ix,3)= b(nz,ix).*fdm(nz,ix,2)- fdm(nz,ix,1) + ...
        a(nz,ix).*(fdm(nz-1,ix,2) + fdm(nz,ix+1,2) + fdm(nz,ix-1,2));
    
    % finite differencing at four corners (1,1), (nz,1), (1,nx), (nz,nx)
    fdm(1 ,1 ,3) = b(1 , 1).*fdm(1 ,1 ,2) -fdm(1 ,1 ,1) + ...
        a(1 , 1)*(fdm(2,1,2) + fdm(1,2,2));
    fdm(nz,1 ,3) = b(nz, 1).*fdm(nz,1 ,2) -fdm(nz,1 ,1) + ...
        a(nz, 1)*(fdm(nz,2,2) +fdm(nz-1,1,2));
    fdm(1 ,nx,3) = b(1 ,nx).*fdm(1 ,nx,2) -fdm(1 ,nx,1) + ...
        a(1 ,nx)*(fdm(1,nx-1,2) +fdm(2,nx,2));
    fdm(nz,nx,3) = b(nz,nx).*fdm(nz,nx,2) -fdm(nz,nx,1) + ...
        a(nz,nx)*(fdm(nz-1,nx,2) +fdm(nz,nx-1,2));
    
    % update fdm for next time iteration
    fdm(:,:,1) = fdm(:,:,2);
    fdm(:,:,2) = fdm(:,:,3);
    
    % apply absorbing boundary conditions to 3 sides (not surface)
    for ixb = 1:20
        fdm(izb,ixb,1) = boundary(ixb).*fdm(izb,ixb,1);
        fdm(izb,ixb,2) = boundary(ixb).*fdm(izb,ixb,2);
        ixb2 = nx-20+ixb;
        fdm(izb,ixb2,1) = boundary(nx-ixb2+1).*fdm(izb,ixb2,1);
        fdm(izb,ixb2,2) = boundary(nx-ixb2+1).*fdm(izb,ixb2,2);
        izb2 = nz-20+ixb;
        fdm(izb2,:,1) = boundary(nz-izb2+1).*fdm(izb2,:,1);
        fdm(izb2,:,2) = boundary(nz-izb2+1).*fdm(izb2,:,2);
    end
    
    % update data
    data(:,it) = fdm(1,:,2);
    
    %{
    figure(3),imagesc(data');
    title(['Time index: ',num2str(it)])
    colormap seismic
    drawnow
    %}
    if exist('buffer','var') && itcnt < bufnt && it < nt
        buffer(:,:,itcnt) = fdm(:,:,1);
        itcnt = itcnt+1;
    elseif exist('buffer','var') && itcnt == bufnt && it < nt;
        buffer(:,:,itcnt) = fdm(:,:,1);
        snapshot(:,:,(it-bufnt+1):it) = buffer;
        itcnt = 1;
    elseif exist('buffer','var') && it == nt
        buffer(:,:,itcnt) = fdm(:,:,1);
        snapshot(:,:,(it-itcnt+1):it) = buffer(:,:,1:itcnt);
        itcnt = 1;
    else
        snapshot(:,:,it) = fdm(:,:,1);
    end
end % time loop

%data = data(21:nx-20,:);