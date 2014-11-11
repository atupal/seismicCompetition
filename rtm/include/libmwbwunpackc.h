/* Copyright 2013 The MathWorks, Inc. */
#ifndef _BWUNPACKC_H_
#define _BWUNPACKC_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWBWUNPACKC_API
#    define LIBMWBWUNPACKC_API
#endif

#include "tmwtypes.h"

EXTERN_C LIBMWBWUNPACKC_API void bwUnpacking(const uint32_T *inputBuffer,
                                             const real64_T *inSize,
                                             boolean_T *BW,
                                             const real64_T *outSize);


#endif /* _BWUNPACKC_H_ */
