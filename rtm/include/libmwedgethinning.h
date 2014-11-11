/* Copyright 2013 The MathWorks, Inc. */

#ifndef _EDGETHINNING_H_
#define _EDGETHINNING_H_


#ifndef LIBMWEDGETHINNING_API
#    define LIBMWEDGETHINNING_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#include <tmwtypes.h>

/*real32*/
EXTERN_C LIBMWEDGETHINNING_API void edgethinning_real32(
	const	real32_T	*	pB,
	const	real32_T	*	pBx,
	const	real32_T	*	pBy,
	const	real64_T		kx,
	const	real64_T		ky,			
	const 	int8_T 		* 	offset,
	const	real64_T		eps,
	const	real64_T		cutoff,
			boolean_T	*	dst,
	const	real64_T	*	dstSize);

/*real64*/
EXTERN_C LIBMWEDGETHINNING_API void edgethinning_real64(
	const	real64_T	*	pB,
	const	real64_T	*	pBx,
	const	real64_T	*	pBy,
	const	real64_T		kx,
	const	real64_T		ky,			
	const 	int8_T 		* 	offset,
	const	real64_T		eps,
	const	real64_T		cutoff,
			boolean_T	*	dst,
	const	real64_T	*	dstSize);

#endif