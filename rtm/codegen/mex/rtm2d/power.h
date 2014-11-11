/*
 * power.h
 *
 * Code generation for function 'power'
 *
 */

#ifndef __POWER_H__
#define __POWER_H__

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
extern void b_power(const real_T a_data[], const int32_T a_size[2], real_T
                    y_data[], int32_T y_size[2]);
extern void power(const real_T a[20], real_T y[20]);

#endif

/* End of code generation (power.h) */
