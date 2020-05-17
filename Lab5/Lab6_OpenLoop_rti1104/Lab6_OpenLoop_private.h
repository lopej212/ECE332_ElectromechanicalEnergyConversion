/*
 * Lab6_OpenLoop_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab6_OpenLoop".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Mar  6 12:55:20 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab6_OpenLoop_private_h_
#define RTW_HEADER_Lab6_OpenLoop_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Lab6_OpenLoop.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern int slaveDSPPwm3StopFlag;
extern void Lab6_OpenLoop_MATLABFunction(real_T rtu_u,
  B_MATLABFunction_Lab6_OpenLoo_T *localB);

/* private model entry point functions */
extern void Lab6_OpenLoop_derivatives(void);

#endif                                 /* RTW_HEADER_Lab6_OpenLoop_private_h_ */
