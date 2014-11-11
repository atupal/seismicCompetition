/* Copyright 2013 The MathWorks, Inc. */
#ifndef _BWPACKC_H_
#define _BWPACKC_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWBWPACKC_API
#    define LIBMWBWPACKC_API
#endif

#include "tmwtypes.h"

EXTERN_C LIBMWBWPACKC_API void bwPacking(const boolean_T *BW,
											const real64_T *inSize,
											uint32_T *outputBuffer,
											const real64_T *outSize);
#endif /* _BWPACKC_H_ */
