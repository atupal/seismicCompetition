function imageModelData(model,mfolder,runMode)
%IMAGEMODELDATA Display image of model data.
%   IMAGEMODELDATA(MODEL,MFOLDER,RUNMODE) calculates the forward and reverse
%   time migration of a MODEL.  The model data folder can be found in top
%   level folder MFOLDER and will be calculated in RUNMODE, where run mode
%   is a cell array of options.  RUNMODE can be either 'serial',
%   'parallel', and/or 'parallel-gpu'.
%
%   Three result files are generated: txt (timings file for all RUNMODE),
%   fig (for each RUNMODE capturing the generated figure), and mat (for
%   each RUNMODE collecting the stacked images displayed in the fig file).
%   The result files are written in the results folder, with a timestamp as
%   part of the filename.
%
%   Example:
%   % Compute FTM/RTM for Summer Salt Tooth in parallel mode, with a
%   % parallel pool size of 24 Workers.
%   p = parpool(24);
%   imageModelData('SummerSaltTooth','/data/SEGY-files',{'parallel'})
%
%   % Compute FTM/RTM for Summer Salt Tooth twice: once in serial mode and
%   % once parallel.  Use a parallel pool of 32 Workers to run the code in
%   % parallel.
%   %
%   % Assuming that a pool doesn't already exist.  If it does, we'd need to
%   % delete it first.
%   p = parpool(32);
%   imageModelData('SummerSaltTooth','/data/SEGY-files',{'serial','parallel'})
%
%   % Compare the results with a baseline file
%   score = ...
%   diffStackedImages('SummerSaltTooth', ...
%                     'results/SummerSaltTooth_SampleRun_parallel', ...
%                     'results/SummerSaltTooth_SampleRun_serial')
%
%   See also DIFFSTACKEDIMAGES, DISPLAYFIGURE.

%   Copyright 2014 The MathWorks, Inc.

narginchk(3,3)

%% Run Configuration
% Set path
rootd = fileparts(mfilename('fullpath'));
modeld = fullfile(mfolder,[model 'ModelData']);
if exist(modeld,'dir')==false
    error(['Failed to find folder: ' modeld])
end

addpath(modeld)
addpath(fullfile(rootd,'rtm'))
addpath(fullfile(rootd,'plots'))
addpath(fullfile(rootd,'fileReader'))
addpath(fullfile(rootd,'SegyMAT'))
addpath(fullfile(rootd,'support'))
resultsd = fullfile(rootd,'results');
addpath(resultsd)

% ATTENTION
% Specify Velocity Model and Shot Records
velocityFile = fullfile(modeld,[model 'VelocityModel.segy']);
% If the Velocity file is not on a shared drive with the "headnode", then
% specify the fully qualified name of the remote file which can be seen by
% the compute nodes.
%
% E.g.
%  remoteVelocityFile = '/home/user/SaltToothModelData/SaltToothVelocityModel.segy';
remoteVelocityFile = velocityFile;

shotFiles = fullfile(modeld,[model 'ShotRecords.segy']);
% If the Shot Records file is not on a shared drive with the
% "headnode", then specify the fully qualified name of the remote file which can be seen by the compute nodes.
%
% E.g.
%  remoteShotFiles = '/home/user/SaltToothModelData/SaltToothShotRecords.segy';
remoteShotFiles = shotFiles;

commonFs = strcmp(remoteVelocityFile,velocityFile) && strcmp(remoteShotFiles,shotFiles);

%% Model and Data Parameters
units = {'m','s'};

run(['Load' model 'Params'])

% shot records
ds = dx;            % shot spacing (E)
dxr = dx;           % receiver spacing (E)
t  = nt*dt;         % trace length (s)
ss = 1;             % shot trace scaling
dsx = ds/dxr;

%% Load velocity model
v = SegYFileReader(velocityFile,true,false);
% v = ReadSegyFast(velocityFile);
velocityModel = v(:,:);

[nz,nx] = size(velocityModel);

x = (0:nx-1)*dx;
z = (0:nz-1)*dz;

%%
imageFigure('Velocity Model')
plotSeismicProgress(units,x,z,velocityModel)

%% Load shot data records
shot = SegYFileReader(shotFiles,true,false);
% shot = ReadSegyFast(shotFiles);
ntr = nr*ns;

% Calculate the number of traces per shot record moving over the domain
xwin = x(end) - (0:ns-1)*ds;
dxwin = xwin/dxr + 1;
nxwin = min(dxwin,repmat(nr,size(dxwin)));
ixwin = cumsum(nxwin);

