/*
 * rtm2d_terminate.c
 *
 * Code generation for function 'rtm2d_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rtm2d.h"
#include "rtm2d_terminate.h"

/* Function Definitions */
void rtm2d_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void rtm2d_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (rtm2d_terminate.c) */
