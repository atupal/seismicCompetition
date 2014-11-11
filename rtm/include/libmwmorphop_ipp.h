/* Copyright 2013 The MathWorks, inc. */
#ifndef _LIBMWMORPHOP_IPP_HPP_
#define _LIBMWMORPHOP_IPP_HPP_

#ifndef LIBMWMORPHOP_IPP_API
#    define LIBMWMORPHOP_IPP_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>


EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_uint8_ipp(const   uint8_T* const in, const real64_T* inDims, const boolean_T useSingleThread, uint8_T*  out);
EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_uint16_ipp(const uint16_T* const in, const real64_T* inDims, const boolean_T useSingleThread, uint16_T* out);
EXTERN_C LIBMWMORPHOP_IPP_API
void dilate_real32_ipp(const real32_T* const in, const real64_T* inDims, const boolean_T useSingleThread, real32_T* out);

EXTERN_C LIBMWMORPHOP_IPP_API
void erode_uint8_ipp(const   uint8_T* const in, const real64_T* inDims, const boolean_T useSingleThread, uint8_T*  out);
EXTERN_C LIBMWMORPHOP_IPP_API
void erode_uint16_ipp(const uint16_T* const in, const real64_T* inDims, const boolean_T useSingleThread, uint16_T* out);
EXTERN_C LIBMWMORPHOP_IPP_API
void erode_real32_ipp(const real32_T* const in, const real64_T* inDims, const boolean_T useSingleThread, real32_T* out);

#endif
