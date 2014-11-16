!rm results/*;
cd rtm;
!sh mex_ICC_O3.sh rtm2d_fm2d_mex.cpp
%!sh mex_cuda.sh kernel.cu
%!sh mex_cuda.sh rtm2d_fm2d_kernel.cu
cd ..;
imageModelData('SummerSaltTooth','./SEGY-files',{'parallel'})
% imageModelData('SummerFault','../SEGY-files',{'parallel'})
!mv results/*.mat results/result.mat;
diffStackedImages('SummerSaltTooth','results.sample/SummerSaltTooth_SampleRun_serial.mat', 'results/result.mat')
% diffStackedImages('SummerFault','results.sample/SummerFault_SampleRun_serial.mat', 'results/result.mat')
