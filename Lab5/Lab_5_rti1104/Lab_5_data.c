/*
 * Lab_5_data.c
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

#include "Lab_5.h"
#include "Lab_5_private.h"

/* Block parameters (auto storage) */
P_Lab_5_T Lab_5_P = {
  /* Expression: 2*pi/1000 *(1/0.0001)
   * Referenced by: '<S3>/velocity'
   */
  62.831853071795869,

  /* Expression: 30/pi
   * Referenced by: '<S3>/rev'
   */
  9.5492965855137211,

  /* Expression: 1
   * Referenced by: '<Root>/Wref'
   */
  1.0,

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

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
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
  0.0062831853071795866,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<Root>/Delay'
   */
  1U
};
