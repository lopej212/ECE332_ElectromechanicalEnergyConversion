/*
 * Lab7.c
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

#include "Lab7_trc_ptr.h"
#include "Lab7.h"
#include "Lab7_private.h"

/* Block signals (auto storage) */
B_Lab7_T Lab7_B;

/* Block states (auto storage) */
DW_Lab7_T Lab7_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Lab7_T Lab7_Y;

/* Real-time model */
RT_MODEL_Lab7_T Lab7_M_;
RT_MODEL_Lab7_T *const Lab7_M = &Lab7_M_;

/* Model output function */
void Lab7_output(void)
{
  real_T u0;
  dsp_MovingAverage_Lab7_T *obj;
  dsp_MovingAverage_Lab7_T *obj_0;
  dsp_private_SlidingWindowAver_T *obj_1;
  dsp_private_SlidingWindowAver_T *obj_2;
  dsp_private_SlidingWindowAver_T *obj_3;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[31];
  real_T z;
  int32_T i;
  int8_T tmp;

  /* S-Function (rti_commonblock): '<S11>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S4>/velocity' */
  Lab7_B.ang_velocity = Lab7_P.velocity_Gain * Lab7_B.SFunction2;

  /* Gain: '<S4>/rev' */
  Lab7_B.rpm = Lab7_P.rev_Gain * Lab7_B.ang_velocity;

  /* MATLABSystem: '<S4>/Moving Average' */
  u0 = Lab7_B.rpm;

  /* Start for MATLABSystem: '<S4>/Moving Average' */
  obj = &Lab7_DW.obj;
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

  /* MATLABSystem: '<S4>/Moving Average' */
  z /= 32.0;

  /* Start for MATLABSystem: '<S4>/Moving Average' */
  obj_1->pCumSum = csum;
  for (i = 0; i < 31; i++) {
    obj_1->pCumSumRev[i] = csumrev[i];
  }

  obj_1->pCumRevIndex = cumRevIndex;

  /* Outport: '<Root>/avg_rpm ' incorporates:
   *  MATLABSystem: '<S4>/Moving Average'
   */
  Lab7_Y.avg_rpm = z;

  /* Outport: '<Root>/ref_out' incorporates:
   *  Constant: '<Root>/input3'
   */
  Lab7_Y.ref_out = Lab7_P.input3_Value;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/input3'
   *  Outport: '<Root>/avg_rpm '
   */
  Lab7_B.Sum1 = Lab7_P.input3_Value - Lab7_Y.avg_rpm;

  /* Gain: '<S2>/Proportional Gain' */
  Lab7_B.ProportionalGain = Lab7_P.DiscretePIDController1_P * Lab7_B.Sum1;

  /* DiscreteIntegrator: '<S2>/Integrator' */
  Lab7_B.Integrator = Lab7_DW.Integrator_DSTATE;

  /* Gain: '<S2>/Derivative Gain' */
  Lab7_B.DerivativeGain = Lab7_P.DiscretePIDController1_D * Lab7_B.Sum1;

  /* DiscreteIntegrator: '<S2>/Filter' */
  Lab7_B.Filter = Lab7_DW.Filter_DSTATE;

  /* Sum: '<S2>/SumD' */
  Lab7_B.SumD = Lab7_B.DerivativeGain - Lab7_B.Filter;

  /* Gain: '<S2>/Filter Coefficient' */
  Lab7_B.FilterCoefficient = Lab7_P.DiscretePIDController1_N * Lab7_B.SumD;

  /* Sum: '<S2>/Sum' */
  Lab7_B.Sum = (Lab7_B.ProportionalGain + Lab7_B.Integrator) +
    Lab7_B.FilterCoefficient;

  /* Saturate: '<S2>/Saturate' */
  u0 = Lab7_B.Sum;
  cumRevIndex = Lab7_P.DiscretePIDController1_LowerSat;
  csum = Lab7_P.DiscretePIDController1_UpperSat;
  if (u0 > csum) {
    Lab7_B.Saturate = csum;
  } else if (u0 < cumRevIndex) {
    Lab7_B.Saturate = cumRevIndex;
  } else {
    Lab7_B.Saturate = u0;
  }

  /* End of Saturate: '<S2>/Saturate' */

  /* Gain: '<Root>/Gain' */
  Lab7_B.Gain = Lab7_P.Gain_Gain * Lab7_B.Saturate;

  /* Fcn: '<S5>/Fcn' */
  Lab7_B.Fcn = (Lab7_B.Gain + 1.0) / 2.0;

  /* Sum: '<S5>/Subtract' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  Lab7_B.Subtract = Lab7_P.Constant2_Value - Lab7_B.Fcn;

  /* S-Function (rti_commonblock): '<S13>/S-Function1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  Lab7_DW.SFunction1_IWORK = Lab7_P.Constant_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], Lab7_B.Fcn,
    Lab7_B.Subtract, Lab7_P.Constant_Value);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (Lab7_DW.SFunction1_IWORK == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwm3StopFlag == 1)||(slaveDSPPwm3StopFlag == 2))/* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwm3StopFlag = 0;
      ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH,
        SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
    }
  } else if (Lab7_DW.SFunction1_IWORK == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation */
    if ((slaveDSPPwm3StopFlag == 0)||(slaveDSPPwm3StopFlag == 2)) {
      slaveDSPPwm3StopFlag = 1;
      ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
        SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
        SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW,
        SLVDSP1104_PWM3_ACTIVE_HIGH, SLVDSP1104_PWM3_ACTIVE_LOW);
    }
  }

  /* Gain: '<S7>/ZeroGain' */
  Lab7_B.ZeroGain = Lab7_P.ZeroGain_Gain * Lab7_B.Sum;

  /* DeadZone: '<S7>/DeadZone' */
  if (Lab7_B.Sum > Lab7_P.DiscretePIDController1_UpperSat) {
    Lab7_B.DeadZone = Lab7_B.Sum - Lab7_P.DiscretePIDController1_UpperSat;
  } else if (Lab7_B.Sum >= Lab7_P.DiscretePIDController1_LowerSat) {
    Lab7_B.DeadZone = 0.0;
  } else {
    Lab7_B.DeadZone = Lab7_B.Sum - Lab7_P.DiscretePIDController1_LowerSat;
  }

  /* End of DeadZone: '<S7>/DeadZone' */

  /* RelationalOperator: '<S7>/NotEqual' */
  Lab7_B.NotEqual = (Lab7_B.ZeroGain != Lab7_B.DeadZone);

  /* Signum: '<S7>/SignDeltaU' */
  u0 = Lab7_B.DeadZone;
  if (u0 < 0.0) {
    Lab7_B.SignDeltaU = -1.0;
  } else if (u0 > 0.0) {
    Lab7_B.SignDeltaU = 1.0;
  } else if (u0 == 0.0) {
    Lab7_B.SignDeltaU = 0.0;
  } else {
    Lab7_B.SignDeltaU = (rtNaN);
  }

  /* End of Signum: '<S7>/SignDeltaU' */

  /* DataTypeConversion: '<S7>/DataTypeConv1' */
  u0 = Lab7_B.SignDeltaU;
  if (u0 < 128.0) {
    if (u0 >= -128.0) {
      tmp = (int8_T)u0;
    } else {
      tmp = MIN_int8_T;
    }
  } else {
    tmp = MAX_int8_T;
  }

  Lab7_B.DataTypeConv1 = tmp;

  /* End of DataTypeConversion: '<S7>/DataTypeConv1' */

  /* Gain: '<S2>/Integral Gain' */
  Lab7_B.IntegralGain = Lab7_P.DiscretePIDController1_I * Lab7_B.Sum1;

  /* Signum: '<S7>/SignPreIntegrator' */
  u0 = Lab7_B.IntegralGain;
  if (u0 < 0.0) {
    Lab7_B.SignPreIntegrator = -1.0;
  } else if (u0 > 0.0) {
    Lab7_B.SignPreIntegrator = 1.0;
  } else if (u0 == 0.0) {
    Lab7_B.SignPreIntegrator = 0.0;
  } else {
    Lab7_B.SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S7>/SignPreIntegrator' */

  /* DataTypeConversion: '<S7>/DataTypeConv2' */
  u0 = floor(Lab7_B.SignPreIntegrator);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 256.0);
  }

  Lab7_B.DataTypeConv2 = (int8_T)(u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
    -u0 : (int32_T)(int8_T)(uint8_T)u0);

  /* End of DataTypeConversion: '<S7>/DataTypeConv2' */

  /* RelationalOperator: '<S7>/Equal' */
  Lab7_B.Equal = (Lab7_B.DataTypeConv1 == Lab7_B.DataTypeConv2);

  /* Logic: '<S7>/AND' */
  Lab7_B.AND = (Lab7_B.NotEqual && Lab7_B.Equal);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (Lab7_B.AND) {
    Lab7_B.Switch = Lab7_P.Constant_Value_a;
  } else {
    Lab7_B.Switch = Lab7_B.IntegralGain;
  }

  /* End of Switch: '<S2>/Switch' */

  /* S-Function (rti_commonblock): '<S11>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S4>/displacement' */
  Lab7_B.theta = Lab7_P.displacement_Gain * Lab7_B.SFunction1;

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S12>/S-Function2' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void Lab7_update(void)
{
  /* Update for DiscreteIntegrator: '<S2>/Integrator' */
  Lab7_DW.Integrator_DSTATE += Lab7_P.Integrator_gainval * Lab7_B.Switch;

  /* Update for DiscreteIntegrator: '<S2>/Filter' */
  Lab7_DW.Filter_DSTATE += Lab7_P.Filter_gainval * Lab7_B.FilterCoefficient;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab7_M->Timing.clockTick0)) {
    ++Lab7_M->Timing.clockTickH0;
  }

  Lab7_M->Timing.taskTime0 = Lab7_M->Timing.clockTick0 *
    Lab7_M->Timing.stepSize0 + Lab7_M->Timing.clockTickH0 *
    Lab7_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Lab7_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab7_M, 0,
                sizeof(RT_MODEL_Lab7_T));
  Lab7_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &Lab7_B), 0,
                sizeof(B_Lab7_T));

  /* states (dwork) */
  (void) memset((void *)&Lab7_DW, 0,
                sizeof(DW_Lab7_T));

  /* external outputs */
  (void) memset((void *)&Lab7_Y, 0,
                sizeof(ExtY_Lab7_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Lab7_rti_init_trc_pointers();
  }

  {
    dsp_MovingAverage_Lab7_T *b_obj;
    dsp_private_SlidingWindowAver_T *iobj_0;
    dsp_MovingAverage_Lab7_T *obj;

    /* Start for MATLABSystem: '<S4>/Moving Average' */
    b_obj = &Lab7_DW.obj;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    Lab7_DW.objisempty = true;
    b_obj = &Lab7_DW.obj;
    iobj_0 = &Lab7_DW.gobj_0;
    b_obj->isInitialized = 1;
    obj = b_obj;
    obj->NumChannels = 1;
    iobj_0->isInitialized = 0;
    obj->pStatistic = iobj_0;
    b_obj->TunablePropsChanged = false;

    /* Start for S-Function (rti_commonblock): '<S13>/S-Function1' incorporates:
     *  Constant: '<S5>/Constant'
     */

    /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
    Lab7_DW.SFunction1_IWORK = 0;
  }

  {
    dsp_MovingAverage_Lab7_T *obj;
    dsp_private_SlidingWindowAver_T *obj_0;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Integrator' */
    Lab7_DW.Integrator_DSTATE = Lab7_P.Integrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Filter' */
    Lab7_DW.Filter_DSTATE = Lab7_P.Filter_IC;

    /* Start for MATLABSystem: '<S4>/Moving Average' */
    obj = &Lab7_DW.obj;
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 31; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    /* End of Start for MATLABSystem: '<S4>/Moving Average' */
  }
}

/* Model terminate function */
void Lab7_terminate(void)
{
  boolean_T flag;
  dsp_MovingAverage_Lab7_T *obj;
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Start for MATLABSystem: '<S4>/Moving Average' */
  obj = &Lab7_DW.obj;
  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &Lab7_DW.obj;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      obj_0 = obj->pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      obj->NumChannels = -1;
    }
  }

  /* End of Start for MATLABSystem: '<S4>/Moving Average' */

  /* Terminate for S-Function (rti_commonblock): '<S13>/S-Function1' incorporates:
   *  Constant: '<S5>/Constant'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM3_SV_INT Group:PWM3 */
  ds1104_slave_dsp_pwm3_output_set(0, SLVDSP1104_PWM3_INT_ON,
    SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW,
    SLVDSP1104_PWM3_TTL_HIGH, SLVDSP1104_PWM3_TTL_LOW, SLVDSP1104_PWM3_TTL_HIGH);
  ds1104_slave_dsp_pwm3_duty_write(0, rti_slv1104_fcn_index[0], 0.5, 0.5, 0.5);

  /* flag = UNDEF */
  slaveDSPPwm3StopFlag = 2;
}
