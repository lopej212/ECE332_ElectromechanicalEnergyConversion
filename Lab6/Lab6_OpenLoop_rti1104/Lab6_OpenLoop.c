/*
 * Lab6_OpenLoop.c
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

#include "Lab6_OpenLoop_trc_ptr.h"
#include "Lab6_OpenLoop.h"
#include "Lab6_OpenLoop_private.h"

/* Block signals (auto storage) */
B_Lab6_OpenLoop_T Lab6_OpenLoop_B;

/* Continuous states */
X_Lab6_OpenLoop_T Lab6_OpenLoop_X;

/* Block states (auto storage) */
DW_Lab6_OpenLoop_T Lab6_OpenLoop_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Lab6_OpenLoop_T Lab6_OpenLoop_Y;

/* Real-time model */
RT_MODEL_Lab6_OpenLoop_T Lab6_OpenLoop_M_;
RT_MODEL_Lab6_OpenLoop_T *const Lab6_OpenLoop_M = &Lab6_OpenLoop_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Lab6_OpenLoop_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S4>/MATLAB Function'
 *    '<S4>/MATLAB Function1'
 *    '<S4>/MATLAB Function2'
 */
void Lab6_OpenLoop_MATLABFunction(real_T rtu_u, B_MATLABFunction_Lab6_OpenLoo_T *
  localB)
{
  real_T u;

  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:3' */
  u = rtu_u + 0.5;
  if (rtu_u + 0.5 >= 1.0) {
    /* '<S11>:1:4' */
    /* '<S11>:1:5' */
    u = 0.999;
  } else if (rtu_u + 0.5 <= 0.0) {
    /* '<S11>:1:6' */
    /* '<S11>:1:7' */
    u = 0.001;
  } else {
    /* '<S11>:1:9' */
  }

  /* '<S11>:1:11' */
  localB->y = u;
}

