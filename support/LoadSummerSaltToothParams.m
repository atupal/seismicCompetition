%% Define Velocity model parameters
dz = 25;                    % depth spacing (ft)
dx = 50;                    % horizontal spacing (ft)

% windowed velocity model is receiver area covered
ns = 301;                   % number of shots
nr = 100;                   % number of receivers

dt = 0.0033;                % sampling time (s)
nt = 6710;                  % trace size
