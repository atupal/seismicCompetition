/*
 * rtm2d_types.h
 *
 * Code generation for function 'rtm2d'
 *
 */

#ifndef __RTM2D_TYPES_H__
#define __RTM2D_TYPES_H__

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
#ifndef struct_emxArray_real_T_119
#define struct_emxArray_real_T_119
struct emxArray_real_T_119
{
    real_T data[119];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_119*/
#ifndef typedef_emxArray_real_T_119
#define typedef_emxArray_real_T_119
typedef struct emxArray_real_T_119 emxArray_real_T_119;
#endif /*typedef_emxArray_real_T_119*/
#ifndef struct_emxArray_real_T_119x48
#define struct_emxArray_real_T_119x48
struct emxArray_real_T_119x48
{
    real_T data[5712];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_119x48*/
#ifndef typedef_emxArray_real_T_119x48
#define typedef_emxArray_real_T_119x48
typedef struct emxArray_real_T_119x48 emxArray_real_T_119x48;
#endif /*typedef_emxArray_real_T_119x48*/
#ifndef struct_emxArray_real_T_120x48
#define struct_emxArray_real_T_120x48
struct emxArray_real_T_120x48
{
    real_T data[5760];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_120x48*/
#ifndef typedef_emxArray_real_T_120x48
#define typedef_emxArray_real_T_120x48
typedef struct emxArray_real_T_120x48 emxArray_real_T_120x48;
#endif /*typedef_emxArray_real_T_120x48*/
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
#ifndef struct_emxArray_real_T_1x119
#define struct_emxArray_real_T_1x119
struct emxArray_real_T_1x119
{
    real_T data[119];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x119*/
#ifndef typedef_emxArray_real_T_1x119
#define typedef_emxArray_real_T_1x119
typedef struct emxArray_real_T_1x119 emxArray_real_T_1x119;
#endif /*typedef_emxArray_real_T_1x119*/
#ifndef struct_emxArray_real_T_1x120
#define struct_emxArray_real_T_1x120
struct emxArray_real_T_1x120
{
    real_T data[120];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x120*/
#ifndef typedef_emxArray_real_T_1x120
#define typedef_emxArray_real_T_1x120
typedef struct emxArray_real_T_1x120 emxArray_real_T_1x120;
#endif /*typedef_emxArray_real_T_1x120*/
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
#ifndef struct_emxArray_real_T_1x70
#define struct_emxArray_real_T_1x70
struct emxArray_real_T_1x70
{
    real_T data[70];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x70*/
#ifndef typedef_emxArray_real_T_1x70
#define typedef_emxArray_real_T_1x70
typedef struct emxArray_real_T_1x70 emxArray_real_T_1x70;
#endif /*typedef_emxArray_real_T_1x70*/
#ifndef struct_emxArray_real_T_50
#define struct_emxArray_real_T_50
struct emxArray_real_T_50
{
    real_T data[50];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_50*/
#ifndef typedef_emxArray_real_T_50
#define typedef_emxArray_real_T_50
typedef struct emxArray_real_T_50 emxArray_real_T_50;
#endif /*typedef_emxArray_real_T_50*/
#ifndef typedef_rtm2dStackData
#define typedef_rtm2dStackData
typedef struct
{
    struct
    {
        real_T v_data[6000];
        real_T a_data[6000];
        real_T b_data[6000];
        real_T fdm_data[5760];
        real_T tmp_data[5712];
        real_T b_tmp_data[5712];
        real_T c_tmp_data[5712];
    } f0;
} rtm2dStackData;
#endif /*typedef_rtm2dStackData*/

#endif
/* End of code generation (rtm2d_types.h) */
