/*
 * fm2d.h
 *
 * Code generation for function 'fm2d'
 *
 */

#ifndef __FM2D_H__
#define __FM2D_H__

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
#include "fm2d_types.h"

/* Function Declarations */
extern void fm2d(fm2dStackData *SD, const emlrtStack *sp, const real_T v_data[],
                 const int32_T v_size[2], const real_T model_data[], const
                 int32_T model_size[2], real_T dx, real_T nt, real_T dt,
                 emxArray_real_T *data, emxArray_real_T *snapshot);

#endif

/* End of code generation (fm2d.h) */
