/*
 * Lab6_OpenLoop.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab6_OpenLoop".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Mar  6 13:47:36 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab6_OpenLoop_h_
#define RTW_HEADER_Lab6_OpenLoop_h_
#include <math.h>
#include <string.h>
#ifndef Lab6_OpenLoop_COMMON_INCLUDES_
# define Lab6_OpenLoop_COMMON_INCLUDES_
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
#endif                                 /* Lab6_OpenLoop_COMMON_INCLUDES_ */

#include "Lab6_OpenLoop_types.h"

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
} B_MATLABFunction_Lab6_OpenLoo_T;

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction2;                   /* '<S8>/S-Function2' */
  real_T ang_velocity;                 /* '<S3>/velocity' */
  real_T rpm;                          /* '<S3>/rev' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S1>/Proportional Gain' */
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T DerivativeGain;               /* '<S1>/Derivative Gain' */
  real_T Filter;                       /* '<S1>/Filter' */
  real_T SumD;                         /* '<S1>/SumD' */
  real_T FilterCoefficient;            /* '<S1>/Filter Coefficient' */
  real_T Integrator_d;                 /* '<S4>/Integrator' */
  real_T SineWave;                     /* '<S4>/Sine Wave' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Product;                      /* '<S4>/Product' */
  real_T SineWave1;                    /* '<S4>/Sine Wave1' */
  real_T Product1;                     /* '<S4>/Product1' */
  real_T SineWave2;                    /* '<S4>/Sine Wave2' */
  real_T Product2;                     /* '<S4>/Product2' */
  real_T IntegralGain;                 /* '<S1>/Integral Gain' */
  real_T SFunction1;                   /* '<S8>/S-Function1' */
  real_T theta;                        /* '<S3>/displacement' */
  B_MATLABFunction_Lab6_OpenLoo_T sf_MATLABFunction2;/* '<S4>/MATLAB Function2' */
  B_MATLABFunction_Lab6_OpenLoo_T sf_MATLABFunction1;/* '<S4>/MATLAB Function1' */
  B_MATLABFunction_Lab6_OpenLoo_T sf_MATLABFunction;/* '<S4>/MATLAB Function' */
} B_Lab6_OpenLoop_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;/* '<S3>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1;/* '<S3>/Moving Average' */
  dsp_MovingAverage_Lab6_OpenLo_T obj; /* '<S3>/Moving Average' */
  real_T Integrator_DSTATE;            /* '<S1>/Integrator' */
  real_T Filter_DSTATE;                /* '<S1>/Filter' */
  int_T SFunction1_IWORK;              /* '<S10>/S-Function1' */
  boolean_T objisempty;                /* '<S3>/Moving Average' */
} DW_Lab6_OpenLoop_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} X_Lab6_OpenLoop_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} XDot_Lab6_OpenLoop_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
} XDis_Lab6_OpenLoop_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Wrpm;                         /* '<Root>/Wrpm' */
  real_T Freq_In;                      /* '<Root>/Freq_In' */
} ExtY_Lab6_OpenLoop_T;

/* Parameters (auto storage) */
struct P_Lab6_OpenLoop_T_ {
  real_T DiscretePIDController_D;      /* Mask Parameter: DiscretePIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  real_T DiscretePIDController_N;      /* Mask Parameter: DiscretePIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T velocity_Gain;                /* Expression: 2*pi/1000 *(1/0.0001)
                                        * Referenced by: '<S3>/velocity'
                                        */
  real_T rev_Gain;                     /* Expression: 30/pi
                                        * Referenced by: '<S3>/rev'
                                        */
  real_T Cool_Name_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Cool_Name'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S1>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
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
};

/* Real-time Model Data Structure */
struct tag_RTM_Lab6_OpenLoop_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Lab6_OpenLoop_T *contStates;
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
extern P_Lab6_OpenLoop_T Lab6_OpenLoop_P;

/* Block signals (auto storage) */
extern B_Lab6_OpenLoop_T Lab6_OpenLoop_B;

/* Continuous states (auto storage) */
extern X_Lab6_OpenLoop_T Lab6_OpenLoop_X;

/* Block states (auto storage) */
extern DW_Lab6_OpenLoop_T Lab6_OpenLoop_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Lab6_OpenLoop_T Lab6_OpenLoop_Y;

/* Model entry point functions */
extern void Lab6_OpenLoop_initialize(void);
extern void Lab6_OpenLoop_output(void);
extern void Lab6_OpenLoop_update(void);
extern void Lab6_OpenLoop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lab6_OpenLoop_T *const Lab6_OpenLoop_M;

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
 * '<Root>' : 'Lab6_OpenLoop'
 * '<S1>'   : 'Lab6_OpenLoop/Discrete PID Controller'
 * '<S2>'   : 'Lab6_OpenLoop/RTI Data'
 * '<S3>'   : 'Lab6_OpenLoop/Subsystem'
 * '<S4>'   : 'Lab6_OpenLoop/Subsystem1'
 * '<S5>'   : 'Lab6_OpenLoop/RTI Data/RTI Data Store'
 * '<S6>'   : 'Lab6_OpenLoop/RTI Data/RTI Data Store/RTI Data Store'
 * '<S7>'   : 'Lab6_OpenLoop/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S8>'   : 'Lab6_OpenLoop/Subsystem/DS1104ENC_POS_C1'
 * '<S9>'   : 'Lab6_OpenLoop/Subsystem/DS1104ENC_SETUP'
 * '<S10>'  : 'Lab6_OpenLoop/Subsystem1/DS1104SL_DSP_PWM3'
 * '<S11>'  : 'Lab6_OpenLoop/Subsystem1/MATLAB Function'
 * '<S12>'  : 'Lab6_OpenLoop/Subsystem1/MATLAB Function1'
 * '<S13>'  : 'Lab6_OpenLoop/Subsystem1/MATLAB Function2'
 */
#endif                                 /* RTW_HEADER_Lab6_OpenLoop_h_ */