/* Model output function */
void Lab6_OpenLoop_output(void)
{
  real_T u0;
  dsp_MovingAverage_Lab6_OpenLo_T *obj;
  dsp_MovingAverage_Lab6_OpenLo_T *obj_0;
  dsp_private_SlidingWindowAver_T *obj_1;
  dsp_private_SlidingWindowAver_T *obj_2;
  dsp_private_SlidingWindowAver_T *obj_3;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[31];
  real_T z;
  int32_T i;
  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    /* set solver stop time */
    if (!(Lab6_OpenLoop_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Lab6_OpenLoop_M->solverInfo,
                            ((Lab6_OpenLoop_M->Timing.clockTickH0 + 1) *
        Lab6_OpenLoop_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Lab6_OpenLoop_M->solverInfo,
                            ((Lab6_OpenLoop_M->Timing.clockTick0 + 1) *
        Lab6_OpenLoop_M->Timing.stepSize0 + Lab6_OpenLoop_M->Timing.clockTickH0 *
        Lab6_OpenLoop_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab6_OpenLoop_M)) {
    Lab6_OpenLoop_M->Timing.t[0] = rtsiGetT(&Lab6_OpenLoop_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    /* S-Function (rti_commonblock): '<S8>/S-Function2' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S3>/velocity' */
    Lab6_OpenLoop_B.ang_velocity = Lab6_OpenLoop_P.velocity_Gain *
      Lab6_OpenLoop_B.SFunction2;

    /* Gain: '<S3>/rev' */
    Lab6_OpenLoop_B.rpm = Lab6_OpenLoop_P.rev_Gain *
      Lab6_OpenLoop_B.ang_velocity;

    /* MATLABSystem: '<S3>/Moving Average' */
    u0 = Lab6_OpenLoop_B.rpm;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    obj = &Lab6_OpenLoop_DW.obj;
    obj_0 = obj;
    if (obj_0->TunablePropsChanged) {
      obj_0->TunablePropsChanged = false;
    }

    obj_1 = obj->pStatistic;
    if (obj_1->isInitialized != 1) {
      obj_2 = obj_1;
      obj_3 = obj_2;
      obj_3->isInitialized = 1;
      obj_3->pCumSum = 0.0;
      for (i = 0; i < 31; i++) {
        obj_3->pCumSumRev[i] = 0.0;
      }

      obj_3->pCumRevIndex = 1.0;
      obj_2->pCumSum = 0.0;
      for (i = 0; i < 31; i++) {
        obj_2->pCumSumRev[i] = 0.0;
      }

      obj_2->pCumRevIndex = 1.0;
    }

    cumRevIndex = obj_1->pCumRevIndex;
    csum = obj_1->pCumSum;
    for (i = 0; i < 31; i++) {
      csumrev[i] = obj_1->pCumSumRev[i];
    }

    csum += u0;
    z = csumrev[(int32_T)cumRevIndex - 1] + csum;
    csumrev[(int32_T)cumRevIndex - 1] = u0;
    if (cumRevIndex != 31.0) {
      cumRevIndex++;
    } else {
      cumRevIndex = 1.0;
      csum = 0.0;
      for (i = 0; i < 30; i++) {
        csumrev[29 - i] += csumrev[30 - i];
      }
    }

    /* MATLABSystem: '<S3>/Moving Average' */
    z /= 32.0;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    obj_1->pCumSum = csum;
    for (i = 0; i < 31; i++) {
      obj_1->pCumSumRev[i] = csumrev[i];
    }

    obj_1->pCumRevIndex = cumRevIndex;

    /* Outport: '<Root>/Wrpm' incorporates:
     *  MATLABSystem: '<S3>/Moving Average'
     */
    Lab6_OpenLoop_Y.Wrpm = z;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Cool_Name'
     *  Outport: '<Root>/Wrpm'
     */
    Lab6_OpenLoop_B.Sum = Lab6_OpenLoop_P.Cool_Name_Value - Lab6_OpenLoop_Y.Wrpm;

    /* Gain: '<S1>/Proportional Gain' */
    Lab6_OpenLoop_B.ProportionalGain = Lab6_OpenLoop_P.DiscretePIDController_P *
      Lab6_OpenLoop_B.Sum;

    /* DiscreteIntegrator: '<S1>/Integrator' */
    Lab6_OpenLoop_B.Integrator = Lab6_OpenLoop_DW.Integrator_DSTATE;

    /* Gain: '<S1>/Derivative Gain' */
    Lab6_OpenLoop_B.DerivativeGain = Lab6_OpenLoop_P.DiscretePIDController_D *
      Lab6_OpenLoop_B.Sum;

    /* DiscreteIntegrator: '<S1>/Filter' */
    Lab6_OpenLoop_B.Filter = Lab6_OpenLoop_DW.Filter_DSTATE;

    /* Sum: '<S1>/SumD' */
    Lab6_OpenLoop_B.SumD = Lab6_OpenLoop_B.DerivativeGain -
      Lab6_OpenLoop_B.Filter;

    /* Gain: '<S1>/Filter Coefficient' */
    Lab6_OpenLoop_B.FilterCoefficient = Lab6_OpenLoop_P.DiscretePIDController_N *
      Lab6_OpenLoop_B.SumD;

    /* Outport: '<Root>/Freq_In' incorporates:
     *  Sum: '<S1>/Sum'
     */
    Lab6_OpenLoop_Y.Freq_In = (Lab6_OpenLoop_B.ProportionalGain +
      Lab6_OpenLoop_B.Integrator) + Lab6_OpenLoop_B.FilterCoefficient;

    /* Gain: '<Root>/Gain' incorporates:
     *  Outport: '<Root>/Freq_In'
     */
    Lab6_OpenLoop_B.Gain = Lab6_OpenLoop_P.Gain_Gain * Lab6_OpenLoop_Y.Freq_In;

    /* Gain: '<Root>/Gain1' */
    Lab6_OpenLoop_B.Gain1 = Lab6_OpenLoop_P.Gain1_Gain * Lab6_OpenLoop_B.Gain;
  }

  /* Integrator: '<S4>/Integrator' */
  Lab6_OpenLoop_B.Integrator_d = Lab6_OpenLoop_X.Integrator_CSTATE;

  /* Sin: '<S4>/Sine Wave' */
  Lab6_OpenLoop_B.SineWave = sin(Lab6_OpenLoop_P.SineWave_Freq *
    Lab6_OpenLoop_B.Integrator_d + Lab6_OpenLoop_P.SineWave_Phase) *
    Lab6_OpenLoop_P.SineWave_Amp + Lab6_OpenLoop_P.SineWave_Bias;

  /* Product: '<S4>/Product' */
  Lab6_OpenLoop_B.Product = Lab6_OpenLoop_B.SineWave * Lab6_OpenLoop_B.Gain1;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  Lab6_OpenLoop_MATLABFunction(Lab6_OpenLoop_B.Product,
    &Lab6_OpenLoop_B.sf_MATLABFunction);

  /* Sin: '<S4>/Sine Wave1' */
  Lab6_OpenLoop_B.SineWave1 = sin(Lab6_OpenLoop_P.SineWave1_Freq *
    Lab6_OpenLoop_B.Integrator_d + Lab6_OpenLoop_P.SineWave1_Phase) *
    Lab6_OpenLoop_P.SineWave1_Amp + Lab6_OpenLoop_P.SineWave1_Bias;

  /* Product: '<S4>/Product1' */
  Lab6_OpenLoop_B.Product1 = Lab6_OpenLoop_B.SineWave1 * Lab6_OpenLoop_B.Gain1;

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  Lab6_OpenLoop_MATLABFunction(Lab6_OpenLoop_B.Product1,
    &Lab6_OpenLoop_B.sf_MATLABFunction1);

  /* Sin: '<S4>/Sine Wave2' */
  Lab6_OpenLoop_B.SineWave2 = sin(Lab6_OpenLoop_P.SineWave2_Freq *
    Lab6_OpenLoop_B.Integrator_d + Lab6_OpenLoop_P.SineWave2_Phase) *
    Lab6_OpenLoop_P.SineWave2_Amp + Lab6_OpenLoop_P.SineWave2_Bias;

  /* Product: '<S4>/Product2' */
  Lab6_OpenLoop_B.Product2 = Lab6_OpenLoop_B.SineWave2 * Lab6_OpenLoop_B.Gain1;

  /* MATLAB Function: '<S4>/MATLAB Function2' */
  Lab6_OpenLoop_MATLABFunction(Lab6_OpenLoop_B.Product2,
    &Lab6_OpenLoop_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    /* S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    Lab6_OpenLoop_DW.SFunction1_IWORK = Lab6_OpenLoop_P.Constant_Value;

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0],
      Lab6_OpenLoop_B.sf_MATLABFunction.y, Lab6_OpenLoop_B.sf_MATLABFunction1.y,
      Lab6_OpenLoop_B.sf_MATLABFunction2.y);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (Lab6_OpenLoop_DW.SFunction1_IWORK == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwm3StopFlag == 1)||(slaveDSPPwm3StopFlag == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwm3StopFlag = 0;
        ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
      }
    } else if (Lab6_OpenLoop_DW.SFunction1_IWORK == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation */
      if ((slaveDSPPwm3StopFlag == 0)||(slaveDSPPwm3StopFlag == 2)) {
        slaveDSPPwm3StopFlag = 1;
        ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW);
      }
    }

    /* Gain: '<S1>/Integral Gain' */
    Lab6_OpenLoop_B.IntegralGain = Lab6_OpenLoop_P.DiscretePIDController_I *
      Lab6_OpenLoop_B.Sum;

    /* S-Function (rti_commonblock): '<S8>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S3>/displacement' */
    Lab6_OpenLoop_B.theta = Lab6_OpenLoop_P.displacement_Gain *
      Lab6_OpenLoop_B.SFunction1;

    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S9>/S-Function2' */
    /* This comment workarounds a code generation problem */
  }
}

/* Model update function */
void Lab6_OpenLoop_update(void)
{
  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    /* Update for DiscreteIntegrator: '<S1>/Integrator' */
    Lab6_OpenLoop_DW.Integrator_DSTATE += Lab6_OpenLoop_P.Integrator_gainval *
      Lab6_OpenLoop_B.IntegralGain;

    /* Update for DiscreteIntegrator: '<S1>/Filter' */
    Lab6_OpenLoop_DW.Filter_DSTATE += Lab6_OpenLoop_P.Filter_gainval *
      Lab6_OpenLoop_B.FilterCoefficient;
  }

  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    rt_ertODEUpdateContinuousStates(&Lab6_OpenLoop_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab6_OpenLoop_M->Timing.clockTick0)) {
    ++Lab6_OpenLoop_M->Timing.clockTickH0;
  }

  Lab6_OpenLoop_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Lab6_OpenLoop_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Lab6_OpenLoop_M->Timing.clockTick1++;
    if (!Lab6_OpenLoop_M->Timing.clockTick1) {
      Lab6_OpenLoop_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void Lab6_OpenLoop_derivatives(void)
{
  XDot_Lab6_OpenLoop_T *_rtXdot;
  _rtXdot = ((XDot_Lab6_OpenLoop_T *) Lab6_OpenLoop_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' incorporates:
   *  Outport: '<Root>/Freq_In'
   */
  _rtXdot->Integrator_CSTATE = Lab6_OpenLoop_Y.Freq_In;
}

/* Model initialize function */
void Lab6_OpenLoop_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Lab6_OpenLoop_M, 0,
                sizeof(RT_MODEL_Lab6_OpenLoop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab6_OpenLoop_M->solverInfo,
                          &Lab6_OpenLoop_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab6_OpenLoop_M->solverInfo, &rtmGetTPtr(Lab6_OpenLoop_M));
    rtsiSetStepSizePtr(&Lab6_OpenLoop_M->solverInfo,
                       &Lab6_OpenLoop_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab6_OpenLoop_M->solverInfo, &Lab6_OpenLoop_M->derivs);
    rtsiSetContStatesPtr(&Lab6_OpenLoop_M->solverInfo, (real_T **)
                         &Lab6_OpenLoop_M->contStates);
    rtsiSetNumContStatesPtr(&Lab6_OpenLoop_M->solverInfo,
      &Lab6_OpenLoop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Lab6_OpenLoop_M->solverInfo,
      &Lab6_OpenLoop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Lab6_OpenLoop_M->solverInfo,
      &Lab6_OpenLoop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Lab6_OpenLoop_M->solverInfo,
      &Lab6_OpenLoop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Lab6_OpenLoop_M->solverInfo, (&rtmGetErrorStatus
      (Lab6_OpenLoop_M)));
    rtsiSetRTModelPtr(&Lab6_OpenLoop_M->solverInfo, Lab6_OpenLoop_M);
  }

  rtsiSetSimTimeStep(&Lab6_OpenLoop_M->solverInfo, MAJOR_TIME_STEP);
  Lab6_OpenLoop_M->intgData.f[0] = Lab6_OpenLoop_M->odeF[0];
  Lab6_OpenLoop_M->contStates = ((X_Lab6_OpenLoop_T *) &Lab6_OpenLoop_X);
  rtsiSetSolverData(&Lab6_OpenLoop_M->solverInfo, (void *)
                    &Lab6_OpenLoop_M->intgData);
  rtsiSetSolverName(&Lab6_OpenLoop_M->solverInfo,"ode1");
  rtmSetTPtr(Lab6_OpenLoop_M, &Lab6_OpenLoop_M->Timing.tArray[0]);
  Lab6_OpenLoop_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &Lab6_OpenLoop_B), 0,
                sizeof(B_Lab6_OpenLoop_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Lab6_OpenLoop_X, 0,
                  sizeof(X_Lab6_OpenLoop_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Lab6_OpenLoop_DW, 0,
                sizeof(DW_Lab6_OpenLoop_T));

  /* external outputs */
  (void) memset((void *)&Lab6_OpenLoop_Y, 0,
                sizeof(ExtY_Lab6_OpenLoop_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Lab6_OpenLoop_rti_init_trc_pointers();
  }

  {
    dsp_MovingAverage_Lab6_OpenLo_T *b_obj;
    dsp_private_SlidingWindowAver_T *iobj_0;
    dsp_MovingAverage_Lab6_OpenLo_T *obj;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    b_obj = &Lab6_OpenLoop_DW.obj;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    Lab6_OpenLoop_DW.objisempty = true;
    b_obj = &Lab6_OpenLoop_DW.obj;
    iobj_0 = &Lab6_OpenLoop_DW.gobj_0;
    b_obj->isInitialized = 1;
    obj = b_obj;
    obj->NumChannels = 1;
    iobj_0->isInitialized = 0;
    obj->pStatistic = iobj_0;
    b_obj->TunablePropsChanged = false;

    /* Start for S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
     *  Constant: '<S4>/Constant'
     */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    Lab6_OpenLoop_DW.SFunction1_IWORK = 0;
  }

  {
    dsp_MovingAverage_Lab6_OpenLo_T *obj;
    dsp_private_SlidingWindowAver_T *obj_0;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Integrator' */
    Lab6_OpenLoop_DW.Integrator_DSTATE = Lab6_OpenLoop_P.Integrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Filter' */
    Lab6_OpenLoop_DW.Filter_DSTATE = Lab6_OpenLoop_P.Filter_IC;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    Lab6_OpenLoop_X.Integrator_CSTATE = Lab6_OpenLoop_P.Integrator_IC_c;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    obj = &Lab6_OpenLoop_DW.obj;
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 31; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of Start for MATLABSystem: '<S3>/Moving Average' */
  }
}

/* Model terminate function */
void Lab6_OpenLoop_terminate(void)
{
  boolean_T flag;
  dsp_MovingAverage_Lab6_OpenLo_T *obj;
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Start for MATLABSystem: '<S3>/Moving Average' */
  obj = &Lab6_OpenLoop_DW.obj;
  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &Lab6_OpenLoop_DW.obj;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      obj_0 = obj->pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      obj->NumChannels = -1;
    }
  }

  /* End of Start for MATLABSystem: '<S3>/Moving Average' */

  /* Terminate for S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
   *  Constant: '<S4>/Constant'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
    SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW,
    SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], 0.5, 0.5, 0.5);

  /* flag = UNDEF */
  slaveDSPPwm3StopFlag = 2;
}
