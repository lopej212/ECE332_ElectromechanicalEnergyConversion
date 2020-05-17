/*
 * Lab_4.h
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

#ifndef RTW_HEADER_Lab_4_h_
#define RTW_HEADER_Lab_4_h_
#include <math.h>
#include <string.h>
#ifndef Lab_4_COMMON_INCLUDES_
# define Lab_4_COMMON_INCLUDES_
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
#endif                                 /* Lab_4_COMMON_INCLUDES_ */

#include "Lab_4_types.h"

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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction1;                   /* '<S8>/S-Function1' */
  real_T SFunction2;                   /* '<S8>/S-Function2' */
  real_T ang_velocity;                 /* '<S7>/velocity' */
  real_T rpm;                          /* '<S7>/rev' */
  real_T theta;                        /* '<S7>/displacement' */
  real_T SineWave;                     /* '<S2>/Sine Wave' */
  real_T SineWave1;                    /* '<S2>/Sine Wave1' */
  real_T SineWave2;                    /* '<S2>/Sine Wave2' */
  real_T avg_rpm;                      /* '<S7>/Moving Average' */
} B_Lab_4_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;/* '<S7>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1;/* '<S7>/Moving Average' */
  dsp_MovingAverage_Lab_4_T obj;       /* '<S7>/Moving Average' */
  int_T SFunction1_IWORK;              /* '<S6>/S-Function1' */
  boolean_T objisempty;                /* '<S7>/Moving Average' */
} DW_Lab_4_T;

/* Parameters (auto storage) */
struct P_Lab_4_T_ {
  real_T velocity_Gain;                /* Expression: 2*pi/1000 *(1/0.0001)
                                        * Referenced by: '<S7>/velocity'
                                        */
  real_T rev_Gain;                     /* Expression: 30/pi
                                        * Referenced by: '<S7>/rev'
                                        */
  real_T displacement_Gain;            /* Expression: 2*pi/1000
                                        * Referenced by: '<S7>/displacement'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.1
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 100*pi
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave1_Amp;                /* Expression: .1
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 100*pi
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: .1
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 100*pi
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 4*pi/3
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Lab_4_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Lab_4_T Lab_4_P;

/* Block signals (auto storage) */
extern B_Lab_4_T Lab_4_B;

/* Block states (auto storage) */
extern DW_Lab_4_T Lab_4_DW;

/* Model entry point functions */
extern void Lab_4_initialize(void);
extern void Lab_4_output(void);
extern void Lab_4_update(void);
extern void Lab_4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lab_4_T *const Lab_4_M;

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
 * '<Root>' : 'Lab_4'
 * '<S1>'   : 'Lab_4/RTI Data'
 * '<S2>'   : 'Lab_4/Subsystem1'
 * '<S3>'   : 'Lab_4/RTI Data/RTI Data Store'
 * '<S4>'   : 'Lab_4/RTI Data/RTI Data Store/RTI Data Store'
 * '<S5>'   : 'Lab_4/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S6>'   : 'Lab_4/Subsystem1/DS1104SL_DSP_PWM3'
 * '<S7>'   : 'Lab_4/Subsystem1/Subsystem'
 * '<S8>'   : 'Lab_4/Subsystem1/Subsystem/DS1104ENC_POS_C1'
 * '<S9>'   : 'Lab_4/Subsystem1/Subsystem/DS1104ENC_SETUP'
 */
#endif                                 /* RTW_HEADER_Lab_4_h_ */
