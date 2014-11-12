#!/bin/bash

mex NVCCFLAGS="-gencode=arch=compute_13,code=sm_13" -largeArrayDims $@
