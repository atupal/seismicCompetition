#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_copy_common.h"
#define min(ELE1,ELE2) (ELE1)>(ELE2)?(ELE2):(ELE1);

void rtm2d_fm2d(double *v, double *data,double *boundary, double* M, int nz, int nx, int nt, double dt, double dx);

int itoa(char *s) {
    int v = 0;
    while (*s) {
        v = v * 10 + (*s - '0');
        s++;
    }
    return v;
}

int main(int argc, char *argv[]) {
    int shmkey = itoa(argv[1]);
    int shmsize = itoa(argv[2]);

    int shmid;

    if ((shmid = shmget(shmkey, shmsize, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    char *shm;
    char *s;

    if ((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    int nx, nz, nt;
    double dt, dx;

    s = shm;
    COPY_TO_LOCAL(&nx, sizeof(int));
    COPY_TO_LOCAL(&nz, sizeof(int));
    COPY_TO_LOCAL(&nt, sizeof(int));
    COPY_TO_LOCAL(&dt, sizeof(double));
    COPY_TO_LOCAL(&dx, sizeof(double));

    double *v = (double *)(malloc(nx * nz * sizeof(double)));
    COPY_TO_LOCAL(v, sizeof(double) * nx * nz);

    double *data = (double *)(malloc(nx * nt * sizeof(double)));
    COPY_TO_LOCAL(data, sizeof(double) * nx * nt);

    double *boundary = (double *)malloc(20 * sizeof(double));
    COPY_TO_LOCAL(boundary, 20 * sizeof(double));

    double *M = (double *)(malloc(nx * nz * sizeof(double)));



    rtm2d_fm2d(v, data, boundary, M, nz, nx, nt, dt, dx);


    COPY_TO_SHM(M, sizeof(double) * nx * nz);


    exit(0);
}

void rtm2d_fm2d(double *v , double *data, double *boundary, double* M, int nz, int nx, int nt, double dt, double dx)
{
	double * fdm1 = (double *)malloc(sizeof(double)*nz*nt);
	double * fdm2 = (double *)malloc(sizeof(double)*nz*nt);
	double * fdm3 = (double *)malloc(sizeof(double)*nz*nt);
	memset(fdm1,0, sizeof(double)*nz*nx);
	memset(fdm2,0, sizeof(double)*nz*nx);
	memset(fdm3,0, sizeof(double)*nz*nx);
	double * b = (double *)malloc(sizeof(double)*nx*nz);
	double * a = (double *)malloc(sizeof(double)*nz*nx);
	//double dt_dx = dt / dx;
	double * temp = NULL;
	double * snapshot = (double*)malloc(sizeof(double)*nz*nx*nt);

	//memset M to zero
#pragma omp parallel for simd collapse(2)
	for (int i = 0; i < nx; i++)
		for (int j = 0; j < nz; j++)
			M[i*nz + j] = 0.0;

	//initial fdm1,fdm2,fdm3
#pragma omp parallel for simd
	for (int ix = 0; ix < nx; ix++)
	{
		fdm1[ix*nz] = data[(nt - 1)*nx + ix];
		fdm2[ix*nz] = data[(nt - 2)*nx + ix];
		fdm3[ix*nz] = data[(nt - 3)*nx + ix];
	}

#pragma omp parallel for simd collapse(2)
	for (int ix = 0; ix < nx; ix++)
	{
		for (int j = 0; j < nz; j++)
		{
      double tmp = v[ix*nz + j] * dt / dx;
			//a[ix*nz + j] = pow(v[ix*nz + j] * dt_dx, 2);
			a[ix*nz + j] = tmp*tmp;
			b[ix*nz + j] = 2 - 4.0*a[ix*nz + j];
		}
	}
	int cz = 3;
	int bz = 0;
//#pragma omp parallel
	for (int it = nt - 2; it >= 0; it--)
	{
        cz++;
        bz = min(cz, nz);

		//fdm1 and fdm2 dot boundary   0~20 and nx-20~nx-1
#pragma omp parallel for simd collapse(2)
		for (int ix = 0; ix < 20; ix++)
		{
			for (int iz = 0; iz < bz; iz++)
			{
				fdm1[ix*nz + iz] = boundary[ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[ix] * fdm2[ix*nz + iz];
				fdm1[(nx - ix - 1)*nz + iz] = boundary[ix] * fdm1[(nx - ix - 1)*nz + iz];
				fdm2[(nx - ix - 1)*nz + iz] = boundary[ix] * fdm2[(nx - ix - 1)*nz + iz];
			}
		}
		if (bz >= (nz - 19))
		{
#pragma omp parallel for simd collapse(2)
			for (int ix = 0; ix < nx; ix++)
			{
				for (int iz = nz - 20; iz < bz; iz++)
				{
					fdm1[ix*nz + iz] = boundary[nz - 1 - iz] * fdm1[ix*nz + iz];
					fdm2[ix*nz + iz] = boundary[nz - 1 - iz] * fdm2[ix*nz + iz];
				}
			}
		}
		int ez = (nz == bz) ? nz - 1 : bz;
#pragma omp parallel for simd collapse(2)
		for (int ix = 1; ix < nx - 1; ix++)
		{
			for (int iz = 0; iz < bz; iz++)
			{
				fdm3[ix*nz + iz] -= fdm1[ix*nz + iz];
			}
		}
#pragma omp parallel for simd collapse(2)
		for (int ix = 1; ix < nx - 1; ix++)
		{
			for (int iz = 1; iz < ez; iz++)
			{
				fdm2[ix*nz + iz] = b[ix*nz + iz] * fdm1[ix*nz + iz] + fdm2[ix*nz + iz]
					+ a[(ix + 1)*nz + iz] * fdm1[(ix + 1)*nz + iz]
					+ a[(ix - 1)*nz + iz] * fdm1[(ix - 1)*nz + iz]
					+ a[ix*nz + iz + 1] * fdm1[ix*nz + iz + 1]
					+ a[ix*nz + iz - 1] * fdm1[ix*nz + iz - 1];
			}
		}
#pragma omp parallel for simd
		for (int ix = 1; ix < nx - 1; ix++)
		{
			fdm2[ix*nz] = b[ix*nz] * fdm1[ix*nz] + fdm2[ix*nz]
				+ a[(ix + 1)*nz] * fdm1[(ix + 1)*nz]
				+ a[(ix - 1)*nz] * fdm1[(ix - 1)*nz]
				+ a[ix*nz + 1] * fdm1[ix*nz + 1];
		}
		if (bz == nz)
		{
#pragma omp parallel for simd
			for (int ix = 1; ix < nx - 1; ix++)
				fdm2[ix*nz + nz - 1] = b[ix*nz + nz - 1] * fdm1[ix*nz + nz - 1] + fdm2[ix*nz + nz - 1]
				+ a[(ix + 1)*nz + nz - 1] * fdm1[(ix + 1)*nz + nz - 1]
				+ a[(ix - 1)*nz + nz - 1] * fdm1[(ix - 1)*nz + nz - 1]
				+ a[ix*nz + nz - 2] * fdm1[ix*nz + nz - 2];

            fdm2[nz - 1] = b[nz - 1] * fdm1[nz - 1] + fdm2[nz - 1]
                + a[nz + nz - 1] * fdm1[nz + nz - 1] + a[nz - 2] * fdm1[nz - 2];
		}

#pragma omp parallel for simd
		for (int iz = 1; iz < ez; iz++)
		{
			// time extrapolation at ix = 0
			fdm2[iz] = b[iz] * fdm1[iz] + fdm2[iz]
				+ a[nz + iz] * fdm1[nz + iz]
				+ a[iz + 1] * fdm1[iz + 1]
				+ a[iz - 1] * fdm1[iz - 1];
			fdm2[(nx - 1)*nz + iz] = b[(nx - 1)*nz + iz] * fdm1[(nx - 1)*nz + iz] + fdm2[(nx - 1)*nz + iz]
				+ a[(nx - 2)*nz + iz] * fdm1[(nx - 2)*nz + iz]
				+ a[(nx - 1)*nz + iz + 1] * fdm1[(nx - 1)*nz + iz + 1]
				+ a[(nx - 1)*nz + iz - 1] * fdm1[(nx - 1)*nz + iz - 1];
		}


        // time extrapolation at corner (0,0)
        fdm2[0] = b[0] * fdm1[0] + fdm2[0]
            + a[nz] * fdm1[nz] + a[1] * fdm1[1];

        // time extrapolation at corner (0,nx-1)
        fdm2[(nx - 1)*nz] = b[(nx - 1)*nz] * fdm1[(nx - 1)*nz] + fdm2[(nx - 1)*nz]
            + a[(nx - 2)*nz] * fdm1[(nx - 2)*nz]
            + a[(nx - 1)*nz + 1] * fdm1[(nx - 1)*nz + 1];


        temp = fdm1;
        fdm1 = fdm2;
        fdm2 = fdm3;
        fdm3 = temp;


		if (it > 1)
		{
			memset(fdm3, 0, sizeof(double)*nz*nx);
#pragma omp parallel for simd
			for (int ix = 0; ix < nx; ix++)
			{
				//find a bug
				fdm3[ix*nz] = data[(it - 2)*nx + ix];
			}
		}
		else
		{
#pragma omp parallel for simd
			for (int ix = 0; ix < nx; ix++)
			{
				for (int iz = 0; iz < nz; iz++)
				{
					fdm3[ix*nz + iz] = fdm2[ix*nz + iz];
				}
			}
		}

		int ntt = nx*nz*it;
#pragma omp parallel for simd
		for (int ix	= 0; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz; iz++)
			{
				snapshot[ntt + ix*nz + iz] = fdm1[ix*nz + iz];
			}
		}
	}


//fm2d function

	memset(fdm2,0,sizeof(double)*nz*nx);


	//exchange fdm2 and fdm1
	temp = fdm2;
	fdm2 = fdm1;
	fdm1 = temp;

	memset(fdm3, 0, sizeof(double)*nz*nx);



	//it prablem
	for (int it = 1; it < nt; it++)
	{

#pragma omp parallel for simd
		for (int ix = 1; ix < nx-1; ix++)
		{
			for (int iz = 1; iz < nz - 1; iz++)
			{
				fdm3[ix*nz + iz] = b[ix*nz + iz] * fdm2[ix*nz + iz] - fdm1[ix*nz + iz] + \
					a[ix*nz + iz] * (fdm2[(ix + 1)*nz + iz] + fdm2[(ix - 1)*nz + iz] + \
					fdm2[ix*nz + (iz + 1)] + fdm2[ix*nz + (iz - 1)]);
			}
		}

#pragma omp parallel for simd
		for (int iz = 1; iz < nz-1; iz++)
		{
			fdm3[iz] = b[iz] * fdm2[iz] - fdm1[iz] +
				a[iz] * (fdm2[nz + iz] + fdm2[(iz + 1)] + fdm2[(iz - 1)]);
			fdm3[(nx - 1)*nz + iz] = b[(nx - 1)*nz + iz] * fdm2[(nx - 1)*nz + iz] - fdm1[(nx - 1)*nz + iz] +
				a[(nx - 1)*nz + iz] * (fdm2[(nx - 2)*nz + iz] + fdm2[(nx - 1)*nz + iz + 1]
				+ fdm2[(nx - 1)*nz + iz - 1]);
		}

#pragma omp parallel for simd
		for (int ix = 1; ix < nx - 1; ix++)
		{
			fdm3[ix*nz] = b[ix*nz] * fdm2[ix*nz] - fdm1[ix*nz] +
				a[ix*nz] * (fdm2[ix*nz + 1] + fdm2[(ix + 1)*nz] + fdm2[(ix - 1)*nz]);
			fdm3[ix*nz + (nz - 1)] = b[ix*nz + nz - 1] * fdm2[ix*nz + nz - 1] - fdm1[ix*nz + nz - 1] +
				a[ix*nz + nz - 1] * (fdm2[ix*nz + (nz - 2)] + fdm2[(ix + 1)*nz + nz - 1] +
				fdm2[(ix - 1)*nz + nz - 1]);
		}

    //  % finite differencing at four corners (1,1), (nz,1), (1,nx), (nz,nx)
		fdm3[0] = b[0] * fdm2[0] - fdm1[0] + a[0] * (fdm2[1] + fdm2[nz]);
		fdm3[nz - 1] = b[nz - 1] * fdm2[nz - 1] - fdm1[nz - 1] +
			a[nz - 1] * (fdm2[nz + nz - 1] + fdm2[nz - 2]);
			//a[nz - 1] * (fdm2[nz + nz - 1] + fdm2[nz + (nz - 2)]); // BUGBUG

		fdm3[(nx - 1)*nz] = b[(nx - 1)*nz] * fdm2[(nx - 1)*nz] - fdm1[(nx - 1)*nz] +
			a[(nx - 1)*nz] * (fdm2[(nx - 2)*nz] + fdm2[(nx - 1)*nz + 1]);
			//a[(nx - 1)*nz] * (fdm2[(nx - 1)*nz] + fdm2[(nx - 1)*nz + 1]); //BUGBUG
		fdm3[(nx - 1)*nz + (nz - 1)] = b[(nx - 1)*nz + (nz - 1)] * fdm2[(nx - 1)*nz + (nz - 1)] - fdm1[(nx - 1)*nz + (nz - 1)] +
			a[(nx - 1)*nz + (nz - 1)] * (fdm2[(nx - 1)*nz + (nz - 2)] + fdm2[(nx - 2)*nz + (nz - 1)]);
			//a[(nx - 1)*nz + (nz - 1)] * (fdm2[(nx - 1)*nz + (nz - 2)] + fdm2[(nx - 1)*nz + (nz - 1)]); //BUGBUG

		temp = fdm1;
		fdm1 = fdm2;
		fdm2 = fdm3;
		fdm3 = temp;

#pragma omp parallel for simd
		for (int ix = 0; ix < 20; ix++)
		{
			for (int iz = 0; iz < nz - 20; iz++)
			{
				fdm1[ix*nz + iz] = boundary[ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[ix] * fdm2[ix*nz + iz];
			}
		}

#pragma omp parallel for simd
		for (int ix = nx - 20; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz - 20; iz++)
			{
				fdm1[ix*nz + iz] = boundary[nx - 1 - ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[nx - 1 - ix] * fdm2[ix*nz + iz];
			}
		}

#pragma omp parallel for simd

		for (int ix = 0; ix < nx; ix++)
		{
			for (int iz = nz - 20; iz < nz; iz++)
			{
				fdm1[ix*nz + iz] = boundary[nz - 1 - iz] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[nz - 1 - iz] * fdm2[ix*nz + iz];
			}
		}

		int tempPoint = (nt-it-1)*nx*nz;
#pragma omp parallel for simd
		for (int ix = 0; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz; iz++)
			{
				//order
				M[ix*nz + iz] += fdm1[ix*nz + iz]*snapshot[ix*nz + iz + tempPoint];
			}
		}
	}
	free(snapshot);
	free(fdm1);
	free(fdm2);
	free(fdm3);
	free(a);
	free(b);
}
