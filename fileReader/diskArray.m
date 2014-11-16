classdef diskArray < handle
    %DISKARRAY Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (SetAccess = protected)
        VariableName = 'tempVar';
        FileName = ['tempvar_',num2str(labindex),'.mat'];
        FilePath = tempdir;
        SizeOfArray = [];
        Writable = false;
    end
    
    properties (SetAccess = protected, Hidden = true)
        matObj = [];
    end
    
    methods
        %% CONSTRUCTOR
        function obj = diskArray(varargin)
            
            if nargin < 1
                return
            else
                parseInputs = inputParser;
                parseInputs.addParamValue('VariableName', obj.VariableName);
                parseInputs.addParamValue('FileName', obj.FileName);
                parseInputs.addParamValue('Writable', obj.Writable);
                parseInputs.addParamValue('SizeOfArray', obj.SizeOfArray);
                parseInputs.parse(varargin{:});
                
                id = ismember(parseInputs.Parameters,parseInputs.UsingDefaults);
                fn = parseInputs.Parameters(~id);
                
                for f = 1:length(fn)
                    obj.(fn{f}) = parseInputs.Results.(fn{f});
                end
                
                % check filename for path info
                [p,fn,xt] = fileparts(obj.FileName);
                if ~isempty(p)
                    obj.FileName = [fn,xt];
                    obj.FilePath = p;
                end
            end
            % create mat file for partial reading and/or writing
            if ~createMatFile(obj)
                error('DISKARRAY:UnableToCreateFile','Unable to create file for storing array');
            end
        end % constructor diskArray
        
        function tf = createMatFile(obj)
            tf = true;
            try
                obj.matObj = matfile(fullfile(obj.FilePath,obj.FileName),'Writable',obj.Writable);
            catch
                tf = false;
            end
            
            % create the array
            if isempty(obj.SizeOfArray)
                obj.matObj.(obj.VariableName) = zeros(3,3,3);
                obj.SizeOfArray = size(obj.matObj.(obj.VariableName));
            else
                obj.matObj.(obj.VariableName)(obj.SizeOfArray(1),obj.SizeOfArray(2),obj.SizeOfArray(3)) = 0;
            end
            
        end %creatematFile
        
        function varargout = size(obj,dim)
            if nargout == 0
                obj.SizeOfArray
            end
            varargout = cell(1,nargout);
            if nargin == 2
                varargout{1} = obj.SizeOfArray(dim);
            else
                for n=1:nargout
                    varargout{n} = obj.SizeOfArray(n);
                end
            end
        end %size
        
        function c = whos(obj)
            c = whos(obj.matObj);
        end
        
        function c = who(obj)
            c = who(obj.matObj);
        end
        
        function varargout = subsref(obj, s)
            if strcmp(s(1).type,'()')
                if length(s) > 1
                    error('DISKARRAY:InvalidIndexing','This index operation is not allowed');
                end
                varargout{1} = obj.matObj.(obj.VariableName)(s.subs{:});
            elseif strcmp(s(1).type,'.')
                varargout{1} = obj.(s(1).subs);
            end
        end %subsref
        
        function varargout = subsasgn(obj,s,B)
            if strcmp(s(1).type,'()')
                if length(s) > 1
                    error('DISKARRAY:InvalidAssignment','This assignment operation is not allowed');
                end
                obj.matObj.(obj.VariableName)(s.subs{:}) = B;
            else
                error('DISKARRAY:InvalidAssignment','This assignment operation is not allowed');
            end 
            
            obj.SizeOfArray = size(obj.matObj,(obj.VariableName));
            varargout{1} = obj;
            
        end %subsassint
        
        function delete(obj)
            % delete the tempeorary file now that we're done.
            delete(fullfile(obj.FilePath,obj.FileName))
        end % delete     
        
    end % methods
    
end %classdef

