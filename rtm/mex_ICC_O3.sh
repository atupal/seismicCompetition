#!/bin/sh

#option="-ansi-alias"
#option="-ansi"

#option="$option -fopenmp"
option="$option -fPIC -fno-omit-frame-pointer"
#option="$option -pthread"

# option="$option -no-prec-div"
# option="$option -no-vec"
#option="$option -restrict -vec-report2"

#ldoption="-fopenmp"

icc -O3 rtm2d_fm2d_mex.core.cpp -o rtm2d_fm2d_mex.core -openmp -simd -xAVX -vec-report || exit 1
#icc -O3 rtm2d_fm2d_mex.core.cpp -o rtm2d_fm2d_mex.core -vec-report -no-vec || exit 1
#g++ -O3 rtm2d_fm2d_mex.core.cpp -o rtm2d_fm2d_mex.core || exit 1
#g++ -g rtm2d_fm2d_mex.core.cpp -o rtm2d_fm2d_mex.core || exit 1

mex CXX="icc" CXXFLAGS="-O2 $option" LDFLAGS="$ldoption" rtm2d_fm2d_mex.cpp
#mex CXX="g++" CXXFLAGS="-O2 $option" $1
