#include <stdio.h>
#include <mex.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <helper_cuda.h>

#define min(ELE1,ELE2) (ELE1)>(ELE2)?(ELE2):(ELE1);
#define GPUMALLOC(POINT,TYPE,SIZE) checkCudaErrors(cudaMalloc((void**)&(POINT),sizeof(TYPE)*(SIZE)))
#define GPUMEMCPY(PON1,PON2,TYPE,SIZE,CPYDERICT) checkCudaErrors(cudaMemcpy(PON1,PON2,sizeof(TYPE)*(SIZE),CPYDERICT))
typedef double * pdouble;



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
    pdouble dfdm1,dfdm2,dfdm3,da,db,dM,dsnapshot,ddata,dv,dboundary;
    GPUMALLOC(dfdm1, double, nz*nx);
	GPUMALLOC(dfdm2, double, nz*nx);
	GPUMALLOC(dfdm3, double, nz*nx);
	GPUMALLOC(da, double, nz*nx);
	GPUMALLOC(db, double, nz*nx);
	GPUMALLOC(dM, double, nz*nx);
	GPUMALLOC(dsnapshot, double, nz*nx*nt);
	GPUMALLOC(ddata, double, nt*nx);
	GPUMALLOC(dv, double, nz*nx);
	GPUMALLOC(dboundary, double, 20);

    GPUMEMCPY(dv, v, double, nz*nx, cudaMemcpyHostToDevice);
	GPUMEMCPY(dboundary, boundary, double, 20, cudaMemcpyHostToDevice);
	GPUMEMCPY(ddata, data, double, nt*nx, cudaMemcpyHostToDevice);

    dim3 threadsPerBlocks(16,16);
    dim3 numBlocks(16,16);
    getAB<<<numBlocks, threadsPerBlocks>>>(dv,da,db,dfdm1,dfdm2,
            dfdm3,dM,ddata,dt,dx,nz,nx,nt);

	int cz = 3;
	int bz = 0;
	for (int it = nt - 2; it >= 0; it--)
	{
		cz++;
		bz = min(cz, nz);
        rtm2d_kernel<<<numBlocks,threadsPerBlocks>>>(dfmd1,dfdm2,dfdm3,da,db,
                dboundary,dsnapshot,nz, nx, nt, dx, dt, it,bz);
    }

    rtm2d_to_fm2d<<<numBlocks,threadsPerBlocks>>>(dfdm1,dfdm2,dfdm3,nz,nx);

    for (int it = 1; it < nt; it++)
    {

        fm2d_kernel<<<numBlocks,threadsPerBlocks>>>(dfdm1,dfdm2,dfdm3,da,db,dboundary,dsnapshot,dM,nz,
                nx,nt,dx,dt,it,bz);
    }

    GPUMEMCPY(M,dM,double,nx*nz,cudaMemcpyDeviceToHost);
    checkCudaErrors(cudaFree(dM));
    checkCudaErrors(cudaFree(dv));
    checkCudaErrors(cudaFree(dsnapshot));
    checkCudaErrors(cudaFree(ddata));
    checkCudaErrors(cudaFree(dfdm3));
    checkCudaErrors(cudaFree(dfdm2));
    checkCudaErrors(cudaFree(dfdm1));
    checkCudaErrors(cudaFree(db));
    checkCudaErrors(cudaFree(da));
    checkCudaErrors(cudaFree(dboundary));
    return ;



}
__global__ void rtm2d_to_fm2d(double *fdm1,double *fdm2,double *fdm3,int nz,int nx)
{
    int idx = threadIdx.x + blockIdx.x*blockDim.x;
	int idy = threadIdx.y + blockIdx.y*blockDim.y;
	int idxDim = blockDim.x*gridDim.x;
	int idyDim = blockDim.y*gridDim.y;
    
	for (int ix = idx; ix < nx; ix += idxDim)
	{
		for (int iz = idy; iz < nz; iz += idyDim)
        {
            fdm2[ix*nz+iz] = fdm1[ix*nz+iz];
            fdm1[ix*nz+iz] = 0;
            fdm3[ix*nz+iz] = 0;
        }
    }

}
__global__ void getAB(double *v, double *a, double *b,double *fdm1,double *fdm2,
        double *fdm3,double *M,double * data,double dt,double dx, int nz, int nx,int nt)
{
	int idx = threadIdx.x + blockIdx.x*blockDim.x;
	int idy = threadIdx.y + blockIdx.y*blockDim.y;
	int idxDim = blockDim.x*gridDim.x;
	int idyDim = blockDim.y*gridDim.y;
	double tmp;
	for (int ix = idx; ix < nx; ix += idxDim)
	{
		for (int iz = idy; iz < nz; iz += idyDim)
		{
			tmp = v[ix*nz + iz] * dt / dx;
			a[ix*nz + iz] = tmp*tmp;
			b[ix*nz + iz] = 2 - 4.0*a[ix*nz + iz];
            if(iz==0)
            {
                fdm1[ix*nz] = data[(nt - 1)*nx + ix];
                fdm2[ix*nz] = data[(nt - 2)*nx + ix];
                fdm3[ix*nz] = data[(nt - 3)*nx + ix];
            }
            else
            {
                fdm1[ix*nz+iz] =0; 
                fdm2[ix*nz+iz] =0;
                fdm3[ix*nz+iz] =0;
            }
            M[ix*nz+iz]=0;

		}
	}
    
}


