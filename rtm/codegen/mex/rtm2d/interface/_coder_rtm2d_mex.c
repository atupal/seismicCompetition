/*
 * _coder_rtm2d_mex.c
 *
 * Code generation for function 'rtm2d'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_rtm2d_api.h"
#include "rtm2d_initialize.h"
#include "rtm2d_terminate.h"

/* Function Declarations */
static void rtm2d_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "rtm2d", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void rtm2d_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[2];
  const mxArray *inputs[4];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  rtm2dStackData* rtm2dStackDataLocal = (rtm2dStackData*)mxCalloc(1,sizeof(rtm2dStackData));
  /* Module initialization. */
  rtm2d_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 4, mxCHAR_CLASS, 5, "rtm2d");
  } else if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 5, "rtm2d");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  rtm2d_api(rtm2dStackDataLocal, inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  rtm2d_terminate();
  mxFree(rtm2dStackDataLocal);
}

void rtm2d_atexit_wrapper(void)
{
   rtm2d_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(rtm2d_atexit_wrapper);
  /* Dispatch the entry-point. */
  rtm2d_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_rtm2d_mex.c) */
