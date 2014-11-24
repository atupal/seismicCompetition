/*
 * fm2d_types.h
 *
 * Code generation for function 'fm2d'
 *
 */

#ifndef __FM2D_TYPES_H__
#define __FM2D_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef typedef_emxArray__common
#define typedef_emxArray__common
typedef struct emxArray__common emxArray__common;
#endif /*typedef_emxArray__common*/
#ifndef struct_emxArray_int32_T_100
#define struct_emxArray_int32_T_100
struct emxArray_int32_T_100
{
    int32_T data[100];
    int32_T size[1];
};
#endif /*struct_emxArray_int32_T_100*/
#ifndef typedef_emxArray_int32_T_100
#define typedef_emxArray_int32_T_100
typedef struct emxArray_int32_T_100 emxArray_int32_T_100;
#endif /*typedef_emxArray_int32_T_100*/
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/
#ifndef struct_emxArray_real_T_100
#define struct_emxArray_real_T_100
struct emxArray_real_T_100
{
    real_T data[100];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_100*/
#ifndef typedef_emxArray_real_T_100
#define typedef_emxArray_real_T_100
typedef struct emxArray_real_T_100 emxArray_real_T_100;
#endif /*typedef_emxArray_real_T_100*/
#ifndef struct_emxArray_real_T_118
#define struct_emxArray_real_T_118
struct emxArray_real_T_118
{
    real_T data[118];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_118*/
#ifndef typedef_emxArray_real_T_118
#define typedef_emxArray_real_T_118
typedef struct emxArray_real_T_118 emxArray_real_T_118;
#endif /*typedef_emxArray_real_T_118*/
#ifndef struct_emxArray_real_T_118x48
#define struct_emxArray_real_T_118x48
struct emxArray_real_T_118x48
{
    real_T data[5664];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_118x48*/
#ifndef typedef_emxArray_real_T_118x48
#define typedef_emxArray_real_T_118x48
typedef struct emxArray_real_T_118x48 emxArray_real_T_118x48;
#endif /*typedef_emxArray_real_T_118x48*/
#ifndef struct_emxArray_real_T_120x50
#define struct_emxArray_real_T_120x50
struct emxArray_real_T_120x50
{
    real_T data[6000];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_120x50*/
#ifndef typedef_emxArray_real_T_120x50
#define typedef_emxArray_real_T_120x50
typedef struct emxArray_real_T_120x50 emxArray_real_T_120x50;
#endif /*typedef_emxArray_real_T_120x50*/
#ifndef struct_emxArray_real_T_1x100
#define struct_emxArray_real_T_1x100
struct emxArray_real_T_1x100
{
    real_T data[100];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x100*/
#ifndef typedef_emxArray_real_T_1x100
#define typedef_emxArray_real_T_1x100
typedef struct emxArray_real_T_1x100 emxArray_real_T_1x100;
#endif /*typedef_emxArray_real_T_1x100*/
#ifndef struct_emxArray_real_T_1x118
#define struct_emxArray_real_T_1x118
struct emxArray_real_T_1x118
{
    real_T data[118];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x118*/
#ifndef typedef_emxArray_real_T_1x118
#define typedef_emxArray_real_T_1x118
typedef struct emxArray_real_T_1x118 emxArray_real_T_1x118;
#endif /*typedef_emxArray_real_T_1x118*/
#ifndef struct_emxArray_real_T_1x48
#define struct_emxArray_real_T_1x48
struct emxArray_real_T_1x48
{
    real_T data[48];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x48*/
#ifndef typedef_emxArray_real_T_1x48
#define typedef_emxArray_real_T_1x48
typedef struct emxArray_real_T_1x48 emxArray_real_T_1x48;
#endif /*typedef_emxArray_real_T_1x48*/
#ifndef struct_emxArray_real_T_1x50
#define struct_emxArray_real_T_1x50
struct emxArray_real_T_1x50
{
    real_T data[50];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x50*/
#ifndef typedef_emxArray_real_T_1x50
#define typedef_emxArray_real_T_1x50
typedef struct emxArray_real_T_1x50 emxArray_real_T_1x50;
#endif /*typedef_emxArray_real_T_1x50*/
#ifndef typedef_fm2dStackData
#define typedef_fm2dStackData
typedef struct
{
    struct
    {
        real_T v_data[6000];
        real_T a_data[6000];
        real_T b_data[6000];
        real_T tmp_data[5664];
        real_T b_tmp_data[5664];
        real_T c_tmp_data[5664];
    } f0;
} fm2dStackData;
#endif /*typedef_fm2dStackData*/

#endif
/* End of code generation (fm2d_types.h) */
