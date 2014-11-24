function [model, snapshot] = rtm2d(v,data,dx,dt)
%
% data(nx,nt)       data vector
% v(nz,nx)          velocity model
% nx                number of horizontal samples
% nz                number of depth samples
% nt                numer of time samples
% dx                horizontal distance per sample
% dz                depth distance per sample
% dt                time difference per sample

% add grid points for boundary condition

%v = [repmat(v(:,1),1,20), v, repmat(v(:,end),1,20)];
%v(end+20,:) = v(end,:);
%% Initialize storage
assert(isa(v, 'double'));
assert(all(size(v)<=[120 50]));
assert(isa(data, 'double'));
assert(all(size(data)<=[50 719]));
assert(isa(dx, 'double'));
assert(all(size(dx)==[1]));
assert(isa(dt, 'double'));
assert(all(size(dt)==[1]));

[nz,nx] = size(v);
[~,nt] = size(data);
fdm  = zeros(nz,nx,3,'double');

%% Boundary Absorbing Model
iz = 1:20;
boundary = (exp(-( (0.015*(20-iz)).^2 ) )).^10;

%% Reverse-Time Migration
fdm(1,:,1) = data(:,nt);
fdm(1,:,2) = data(:,nt-1);
fdm(1,:,3) = data(:,nt-2);

% finite difference coefficients
a = (v*dt/dx).^2;    % wave equation coefficient
b = 2-4*a;

% common indicies
ix   = 2:nx-1;       % interior x
ixb  = 1:20;         % boundary x (right)
ixb2 = nx-19:nx;     % boundary x (left)

cz = 3;
snapshot = ones(nz,nx,nt);
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
        fdm(1,:,3) = data(:,it-2);
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
    snapshot(:,:,it) = fdm(:,:,1);
    
end % time loop

% write out final wavefield
model = fdm(:,:,1);
