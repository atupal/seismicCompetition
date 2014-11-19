#!/usr/bin/bash
ssh cpu1 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh cpu3 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh cpu4 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh gpu1 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh gpu2 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh gpu3 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh gpu4 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh gpu5 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
