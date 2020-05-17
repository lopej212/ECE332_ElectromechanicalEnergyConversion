/*
 * Lab3Sim_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab3Sim".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Feb  7 11:31:27 2020
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab3Sim.h"
#include "Lab3Sim_private.h"

/* Block parameters (auto storage) */
P_Lab3Sim_T Lab3Sim_P = {
  /* Expression: .75
   * Referenced by: '<Root>/Cmd'
   */
  0.75,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 2*pi/1000 *(1/0.0001)
   * Referenced by: '<Root>/velocity'
   */
  62.831853071795869,

  /* Expression: 30/pi
   * Referenced by: '<Root>/rev'
   */
  9.5492965855137211,

  /* Expression: 2*pi/1000
   * Referenced by: '<Root>/displacement'
   */
  0.0062831853071795866
};
