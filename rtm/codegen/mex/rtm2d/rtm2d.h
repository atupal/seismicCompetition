/*
 * rtm2d.h
 *
 * Code generation for function 'rtm2d'
 *
 */

#ifndef __RTM2D_H__
#define __RTM2D_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "rtm2d_types.h"

/* Function Declarations */
extern void rtm2d(rtm2dStackData *SD, const emlrtStack *sp, const real_T v_data[],
                  const int32_T v_size[2], const emxArray_real_T *data, real_T
                  dx, real_T dt, real_T model_data[], int32_T model_size[2],
                  emxArray_real_T *snapshot);

#endif

/* End of code generation (rtm2d.h) */
