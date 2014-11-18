#!/usr/bin/bash

MJS_SERVER="cpu1"
MDCE_SERVER="cpu1,cpu3,cpu4,gpu1,gpu2,gpu3,gpu4,gpu5"

MATLAB_ROOT=/public/MATLAB/R2014a

cd $MATLAB_ROOT/toolbox/distcomp/bin

# start mdce
./remotemdce start -remotehost $MDCE_SERVER

# start MJS
./startjobmanager -name sc14 -remotehost $MJS_SERVER -v

# check
./nodestatus -remotehost $MJS_SERVER

#./startworker -jobmanagerhost $MJS_SERVER -jobmanager sc14 -remotehost $MDCE_SERVER -v
#./startworker -jobmanagerhost $MJS_SERVER -jobmanager sc14 -remotehost $MDCE_SERVER -v

for node in cpu1 cpu3 cpu4 gpu1 gpu2 gpu3 gpu4 gpu5; do
  for worker in `seq 1 15`; do
    ssh $node "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./startworker \
      -jobmanagerhost $MJS_SERVER -jobmanager sc14 -name worker${worker}"
  done
done

#ssh cpu1 "su - sc14 && cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
#ssh cpu3 "su - sc14 && cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
