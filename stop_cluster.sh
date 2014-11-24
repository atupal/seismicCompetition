#!/usr/bin/bash

MATLAB_ROOT="/public/MATLAB/R2014a"

ssh cpu1 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./stopjobmanager -name sc14"

#ssh cpu1 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./mdce stop -clean"
#ssh cpu3 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./mdce stop -clean"
#ssh cpu4 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./mdce stop -clean"

for node in cpu1 cpu3 cpu4 gpu1 gpu2 gpu3 gpu4 gpu5; do
  ssh $node "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./mdce stop -clean"
done
