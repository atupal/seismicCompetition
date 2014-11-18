#!/usr/bin/bash
ssh cpu1 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
ssh cpu3 "cd /public/sc14/matlab/seismicCompetition-git/rtm && ./sem && ./sem 11"
