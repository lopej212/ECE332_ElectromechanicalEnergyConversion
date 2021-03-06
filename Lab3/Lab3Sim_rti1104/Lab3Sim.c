/*
 * Lab3Sim.c
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

#include "Lab3Sim_trc_ptr.h"
#include "Lab3Sim.h"
#include "Lab3Sim_private.h"

/* Block signals (auto storage) */
B_Lab3Sim_T Lab3Sim_B;

/* Block states (auto storage) */
DW_Lab3Sim_T Lab3Sim_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Lab3Sim_T Lab3Sim_Y;

/* Real-time model */
RT_MODEL_Lab3Sim_T Lab3Sim_M_;
RT_MODEL_Lab3Sim_T *const Lab3Sim_M = &Lab3Sim_M_;

/* Model output function */
void Lab3Sim_output(void)
{
  real_T u0;
  dsp_MovingAverage_Lab3Sim_T *obj;
  dsp_MovingAverage_Lab3Sim_T *obj_0;
  dsp_private_SlidingWindowAver_T *obj_1;
  dsp_private_SlidingWindowAver_T *obj_2;
  dsp_private_SlidingWindowAver_T *obj_3;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[31];
  real_T z;
  int32_T i;

  /* S-Function (rti_commonblock): '<S8>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S3>/velocity' */
  Lab3Sim_B.ang_velocity = Lab3Sim_P.velocity_Gain * Lab3Sim_B.SFunction2;

  /* Gain: '<S3>/rev' */
  Lab3Sim_B.rpm = Lab3Sim_P.rev_Gain * Lab3Sim_B.ang_velocity;

  /* MATLABSystem: '<S3>/Moving Average' */
  u0 = Lab3Sim_B.rpm;

  /* Start for MATLABSystem: '<S3>/Moving Average' */
  obj = &Lab3Sim_DW.obj;
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
  Lab3Sim_Y.Out1 = z;

  /* Delay: '<Root>/Delay' */
  Lab3Sim_B.Delay = Lab3Sim_DW.Delay_DSTATE;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/input3'
   *  Outport: '<Root>/Out1'
   *  Outport: '<Root>/command '
   */
  /* MATLAB Function 'MATLAB Function1': '<S1>:1' */
  /* '<S1>:1:3' */
  cumRevIndex = Lab3Sim_P.input3_Value - Lab3Sim_Y.Out1;
  if (cumRevIndex > 0.0) {
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    Lab3Sim_Y.command = Lab3Sim_B.Delay + 0.0001;
  } else if (cumRevIndex < 0.0) {
    /* '<S1>:1:6' */
    /* '<S1>:1:7' */
    Lab3Sim_Y.command = Lab3Sim_B.Delay - 0.0001;
  } else {
    /* '<S1>:1:9' */
    Lab3Sim_Y.command = Lab3Sim_B.Delay;
  }

  if (Lab3Sim_Y.command > 1.0) {
    /* '<S1>:1:12' */
    /* '<S1>:1:13' */
    Lab3Sim_Y.command = 0.99;
  } else {
    if (Lab3Sim_Y.command < -1.0) {
      /* '<S1>:1:14' */
      /* '<S1>:1:15' */
      Lab3Sim_Y.command = -0.99;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Outport: '<Root>/Ref_w ' incorporates:
   *  Constant: '<Root>/input3'
   */
  Lab3Sim_Y.Ref_w = Lab3Sim_P.input3_Value;

  /* Fcn: '<S4>/Fcn' incorporates:
   *  Outport: '<Root>/command '
   */
  Lab3Sim_B.Fcn = (Lab3Sim_Y.command + 1.0) / 2.0;

  /* Sum: '<S4>/Subtract' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  Lab3Sim_B.Subtract = Lab3Sim_P.Constant2_Value - Lab3Sim_B.Fcn;

  /* S-Function (rti_commonblock): '<S10>/S-Function1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  Lab3Sim_DW.SFunction1_IWORK = Lab3Sim_P.Constant_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], Lab3Sim_B.Fcn,
    Lab3Sim_B.Subtract, Lab3Sim_P.Constant_Value);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (Lab3Sim_DW.SFunction1_IWORK == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwm3StopFlag == 1)||(slaveDSPPwm3StopFlag == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwm3StopFlag = 0;
      ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
    }
  } else if (Lab3Sim_DW.SFunction1_IWORK == 0 ) {
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
  Lab3Sim_B.theta = Lab3Sim_P.displacement_Gain * Lab3Sim_B.SFunction1;

  /* S-Function (rti_commonblock): '<S9>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S9>/S-Function2' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void Lab3Sim_update(void)
{
  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Outport: '<Root>/command '
   */
  Lab3Sim_DW.Delay_DSTATE = Lab3Sim_Y.command;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab3Sim_M->Timing.clockTick0)) {
    ++Lab3Sim_M->Timing.clockTickH0;
  }

  Lab3Sim_M->Timing.taskTime0 = Lab3Sim_M->Timing.clockTick0 *
    Lab3Sim_M->Timing.stepSize0 + Lab3Sim_M->Timing.clockTickH0 *
    Lab3Sim_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Lab3Sim_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Lab3Sim_M, 0,
                sizeof(RT_MODEL_Lab3Sim_T));
  Lab3Sim_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &Lab3Sim_B), 0,
                sizeof(B_Lab3Sim_T));

  /* states (dwork) */
  (void) memset((void *)&Lab3Sim_DW, 0,
                sizeof(DW_Lab3Sim_T));

  /* external outputs */
  (void) memset((void *)&Lab3Sim_Y, 0,
                sizeof(ExtY_Lab3Sim_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Lab3Sim_rti_init_trc_pointers();
  }

  {
    dsp_MovingAverage_Lab3Sim_T *b_obj;
    dsp_private_SlidingWindowAver_T *iobj_0;
    dsp_MovingAverage_Lab3Sim_T *obj;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    b_obj = &Lab3Sim_DW.obj;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    Lab3Sim_DW.objisempty = true;
    b_obj = &Lab3Sim_DW.obj;
    iobj_0 = &Lab3Sim_DW.gobj_0;
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
    Lab3Sim_DW.SFunction1_IWORK = 0;
  }

  {
    dsp_MovingAverage_Lab3Sim_T *obj;
    dsp_private_SlidingWindowAver_T *obj_0;
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    Lab3Sim_DW.Delay_DSTATE = Lab3Sim_P.Delay_InitialCondition;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    obj = &Lab3Sim_DW.obj;
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
void Lab3Sim_terminate(void)
{
  boolean_T flag;
  dsp_MovingAverage_Lab3Sim_T *obj;
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Start for MATLABSystem: '<S3>/Moving Average' */
  obj = &Lab3Sim_DW.obj;
  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &Lab3Sim_DW.obj;
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
