/*
 * exp1.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "exp1".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Jan 31 13:11:58 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_exp1_h_
#define RTW_HEADER_exp1_h_
#include <string.h>
#ifndef exp1_COMMON_INCLUDES_
# define exp1_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <def1104.h>
#include <slvdsp1104.h>
#include <rti_slv1104.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* exp1_COMMON_INCLUDES_ */

#include "exp1_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T SFunction1;                   /* '<S1>/S-Function1' */
  real_T SFunction2;                   /* '<S1>/S-Function2' */
  real_T ang_velocity;                 /* '<Root>/velocity' */
  real_T rpm;                          /* '<Root>/rev' */
  real_T theta;                        /* '<Root>/displacement' */
  real_T avg_rpm;                      /* '<Root>/Moving Average' */
} B_exp1_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;/* '<Root>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1;/* '<Root>/Moving Average' */
  dsp_MovingAverage_exp1_T obj;        /* '<Root>/Moving Average' */
  int_T SFunction1_IWORK;              /* '<S3>/S-Function1' */
  boolean_T objisempty;                /* '<Root>/Moving Average' */
} DW_exp1_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_exp1_T;

/* Parameters (auto storage) */
struct P_exp1_T_ {
  real_T Cmd_Value;                    /* Expression: .75
                                        * Referenced by: '<Root>/Cmd'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T velocity_Gain;                /* Expression: 2*pi/1000 *(1/0.0001)
                                        * Referenced by: '<Root>/velocity'
                                        */
  real_T rev_Gain;                     /* Expression: 30/pi
                                        * Referenced by: '<Root>/rev'
                                        */
  real_T displacement_Gain;            /* Expression: 2*pi/1000
                                        * Referenced by: '<Root>/displacement'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_exp1_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_exp1_T exp1_P;

/* Block signals (auto storage) */
extern B_exp1_T exp1_B;

/* Block states (auto storage) */
extern DW_exp1_T exp1_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_exp1_T exp1_Y;

/* Model entry point functions */
extern void exp1_initialize(void);
extern void exp1_output(void);
extern void exp1_update(void);
extern void exp1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_exp1_T *const exp1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'exp1'
 * '<S1>'   : 'exp1/DS1104ENC_POS_C1'
 * '<S2>'   : 'exp1/DS1104ENC_SETUP'
 * '<S3>'   : 'exp1/DS1104SL_DSP_PWM3'
 * '<S4>'   : 'exp1/RTI Data'
 * '<S5>'   : 'exp1/RTI Data/RTI Data Store'
 * '<S6>'   : 'exp1/RTI Data/RTI Data Store/RTI Data Store'
 * '<S7>'   : 'exp1/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_exp1_h_ */