file = LOGGER('init',resultsd,model);
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
                [dM,indv,inds,vshot] = processShotRecords(v,shot,ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss);
                tserial = toc(stic) + tserial;
                if mod(ixs,100)==0 || ixs==ns
                    disp(['Completed: ' num2str(ixs) '/' num2str(ns)])
                end
                Stacked(:,indv(1):indv(end)) = dM + Stacked(:,indv(1):indv(end));
                LOGGER('Total processing time through iter %04d: %s\n',ixs,hms(tserial))
                % plotSeismicProgress(units,x,z,velocityModel,t,shot(:,inds)'*ss,dM,Stacked,ixs,[indv(1),indv(end)],tserial,ixs)
                plotSeismicProgress(units,x,z,velocityModel,t,vshot,dM,Stacked,ixs,[indv(1),indv(end)],tserial,ixs)
            end
            LOGGER('Processing time for serial run:\t\t %s\n',hms(tserial))
            save(fullfile(resultsd,[resultsfile '_serial']),'Stacked')
            savefig(fullfile(resultsd,[resultsfile '_serial']))
            
        case 'parallel'
            %% Run in parallel
            % Submit the shots to run asynchronously and plot
            LOGGER('\nPARALLEL RUN\n')
            imageFigure('Parallel')
            
            % Get the current pool
            p = gcp('nocreate');
            if isempty(p)
                error('Cannot run runmode as ''parallel'' unless a parallel pool has been started.  Use parpool to start a new pool.')
            end
            
            %            if commonFs==false
            %                af = {fullfile(rootd,'fileReader'), fullfile(rootd,'rtm')};
            %                addAttachedFiles(p,af)
            %            end
            
            LOGGER(['Number of Workers: ' num2str(p.NumWorkers) '\n'])
            
            ptic = tic;
            tparallel = 0;
            for ixs = 1:ns
                % Submit futures
                if commonFs==true
                    f(ixs) = parfeval(p,@processShotRecords,4, ...
                        v,shot, ...
                        ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss); %#ok<AGROW>
                else
                    f(ixs) = parfeval(p,@processShotRecords,4, ...
                        remoteVelocityFile,remoteShotFiles, ...
                        ixs,ixwin,nxwin,ntr,nz,nx,nr,nt,dsx,dx,dt,ss); %#ok<AGROW>
                end
            end
            
            % Collect data and update plot as results come back
            try
                for ixs = 1:ns
                    caught_fetch_error_flag = false;
                    % Fetch next available block
                    try
                        [IXS,dM,indv,inds,vshot] = fetchNext(f);
                    catch E
                        % There could be several reasons the fetch
                        % fails.  We don't want to long jump out of
                        % here, but we don't want to stack and plot
                        % bad results.  So flag the issue and then
                        % move onto the next future.
                        LOGGER('error',E)
                        caught_fetch_error_flag = true;
                    end
                    % What is the processing time
                    tparallel = toc(ptic);
                    if mod(ixs,100)==0 || ixs==ns
                        disp(['Completed: ' num2str(ixs) '/' num2str(ns)])
                    end
                    if caught_fetch_error_flag==false
                        % Store results in final image
                        Stacked(:,indv(1):indv(end)) = dM + Stacked(:,indv(1):indv(end));
                        % Show current plot
                        % plotSeismicProgress(units,x,z,velocityModel,t,shot(:,inds)'*ss,dM,Stacked,IXS,[indv(1),indv(end)],tparallel,ixs)
                        plotSeismicProgress(units,x,z,velocityModel,t,vshot,dM,Stacked,IXS,[indv(1),indv(end)],tparallel,ixs)
                    end
                    LOGGER('Total processing time through iter %04d: %s\n',ixs,hms(tparallel))
                end
            catch E
                LOGGER('error',E)
                
                % If there's any error, cancel any queued or running future
                if isempty(f)==false
                    cancel(f)
                end
            end
            LOGGER('Processing time for parallel run:\t %s\n',hms(tparallel))
            save(fullfile(resultsd,[resultsfile '_parallel']),'Stacked')
            savefig(fullfile(resultsd,[resultsfile '_parallel']))
            
        case 'parallel-gpu'
            %% Run on GPU(s)
            
            % NOTE: LEFT TO THE USER IF SO CHOOSEN TO DO SO.  IT IS
            % NOT A REQUIREMENT TO IMPLEMENT A GPU VERSION OF THE CODE.
            
            LOGGER('\nPARALLEL-GPU RUN\n')
            imageFigure('Parallel-GPU')
            
            tgpu = 0;
            
            LOGGER('Processing time for parallel-gpu run:\t %s\n',hms(tgpu))
            save(fullfile(resultsd,[resultsfile '_parallel-gpu']),'Stacked')
            savefig(fullfile(resultsd,[resultsfile '_parallel-gpu']))
            
            % NOTE: LEFT TO THE USER IF SO CHOOSEN TO DO SO.  IT IS
            % NOT A REQUIREMENT TO IMPLEMENT A GPU VERSION OF THE CODE.
            
        otherwise
            error('ImageFaultModel:WhichCase','runMode must be defined.')
    end
end
