/*
 * _coder_rtm2d_api.c
 *
 * Code generation for function '_coder_rtm2d_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rtm2d.h"
#include "_coder_rtm2d_api.h"
#include "rtm2d_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, 1, "_coder_rtm2d_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *data, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dx, const
  char_T *identifier);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *v, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv19[3] = { 0, 0, 0 };

  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericArray(3, iv19, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)u->data);
  emlrtSetDimensions((mxArray *)m1, u->size, 3);
  emlrtAssign(&y, m1);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *data, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(data), &thisId, y);
  emlrtDestroyArray(&data);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dx, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(dx), &thisId);
  emlrtDestroyArray(&dx);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *v, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(v), &thisId, y_data, y_size);
  emlrtDestroyArray(&v);
}

static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  static const int32_T iv18[2] = { 0, 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv18, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u_data);
  emlrtSetDimensions((mxArray *)m0, u_size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  int32_T iv20[2];
  boolean_T bv0[2];
  int32_T i5;
  int32_T iv21[2];
  for (i5 = 0; i5 < 2; i5++) {
    iv20[i5] = 120 + -70 * i5;
    bv0[i5] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv20, bv0, iv21);
  ret_size[0] = iv21[0];
  ret_size[1] = iv21[1];
  *ret_data = (real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv22[2];
  boolean_T bv1[2];
  int32_T i6;
  int32_T iv23[2];
  for (i6 = 0; i6 < 2; i6++) {
    iv22[i6] = 50 + 669 * i6;
    bv1[i6] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv22, bv1, iv23);
  ret->size[0] = iv23[0];
  ret->size[1] = iv23[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void rtm2d_api(rtm2dStackData *SD, const mxArray * const prhs[4], const mxArray *
               plhs[2])
{
  real_T (*model_data)[6000];
  emxArray_real_T *data;
  emxArray_real_T *snapshot;
  int32_T v_size[2];
  real_T (*v_data)[6000];
  real_T dx;
  real_T dt;
  int32_T model_size[2];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  model_data = (real_T (*)[6000])mxMalloc(sizeof(real_T [6000]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_real_T(&st, &data, 2, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &snapshot, 3, &c_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "v", (real_T **)&v_data, v_size);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "data", data);
  dx = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "dx");
  dt = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "dt");

  /* Invoke the target function */
  rtm2d(SD, &st, *v_data, v_size, data, dx, dt, *model_data, model_size,
        snapshot);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*model_data, model_size);
  plhs[1] = b_emlrt_marshallOut(snapshot);
  snapshot->canFreeData = false;
  emxFree_real_T(&snapshot);
  data->canFreeData = false;
  emxFree_real_T(&data);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_rtm2d_api.c) */