__global__ void rtm2d_kernel(double *fmd1,double *fdm2,double*fdm3,double*a,double*b,
        double*boundary,double*snapshot,int nz,int nx,int nt,double dx,double dt,int it,int bz)
{
    int idx=threadIdx.x+blockIdx.x*blockDim.x;
    int idz=threadIdx.y+blockIdx.y*blockDim.y;
    int idxDim = blockDim.x*gridDim.x;
    int idzDim = blockDim.y*gridDim.y;

    int ez = (nz == bz) ? nz - 1 : bz;
    int ntt = nx*nz*it;

    for(int ix=idx;ix<nx;ix+=idxDim)
    {
        for(int iz=idz;iz<nz;iz+=idzDim)
        {
            if(ix<20&&iz<bz)
            {
                fdm1[ix*nz + iz] = boundary[ix] * fdm1[ix*nz + iz];
                fdm2[ix*nz + iz] = boundary[ix] * fdm2[ix*nz + iz];
                fdm1[(nx - ix - 1)*nz + iz] = boundary[ix] * fdm1[(nx - ix - 1)*nz + iz];
                fdm2[(nx - ix - 1)*nz + iz] = boundary[ix] * fdm2[(nx - ix - 1)*nz + iz];
            }
            if (bz >= (nz - 19)&&iz>=nz-20&&iz<bz)
            {
                fdm1[ix*nz + iz] = boundary[nz - 1 - iz] * fdm1[ix*nz + iz];
                fdm2[ix*nz + iz] = boundary[nz - 1 - iz] * fdm2[ix*nz + iz];
            }
            if(ix>0&&ix<nx-1&&iz<bz)
            {
                fdm3[ix*nz + iz] -= fdm1[ix*nz + iz];
            }
            if(ix>0&&ix<nx-1&&iz>0&&iz<ez)
			{
				fdm2[ix*nz + iz] = b[ix*nz + iz] * fdm1[ix*nz + iz] + fdm2[ix*nz + iz]
					+ a[(ix + 1)*nz + iz] * fdm1[(ix + 1)*nz + iz]
					+ a[(ix - 1)*nz + iz] * fdm1[(ix - 1)*nz + iz]
					+ a[ix*nz + iz + 1] * fdm1[ix*nz + iz + 1]
					+ a[ix*nz + iz - 1] * fdm1[ix*nz + iz - 1];
			}
            if(ix>0&&ix<nx-1&&iz==0)
            {
                fdm2[ix*nz] = b[ix*nz] * fdm1[ix*nz] + fdm2[ix*nz]
                    + a[(ix + 1)*nz] * fdm1[(ix + 1)*nz]
                    + a[(ix - 1)*nz] * fdm1[(ix - 1)*nz]
                    + a[ix*nz + 1] * fdm1[ix*nz + 1];
            }
            if (bz == nz)
            {
                if(ix>0&&ix<nx-1&&iz==nz-1)
                {
                    for (int ix = 1; ix < nx - 1; ix++)
                        fdm2[ix*nz + nz - 1] = b[ix*nz + nz - 1] * fdm1[ix*nz + nz - 1] + fdm2[ix*nz + nz - 1]
                            + a[(ix + 1)*nz + nz - 1] * fdm1[(ix + 1)*nz + nz - 1]
                            + a[(ix - 1)*nz + nz - 1] * fdm1[(ix - 1)*nz + nz - 1]
                            + a[ix*nz + nz - 2] * fdm1[ix*nz + nz - 2];
                }
                if(ix==0&&iz==nz-1)
                {
                    fdm2[nz - 1] = b[nz - 1] * fdm1[nz - 1] + fdm2[nz - 1]
                        + a[nz + nz - 1] * fdm1[nz + nz - 1] + a[nz - 2] * fdm1[nz - 2];
                }
            }
            if(iz>0&&iz<ez)
            {
                if(ix==0)
                    fdm2[iz] = b[iz] * fdm1[iz] + fdm2[iz]
                        + a[nz + iz] * fdm1[nz + iz]
                        + a[iz + 1] * fdm1[iz + 1]
                        + a[iz - 1] * fdm1[iz - 1];
                if(ix==nx-1)
                    fdm2[(nx - 1)*nz + iz] = b[(nx - 1)*nz + iz] * fdm1[(nx - 1)*nz + iz] + fdm2[(nx - 1)*nz + iz]
                        + a[(nx - 2)*nz + iz] * fdm1[(nx - 2)*nz + iz]
                        + a[(nx - 1)*nz + iz + 1] * fdm1[(nx - 1)*nz + iz + 1]
                        + a[(nx - 1)*nz + iz - 1] * fdm1[(nx - 1)*nz + iz - 1];
            }
		// time extrapolation at corner (0,0)
            if(ix==0&&iz==0)
            {
                fdm2[0] = b[0] * fdm1[0] + fdm2[0]
                    + a[nz] * fdm1[nz] + a[1] * fdm1[1];
            }
		// time extrapolation at corner (0,nx-1)
            if(ix==nx-1&&iz==0)
            {
                fdm2[(nx - 1)*nz] = b[(nx - 1)*nz] * fdm1[(nx - 1)*nz] + fdm2[(nx - 1)*nz]
                    + a[(nx - 2)*nz] * fdm1[(nx - 2)*nz]
                    + a[(nx - 1)*nz + 1] * fdm1[(nx - 1)*nz + 1];
            }
            fdm1[ix*nz+iz]=fdm2[ix*nz+iz];
            fdm2[ix*nz+iz]=fdm3[ix*nz+iz];


            if (it > 1)
            {
                if(iz==0)
                {
                    fdm3[ix*nz] = data[(it - 2)*nx + ix];
                }
                else
                {
                    fdm3[ix*nz]=0.0;
                }
            }

            snapshot[ntt + ix*nz + iz] = fdm1[ix*nz + iz];
        }
    }
}

