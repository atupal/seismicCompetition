/*
 * _coder_fm2d_mex.c
 *
 * Code generation for function 'fm2d'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_fm2d_api.h"
#include "fm2d_initialize.h"
#include "fm2d_terminate.h"

/* Function Declarations */
static void fm2d_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "fm2d", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void fm2d_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[2];
  const mxArray *inputs[5];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  fm2dStackData* fm2dStackDataLocal = (fm2dStackData*)mxCalloc(1,sizeof(fm2dStackData));
  /* Module initialization. */
  fm2d_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 5, mxCHAR_CLASS, 4, "fm2d");
  } else if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 4, "fm2d");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  fm2d_api(fm2dStackDataLocal, inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  fm2d_terminate();
  mxFree(fm2dStackDataLocal);
}

void fm2d_atexit_wrapper(void)
{
   fm2d_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(fm2d_atexit_wrapper);
  /* Dispatch the entry-point. */
  fm2d_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_fm2d_mex.c) */
