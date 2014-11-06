function [dM,indv,inds,trtm,tfm] = processShotRecords(v,shot,ixs,ixwin,nxwin,ntr,nnz,nnx,nnr,nnt,dsx,dx,dt,ss)
%PROCESSSHOTRECORDS creates an image using reverse-time migration
%
% Inputs
%   v       velocity model [nz,nx]
%   shot    shot record data set [nt,ns]
%   ixs     current shot record number
%   ixwin   index ranges of all shot records [ns]
%   nxwin   index ranges of corresponding velocity model to shot [ns]
%   ntr     total number of traces
%   nnz      number of z samples in velocity model
%   nnx      number of x samples in velocity model
%   nnr      number of receivers in shot record
%   nnt      number of time samples
%   dsx     shot to receiver spacing
%   dx      surface spacing for velocity model
%   dt      sampling time
%   ss      shot scaling parameter
%%
if ischar(v)
    v = SegYFileReader(v,true,false);
    v = v(:,:);
end
if ischar(shot)
    shot = SegYFileReader(shot,true,false);
end

%% Shot record indicies
% Calculate the indicies of the shot data
if ixs == 1
    % 1st record
    inds = 1:ixwin(ixs);
else
    inds = ixwin(ixs-1)+1:ixwin(ixs);
end
% remove if outside recorded data
inds(inds>ntr) = [];

%% Velocity model indicies
% Find the region of the velocity model that goes with the shot record
indv = (1:nxwin(ixs))+dsx*(ixs-1);
indv(indv>nnx) = [];

%% Add boundary for simulation
% add region around model for applying absorbing boundary conditions (20
% nodes wide)
if indv(1) <= 20
    V = [repmat(v(:,1),1,20), v(:,indv(1):(indv(end)+20))];
elseif indv(end) >= nnx-20
    V = [v(:,(indv(1)-20):indv(end)), repmat(v(:,end),1,20)];
else
    V = v(:,(indv(1)-20):(indv(end)+20));
end
V(end+1:end+20,:) = repmat(V(end,:),20,1);

% add absorbing boundary condition to initial shot record data
currentShot = [repmat(shot(:,inds(1)),1,20), shot(:,inds),...
    repmat(shot(:,inds(end)),1,20)]' * ss;

%% Process shots in reverse time




rtic=tic;
%% Initialize storage
[nz,nx] = size(V);
[~,nt] = size(currentShot);
fdm  = zeros(nz,nx,3);

%% Boundary Absorbing Model
iz = 1:20;
boundary = (exp(-( (0.015*(20-iz)).^2 ) )).^10;

%% Reverse-Time Migration
fdm(1,:,1) = currentShot(:,nt);
fdm(1,:,2) = currentShot(:,nt-1);
fdm(1,:,3) = currentShot(:,nt-2);

% finite difference coefficients
a = (V*dt/dx).^2;    % wave equation coefficient
b = 2-4*a;

% common indicies
ix   = 2:nx-1;       % interior x
ixb  = 1:20;         % boundary x (right)
ixb2 = nx-19:nx;     % boundary x (left)

cz = 3;
try
    snapshot = zeros(nz,nx,nt);
catch
    bufnt = floor(nt/((nz*nx*nt*8)/(4*1024^3)));
    buffer = zeros(nz,nx,bufnt);
    itcnt = 1;
    snapshot = diskArray('VariableName','rtm2d','SizeOfArray',[nz nx nt],'Writable',true);
