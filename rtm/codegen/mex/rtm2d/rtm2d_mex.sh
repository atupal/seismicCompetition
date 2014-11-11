MATLAB="/matlab"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/atupal/.matlab/R2014a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for rtm2d" > rtm2d_mex.mki
echo "CC=$CC" >> rtm2d_mex.mki
echo "CFLAGS=$CFLAGS" >> rtm2d_mex.mki
echo "CLIBS=$CLIBS" >> rtm2d_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> rtm2d_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> rtm2d_mex.mki
echo "CXX=$CXX" >> rtm2d_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> rtm2d_mex.mki
echo "CXXLIBS=$CXXLIBS" >> rtm2d_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> rtm2d_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> rtm2d_mex.mki
echo "LD=$LD" >> rtm2d_mex.mki
echo "LDFLAGS=$LDFLAGS" >> rtm2d_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> rtm2d_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> rtm2d_mex.mki
echo "Arch=$Arch" >> rtm2d_mex.mki
echo OMPFLAGS= >> rtm2d_mex.mki
echo OMPLINKFLAGS= >> rtm2d_mex.mki
echo "EMC_COMPILER=gcc" >> rtm2d_mex.mki
echo "EMC_CONFIG=optim" >> rtm2d_mex.mki
"/matlab/bin/glnxa64/gmake" -B -f rtm2d_mex.mk
