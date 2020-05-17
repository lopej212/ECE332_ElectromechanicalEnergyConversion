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
 * C source code generated on : Fri Mar  6 12:55:20 2020
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
 *    '<S2>/MATLAB Function'
 *    '<S2>/MATLAB Function1'
 *    '<S2>/MATLAB Function2'
 */
void Lab6_OpenLoop_MATLABFunction(real_T rtu_u, B_MATLABFunction_Lab6_OpenLoo_T *
  localB)
{
  real_T u;

  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:3' */
  u = rtu_u + 0.5;
  if (rtu_u + 0.5 >= 1.0) {
    /* '<S7>:1:4' */
    /* '<S7>:1:5' */
    u = 0.999;
  } else if (rtu_u + 0.5 <= 0.0) {
    /* '<S7>:1:6' */
    /* '<S7>:1:7' */
    u = 0.001;
  } else {
    /* '<S7>:1:9' */
  }

  /* '<S7>:1:11' */
  localB->y = u;
}

/* Model output function */
void Lab6_OpenLoop_output(void)
{
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

  /* Integrator: '<S2>/Integrator' */
  Lab6_OpenLoop_B.Integrator = Lab6_OpenLoop_X.Integrator_CSTATE;

  /* Sin: '<S2>/Sine Wave' */
  Lab6_OpenLoop_B.SineWave = sin(Lab6_OpenLoop_P.SineWave_Freq *
    Lab6_OpenLoop_B.Integrator + Lab6_OpenLoop_P.SineWave_Phase) *
    Lab6_OpenLoop_P.SineWave_Amp + Lab6_OpenLoop_P.SineWave_Bias;
  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    /* Constant: '<Root>/Input' */
    Lab6_OpenLoop_B.Input = Lab6_OpenLoop_P.Input_Value;

    /* Gain: '<Root>/Gain' */
    Lab6_OpenLoop_B.Gain = Lab6_OpenLoop_P.Gain_Gain * Lab6_OpenLoop_B.Input;

    /* Gain: '<Root>/Gain1' */
    Lab6_OpenLoop_B.Gain1 = Lab6_OpenLoop_P.Gain1_Gain * Lab6_OpenLoop_B.Gain;
  }

  /* Product: '<S2>/Product' */
  Lab6_OpenLoop_B.Product = Lab6_OpenLoop_B.SineWave * Lab6_OpenLoop_B.Gain1;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  Lab6_OpenLoop_MATLABFunction(Lab6_OpenLoop_B.Product,
    &Lab6_OpenLoop_B.sf_MATLABFunction);

  /* Sin: '<S2>/Sine Wave1' */
  Lab6_OpenLoop_B.SineWave1 = sin(Lab6_OpenLoop_P.SineWave1_Freq *
    Lab6_OpenLoop_B.Integrator + Lab6_OpenLoop_P.SineWave1_Phase) *
    Lab6_OpenLoop_P.SineWave1_Amp + Lab6_OpenLoop_P.SineWave1_Bias;

  /* Product: '<S2>/Product1' */
  Lab6_OpenLoop_B.Product1 = Lab6_OpenLoop_B.SineWave1 * Lab6_OpenLoop_B.Gain1;

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  Lab6_OpenLoop_MATLABFunction(Lab6_OpenLoop_B.Product1,
    &Lab6_OpenLoop_B.sf_MATLABFunction1);

  /* Sin: '<S2>/Sine Wave2' */
  Lab6_OpenLoop_B.SineWave2 = sin(Lab6_OpenLoop_P.SineWave2_Freq *
    Lab6_OpenLoop_B.Integrator + Lab6_OpenLoop_P.SineWave2_Phase) *
    Lab6_OpenLoop_P.SineWave2_Amp + Lab6_OpenLoop_P.SineWave2_Bias;

  /* Product: '<S2>/Product2' */
  Lab6_OpenLoop_B.Product2 = Lab6_OpenLoop_B.SineWave2 * Lab6_OpenLoop_B.Gain1;

  /* MATLAB Function: '<S2>/MATLAB Function2' */
  Lab6_OpenLoop_MATLABFunction(Lab6_OpenLoop_B.Product2,
    &Lab6_OpenLoop_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(Lab6_OpenLoop_M)) {
    /* S-Function (rti_commonblock): '<S6>/S-Function1' incorporates:
     *  Constant: '<S2>/Constant'
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
  }
}

/* Model update function */
void Lab6_OpenLoop_update(void)
{
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
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
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

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = Lab6_OpenLoop_B.Input;
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
  Lab6_OpenLoop_M->Timing.stepSize0 = 0.001;

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

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Lab6_OpenLoop_rti_init_trc_pointers();
  }

  /* Start for S-Function (rti_commonblock): '<S6>/S-Function1' incorporates:
   *  Constant: '<S2>/Constant'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  Lab6_OpenLoop_DW.SFunction1_IWORK = 0;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Lab6_OpenLoop_X.Integrator_CSTATE = Lab6_OpenLoop_P.Integrator_IC;
}

/* Model terminate function */
void Lab6_OpenLoop_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S6>/S-Function1' incorporates:
   *  Constant: '<S2>/Constant'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
    SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW,
    SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], 0.5, 0.5, 0.5);

  /* flag = UNDEF */
  slaveDSPPwm3StopFlag = 2;
}
