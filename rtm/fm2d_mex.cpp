#include <stdio.h>
#include <mex.h>
#include <math.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>
#define min(ELE1,ELE2) (ELE1)>(ELE2)?(ELE2):(ELE1);

void rtm2d_fm2d(double *v, double *model,double *boundary, 
    double* snapshot, int nz, int nx, int nt, 
    double dt, double dx);

void mexFunction(int plhs, mxArray *alhs[], const int prhs, 
    const mxArray *arhs[])
{
	//int nt = mxGetN(arhs[1]);
	//int nt = ((int*)mxGetPr(arhs[3]))[0];

	int nz = mxGetM(arhs[0]);
	int nx = mxGetN(arhs[0]);
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


	double * v = mxGetPr(arhs[0]);
	double * model = mxGetPr(arhs[1]);
	double  dx = mxGetPr(arhs[2])[0];
	int nt = (int)(mxGetPr(arhs[3]))[0];
	double  dt = mxGetPr(arhs[4])[0];

  mwSize size[3];
  size[0] = nz;
  size[1] = nx;
  size[2] = nt;
  alhs[0] = mxCreateNumericArray(3, size, mxDOUBLE_CLASS, mxREAL);
  double *snapshot = mxGetPr(alhs[0]);

	rtm2d_fm2d(v, model, boundary, snapshot, nz, nx, nt, dt, dx);
	
}

void rtm2d_fm2d(double *v , double *model, double *boundary, 
    double* snapshot, int nz, int nx, int nt, 
    double dt, double dx)
{
	double * fdm1 = (double *)malloc(sizeof(double)*nz*nx);
	double * fdm2 = (double *)malloc(sizeof(double)*nz*nx);
  //memcpy(fdm2, model, sizeof(double)*nz*nx);
	double * fdm3 = (double *)malloc(sizeof(double)*nz*nx);
	memset(fdm1,0, sizeof(double)*nz*nx);

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < nz; ++ j) {
      fdm2[ i*nz + j ] = model[i*nz + j];
    }
  }

	memset(fdm3,0, sizeof(double)*nz*nx);

	double * b = (double *)malloc(sizeof(double)*nx*nz);
	double * a = (double *)malloc(sizeof(double)*nz*nx);
	double * temp = NULL;

#pragma omp parallel for
	for (int ix = 0; ix < nx; ix++)
	{
		for (int j = 0; j < nz; j++)
		{
			//a[ix*nz + j] = pow(v[ix*nz + j] * dt_dx, 2);
      double tmp = v[ix*nz + j] * dt/ dx;
      a[ix*nz + j] = tmp * tmp;
			b[ix*nz + j] = 2 - 4.0*a[ix*nz + j];
		}
	}

//fm2d function

	//it prablem
	for (int it = 1; it < nt; it++)
	{

    // % finite differencing on interior
#pragma omp parallel for
		for (int ix = 1; ix < nx-1; ix++)
		{
			for (int iz = 1; iz < nz - 1; iz++)
			{
				fdm3[ix*nz + iz] = b[ix*nz + iz] * fdm2[ix*nz + iz] - fdm1[ix*nz + iz] + \
					a[ix*nz + iz] * (fdm2[(ix + 1)*nz + iz] + fdm2[(ix - 1)*nz + iz] + \
					fdm2[ix*nz + (iz + 1)] + fdm2[ix*nz + (iz - 1)]);
			}
		}

    // % finite differencing at ix = 1 and ix = nx (surface, bottom)
#pragma omp parallel for
		for (int iz = 1; iz < nz-1; iz++)
		{
			fdm3[iz] = b[iz] * fdm2[iz] - fdm1[iz] +
				a[iz] * (fdm2[nz + iz] + fdm2[(iz + 1)] + fdm2[(iz - 1)]);
			fdm3[(nx - 1)*nz + iz] = b[(nx - 1)*nz + iz] * fdm2[(nx - 1)*nz + iz] - fdm1[(nx - 1)*nz + iz] +
				a[(nx - 1)*nz + iz] * (fdm2[(nx - 2)*nz + iz] + fdm2[(nx - 1)*nz + iz + 1]
				+ fdm2[(nx - 1)*nz + iz - 1]);
		}

    //% finite differencing at iz = 1 and iz = nz (z boundaries)
#pragma omp parallel for
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

    //  % apply absorbing boundary conditions to 3 sides (not surface)
#pragma omp parallel for 
		for (int ix = 0; ix < 20; ix++)
		{
			for (int iz = 0; iz < nz - 20; iz++)
			{
				fdm1[ix*nz + iz] = boundary[ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[ix] * fdm2[ix*nz + iz];
			}
		}

#pragma omp parallel for 
		for (int ix = nx - 20; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz - 20; iz++)
			{
				fdm1[ix*nz + iz] = boundary[nx - 1 - ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[nx - 1 - ix] * fdm2[ix*nz + iz];
			}
		}

#pragma omp parallel for
		
		for (int ix = 0; ix < nx; ix++)
		{
			for (int iz = nz - 20; iz < nz; iz++)
			{
				fdm1[ix*nz + iz] = boundary[nz - 1 - iz] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[nz - 1 - iz] * fdm2[ix*nz + iz];
			}
		}

		int tempPoint = (it)*nx*nz;
#pragma omp parallel for
		for (int ix = 0; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz; iz++)
			{
				//order 
				//M[ix*nz + iz] += fdm1[ix*nz + iz]*snapshot[ix*nz + iz + tempPoint];
        snapshot[ix*nz+iz+tempPoint] = fdm1[ix*nz + iz];
			}
		}
	}

	free(fdm1);
	free(fdm2);
	free(fdm3);
	free(a);
	free(b);
}
