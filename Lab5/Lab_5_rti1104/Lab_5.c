/*
 * Lab_5.c
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

#include "Lab_5_trc_ptr.h"
#include "Lab_5.h"
#include "Lab_5_private.h"

/* Block signals (auto storage) */
B_Lab_5_T Lab_5_B;

/* Continuous states */
X_Lab_5_T Lab_5_X;

/* Block states (auto storage) */
DW_Lab_5_T Lab_5_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Lab_5_T Lab_5_Y;

/* Real-time model */
RT_MODEL_Lab_5_T Lab_5_M_;
RT_MODEL_Lab_5_T *const Lab_5_M = &Lab_5_M_;

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
  Lab_5_derivatives();
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
void Lab_5_MATLABFunction(real_T rtu_u, B_MATLABFunction_Lab_5_T *localB)
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
void Lab_5_output(void)
{
  real_T u0;
  dsp_MovingAverage_Lab_5_T *obj;
  dsp_MovingAverage_Lab_5_T *obj_0;
  dsp_private_SlidingWindowAver_T *obj_1;
  dsp_private_SlidingWindowAver_T *obj_2;
  dsp_private_SlidingWindowAver_T *obj_3;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[31];
  real_T z;
  int32_T i;
  if (rtmIsMajorTimeStep(Lab_5_M)) {
    /* set solver stop time */
    if (!(Lab_5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Lab_5_M->solverInfo, ((Lab_5_M->Timing.clockTickH0
        + 1) * Lab_5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Lab_5_M->solverInfo, ((Lab_5_M->Timing.clockTick0 +
        1) * Lab_5_M->Timing.stepSize0 + Lab_5_M->Timing.clockTickH0 *
        Lab_5_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab_5_M)) {
    Lab_5_M->Timing.t[0] = rtsiGetT(&Lab_5_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab_5_M)) {
    /* S-Function (rti_commonblock): '<S8>/S-Function2' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S3>/velocity' */
    Lab_5_B.ang_velocity = Lab_5_P.velocity_Gain * Lab_5_B.SFunction2;

    /* Gain: '<S3>/rev' */
    Lab_5_B.rpm = Lab_5_P.rev_Gain * Lab_5_B.ang_velocity;

    /* MATLABSystem: '<S3>/Moving Average' */
    u0 = Lab_5_B.rpm;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    obj = &Lab_5_DW.obj;
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

    /* Outport: '<Root>/Out1' incorporates:
     *  MATLABSystem: '<S3>/Moving Average'
     */
    Lab_5_Y.Out1 = z;

    /* Outport: '<Root>/Wref_out' incorporates:
     *  Constant: '<Root>/Wref'
     */
    Lab_5_Y.Wref_out = Lab_5_P.Wref_Value;

    /* Delay: '<Root>/Delay' */
    Lab_5_B.Delay = Lab_5_DW.Delay_DSTATE;

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Wref'
     *  Outport: '<Root>/Out1'
     */
    /* MATLAB Function 'MATLAB Function': '<S1>:1' */
    /* '<S1>:1:3' */
    cumRevIndex = (Lab_5_P.Wref_Value - Lab_5_Y.Out1) + 17.5;
    if (cumRevIndex > 1.0) {
      /* '<S1>:1:4' */
      if (cumRevIndex > 50.0) {
        /* '<S1>:1:5' */
        /* '<S1>:1:6' */
        Lab_5_B.u = Lab_5_B.Delay + 0.01;
      } else {
        /* '<S1>:1:8' */
        Lab_5_B.u = Lab_5_B.Delay + 0.0001;
      }
    } else if (cumRevIndex < 1.0) {
      /* '<S1>:1:10' */
      /* '<S1>:1:11' */
      /* '<S1>:1:12' */
      Lab_5_B.u = Lab_5_B.Delay - 0.01;
    } else {
      /* '<S1>:1:17' */
      Lab_5_B.u = Lab_5_B.Delay;
    }

    if (Lab_5_B.u >= 128.0) {
      /* '<S1>:1:20' */
      /* '<S1>:1:21' */
      Lab_5_B.u = 127.0;
    } else {
      if (Lab_5_B.u <= 0.0) {
        /* '<S1>:1:22' */
        /* '<S1>:1:23' */
        Lab_5_B.u = 1.0;
      }
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* Gain: '<Root>/Gain' */
    Lab_5_B.Gain = Lab_5_P.Gain_Gain * Lab_5_B.u;

    /* Gain: '<Root>/Gain1' */
    Lab_5_B.Gain1 = Lab_5_P.Gain1_Gain * Lab_5_B.Gain;
  }

  /* Integrator: '<S4>/Integrator' */
  Lab_5_B.Integrator = Lab_5_X.Integrator_CSTATE;

  /* Sin: '<S4>/Sine Wave' */
  Lab_5_B.SineWave = sin(Lab_5_P.SineWave_Freq * Lab_5_B.Integrator +
    Lab_5_P.SineWave_Phase) * Lab_5_P.SineWave_Amp + Lab_5_P.SineWave_Bias;

  /* Product: '<S4>/Product' */
  Lab_5_B.Product = Lab_5_B.SineWave * Lab_5_B.Gain1;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  Lab_5_MATLABFunction(Lab_5_B.Product, &Lab_5_B.sf_MATLABFunction_j);

  /* Sin: '<S4>/Sine Wave1' */
  Lab_5_B.SineWave1 = sin(Lab_5_P.SineWave1_Freq * Lab_5_B.Integrator +
    Lab_5_P.SineWave1_Phase) * Lab_5_P.SineWave1_Amp + Lab_5_P.SineWave1_Bias;

  /* Product: '<S4>/Product1' */
  Lab_5_B.Product1 = Lab_5_B.SineWave1 * Lab_5_B.Gain1;

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  Lab_5_MATLABFunction(Lab_5_B.Product1, &Lab_5_B.sf_MATLABFunction1);

  /* Sin: '<S4>/Sine Wave2' */
  Lab_5_B.SineWave2 = sin(Lab_5_P.SineWave2_Freq * Lab_5_B.Integrator +
    Lab_5_P.SineWave2_Phase) * Lab_5_P.SineWave2_Amp + Lab_5_P.SineWave2_Bias;

  /* Product: '<S4>/Product2' */
  Lab_5_B.Product2 = Lab_5_B.SineWave2 * Lab_5_B.Gain1;

  /* MATLAB Function: '<S4>/MATLAB Function2' */
  Lab_5_MATLABFunction(Lab_5_B.Product2, &Lab_5_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(Lab_5_M)) {
    /* S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    Lab_5_DW.SFunction1_IWORK = Lab_5_P.Constant_Value;

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0],
      Lab_5_B.sf_MATLABFunction_j.y, Lab_5_B.sf_MATLABFunction1.y,
      Lab_5_B.sf_MATLABFunction2.y);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (Lab_5_DW.SFunction1_IWORK == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwm3StopFlag == 1)||(slaveDSPPwm3StopFlag == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwm3StopFlag = 0;
        ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
      }
    } else if (Lab_5_DW.SFunction1_IWORK == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation */
      if ((slaveDSPPwm3StopFlag == 0)||(slaveDSPPwm3StopFlag == 2)) {
        slaveDSPPwm3StopFlag = 1;
        ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW);
      }
    }

    /* S-Function (rti_commonblock): '<S8>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S3>/displacement' */
    Lab_5_B.theta = Lab_5_P.displacement_Gain * Lab_5_B.SFunction1;

    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S9>/S-Function2' */
    /* This comment workarounds a code generation problem */
  }
}

/* Model update function */
void Lab_5_update(void)
{
  if (rtmIsMajorTimeStep(Lab_5_M)) {
    /* Update for Delay: '<Root>/Delay' */
    Lab_5_DW.Delay_DSTATE = Lab_5_B.u;
  }

  if (rtmIsMajorTimeStep(Lab_5_M)) {
    rt_ertODEUpdateContinuousStates(&Lab_5_M->solverInfo);
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
  if (!(++Lab_5_M->Timing.clockTick0)) {
    ++Lab_5_M->Timing.clockTickH0;
  }

  Lab_5_M->Timing.t[0] = rtsiGetSolverStopTime(&Lab_5_M->solverInfo);

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
    Lab_5_M->Timing.clockTick1++;
    if (!Lab_5_M->Timing.clockTick1) {
      Lab_5_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void Lab_5_derivatives(void)
{
  XDot_Lab_5_T *_rtXdot;
  _rtXdot = ((XDot_Lab_5_T *) Lab_5_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = Lab_5_B.u;
}

/* Model initialize function */
void Lab_5_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Lab_5_M, 0,
                sizeof(RT_MODEL_Lab_5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab_5_M->solverInfo, &Lab_5_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab_5_M->solverInfo, &rtmGetTPtr(Lab_5_M));
    rtsiSetStepSizePtr(&Lab_5_M->solverInfo, &Lab_5_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab_5_M->solverInfo, &Lab_5_M->derivs);
    rtsiSetContStatesPtr(&Lab_5_M->solverInfo, (real_T **) &Lab_5_M->contStates);
    rtsiSetNumContStatesPtr(&Lab_5_M->solverInfo, &Lab_5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Lab_5_M->solverInfo,
      &Lab_5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Lab_5_M->solverInfo,
      &Lab_5_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Lab_5_M->solverInfo,
      &Lab_5_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Lab_5_M->solverInfo, (&rtmGetErrorStatus(Lab_5_M)));
    rtsiSetRTModelPtr(&Lab_5_M->solverInfo, Lab_5_M);
  }

  rtsiSetSimTimeStep(&Lab_5_M->solverInfo, MAJOR_TIME_STEP);
  Lab_5_M->intgData.f[0] = Lab_5_M->odeF[0];
  Lab_5_M->contStates = ((X_Lab_5_T *) &Lab_5_X);
  rtsiSetSolverData(&Lab_5_M->solverInfo, (void *)&Lab_5_M->intgData);
  rtsiSetSolverName(&Lab_5_M->solverInfo,"ode1");
  rtmSetTPtr(Lab_5_M, &Lab_5_M->Timing.tArray[0]);
  Lab_5_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &Lab_5_B), 0,
                sizeof(B_Lab_5_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Lab_5_X, 0,
                  sizeof(X_Lab_5_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Lab_5_DW, 0,
                sizeof(DW_Lab_5_T));

  /* external outputs */
  (void) memset((void *)&Lab_5_Y, 0,
                sizeof(ExtY_Lab_5_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Lab_5_rti_init_trc_pointers();
  }

  {
    dsp_MovingAverage_Lab_5_T *b_obj;
    dsp_private_SlidingWindowAver_T *iobj_0;
    dsp_MovingAverage_Lab_5_T *obj;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    b_obj = &Lab_5_DW.obj;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    Lab_5_DW.objisempty = true;
    b_obj = &Lab_5_DW.obj;
    iobj_0 = &Lab_5_DW.gobj_0;
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
    Lab_5_DW.SFunction1_IWORK = 0;
  }

  {
    dsp_MovingAverage_Lab_5_T *obj;
    dsp_private_SlidingWindowAver_T *obj_0;
    int32_T i;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    Lab_5_X.Integrator_CSTATE = Lab_5_P.Integrator_IC;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    Lab_5_DW.Delay_DSTATE = Lab_5_P.Delay_InitialCondition;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    obj = &Lab_5_DW.obj;
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
void Lab_5_terminate(void)
{
  boolean_T flag;
  dsp_MovingAverage_Lab_5_T *obj;
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Start for MATLABSystem: '<S3>/Moving Average' */
  obj = &Lab_5_DW.obj;
  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &Lab_5_DW.obj;
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
