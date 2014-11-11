/* Copyright 2013 The MathWorks, Inc. */
#ifndef _BWUNPACKCTBB_H_
#define _BWUNPACKCTBB_H_

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifndef LIBMWBWUNPACKCTBB_API
#    define LIBMWBWUNPACKCTBB_API
#endif

#include "tmwtypes.h"

EXTERN_C LIBMWBWUNPACKCTBB_API void bwUnpackingtbb(const uint32_T *inputBuffer,
                                                   const real64_T *inSize,
												   boolean_T *BW,
                                                   const real64_T *outSize);


#endif /* _BWUNPACKCTBB_H_ */
