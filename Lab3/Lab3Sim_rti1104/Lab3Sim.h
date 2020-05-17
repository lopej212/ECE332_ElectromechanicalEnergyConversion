/*
 * Lab3Sim.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab3Sim".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Feb  7 13:24:47 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab3Sim_h_
#define RTW_HEADER_Lab3Sim_h_
#include <string.h>
#ifndef Lab3Sim_COMMON_INCLUDES_
# define Lab3Sim_COMMON_INCLUDES_
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
#endif                                 /* Lab3Sim_COMMON_INCLUDES_ */

#include "Lab3Sim_types.h"

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
  real_T SFunction2;                   /* '<S8>/S-Function2' */
  real_T ang_velocity;                 /* '<S3>/velocity' */
  real_T rpm;                          /* '<S3>/rev' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Fcn;                          /* '<S4>/Fcn' */
  real_T Subtract;                     /* '<S4>/Subtract' */
  real_T SFunction1;                   /* '<S8>/S-Function1' */
  real_T theta;                        /* '<S3>/displacement' */
} B_Lab3Sim_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;/* '<S3>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1;/* '<S3>/Moving Average' */
  dsp_MovingAverage_Lab3Sim_T obj;     /* '<S3>/Moving Average' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  int_T SFunction1_IWORK;              /* '<S10>/S-Function1' */
  boolean_T objisempty;                /* '<S3>/Moving Average' */
} DW_Lab3Sim_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T command;                      /* '<Root>/command ' */
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Ref_w;                        /* '<Root>/Ref_w ' */
} ExtY_Lab3Sim_T;

/* Parameters (auto storage) */
struct P_Lab3Sim_T_ {
  real_T velocity_Gain;                /* Expression: 2*pi/1000 *(1/0.0001)
                                        * Referenced by: '<S3>/velocity'
                                        */
  real_T rev_Gain;                     /* Expression: 30/pi
                                        * Referenced by: '<S3>/rev'
                                        */
  real_T input3_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/input3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T displacement_Gain;            /* Expression: 2*pi/1000
                                        * Referenced by: '<S3>/displacement'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Lab3Sim_T {
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
extern P_Lab3Sim_T Lab3Sim_P;

/* Block signals (auto storage) */
extern B_Lab3Sim_T Lab3Sim_B;

/* Block states (auto storage) */
extern DW_Lab3Sim_T Lab3Sim_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Lab3Sim_T Lab3Sim_Y;

/* Model entry point functions */
extern void Lab3Sim_initialize(void);
extern void Lab3Sim_output(void);
extern void Lab3Sim_update(void);
extern void Lab3Sim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lab3Sim_T *const Lab3Sim_M;

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
 * '<Root>' : 'Lab3Sim'
 * '<S1>'   : 'Lab3Sim/MATLAB Function1'
 * '<S2>'   : 'Lab3Sim/RTI Data'
 * '<S3>'   : 'Lab3Sim/Subsystem'
 * '<S4>'   : 'Lab3Sim/Subsystem1'
 * '<S5>'   : 'Lab3Sim/RTI Data/RTI Data Store'
 * '<S6>'   : 'Lab3Sim/RTI Data/RTI Data Store/RTI Data Store'
 * '<S7>'   : 'Lab3Sim/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S8>'   : 'Lab3Sim/Subsystem/DS1104ENC_POS_C1'
 * '<S9>'   : 'Lab3Sim/Subsystem/DS1104ENC_SETUP'
 * '<S10>'  : 'Lab3Sim/Subsystem1/DS1104SL_DSP_PWM3'
 */
#endif                                 /* RTW_HEADER_Lab3Sim_h_ */
