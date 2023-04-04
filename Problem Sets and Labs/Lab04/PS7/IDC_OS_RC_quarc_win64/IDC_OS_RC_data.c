/*
 * IDC_OS_RC_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IDC_OS_RC".
 *
 * Model version              : 8.15
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Apr  1 13:36:39 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IDC_OS_RC.h"
#include "IDC_OS_RC_private.h"

/* Block parameters (default storage) */
P_IDC_OS_RC_T IDC_OS_RC_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S35>/Derivative Gain'
   */
  20.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S36>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S44>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S46>/Proportional Gain'
   */
  500.0,

  /* Mask Parameter: XYSuperimposed_maximum_x
   * Referenced by: '<S9>/XY Superimposed'
   */
  0.3,

  /* Mask Parameter: XYSuperimposed_maximum_y
   * Referenced by: '<S9>/XY Superimposed'
   */
  0.2,

  /* Mask Parameter: XYSuperimposed_minimum_x
   * Referenced by: '<S9>/XY Superimposed'
   */
  0.0,

  /* Mask Parameter: XYSuperimposed_minimum_y
   * Referenced by: '<S9>/XY Superimposed'
   */
  0.0,

  /* Mask Parameter: XYSuperimposed_update_rate
   * Referenced by: '<S9>/XY Superimposed'
   */
  100,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S7>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S7>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<S7>/HIL Read Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S7>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S7>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S7>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S7>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S7>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S7>/HIL Initialize'
   */
  0.0,

  /* Expression: [1024;0]
   * Referenced by: '<S7>/Home Position'
   */
  { 1024.0, 0.0 },

  /* Expression: [2*pi/4096 ; -2*pi/4096]
   * Referenced by: '<S7>/Encoder Gain'
   */
  { 0.0015339807878856412, -0.0015339807878856412 },

  /* Expression: 1
   * Referenced by: '<Root>/Speed'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Lambda'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<Root>/1//eps'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Saturation'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<Root>/Saturation'
   */
  -0.2,

  /* Expression: 35
   * Referenced by: '<Root>/rho'
   */
  35.0,

  /* Expression: 1/0.539
   * Referenced by: '<Root>/1//AmpGain (V//A)1'
   */
  1.8552875695732838,

  /* Expression: [0; 0]
   * Referenced by: '<S7>/Amp Bias Tune for each  amp//channel if needed'
   */
  { 0.0, 0.0 },

  /* Expression: [10;-10]
   * Referenced by: '<S7>/1//AmpGain'
   */
  { 10.0, -10.0 },

  /* Expression: 2
   * Referenced by: '<S7>/1//Sense Gain'
   */
  2.0,

  /* Expression: [0; 0]
   * Referenced by: '<S7>/Current Sense Bias Tune for each amp//channel if needed'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S7>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S7>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S7>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S7>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S7>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S7>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S7>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S7>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S7>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<S7>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S7>/HIL Write Analog'
   */
  false,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<S7>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: XYSuperimposed_Mode
   * Referenced by: '<S9>/XY Superimposed'
   */
  1U
};
