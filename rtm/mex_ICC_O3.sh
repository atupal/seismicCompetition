#!/bin/sh

#option="-ansi-alias"
#option="-ansi"

option="$option -fopenmp"
option="$option -fPIC -fno-omit-frame-pointer"
option="$option -pthread"
# option="$option -no-prec-div"
# option="$option -no-vec"
#option="$option -restrict -vec-report2"

ldoption="-fopenmp"

mex -largeArrayDims CXX="g++" CXXFLAGS="-O2 $option" LDFLAGS="$ldoption" $@
