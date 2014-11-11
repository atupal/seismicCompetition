!rm results/*;
cd rtm;
!sh mex_ICC_O3.sh rtm2d_fm2d_mex.cpp
cd ..;
imageFaultModel;
!mv results/*.mat results/result.mat;
diffStackedImages('SummerFault','fault.mat', 'results/result.mat')
