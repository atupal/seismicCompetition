/*
 * _coder_fm2d_api.c
 *
 * Code generation for function '_coder_fm2d_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fm2d.h"
#include "_coder_fm2d_api.h"
#include "fm2d_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, 1, "_coder_fm2d_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dx, const
  char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *v, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
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

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dx, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(dx), &thisId);
  emlrtDestroyArray(&dx);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  int32_T iv20[2];
  boolean_T bv0[2];
  int32_T i9;
  int32_T iv21[2];
  for (i9 = 0; i9 < 2; i9++) {
    iv20[i9] = 120 + -70 * i9;
    bv0[i9] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv20, bv0, iv21);
  ret_size[0] = iv21[0];
  ret_size[1] = iv21[1];
  *ret_data = (real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
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

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv18[2] = { 0, 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv18, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void fm2d_api(fm2dStackData *SD, const mxArray * const prhs[5], const mxArray
              *plhs[2])
{
  emxArray_real_T *data;
  emxArray_real_T *snapshot;
  int32_T v_size[2];
  real_T (*v_data)[6000];
  int32_T model_size[2];
  real_T (*model_data)[6000];
  real_T dx;
  real_T nt;
  real_T dt;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_real_T(&st, &data, 2, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &snapshot, 3, &c_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "v", (real_T **)&v_data, v_size);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "model", (real_T **)&model_data,
                   model_size);
  dx = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "dx");
  nt = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "nt");
  dt = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "dt");

  /* Invoke the target function */
  fm2d(SD, &st, *v_data, v_size, *model_data, model_size, dx, nt, dt, data,
       snapshot);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(data);
  plhs[1] = b_emlrt_marshallOut(snapshot);
  snapshot->canFreeData = false;
  emxFree_real_T(&snapshot);
  data->canFreeData = false;
  emxFree_real_T(&data);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_fm2d_api.c) */
