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
    if isempty(err.cause)==true
        fprintf(fid,'\n*** %s ***\n',err.message);
    else
        fprintf(fid,'\n*** %s ***\n',err.cause{1}.identifier);
        fprintf(fid,'\t\t%s\n\n',err.cause{1}.message);
        fprintf('\n*** %s ***\n',err.cause{1}.identifier);
        fprintf('\t\t%s\n\n',err.cause{1}.message);
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
