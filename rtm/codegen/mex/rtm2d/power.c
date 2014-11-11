/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rtm2d.h"
#include "power.h"

/* Function Declarations */
static void eml_scalexp_alloc(const int32_T varargin_1_size[2], int32_T z_size[2]);

/* Function Definitions */
static void eml_scalexp_alloc(const int32_T varargin_1_size[2], int32_T z_size[2])
{
  int8_T iv17[2];
  int32_T i4;
  for (i4 = 0; i4 < 2; i4++) {
    iv17[i4] = (int8_T)varargin_1_size[i4];
  }

  z_size[0] = iv17[0];
  z_size[1] = iv17[1];
}

void b_power(const real_T a_data[], const int32_T a_size[2], real_T y_data[],
             int32_T y_size[2])
{
  int32_T i3;
  int32_T k;
  eml_scalexp_alloc(a_size, y_size);
  i3 = y_size[0] * y_size[1];
  for (k = 0; k < i3; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }
}

void power(const real_T a[20], real_T y[20])
{
  int32_T k;
  for (k = 0; k < 20; k++) {
    y[k] = muDoubleScalarPower(a[k], 10.0);
  }
}

/* End of code generation (power.c) */
