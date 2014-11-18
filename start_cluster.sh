#!/usr/bin/bash

MJS_SERVER="cpu1"
MDCE_SERVER="cpu1,cpu3"

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

for worker in `seq 1 15`; do
  ssh cpu1 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./startworker \
    -jobmanagerhost $MJS_SERVER -jobmanager sc14 -name worker${worker}"
  ssh cpu3 "cd $MATLAB_ROOT/toolbox/distcomp/bin && ./startworker \
    -jobmanagerhost $MJS_SERVER -jobmanager sc14 -name worker${worker}"
done

#ssh cpu1 "su - sc14 && cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
#ssh cpu3 "su - sc14 && cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
