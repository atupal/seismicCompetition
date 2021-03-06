/*
 * rtm2d_initialize.c
 *
 * Code generation for function 'rtm2d_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rtm2d.h"
#include "rtm2d_initialize.h"
#include "rtm2d_data.h"

/* Function Definitions */
void rtm2d_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (rtm2d_initialize.c) */
