function imageSaltToothModel

%% Run Configuration
% Set path
rootd = fileparts(mfilename('fullpath'));
addpath(fullfile(rootd,'saltToothModelData'))
addpath(fullfile(rootd,'rtm'))
addpath(fullfile(rootd,'plots'))
addpath(fullfile(rootd,'fileReader'))
resultsd = fullfile(rootd,'results');

% ATTENTION #1
% Specify Velocity Model and Shot Records
velocityFile = fullfile(rootd,'saltToothModelData','saltToothVelocityModel.segy');
% If the Velocity file is not on a shared drive with the cluster, then
% specify the remote file location and see ATTENTION #2 below.
% E.g.
%  remoteVelocityFile = '/home/user/saltToothModelData/saltToothVelocityModel.segy';
remoteVelocityFile = '';

shotFiles = fullfile(rootd,'saltToothModelData','saltToothShotRecords.segy');
% If the Shot Records file is not on a shared drive with the cluster, then
% specify the remote file location and see ATTENTION #2 below.
% E.g.
%  remoteShotFiles = '/home/user/saltToothModelData/saltToothShotRecords.segy';
remoteShotFiles = '';

% ATTENTION #2
% Set readFromMem to true if the entire pool of workers is being run on the
% same machine has the MATLAB client.  Otherwise, set it to false.
% If set to false, both the remoteVelocityFile and remoteShotFiles
% should be set in ATTENTION #1.
readFromMem = true;

% ATTENTION #3
% Options are 'serial','parallel','parallel-gpu' (or any combination of
% them).
%  NOTE: parallel-gpu is not implemented.
% runMode = {'serial','parallel','parallel-gpu'};
runMode = {'serial'};

%% Model and Data Parameters
units = {'m','s'};
% velocity model
dz = 6.25*4;        % depth spacing (E)
dx = 12.5*4;        % surface spacing (E)

% shot records
ns = 301;           % number of shots
ds = dx;            % shot spacing (E)
dxr = dx;           % receiver spacing (E)
xr  = 100*dx;       % maximum receiver offset (E)
nr  = xr/dxr;       % number of receivers
dt = 0.0033;        % sampling time (s)
nt = 6710;          % trace size
t  = nt*dt;         % trace length (s)
ss = 1;             % shot trace scaling
dsx = ds/dxr;

%% Load velocity model
v = SegYFileReader(velocityFile,true,false);
velocityModel = v(:,:);

[nz,nx] = size(velocityModel);

x = (0:nx-1)*dx;
z = (0:nz-1)*dz;

%%
imageFigure('Velocity Model')
plotSeismicProgress(units,x,z,velocityModel)

%% Load shot data records
shot = SegYFileReader(shotFiles,true,false);
ntr = nr*ns;

% Calculate the number of traces per shot record moving over the domain
xwin = x(end) - (0:ns-1)*ds;
dxwin = xwin/dxr + 1;
nxwin = min(dxwin,repmat(nr,size(dxwin)));
ixwin = cumsum(nxwin);

test = 'salt_tooth';

file = LOGGER('init',resultsd,test);
loggerObj = onCleanup(@() LOGGER('close'));
[~,resultsfile] = fileparts(file);

%% Process Shots - Reverse Time Migration
for runCase = 1:length(runMode)
    Stacked = zeros(nz,nx);
    switch lower(runMode{runCase})
        
        case 'serial'
            %% Run serially
            LOGGER('\nSERIAL RUN\n')
            imageFigure('Serial')

            tserial = 0;
            for ixs = 1:ns
                stic = tic;
                [dM,indv,inds] = processShotRecords(v,shot,ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss);
                Stacked(:,indv(1):indv(end)) = dM + Stacked(:,indv(1):indv(end));
                tserial = toc(stic) + tserial;
                LOGGER('Total processing time through iter %03d: %s\n',ixs,hms(tserial))
                plotSeismicProgress(units,x,z,velocityModel,t,shot(:,inds)'*ss,dM,Stacked,ixs,[indv(1),indv(end)],tserial)
            end
            LOGGER('Processing time for serial run:\t\t%s\n',hms(tserial))
            save(fullfile(resultsd,[resultsfile '_serial']),'Stacked')
            
        case 'parallel'
            %% Run in parallel
            % Submit the shots to run asynchronously and plot
            LOGGER('\nPARALLEL RUN\n')
            imageFigure('Parallel')

            % Get the current pool
            % p = gcp();
            p = parpool(3);
            af = {fullfile(rootd,'fileReader'), fullfile(rootd,'rtm')};
            addAttachedFiles(p,af)
            LOGGER(['Number of Workers: ' num2str(p.NumWorkers) '\n'])
            
            ptic = tic;
            tparallel = 0;
            for ixs = 1:ns
                % Submit futures
                if readFromMem==true
                    f(ixs) = parfeval(p,@processShotRecords,3, ...
                        v,shot, ...
                        ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss); %#ok<AGROW>
                else
                    f(ixs) = parfeval(p,@processShotRecords,3, ...
                        remoteVelocityFile,remoteShotFiles, ...
                        ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss); %#ok<AGROW>
                end
            end
            
            % Collect data and update plot as results come back
            try
                for ixs = 1:ns
                    % Fetch next available block
                    [~,dM,indv,inds] = fetchNext(f);
                    % Store results in final image
                    Stacked(:,indv(1):indv(end)) = dM + Stacked(:,indv(1):indv(end));
                    % What is the processing time
                    tparallel = toc(ptic);
                    LOGGER('Total processing time through iter %03d: %s\n',ixs,hms(tparallel))
                    % Show current plot
                    plotSeismicProgress(units,x,z,velocityModel,t,shot(:,inds)'*ss,dM,Stacked,ixs,[indv(1),indv(end)],tparallel)
                end
            catch E
                LOGGER('error',E)
                
                % If there's any error, cancel any queued or running future
                if isempty(f)==false
                    cancel(f)
                end
            end
            LOGGER('Processing time for parallel run:\t%s\n',hms(tparallel))
            save(fullfile(resultsd,[resultsfile '_parallel']),'Stacked')
            
        case 'parallel-gpu'
            %% Run on GPU(s)
            LOGGER('\nPARALLEL-GPU RUN\n')
            imageFigure('Parallel-GPU')
            
            gtic = tic;
            tgpu = 0;
            
            %TODO
            
            tgpu = toc(gtic) + tgpu;

            LOGGER('Processing time for parallel-gpu run: %s\n',hms(tgpu))
            save(fullfile(resultsd,[resultsfile '_parallel-gpu']),'Stacked')
            
        otherwise
            error('ImageFaultModel:WhichCase','runMode must be defined.')
    end
end
