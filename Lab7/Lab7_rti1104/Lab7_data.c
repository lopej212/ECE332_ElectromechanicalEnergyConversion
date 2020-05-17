/*
 * Lab7_data.c
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

#include "Lab7.h"
#include "Lab7_private.h"

/* Block parameters (auto storage) */
P_Lab7_T Lab7_P = {
  /* Mask Parameter: DiscretePIDController1_D
   * Referenced by: '<S2>/Derivative Gain'
   */
  8.9070772498604E-6,

  /* Mask Parameter: DiscretePIDController1_I
   * Referenced by: '<S2>/Integral Gain'
   */
  0.483904620825606,

  /* Mask Parameter: DiscretePIDController1_LowerSat
   * Referenced by:
   *   '<S2>/Saturate'
   *   '<S7>/DeadZone'
   */
  -42.0,

  /* Mask Parameter: DiscretePIDController1_N
   * Referenced by: '<S2>/Filter Coefficient'
   */
  117.23921257214,

  /* Mask Parameter: DiscretePIDController1_P
   * Referenced by: '<S2>/Proportional Gain'
   */
  0.00967058994147408,

  /* Mask Parameter: DiscretePIDController1_UpperSat
   * Referenced by:
   *   '<S2>/Saturate'
   *   '<S7>/DeadZone'
   */
  42.0,

  /* Expression: 2*pi/1000 *(1/0.0001)
   * Referenced by: '<S4>/velocity'
   */
  62.831853071795869,

  /* Expression: 30/pi
   * Referenced by: '<S4>/rev'
   */
  9.5492965855137211,

  /* Expression: 0
   * Referenced by: '<Root>/input3'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S2>/Integrator'
   */
  0.0001,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S2>/Filter'
   */
  0.0001,

  /* Expression: InitialConditionForFilter
   * Referenced by: '<S2>/Filter'
   */
  0.0,

  /* Expression: 1/42
   * Referenced by: '<Root>/Gain'
   */
  0.023809523809523808,

  /* Expression: 1
   * Referenced by: '<S5>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/ZeroGain'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 2*pi/1000
   * Referenced by: '<S4>/displacement'
   */
  0.0062831853071795866
};
