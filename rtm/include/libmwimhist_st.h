/* Copyright 2013 The MathWorks, Inc. */

#ifndef _LIBMWIMHIST_ST_H_
#define _LIBMWIMHIST_ST_H_


#ifndef LIBMWIMHIST_ST_API
#    define LIBMWIMHIST_ST_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>

/* uint8_T*/
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_uint8(
        uint8_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint8_T scaled*/
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_uint8_scaled(
        uint8_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint16_T */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_uint16(
        uint16_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint16_T scaled */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_uint16_scaled(
        uint16_T *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* uint32_T scaled */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_uint32_scaled(
        uint32_T *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* real32_T */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_real32(
        real32_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* real32_T scaled */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_real32_scaled(
        real32_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/*  real64_T */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_real64(
        real64_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

/* real64_T scaled */
EXTERN_C LIBMWIMHIST_ST_API void imhist_st_real64_scaled(
        real64_T  *in,
        const real64_T  numInElem,
        const real64_T  numRows,
        const real64_T  numCols,
        real64_T       *out,
        const real64_T  numOutElem,
        const real64_T  maxVal,
        const real64_T  numBins,
        boolean_T      *rngFlag,
        boolean_T      *nanFlag);

#endif
