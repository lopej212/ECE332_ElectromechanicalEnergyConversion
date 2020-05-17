/*
 * Lab7.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab7".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Mar 13 12:37:27 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lab7_h_
#define RTW_HEADER_Lab7_h_
#include <math.h>
#include <string.h>
#ifndef Lab7_COMMON_INCLUDES_
# define Lab7_COMMON_INCLUDES_
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
#endif                                 /* Lab7_COMMON_INCLUDES_ */

#include "Lab7_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T SFunction2;                   /* '<S11>/S-Function2' */
  real_T ang_velocity;                 /* '<S4>/velocity' */
  real_T rpm;                          /* '<S4>/rev' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T ProportionalGain;             /* '<S2>/Proportional Gain' */
  real_T Integrator;                   /* '<S2>/Integrator' */
  real_T DerivativeGain;               /* '<S2>/Derivative Gain' */
  real_T Filter;                       /* '<S2>/Filter' */
  real_T SumD;                         /* '<S2>/SumD' */
  real_T FilterCoefficient;            /* '<S2>/Filter Coefficient' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T Saturate;                     /* '<S2>/Saturate' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Fcn;                          /* '<S5>/Fcn' */
  real_T Subtract;                     /* '<S5>/Subtract' */
  real_T ZeroGain;                     /* '<S7>/ZeroGain' */
  real_T DeadZone;                     /* '<S7>/DeadZone' */
  real_T SignDeltaU;                   /* '<S7>/SignDeltaU' */
  real_T IntegralGain;                 /* '<S2>/Integral Gain' */
  real_T SignPreIntegrator;            /* '<S7>/SignPreIntegrator' */
  real_T Switch;                       /* '<S2>/Switch' */
  real_T SFunction1;                   /* '<S11>/S-Function1' */
  real_T theta;                        /* '<S4>/displacement' */
  int8_T DataTypeConv1;                /* '<S7>/DataTypeConv1' */
  int8_T DataTypeConv2;                /* '<S7>/DataTypeConv2' */
  boolean_T NotEqual;                  /* '<S7>/NotEqual' */
  boolean_T Equal;                     /* '<S7>/Equal' */
  boolean_T AND;                       /* '<S7>/AND' */
} B_Lab7_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;/* '<S4>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1;/* '<S4>/Moving Average' */
  dsp_MovingAverage_Lab7_T obj;        /* '<S4>/Moving Average' */
  real_T Integrator_DSTATE;            /* '<S2>/Integrator' */
  real_T Filter_DSTATE;                /* '<S2>/Filter' */
  int_T SFunction1_IWORK;              /* '<S13>/S-Function1' */
  boolean_T objisempty;                /* '<S4>/Moving Average' */
} DW_Lab7_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T avg_rpm;                      /* '<Root>/avg_rpm ' */
  real_T ref_out;                      /* '<Root>/ref_out' */
} ExtY_Lab7_T;

/* Parameters (auto storage) */
struct P_Lab7_T_ {
  real_T DiscretePIDController1_D;     /* Mask Parameter: DiscretePIDController1_D
                                        * Referenced by: '<S2>/Derivative Gain'
                                        */
  real_T DiscretePIDController1_I;     /* Mask Parameter: DiscretePIDController1_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  real_T DiscretePIDController1_LowerSat;/* Mask Parameter: DiscretePIDController1_LowerSat
                                          * Referenced by:
                                          *   '<S2>/Saturate'
                                          *   '<S7>/DeadZone'
                                          */
  real_T DiscretePIDController1_N;     /* Mask Parameter: DiscretePIDController1_N
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  real_T DiscretePIDController1_P;     /* Mask Parameter: DiscretePIDController1_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  real_T DiscretePIDController1_UpperSat;/* Mask Parameter: DiscretePIDController1_UpperSat
                                          * Referenced by:
                                          *   '<S2>/Saturate'
                                          *   '<S7>/DeadZone'
                                          */
  real_T velocity_Gain;                /* Expression: 2*pi/1000 *(1/0.0001)
                                        * Referenced by: '<S4>/velocity'
                                        */
  real_T rev_Gain;                     /* Expression: 30/pi
                                        * Referenced by: '<S4>/rev'
                                        */
  real_T input3_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/input3'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S2>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S2>/Filter'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/42
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S7>/ZeroGain'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T displacement_Gain;            /* Expression: 2*pi/1000
                                        * Referenced by: '<S4>/displacement'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Lab7_T {
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
extern P_Lab7_T Lab7_P;

/* Block signals (auto storage) */
extern B_Lab7_T Lab7_B;

/* Block states (auto storage) */
extern DW_Lab7_T Lab7_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Lab7_T Lab7_Y;

/* Model entry point functions */
extern void Lab7_initialize(void);
extern void Lab7_output(void);
extern void Lab7_update(void);
extern void Lab7_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lab7_T *const Lab7_M;

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
 * '<Root>' : 'Lab7'
 * '<S1>'   : 'Lab7/Discrete PID Controller'
 * '<S2>'   : 'Lab7/Discrete PID Controller1'
 * '<S3>'   : 'Lab7/RTI Data'
 * '<S4>'   : 'Lab7/Subsystem'
 * '<S5>'   : 'Lab7/Subsystem1'
 * '<S6>'   : 'Lab7/Discrete PID Controller/Clamping circuit'
 * '<S7>'   : 'Lab7/Discrete PID Controller1/Clamping circuit'
 * '<S8>'   : 'Lab7/RTI Data/RTI Data Store'
 * '<S9>'   : 'Lab7/RTI Data/RTI Data Store/RTI Data Store'
 * '<S10>'  : 'Lab7/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S11>'  : 'Lab7/Subsystem/DS1104ENC_POS_C1'
 * '<S12>'  : 'Lab7/Subsystem/DS1104ENC_SETUP'
 * '<S13>'  : 'Lab7/Subsystem1/DS1104SL_DSP_PWM3'
 */
#endif                                 /* RTW_HEADER_Lab7_h_ */
