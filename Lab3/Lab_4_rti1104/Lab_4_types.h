/*
 * Lab_4_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab_4".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Feb 21 12:40:46 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab_4_types_h_
#define RTW_HEADER_Lab_4_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_isB4Cw3Ovpp8VfzP6RUqbD_
#define DEFINED_TYPEDEF_FOR_struct_isB4Cw3Ovpp8VfzP6RUqbD_

typedef struct {
  int32_T OutputPortsWidth;
} struct_isB4Cw3Ovpp8VfzP6RUqbD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_dZjXwTiylTPloSUBFpnHJB_
#define DEFINED_TYPEDEF_FOR_struct_dZjXwTiylTPloSUBFpnHJB_

typedef struct {
  int32_T InputPortsWidth;
} struct_dZjXwTiylTPloSUBFpnHJB;

#endif

#ifndef typedef_dsp_private_SlidingWindowAver_T
#define typedef_dsp_private_SlidingWindowAver_T

typedef struct {
  int32_T isInitialized;
  real_T pCumSum;
  real_T pCumSumRev[31];
  real_T pCumRevIndex;
} dsp_private_SlidingWindowAver_T;

#endif                                 /*typedef_dsp_private_SlidingWindowAver_T*/

#ifndef typedef_cell_wrap_Lab_4_T
#define typedef_cell_wrap_Lab_4_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_Lab_4_T;

#endif                                 /*typedef_cell_wrap_Lab_4_T*/

#ifndef typedef_dsp_MovingAverage_Lab_4_T
#define typedef_dsp_MovingAverage_Lab_4_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_Lab_4_T inputVarSize;
  dsp_private_SlidingWindowAver_T *pStatistic;
  int32_T NumChannels;
} dsp_MovingAverage_Lab_4_T;

#endif                                 /*typedef_dsp_MovingAverage_Lab_4_T*/

/* Parameters (auto storage) */
typedef struct P_Lab_4_T_ P_Lab_4_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Lab_4_T RT_MODEL_Lab_4_T;

#endif                                 /* RTW_HEADER_Lab_4_types_h_ */
