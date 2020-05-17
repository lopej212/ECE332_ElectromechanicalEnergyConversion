/*
 * Lab6_OpenLoop_data.c
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

#include "Lab6_OpenLoop.h"
#include "Lab6_OpenLoop_private.h"

/* Block parameters (auto storage) */
P_Lab6_OpenLoop_T Lab6_OpenLoop_P = {
  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S1>/Integral Gain'
   */
  0.657149548237365,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S1>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  3.28574774118682E-5,

  /* Expression: 2*pi/1000 *(1/0.0001)
   * Referenced by: '<S3>/velocity'
   */
  62.831853071795869,

  /* Expression: 30/pi
   * Referenced by: '<S3>/rev'
   */
  9.5492965855137211,

  /* Expression: 1
   * Referenced by: '<Root>/Cool_Name'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S1>/Integrator'
   */
  0.0001,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S1>/Filter'
   */
  0.0001,

  /* Expression: InitialConditionForFilter
   * Referenced by: '<S1>/Filter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Sine Wave'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave'
   */
  0.0,

  /* Expression: .15
   * Referenced by: '<Root>/Gain'
   */
  0.15,

  /* Expression: 1/42
   * Referenced by: '<Root>/Gain1'
   */
  0.023809523809523808,

  /* Expression: 1
   * Referenced by: '<S4>/Sine Wave1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave1'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Sine Wave1'
   */
  6.2831853071795862,

  /* Expression: 2*pi/3
   * Referenced by: '<S4>/Sine Wave1'
   */
  2.0943951023931953,

  /* Expression: 1
   * Referenced by: '<S4>/Sine Wave2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave2'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S4>/Sine Wave2'
   */
  6.2831853071795862,

  /* Expression: 4*pi/3
   * Referenced by: '<S4>/Sine Wave2'
   */
  4.1887902047863905,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 2*pi/1000
   * Referenced by: '<S3>/displacement'
   */
  0.0062831853071795866
};