end
for it = (nt-1):-1:1
    cz = cz+1;
    bz = min(cz,nz);

    % apply absorbing boundary condition on left/right sides
    for iz = 1:bz
        fdm(iz,ixb,1) = boundary.*fdm(iz,ixb,1);
        fdm(iz,ixb,2) = boundary.*fdm(iz,ixb,2);
        fdm(iz,ixb2,1) = boundary(end:-1:1).*fdm(iz,ixb2,1);
        fdm(iz,ixb2,2) = boundary(end:-1:1).*fdm(iz,ixb2,2);
    end

    % apply absorbing boundary condition at depth nz
    if bz >= (nz-19)
        for iz = nz-19:bz
            fdm(iz,:,1) = boundary(nz-iz+1).*fdm(iz,:,1);
            fdm(iz,:,2) = boundary(nz-iz+1).*fdm(iz,:,2);
        end
    end

    % computing grid depth (extend in z to solve)
    if bz == nz
        ez = nz-1;
    else
        ez = bz;
    end

    % time extrapolation between iz and bz
    iz = 1:bz;
    fdm(iz,ix,3) = fdm(iz,ix,3) - fdm(iz,ix,1);

    iz = 2:ez;
    fdm(iz,ix,2) = b(iz,ix).*fdm(iz,ix,1) + fdm(iz,ix,2) ...
        + a(iz,ix+1).*fdm(iz,ix+1,1) ...
        + a(iz,ix-1).*fdm(iz,ix-1,1) ...
        + a(iz+1,ix).*fdm(iz+1,ix,1) ...
        + a(iz-1,ix).*fdm(iz-1,ix,1);

    % time extrapolation at iz = 1
    fdm(1,ix,2) = b(1,ix).*fdm(1,ix,1) + fdm(1,ix,2) ...
        + a(1,ix+1).*fdm(1,ix+1,1) ...
        + a(1,ix-1).*fdm(1,ix-1,1) ...
        + a(2,ix).*fdm(2,ix,1);


    if bz == nz
        % time extrapolation at iz = nz
        fdm(nz,ix,2) = b(nz,ix,1).*fdm(nz,ix,1) + fdm(nz,ix,2) ...
            + a(nz,ix+1).*fdm(nz,ix+1,1) ...
            + a(nz,ix-1).*fdm(nz,ix-1,1) ...
            + a(nz-1,ix).*fdm(nz-1,ix,1);

        % time extrapolation at corner (nz,1)
        fdm(nz,1,2) = b(nz,1,1).*fdm(nz,1,1) + fdm(nz,1,2) ...
            + a(nz,2,1).*fdm(nz,2,1) + a(nz-1,1,1).*fdm(nz-1,1,1);
    end

    fdm(iz,1,2) = b(iz,1,1).*fdm(iz,1,1) + fdm(iz,1,2) ...
        + a(iz,2).*fdm(iz,2,1) ...
        + a(iz+1,1).*fdm(iz+1,1,1) ...
        + a(iz-1,1).*fdm(iz-1,1,1);

    fdm(iz,nx,2) = b(iz,nx,1).*fdm(iz,nx,1) + fdm(iz,nx,2) ...
        + a(iz,nx-1).*fdm(iz,nx-1,1) ...
        + a(iz+1,nx).*fdm(iz+1,nx,1) ...
        + a(iz-1,nx).*fdm(iz-1,nx,1);

    % time extrapolation at corner (1,1)
    fdm(1,1,2) = b(1,1,1).*fdm(1,1,1) + fdm(1,1,2) ...
        + a(1,2,1).*fdm(1,2,1) + a(2,1,1).*fdm(2,1,1);

    % time extrapolation at corner (1,nx)
    fdm(1,nx,2) = b(1,nx,1).*fdm(1,nx,1) + fdm(1,nx,2) ...
        + a(1,nx-1,1).*fdm(1,nx-1,1) + a(2,nx,1).*fdm(2,nx,1);

    % set up fdm for next iteration
    fdm(:,:,1) = fdm(:,:,2);
    fdm(:,:,2) = fdm(:,:,3);

    % insert surface boundary wavefield
    if it > 2
        fdm(2:nz,:,3) = 0;
        fdm(1,:,3) = currentShot(:,it-2);
    end

    %{
    figure(3), imagesc(diff(fdm(:,:,1),2,1))
    title(['Iteration: ',num2str(it)])
    colormap gray
    %caxis([-2 2])
    drawnow
    if it < 12800
        disp('checking')
    end
    %}
    if exist('buffer','var') && itcnt < bufnt && it > 1
        buffer(:,:,itcnt) = fdm(:,:,1);
        itcnt = itcnt+1;
    elseif exist('buffer','var') && itcnt == bufnt && it > 1;
        buffer(:,:,itcnt) = fdm(:,:,1);
        snapshot(:,:,it:(it+bufnt-1)) = buffer;
        itcnt = 1;
    elseif exist('buffer','var') && it == 1
        buffer(:,:,itcnt) = fdm(:,:,1);
        snapshot(:,:,it:(it+itcnt-1)) = buffer(:,:,1:itcnt);
        itcnt = 1;
    else
        snapshot(:,:,it) = fdm(:,:,1);
    end

end % time loop

% write out final wavefield
model = fdm(:,:,1);
trtm=toc(rtic);









%% Process rtm solution in forward time










%% Initialize storage
ftic=tic;

nt=nnt;
[nz,nx] = size(model);
data = zeros(nx,nt);
fdm  = zeros(nz,nx,3);

%% Boundary Absorbing Model
%iz = 1:20;
%boundary = (exp(-( (0.015*(20-iz)).^2 ) )).^10;
boundary = boundary';

%% Forward-Time Modeling

fdm(:,:,2) = model;
data(:,1)  = model(1,:);



% common indicies
iz   = 2:(nz-1);     % interior z
ix   = 2:(nx-1);     % interior x
izb  = 1:nz-20;      % boundary z

%%debug
%{
try
    snapshot = zeros(nz,nx,nt);
catch
    bufnt = floor(nt/((nz*nx*nt*8)/(4*1024^3)));
    buffer = zeros(nz,nx,bufnt);
    itcnt = 1;
    snapshot = diskArray('VariableName','rtm2d','SizeOfArray',[nz nx nt],'Writable',true);
end
%}

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
    %{
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
    %}
    snapshot(:,:,nt) = snapshot(:,:,nt-it+1).*fdm(:,:,1)+snapshot(:,:,nt);
    %end
end % time loop
tfm=toc(ftic);

M=snapshot(:,:,nt);


%% Create an image from rtm and fm
% Image is the product of rtm and fm solutions
%{
[r,c,~] = size(snapshot);
M = zeros(r,c);
for i = 1:nt
    M = snapshot(:,:,i).*rtmsnapshot(:,:,nt-i+1) + M;
end
%}
sw = repmat(0:nnr-1,nnz,1) + ixs;
sw(sw>nnr)=nnr;

dM = diff(M(1:end-18,21:end-20),2,1);
dM = dM - mean(dM(:));
sw = sw(:,1:size(dM,2));
dM = dM./sw;
