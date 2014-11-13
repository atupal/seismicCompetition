function f = displayFigure(figfile)

ext = '.fig';
if length(figfile)<5 || isequal(figfile(end-3:end),ext)==false
    figfile = [figfile ext];
end

if exist(figfile,'file')==false
    error(['Failed to find file: ' figfile])
end

fig_h = openfig(figfile);
if nargout==1
    f = fig_h;
end
