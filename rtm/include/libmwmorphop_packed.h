/* Copyright 2013 The MathWorks, inc. */
#ifndef _LIBMWMORPHOP_PACKED_HPP_
#define _LIBMWMORPHOP_PACKED_HPP_

#ifndef LIBMWMORPHOP_PACKED_API
#    define LIBMWMORPHOP_PACKED_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>


EXTERN_C LIBMWMORPHOP_PACKED_API
void dilate_packed_uint32(const uint32_T* const  in,
                          const real64_T* const  inDims,
                          const real64_T         inNumDims,
                          const boolean_T* const nhood,
                          const real64_T*  const nhoodDims,
                          const real64_T         nhoodNumDims,
                                uint32_T*        out);

EXTERN_C LIBMWMORPHOP_PACKED_API
void erode_packed_uint32(const uint32_T* const  in,
                         const real64_T* const  inDims,
                         const real64_T         inNumDims,
                         const boolean_T* const nhood,
                         const real64_T*  const nhoodDims,
                         const real64_T         nhoodNumDims,
                         const real64_T         unpacked_M,
                               uint32_T*        out);

#endif