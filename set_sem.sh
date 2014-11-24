#!/usr/bin/bash
sem=11
ssh cpu1 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh cpu3 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh cpu4 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh gpu1 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh gpu2 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh gpu3 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh gpu4 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
ssh gpu5 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem $sem && pkill rtm2d"
