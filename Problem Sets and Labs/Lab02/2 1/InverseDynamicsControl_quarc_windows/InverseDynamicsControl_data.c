/*
 * InverseDynamicsControl_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "InverseDynamicsControl".
 *
 * Model version              : 3.17
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 16 12:19:05 2023
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "InverseDynamicsControl.h"
#include "InverseDynamicsControl_private.h"

/* Block parameters (default storage) */
P_InverseDynamicsControl_T InverseDynamicsControl_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S33>/Derivative Gain'
   */
  39.8,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S34>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S42>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S44>/Proportional Gain'
   */
  1142.3,

  /* Expression: 0.2
   * Referenced by: '<Root>/Speed'
   */
  0.2,

  /* Expression: [1.1934;-0.2661]
   * Referenced by: '<S6>/v2p'
   */
  { 1.1934, -0.2661 },

  /* Expression: 0
   * Referenced by: '<S6>/a2v'
   */
  0.0,

  /* Expression: 1/0.539
   * Referenced by: '<Root>/1//AmpGain (V//A)1'
   */
  1.8552875695732838,

  /* Expression: 10
   * Referenced by: '<Root>/1//AmpGain (V//A)'
   */
  10.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Amp Gain (A//V)'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<S6>/Amp Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Amp Saturation'
   */
  -1.0,

  /* Expression: 0.539
   * Referenced by: '<S6>/Motor Gain (Nm//A) = N*kt'
   */
  0.539
};
