#!/usr/bin/bash
MATLAB_ROOT="/public/MATLAB/R2014a"
MJS_SERVER="cpu1"
case $1 in
  start)
    ssh $2 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./mdce start"
    for worker in `seq 1 15`; do
      ssh $2 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./startworker \
        -jobmanagerhost $MJS_SERVER -jobmanager sc14 -name worker${worker}"
    done
    ;;
  stop)
    ssh $2 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./stopjobmanager -name sc14"
    ;;
esac
