function [dM,indv,inds,trtm,tfm] = processShotRecords(v,shot,ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss)
%PROCESSSHOTRECORDS creates an image using reverse-time migration
%
% Inputs
%   v       velocity model [nz,nx]
%   shot    shot record data set [nt,ns]
%   ixs     current shot record number
%   ixwin   index ranges of all shot records [ns]
%   nxwin   index ranges of corresponding velocity model to shot [ns]
%   ntr     total number of traces
%   nz      number of z samples in velocity model
%   nx      number of x samples in velocity model
%   nr      number of receivers in shot record
%   nt      number of time samples
%   dsx     shot to receiver spacing
%   dx      surface spacing for velocity model
%   dt      sampling time
%   ss      shot scaling parameter

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
indv(indv>nx) = [];

%% Add boundary for simulation
% add region around model for applying absorbing boundary conditions (20
% nodes wide)
if indv(1) <= 20
    V = [repmat(v(:,1),1,20), v(:,indv(1):(indv(end)+20))];
elseif indv(end) >= nx-20
    V = [v(:,(indv(1)-20):indv(end)), repmat(v(:,end),1,20)];
else
    V = v(:,(indv(1)-20):(indv(end)+20));
end
V(end+1:end+20,:) = repmat(V(end,:),20,1);

% add absorbing boundary condition to initial shot record data
currentShot = [repmat(shot(:,inds(1)),1,20), shot(:,inds),...
    repmat(shot(:,inds(end)),1,20)]' * ss;

%% Process shots in reverse time

rtic = tic;
[rtmdl, rtmsnapshot] = rtm2d(V,currentShot,dx,dt);
trtm = toc(rtic);
%% Process rtm solution in forward time
ftic = tic;
[~, M] = fm2d(V,rtmdl,dx,nt,dt,rtmsnapshot);
tfm = toc(ftic);

%% Create an image from rtm and fm
% Image is the product of rtm and fm solutions
%{
[r,c,~] = size(snapshot);
M = zeros(r,c);
for i = 1:nt
    M = snapshot(:,:,i).*rtmsnapshot(:,:,nt-i+1) + M;
end
%}
sw = repmat(0:nr-1,nz,1) + ixs;
sw(sw>nr)=nr;

dM = diff(M(1:end-18,21:end-20),2,1);
dM = dM - mean(dM(:));
sw = sw(:,1:size(dM,2));
dM = dM./sw;
