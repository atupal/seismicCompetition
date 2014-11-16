function str = hms(t)
% Convert t in seconds to hr:min:sec format

nhours = 0;
nmins = 0;
if t >= 3600
    nhours = floor(t/3600);
end
if t >= 60
    nmins = floor((t - 3600*nhours)/60);
end
nsecs = t - 3600*nhours - 60*nmins;
str = sprintf('%02.0f:%02.0f:%04.1f', nhours,nmins,nsecs);
str = strrep(str,' ','');
end
