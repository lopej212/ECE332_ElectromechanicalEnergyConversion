/*
 * exp1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "exp1".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Jan 31 13:11:58 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "exp1_trc_ptr.h"
#include "exp1.h"
#include "exp1_private.h"

/* Block signals (auto storage) */
B_exp1_T exp1_B;

/* Block states (auto storage) */
DW_exp1_T exp1_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_exp1_T exp1_Y;

/* Real-time model */
RT_MODEL_exp1_T exp1_M_;
RT_MODEL_exp1_T *const exp1_M = &exp1_M_;

/* Model output function */
void exp1_output(void)
{
  real_T u0;
  dsp_MovingAverage_exp1_T *obj;
  dsp_MovingAverage_exp1_T *obj_0;
  dsp_private_SlidingWindowAver_T *obj_1;
  dsp_private_SlidingWindowAver_T *obj_2;
  dsp_private_SlidingWindowAver_T *obj_3;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[31];
  real_T z;
  int32_T i;

  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<Root>/Cmd'
   */
  exp1_Y.Out1 = exp1_P.Cmd_Value;

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Cmd'
   *  Constant: '<Root>/Constant2'
   */
  exp1_B.Subtract = exp1_P.Constant2_Value - exp1_P.Cmd_Value;

  /* S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
   *  Constant: '<Root>/Cmd'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  exp1_DW.SFunction1_IWORK = exp1_P.Constant_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], exp1_P.Cmd_Value,
    exp1_B.Subtract, exp1_P.Constant1_Value);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (exp1_DW.SFunction1_IWORK == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwm3StopFlag == 1)||(slaveDSPPwm3StopFlag == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwm3StopFlag = 0;
      ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
    }
  } else if (exp1_DW.SFunction1_IWORK == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation */
    if ((slaveDSPPwm3StopFlag == 0)||(slaveDSPPwm3StopFlag == 2)) {
      slaveDSPPwm3StopFlag = 1;
      ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
        SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
        SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
        SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW);
    }
  }

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S1>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<Root>/velocity' */
  exp1_B.ang_velocity = exp1_P.velocity_Gain * exp1_B.SFunction2;

  /* Gain: '<Root>/rev' */
  exp1_B.rpm = exp1_P.rev_Gain * exp1_B.ang_velocity;

  /* MATLABSystem: '<Root>/Moving Average' */
  u0 = exp1_B.rpm;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  obj = &exp1_DW.obj;
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

  /* MATLABSystem: '<Root>/Moving Average' */
  z /= 32.0;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  obj_1->pCumSum = csum;
  for (i = 0; i < 31; i++) {
    obj_1->pCumSumRev[i] = csumrev[i];
  }

  obj_1->pCumRevIndex = cumRevIndex;

  /* MATLABSystem: '<Root>/Moving Average' */
  exp1_B.avg_rpm = z;

  /* Gain: '<Root>/displacement' */
  exp1_B.theta = exp1_P.displacement_Gain * exp1_B.SFunction1;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function2' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void exp1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++exp1_M->Timing.clockTick0)) {
    ++exp1_M->Timing.clockTickH0;
  }

  exp1_M->Timing.taskTime0 = exp1_M->Timing.clockTick0 *
    exp1_M->Timing.stepSize0 + exp1_M->Timing.clockTickH0 *
    exp1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void exp1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)exp1_M, 0,
                sizeof(RT_MODEL_exp1_T));
  exp1_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &exp1_B), 0,
                sizeof(B_exp1_T));

  /* states (dwork) */
  (void) memset((void *)&exp1_DW, 0,
                sizeof(DW_exp1_T));

  /* external outputs */
  exp1_Y.Out1 = 0.0;

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    exp1_rti_init_trc_pointers();
  }

  {
    dsp_MovingAverage_exp1_T *b_obj;
    dsp_private_SlidingWindowAver_T *iobj_0;
    dsp_MovingAverage_exp1_T *obj;

    /* Start for S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
     *  Constant: '<Root>/Cmd'
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    exp1_DW.SFunction1_IWORK = 0;

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    b_obj = &exp1_DW.obj;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    exp1_DW.objisempty = true;
    b_obj = &exp1_DW.obj;
    iobj_0 = &exp1_DW.gobj_0;
    b_obj->isInitialized = 1;
    obj = b_obj;
    obj->NumChannels = 1;
    iobj_0->isInitialized = 0;
    obj->pStatistic = iobj_0;
    b_obj->TunablePropsChanged = false;
  }

  {
    dsp_MovingAverage_exp1_T *obj;
    dsp_private_SlidingWindowAver_T *obj_0;
    int32_T i;

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    obj = &exp1_DW.obj;
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 31; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of Start for MATLABSystem: '<Root>/Moving Average' */
  }
}

/* Model terminate function */
void exp1_terminate(void)
{
  boolean_T flag;
  dsp_MovingAverage_exp1_T *obj;
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' incorporates:
   *  Constant: '<Root>/Cmd'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
    SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW,
    SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], 0.5, 0.5, 0.5);

  /* flag = UNDEF */
  slaveDSPPwm3StopFlag = 2;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  obj = &exp1_DW.obj;
  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &exp1_DW.obj;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      obj_0 = obj->pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      obj->NumChannels = -1;
    }
  }

  /* End of Start for MATLABSystem: '<Root>/Moving Average' */
}
