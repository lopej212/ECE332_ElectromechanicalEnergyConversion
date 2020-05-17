/*
 * Lab_4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab_4".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Feb 21 13:41:25 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab_4_trc_ptr.h"
#include "Lab_4.h"
#include "Lab_4_private.h"

/* Block signals (auto storage) */
B_Lab_4_T Lab_4_B;

/* Continuous states */
X_Lab_4_T Lab_4_X;

/* Block states (auto storage) */
DW_Lab_4_T Lab_4_DW;

/* Real-time model */
RT_MODEL_Lab_4_T Lab_4_M_;
RT_MODEL_Lab_4_T *const Lab_4_M = &Lab_4_M_;

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
  Lab_4_derivatives();
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
void Lab_4_MATLABFunction(real_T rtu_u, B_MATLABFunction_Lab_4_T *localB)
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
void Lab_4_output(void)
{
  real_T u0;
  dsp_MovingAverage_Lab_4_T *obj;
  dsp_MovingAverage_Lab_4_T *obj_0;
  dsp_private_SlidingWindowAver_T *obj_1;
  dsp_private_SlidingWindowAver_T *obj_2;
  dsp_private_SlidingWindowAver_T *obj_3;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[31];
  real_T z;
  int32_T i;
  if (rtmIsMajorTimeStep(Lab_4_M)) {
    /* set solver stop time */
    if (!(Lab_4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Lab_4_M->solverInfo, ((Lab_4_M->Timing.clockTickH0
        + 1) * Lab_4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Lab_4_M->solverInfo, ((Lab_4_M->Timing.clockTick0 +
        1) * Lab_4_M->Timing.stepSize0 + Lab_4_M->Timing.clockTickH0 *
        Lab_4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab_4_M)) {
    Lab_4_M->Timing.t[0] = rtsiGetT(&Lab_4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab_4_M)) {
    /* S-Function (rti_commonblock): '<S11>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S11>/S-Function2' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S10>/velocity' */
    Lab_4_B.ang_velocity = Lab_4_P.velocity_Gain * Lab_4_B.SFunction2;

    /* Gain: '<S10>/rev' */
    Lab_4_B.rpm = Lab_4_P.rev_Gain * Lab_4_B.ang_velocity;

    /* MATLABSystem: '<S10>/Moving Average' */
    u0 = Lab_4_B.rpm;

    /* Start for MATLABSystem: '<S10>/Moving Average' */
    obj = &Lab_4_DW.obj;
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

    /* MATLABSystem: '<S10>/Moving Average' */
    z /= 32.0;

    /* Start for MATLABSystem: '<S10>/Moving Average' */
    obj_1->pCumSum = csum;
    for (i = 0; i < 31; i++) {
      obj_1->pCumSumRev[i] = csumrev[i];
    }

    obj_1->pCumRevIndex = cumRevIndex;

    /* MATLABSystem: '<S10>/Moving Average' */
    Lab_4_B.avg_rpm = z;

    /* Gain: '<S10>/displacement' */
    Lab_4_B.theta = Lab_4_P.displacement_Gain * Lab_4_B.SFunction1;

    /* S-Function (rti_commonblock): '<S12>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S12>/S-Function2' */
    /* This comment workarounds a code generation problem */
  }

  /* Integrator: '<S2>/Integrator' */
  Lab_4_B.Integrator = Lab_4_X.Integrator_CSTATE;

  /* Sin: '<S2>/Sine Wave' */
  Lab_4_B.SineWave = sin(Lab_4_P.SineWave_Freq * Lab_4_B.Integrator +
    Lab_4_P.SineWave_Phase) * Lab_4_P.SineWave_Amp + Lab_4_P.SineWave_Bias;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  Lab_4_MATLABFunction(Lab_4_B.SineWave, &Lab_4_B.sf_MATLABFunction);

  /* Sin: '<S2>/Sine Wave1' */
  Lab_4_B.SineWave1 = sin(Lab_4_P.SineWave1_Freq * Lab_4_B.Integrator +
    Lab_4_P.SineWave1_Phase) * Lab_4_P.SineWave1_Amp + Lab_4_P.SineWave1_Bias;

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  Lab_4_MATLABFunction(Lab_4_B.SineWave1, &Lab_4_B.sf_MATLABFunction1);

  /* Sin: '<S2>/Sine Wave2' */
  Lab_4_B.SineWave2 = sin(Lab_4_P.SineWave2_Freq * Lab_4_B.Integrator +
    Lab_4_P.SineWave2_Phase) * Lab_4_P.SineWave2_Amp + Lab_4_P.SineWave2_Bias;

  /* MATLAB Function: '<S2>/MATLAB Function2' */
  Lab_4_MATLABFunction(Lab_4_B.SineWave2, &Lab_4_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(Lab_4_M)) {
    /* S-Function (rti_commonblock): '<S6>/S-Function1' incorporates:
     *  Constant: '<S2>/Constant'
     */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    Lab_4_DW.SFunction1_IWORK = Lab_4_P.Constant_Value;

    /* write the duty cycle down */
    ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0],
      Lab_4_B.sf_MATLABFunction.y, Lab_4_B.sf_MATLABFunction1.y,
      Lab_4_B.sf_MATLABFunction2.y);

    /* set outputs to TTL-level or retrigger PWM generation */
    if (Lab_4_DW.SFunction1_IWORK == 1 ) {
      /*  if (flag == RUN)||(flag == UNDEF) */
      if ((slaveDSPPwm3StopFlag == 1)||(slaveDSPPwm3StopFlag == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
      {
        slaveDSPPwm3StopFlag = 0;
        ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
          SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
      }
    } else if (Lab_4_DW.SFunction1_IWORK == 0 ) {
      /* PWM Stop signal disabled -> trigger PWM generation */
      if ((slaveDSPPwm3StopFlag == 0)||(slaveDSPPwm3StopFlag == 2)) {
        slaveDSPPwm3StopFlag = 1;
        ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
          SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW);
      }
    }

    /* Constant: '<S2>/Freq.' */
    Lab_4_B.Freq = Lab_4_P.Freq_Value;
  }
}

/* Model update function */
void Lab_4_update(void)
{
  if (rtmIsMajorTimeStep(Lab_4_M)) {
    rt_ertODEUpdateContinuousStates(&Lab_4_M->solverInfo);
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
  if (!(++Lab_4_M->Timing.clockTick0)) {
    ++Lab_4_M->Timing.clockTickH0;
  }

  Lab_4_M->Timing.t[0] = rtsiGetSolverStopTime(&Lab_4_M->solverInfo);

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
    Lab_4_M->Timing.clockTick1++;
    if (!Lab_4_M->Timing.clockTick1) {
      Lab_4_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void Lab_4_derivatives(void)
{
  XDot_Lab_4_T *_rtXdot;
  _rtXdot = ((XDot_Lab_4_T *) Lab_4_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = Lab_4_B.Freq;
}

/* Model initialize function */
void Lab_4_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Lab_4_M, 0,
                sizeof(RT_MODEL_Lab_4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab_4_M->solverInfo, &Lab_4_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab_4_M->solverInfo, &rtmGetTPtr(Lab_4_M));
    rtsiSetStepSizePtr(&Lab_4_M->solverInfo, &Lab_4_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab_4_M->solverInfo, &Lab_4_M->derivs);
    rtsiSetContStatesPtr(&Lab_4_M->solverInfo, (real_T **) &Lab_4_M->contStates);
    rtsiSetNumContStatesPtr(&Lab_4_M->solverInfo, &Lab_4_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Lab_4_M->solverInfo,
      &Lab_4_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Lab_4_M->solverInfo,
      &Lab_4_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Lab_4_M->solverInfo,
      &Lab_4_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Lab_4_M->solverInfo, (&rtmGetErrorStatus(Lab_4_M)));
    rtsiSetRTModelPtr(&Lab_4_M->solverInfo, Lab_4_M);
  }

  rtsiSetSimTimeStep(&Lab_4_M->solverInfo, MAJOR_TIME_STEP);
  Lab_4_M->intgData.f[0] = Lab_4_M->odeF[0];
  Lab_4_M->contStates = ((X_Lab_4_T *) &Lab_4_X);
  rtsiSetSolverData(&Lab_4_M->solverInfo, (void *)&Lab_4_M->intgData);
  rtsiSetSolverName(&Lab_4_M->solverInfo,"ode1");
  rtmSetTPtr(Lab_4_M, &Lab_4_M->Timing.tArray[0]);
  Lab_4_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &Lab_4_B), 0,
                sizeof(B_Lab_4_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Lab_4_X, 0,
                  sizeof(X_Lab_4_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Lab_4_DW, 0,
                sizeof(DW_Lab_4_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Lab_4_rti_init_trc_pointers();
  }

  {
    dsp_MovingAverage_Lab_4_T *b_obj;
    dsp_private_SlidingWindowAver_T *iobj_0;
    dsp_MovingAverage_Lab_4_T *obj;

    /* Start for MATLABSystem: '<S10>/Moving Average' */
    b_obj = &Lab_4_DW.obj;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    Lab_4_DW.objisempty = true;
    b_obj = &Lab_4_DW.obj;
    iobj_0 = &Lab_4_DW.gobj_0;
    b_obj->isInitialized = 1;
    obj = b_obj;
    obj->NumChannels = 1;
    iobj_0->isInitialized = 0;
    obj->pStatistic = iobj_0;
    b_obj->TunablePropsChanged = false;

    /* Start for S-Function (rti_commonblock): '<S6>/S-Function1' incorporates:
     *  Constant: '<S2>/Constant'
     */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    Lab_4_DW.SFunction1_IWORK = 0;
  }

  {
    dsp_MovingAverage_Lab_4_T *obj;
    dsp_private_SlidingWindowAver_T *obj_0;
    int32_T i;

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    Lab_4_X.Integrator_CSTATE = Lab_4_P.Integrator_IC;

    /* Start for MATLABSystem: '<S10>/Moving Average' */
    obj = &Lab_4_DW.obj;
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 31; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of Start for MATLABSystem: '<S10>/Moving Average' */
  }
}

/* Model terminate function */
void Lab_4_terminate(void)
{
  boolean_T flag;
  dsp_MovingAverage_Lab_4_T *obj;
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Start for MATLABSystem: '<S10>/Moving Average' */
  obj = &Lab_4_DW.obj;
  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &Lab_4_DW.obj;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      obj_0 = obj->pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      obj->NumChannels = -1;
    }
  }

  /* End of Start for MATLABSystem: '<S10>/Moving Average' */
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
