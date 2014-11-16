function file = LOGGER(str,varargin)

persistent fid

if nargout==1
    file = [];
end

if strcmp(str,'init')
    rootd = varargin{1};
    test = varargin{2};
    file = strrep(fullfile(rootd,[test '_' datestr(now) '.txt']),' ','_');
    file = [file(1:2) strrep(file(3:end),':','-')];
    if isempty(fid)
        fid = fopen(file,'wt');
        if fid<0
            fid = [];
            error('Failed to open file ''%s'' for writing.',file)
        end
        host = char(java.net.InetAddress.getLocalHost.toString());
        fprintf(fid,'Host: %s\n',host);
        fprintf(fid,'Test: %s\n\n',test);
        fprintf(fid,'Start Time:\t%s\n',datestr(now));
    end
elseif strcmp(str,'close')
    fprintf(fid,'\nEnd Time:\t%s\n',datestr(now));
    fclose(fid);
    fid = [];
elseif strcmp(str,'error')
    err = varargin{1};

    displayException(fid,err)

    if isempty(err.cause)==false
        for cidx = 1:length(err.cause{:})
            displayException(fid,err.cause{cidx})
        end
    end
else
    if isempty(fid)
        error('Must first call %s(''init'')',mfilename)
    end
    fprintf(fid,str,varargin{:});
    if length(varargin)==1
        str = [str '\n'];
        fprintf(str,varargin{:});
    end
end

function displayException(fid,err)

fprintf('\n*** %s:%s ***\n',err.identifier,err.message);
fprintf(fid,'\n*** %s:%s ***\n',err.identifier,err.message);

for sidx = 1:length(err.stack)
    fprintf('\t\t%s:%d\n',err.stack(sidx).file,err.stack(sidx).line);
    fprintf(fid,'\t\t%s:%d\n',err.stack(sidx).file,err.stack(sidx).line);
end
