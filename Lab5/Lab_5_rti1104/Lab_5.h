/*
 * Lab_5.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab_5".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Feb 28 13:40:01 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab_5_h_
#define RTW_HEADER_Lab_5_h_
#include <math.h>
#include <string.h>
#ifndef Lab_5_COMMON_INCLUDES_
# define Lab_5_COMMON_INCLUDES_
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
#endif                                 /* Lab_5_COMMON_INCLUDES_ */

#include "Lab_5_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

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

/* Block signals for system '<S4>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S4>/MATLAB Function' */
} B_MATLABFunction_Lab_5_T;

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction2;                   /* '<S8>/S-Function2' */
  real_T ang_velocity;                 /* '<S3>/velocity' */
  real_T rpm;                          /* '<S3>/rev' */
  real_T Integrator;                   /* '<S4>/Integrator' */
  real_T SineWave;                     /* '<S4>/Sine Wave' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Product;                      /* '<S4>/Product' */
  real_T SineWave1;                    /* '<S4>/Sine Wave1' */
  real_T Product1;                     /* '<S4>/Product1' */
  real_T SineWave2;                    /* '<S4>/Sine Wave2' */
  real_T Product2;                     /* '<S4>/Product2' */
  real_T SFunction1;                   /* '<S8>/S-Function1' */
  real_T theta;                        /* '<S3>/displacement' */
  real_T u;                            /* '<Root>/MATLAB Function' */
  B_MATLABFunction_Lab_5_T sf_MATLABFunction2;/* '<S4>/MATLAB Function2' */
  B_MATLABFunction_Lab_5_T sf_MATLABFunction1;/* '<S4>/MATLAB Function1' */
  B_MATLABFunction_Lab_5_T sf_MATLABFunction_j;/* '<S4>/MATLAB Function' */
} B_Lab_5_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;/* '<S3>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1;/* '<S3>/Moving Average' */
  dsp_MovingAverage_Lab_5_T obj;       /* '<S3>/Moving Average' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  int_T SFunction1_IWORK;              /* '<S10>/S-Function1' */
  boolean_T objisempty;                /* '<S3>/Moving Average' */
} DW_Lab_5_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} X_Lab_5_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} XDot_Lab_5_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
} XDis_Lab_5_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Wref_out;                     /* '<Root>/Wref_out' */
} ExtY_Lab_5_T;

/* Parameters (auto storage) */
struct P_Lab_5_T_ {
  real_T velocity_Gain;                /* Expression: 2*pi/1000 *(1/0.0001)
                                        * Referenced by: '<S3>/velocity'
                                        */
  real_T rev_Gain;                     /* Expression: 30/pi
                                        * Referenced by: '<S3>/rev'
                                        */
  real_T Wref_Value;                   /* Expression: 1
                                        * Referenced by: '<Root>/Wref'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2*pi
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .15
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/42
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T SineWave1_Amp;                /* Expression: 1
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 2*pi
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 1
                                        * Referenced by: '<S4>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 2*pi
                                        * Referenced by: '<S4>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 4*pi/3
                                        * Referenced by: '<S4>/Sine Wave2'
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
struct tag_RTM_Lab_5_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Lab_5_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][1];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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
extern P_Lab_5_T Lab_5_P;

/* Block signals (auto storage) */
extern B_Lab_5_T Lab_5_B;

/* Continuous states (auto storage) */
extern X_Lab_5_T Lab_5_X;

/* Block states (auto storage) */
extern DW_Lab_5_T Lab_5_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Lab_5_T Lab_5_Y;

/* Model entry point functions */
extern void Lab_5_initialize(void);
extern void Lab_5_output(void);
extern void Lab_5_update(void);
extern void Lab_5_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lab_5_T *const Lab_5_M;

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
 * '<Root>' : 'Lab_5'
 * '<S1>'   : 'Lab_5/MATLAB Function'
 * '<S2>'   : 'Lab_5/RTI Data'
 * '<S3>'   : 'Lab_5/Subsystem'
 * '<S4>'   : 'Lab_5/Subsystem1'
 * '<S5>'   : 'Lab_5/RTI Data/RTI Data Store'
 * '<S6>'   : 'Lab_5/RTI Data/RTI Data Store/RTI Data Store'
 * '<S7>'   : 'Lab_5/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S8>'   : 'Lab_5/Subsystem/DS1104ENC_POS_C1'
 * '<S9>'   : 'Lab_5/Subsystem/DS1104ENC_SETUP'
 * '<S10>'  : 'Lab_5/Subsystem1/DS1104SL_DSP_PWM3'
 * '<S11>'  : 'Lab_5/Subsystem1/MATLAB Function'
 * '<S12>'  : 'Lab_5/Subsystem1/MATLAB Function1'
 * '<S13>'  : 'Lab_5/Subsystem1/MATLAB Function2'
 */
#endif                                 /* RTW_HEADER_Lab_5_h_ */
