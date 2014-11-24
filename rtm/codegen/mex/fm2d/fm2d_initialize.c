/*
 * fm2d_initialize.c
 *
 * Code generation for function 'fm2d_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fm2d.h"
#include "fm2d_initialize.h"
#include "fm2d_data.h"

/* Function Definitions */
void fm2d_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (fm2d_initialize.c) */
