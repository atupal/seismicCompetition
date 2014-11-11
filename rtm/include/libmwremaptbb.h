/* Copyright 2013 The MathWorks, Inc. */
#ifndef _REMAPTBB_H_
#define _REMAPTBB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWREMAPTBB_API
#    define LIBMWREMAPTBB_API
#endif

#include "tmwtypes.h"

EXTERN_C LIBMWREMAPTBB_API void remaptbb_real64(const real64_T *pSrc, 
                                                const real64_T *srcSize, 
                                                const real64_T ndims,
                                                real64_T *px, 
                                                real64_T *py, 
                                                int8_T interpolationMethod, 
                                                real64_T *fillVal,
                                                real64_T *pDst, 
                                                const real64_T *dstSize, 
                                                const real64_T numelDst);

EXTERN_C LIBMWREMAPTBB_API void remaptbb_real32(const real32_T *pSrc, 
                                                const real64_T *srcSize, 
                                                const real64_T ndims,
                                                real32_T *px, 
                                                real32_T *py, 
                                                int8_T interpolationMethod, 
                                                real32_T *fillVal,
                                                real32_T *pDst, 
                                                const real64_T *dstSize, 
                                                const real64_T numelDst);

EXTERN_C LIBMWREMAPTBB_API void remaptbb_uint8(const uint8_T *pSrc, 
                                               const real64_T *srcSize, 
                                               const real64_T ndims,
                                               real32_T *px, 
                                               real32_T *py, 
                                               int8_T interpolationMethod, 
                                               uint8_T *fillVal,
                                               uint8_T *pDst, 
                                               const real64_T *dstSize, 
                                               const real64_T numelDst);

#endif /* _REMAPTBB_H_ */
