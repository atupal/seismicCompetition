MATLAB="/matlab"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/atupal/.matlab/R2014a"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for fm2d" > fm2d_mex.mki
echo "CC=$CC" >> fm2d_mex.mki
echo "CFLAGS=$CFLAGS" >> fm2d_mex.mki
echo "CLIBS=$CLIBS" >> fm2d_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> fm2d_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> fm2d_mex.mki
echo "CXX=$CXX" >> fm2d_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> fm2d_mex.mki
echo "CXXLIBS=$CXXLIBS" >> fm2d_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> fm2d_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> fm2d_mex.mki
echo "LD=$LD" >> fm2d_mex.mki
echo "LDFLAGS=$LDFLAGS" >> fm2d_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> fm2d_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> fm2d_mex.mki
echo "Arch=$Arch" >> fm2d_mex.mki
echo OMPFLAGS= >> fm2d_mex.mki
echo OMPLINKFLAGS= >> fm2d_mex.mki
echo "EMC_COMPILER=gcc" >> fm2d_mex.mki
echo "EMC_CONFIG=optim" >> fm2d_mex.mki
"/matlab/bin/glnxa64/gmake" -B -f fm2d_mex.mk
