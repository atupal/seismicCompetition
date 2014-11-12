!rm results/*;
cd rtm;
%!sh mex_ICC_O3.sh rtm2d_fm2d_mex.cpp
%!sh mex_cuda.sh kernel.cu
!sh mex_cuda.sh rtm2d_fm2d_mex.cu
cd ..;
imageFaultModel;
!mv results/*.mat results/result.mat;
diffStackedImages('SummerFault','fault.mat', 'results/result.mat')