fdm2[ix*nz+iz]=fdm1[ix*nz+iz];
fdm1[ix*nz+iz]=0.0;
fdm3[ix*nz+iz]=0.0;




__global__ void fm2d_kernel(double *fmd1,double *fdm2,double*fdm3,double*a,double*b,
        double*boundary,double*snapshot,double*M,int nz,int nx,int nt,double dx,double dt,int it,int bz)
{
    int idx=threadIdx.x+blockIdx.x*blockDim.x;
    int idz=threadIdx.y+blockIdx.y*blockDim.y;
    int idxDim = blockDim.x*gridDim.x;
    int idzDim = blockDim.y*gridDim.y;

    int tempPoint = (nt-it-1)*nx*nz;

    for(int ix=idx;ix<nx;ix+=idxDim)
    {
        for(int iz=idz;iz<nz;iz+=idzDim)
        {
            if(ix>0&&ix<nx-1&&iz>0&&iz<nz-1)
            {
				fdm3[ix*nz + iz] = b[ix*nz + iz] * fdm2[ix*nz + iz] - fdm1[ix*nz + iz] + \
					a[ix*nz + iz] * (fdm2[(ix + 1)*nz + iz] + fdm2[(ix - 1)*nz + iz] + \
					fdm2[ix*nz + (iz + 1)] + fdm2[ix*nz + (iz - 1)]);
			}

            if(iz>0&&iz<nz-1&&ix==0)
            {
                fdm3[iz] = b[iz] * fdm2[iz] - fdm1[iz] +
                    a[iz] * (fdm2[nz + iz] + fdm2[(iz + 1)] + fdm2[(iz - 1)]);
            }
            if(iz>0&&iz<nz-1&&ix==nx-1)
            {
                fdm3[(nx - 1)*nz + iz] = b[(nx - 1)*nz + iz] * fdm2[(nx - 1)*nz + iz] - fdm1[(nx - 1)*nz + iz] +
                    a[(nx - 1)*nz + iz] * (fdm2[(nx - 2)*nz + iz] + fdm2[(nx - 1)*nz + iz + 1]+ 
                    fdm2[(nx - 1)*nz + iz - 1]);
            }
            if(iz==0&&ix<nx-1&&ix>0)
            {
                fdm3[ix*nz] = b[ix*nz] * fdm2[ix*nz] - fdm1[ix*nz] +
                    a[ix*nz] * (fdm2[ix*nz + 1] + fdm2[(ix + 1)*nz] + fdm2[(ix - 1)*nz]);
            }
            if(iz==nz-1&&ix<nx-1&&ix>0)
            {
                fdm3[ix*nz + (nz - 1)] = b[ix*nz + nz - 1] * fdm2[ix*nz + nz - 1] - fdm1[ix*nz + nz - 1] +
                    a[ix*nz + nz - 1] * (fdm2[ix*nz + (nz - 2)] + fdm2[(ix + 1)*nz + nz - 1] +
                            fdm2[(ix - 1)*nz + nz - 1]);
            }
            if(iz==0&&ix==0)
            {
                fdm3[0] = b[0] * fdm2[0] - fdm1[0] + a[0] * (fdm2[1] + fdm2[nz]);
            }
            if(iz==nz-1&&ix==0)
            {
                fdm3[nz - 1] = b[nz - 1] * fdm2[nz - 1] - fdm1[nz - 1] +
                    a[nz - 1] * (fdm2[nz + nz - 1] + fdm2[nz - 2]);
            }
            if(ix==nx-1&&iz==0)
            {
                fdm3[(nx - 1)*nz] = b[(nx - 1)*nz] * fdm2[(nx - 1)*nz] - fdm1[(nx - 1)*nz] +
                    a[(nx - 1)*nz] * (fdm2[(nx - 2)*nz] + fdm2[(nx - 1)*nz + 1]);
            }
            if(ix==nx-1&&iz==nz-1)
            {
                fdm3[(nx - 1)*nz + (nz - 1)] = b[(nx - 1)*nz + (nz - 1)] * fdm2[(nx - 1)*nz + (nz - 1)] - fdm1[(nx - 1)*nz + (nz - 1)] +
                    a[(nx - 1)*nz + (nz - 1)] * (fdm2[(nx - 1)*nz + (nz - 2)] + fdm2[(nx - 2)*nz + (nz - 1)]);
            }

            fdm1[ix*nz+iz]=fdm2[ix*nz+iz];
            fdm2[ix*nz+iz]=fdm3[ix*nz+iz];

            if(ix<20&&iz<nz-20)
            {
				fdm1[ix*nz + iz] = boundary[ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[ix] * fdm2[ix*nz + iz];
			}
            if(iz<nz-20&&ix>=nx-20&&ix<nx)
            {
				fdm1[ix*nz + iz] = boundary[nx - 1 - ix] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[nx - 1 - ix] * fdm2[ix*nz + iz];
			}

		
            if(iz>=nz-20&&iz<nz)
            {
				fdm1[ix*nz + iz] = boundary[nz - 1 - iz] * fdm1[ix*nz + iz];
				fdm2[ix*nz + iz] = boundary[nz - 1 - iz] * fdm2[ix*nz + iz];
			}

            M[ix*nz + iz] += fdm1[ix*nz + iz]*snapshot[ix*nz + iz + tempPoint];
        }
	}
}
