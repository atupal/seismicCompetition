#include <stdio.h>
#include <mex.h>
#include <math.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shm_copy_common.h"
#define min(ELE1,ELE2) (ELE1)>(ELE2)?(ELE2):(ELE1);

void rtm2d_fm2d(double *v, double *data,double *boundary, double* M, int nz, int nx, int nt, double dt, double dx);


void mexFunction(int plhs, mxArray *alhs[], const int prhs,
    const mxArray *arhs[])
{
	int nt = mxGetN(arhs[1]);
	int nz = mxGetM(arhs[0]);
	int nx = mxGetN(arhs[0]);
	int cz = 3;
	double boundary[] = { 4.4385826077685947e-01,
		4.8239114011512579e-01, 5.2191528162939682e-01,
		5.6214244519682266e-01, 6.0275166475009512e-01,
		6.4339270657295611e-01, 6.8369046522894072e-01,
		7.2325024237984237e-01, 7.6166382133052701e-01,
		7.9851621875937684e-01, 8.3339296612850211e-01,
		8.6588774805920488e-01, 8.9561020475518838e-01,
		9.2219369144460783e-01, 9.4530278065205997e-01,
		9.6464029348312264e-01, 9.7995365426708503e-01,
		9.9104037877288398e-01, 9.9775252935263015e-01,
		1.0000000000000000e+00 };
	double * data = mxGetPr(arhs[1]);
	double * v = mxGetPr(arhs[0]);
	double  dt = mxGetPr(arhs[3])[0];
	double  dx = mxGetPr(arhs[2])[0];
	double *temp = NULL;
	alhs[0] = mxCreateDoubleMatrix(nz, nx, mxREAL);
	double * M = mxGetPr(alhs[0]);
	rtm2d_fm2d(v, data,boundary, M, nz, nx, nt, dt, dx);

}

void rtm2d_fm2d(double *v , double *data, double *boundary, double* M, int nz, int nx, int nt, double dt, double dx)
{

    pid_t pid = getpid();
    int shmid;
    char *shm;
    int key = 12345 + pid;
    int shmsize = (nx * nz + nx * nt + 20 + nz * nx) * sizeof(double) + 3 * sizeof(int) + 2 * sizeof(double);

    if ((shmid = shmget(key, shmsize, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }


    if ((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    char *s = shm;

    COPY_TO_SHM(&nx, sizeof(int));
    COPY_TO_SHM(&nz, sizeof(int));
    COPY_TO_SHM(&nt, sizeof(int));
    COPY_TO_SHM(&dt, sizeof(double));
    COPY_TO_SHM(&dx, sizeof(double));
    COPY_TO_SHM(v, nx * nz * sizeof(double));
    COPY_TO_SHM(data, nx * nt * sizeof(double));
    COPY_TO_SHM(boundary, 20 * sizeof(double));


    char systemargs[1000];
    snprintf(systemargs, 999, "env OMP_NUM_THREADS=1 rtm/rtm2d_fm2d_mex.core %d %d", key, shmsize);
    //snprintf(systemargs, 999, "rtm/rtm2d_fm2d_mex.core %d %d", key, shmsize);
    system(systemargs);


    COPY_TO_LOCAL(M, nx * nz * sizeof(double));


    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
    }
}
