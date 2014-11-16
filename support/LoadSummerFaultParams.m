%% Define Velocity model parameters
dz = 10;                    % depth spacing (ft)
dx = 10;                    % horizontal spacing (ft)

% windowed velocity model is receiver area covered
ns = 100;                   % number of shots
nr =  10;                   % number of receivers

dt = 0.002;                 % sampling time (s)
nt = 719;                   % trace size
