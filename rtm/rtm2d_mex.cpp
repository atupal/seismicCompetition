#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include <math.h>

void rtm2d(double *v , double *data, double *boundary, 
    int nz, int nx, int nt, 
    double dt, double dx,
    double *model, double *snapshot
    );

#define min(a, b) (a) < (b) ? (a) : (b)

void mexFunction(int plhs, mxArray *alhs[], 
    const int prhs, const mxArray *arhs[]) {
  int nz = mxGetM(arhs[0]);
  int nx = mxGetN(arhs[0]);
  int nt = mxGetN(arhs[1]);
  //double *fdm1 = (double *) malloc (sizeof(double) * (nz * nx));
  //double *fdm2 = (double *) malloc (sizeof(double) * (nz * nx));
  //double *fdm3 = (double *) malloc (sizeof(double) * (nz * nx));
  int iz ; // TODO
  //double boundary[20];
  //for (int i = 1; i <= 20; ++ i) {
  //  boundary[i-1] = exp( - ( (0.015*0.015*(20-i)*(20-i)) )  * 10);
  //}
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

  mwSize size[3];
  size[0] = nz;
  size[1] = nx;
  size[2] = nt;
  alhs[1] = mxCreateNumericArray(3, size, mxDOUBLE_CLASS, mxREAL);
  alhs[0] = mxCreateDoubleMatrix(nz, nx, mxREAL);

  double *model = mxGetPr(alhs[0]);
  double *snapshot = mxGetPr(alhs[1]);
	double * data = mxGetPr(arhs[1]);
	double * v = mxGetPr(arhs[0]);
	double  dt = mxGetPr(arhs[3])[0];
	double  dx = mxGetPr(arhs[2])[0];

  rtm2d(v, data, boundary, nz, nx, nt, dt, dx, model, snapshot);

}



void rtm2d(double *v , double *data, double *boundary, 
    int nz, int nx, int nt, 
    double dt, double dx,
    double *model, double *snapshot
    ) {
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
	//double * snapshot = (double*)malloc(sizeof(double)*nz*nx*nt);

	//memset M to zero
//#pragma omp parallel for
//	for (int i = 0; i < nx; i++)
//		for (int j = 0; j < nz; j++)
//			M[i*nz + j] = 0.0;

	//initial fdm1,fdm2,fdm3
	for (int ix = 0; ix < nx; ix++)
	{
		fdm1[ix*nz] = data[(nt - 1)*nx + ix];
		fdm2[ix*nz] = data[(nt - 2)*nx + ix];
		fdm3[ix*nz] = data[(nt - 3)*nx + ix];
	}

#pragma omp parallel for
	for (int ix = 0; ix < nx; ix++)
	{
		for (int j = 0; j < nz; j++)
		{
      double tmp = v[ix*nz + j] * dt / dx;
			a[ix*nz + j] = tmp*tmp;
			b[ix*nz + j] = 2 - 4.0*a[ix*nz + j];
		}
	}
	int cz = 3;
	int bz = 0;
	for (int it = nt - 2; it >= 0; it--)
	{
		cz++;
		bz = min(cz, nz);

		//fdm1 and fdm2 dot boundary   0~20 and nx-20~nx-1
#pragma omp parallel for
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
#pragma omp parallel for
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
#pragma omp parallel for
		for (int ix = 1; ix < nx - 1; ix++)
		{
			for (int iz = 0; iz < bz; iz++)
			{
				fdm3[ix*nz + iz] -= fdm1[ix*nz + iz];
			}
		}
#pragma omp parallel for
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
#pragma omp parallel for
		for (int ix = 1; ix < nx - 1; ix++)
		{
			fdm2[ix*nz] = b[ix*nz] * fdm1[ix*nz] + fdm2[ix*nz]
				+ a[(ix + 1)*nz] * fdm1[(ix + 1)*nz]
				+ a[(ix - 1)*nz] * fdm1[(ix - 1)*nz]
				+ a[ix*nz + 1] * fdm1[ix*nz + 1];
		}
		if (bz == nz)
		{
#pragma omp parallel for
			for (int ix = 1; ix < nx - 1; ix++)
				fdm2[ix*nz + nz - 1] = b[ix*nz + nz - 1] * fdm1[ix*nz + nz - 1] + fdm2[ix*nz + nz - 1]
				+ a[(ix + 1)*nz + nz - 1] * fdm1[(ix + 1)*nz + nz - 1]
				+ a[(ix - 1)*nz + nz - 1] * fdm1[(ix - 1)*nz + nz - 1]
				+ a[ix*nz + nz - 2] * fdm1[ix*nz + nz - 2];
			fdm2[nz - 1] = b[nz - 1] * fdm1[nz - 1] + fdm2[nz - 1]
				+ a[nz + nz - 1] * fdm1[nz + nz - 1] + a[nz - 2] * fdm1[nz - 2];
		}

#pragma omp parallel for
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
#pragma omp parallel for 
			for (int ix = 0; ix < nx; ix++)
			{
				//find a bug
				fdm3[ix*nz] = data[(it - 2)*nx + ix];
			}
		}
		else
		{
#pragma omp parallel for
			for (int ix = 0; ix < nx; ix++)
			{
				for (int iz = 0; iz < nz; iz++)
				{
					fdm3[ix*nz + iz] = fdm2[ix*nz + iz];
				}
			}
		}

		int ntt = nx*nz*it;
#pragma omp parallel for
		for (int ix	= 0; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz; iz++)
			{
				snapshot[ntt + ix*nz + iz] = fdm1[ix*nz + iz];
			}
		}
	}

		for (int ix	= 0; ix < nx; ix++)
		{
			for (int iz = 0; iz < nz; iz++)
			{
				model[ix*nz + iz] = fdm1[ix*nz + iz];
			}
		}

    free(fdm1);
    free(fdm2);
    free(fdm3);
    free(a);
    free(b);
}


void test() {
}

int main() {
  test();

  return 0;
}