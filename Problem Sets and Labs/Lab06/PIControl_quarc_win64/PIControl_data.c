/*
 * PIControl_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIControl".
 *
 * Model version              : 8.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Apr 14 13:17:51 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIControl.h"
#include "PIControl_private.h"

/* Block parameters (default storage) */
P_PIControl_T PIControl_P = {
  /* Mask Parameter: PDController_D
   * Referenced by: '<S33>/Derivative Gain'
   */
  { 5.0, 5.0 },

  /* Mask Parameter: PDController_InitialConditionFo
   * Referenced by: '<S34>/Filter'
   */
  0.0,

  /* Mask Parameter: PDController_N
   * Referenced by: '<S42>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PDController_P
   * Referenced by: '<S44>/Proportional Gain'
   */
  { 200.0, 200.0 },

  /* Mask Parameter: BiasRemoval_end_time
   * Referenced by: '<S56>/Bias Removal'
   */
  0.5,

  /* Mask Parameter: BiasRemoval1_end_time
   * Referenced by: '<S56>/Bias Removal1'
   */
  0.5,

  /* Mask Parameter: SecondOrderLowPassFilter_input_
   * Referenced by: '<S62>/wn'
   */
  10.0,

  /* Mask Parameter: SecondOrderLowPassFilter1_input
   * Referenced by: '<S63>/wn'
   */
  10.0,

  /* Mask Parameter: SecondOrderLowPassFilter_inpu_h
   * Referenced by: '<S62>/zt'
   */
  1.0,

  /* Mask Parameter: SecondOrderLowPassFilter1_inp_n
   * Referenced by: '<S63>/zt'
   */
  1.0,

  /* Mask Parameter: XYSuperimposed_maximum_x
   * Referenced by: '<Root>/XY Superimposed'
   */
  0.37,

  /* Mask Parameter: XYSuperimposed_maximum_y
   * Referenced by: '<Root>/XY Superimposed'
   */
  0.03,

  /* Mask Parameter: XYSuperimposed_minimum_x
   * Referenced by: '<Root>/XY Superimposed'
   */
  0.19,

  /* Mask Parameter: XYSuperimposed_minimum_y
   * Referenced by: '<Root>/XY Superimposed'
   */
  -0.15,

  /* Mask Parameter: BiasRemoval_start_time
   * Referenced by: '<S56>/Bias Removal'
   */
  0.1,

  /* Mask Parameter: BiasRemoval1_start_time
   * Referenced by: '<S56>/Bias Removal1'
   */
  0.1,

  /* Mask Parameter: BiasRemoval_switch_id
   * Referenced by: '<S56>/Bias Removal'
   */
  1.0,

  /* Mask Parameter: BiasRemoval1_switch_id
   * Referenced by: '<S56>/Bias Removal1'
   */
  1.0,

  /* Mask Parameter: XYSuperimposed_update_rate
   * Referenced by: '<Root>/XY Superimposed'
   */
  100,

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<S56>/HIL Read Analog'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S58>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S58>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadAnalog_channels_c
   * Referenced by: '<S58>/HIL Read Analog'
   */
  { 0U, 1U },

  /* Expression: .2
   * Referenced by: '<S5>/I Gain'
   */
  0.2,

  /* Expression: 2.5
   * Referenced by: '<S5>/Kf Gain'
   */
  2.5,

  /* Expression: [0 0; 0 1]
   * Referenced by: '<S5>/I-S'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [5 5]
   * Referenced by: '<S5>/D Gain'
   */
  { 5.0, 5.0 },

  /* Expression: 90
   * Referenced by: '<S5>/ P Gain'
   */
  90.0,

  /* Expression: [1 0; 0 0]
   * Referenced by: '<S5>/S'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S56>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S56>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S56>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S56>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S56>/HIL Initialize'
   */
  4882.8125,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S56>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S58>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S58>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S58>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S58>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S58>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S58>/HIL Initialize'
   */
  0.0,

  /* Expression: 4000
   * Referenced by: '<S56>/X Gain (N//V)'
   */
  4000.0,

  /* Expression: 4000
   * Referenced by: '<S56>/Y Gain (N//V)'
   */
  4000.0,

  /* Expression: 2
   * Referenced by: '<S62>/Constant'
   */
  2.0,

  /* Expression: input_init
   * Referenced by: '<S62>/x0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S62>/Integrator2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S63>/Constant'
   */
  2.0,

  /* Expression: input_init
   * Referenced by: '<S63>/x0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S63>/Integrator2'
   */
  0.0,

  /* Expression: [1024;0]
   * Referenced by: '<S58>/Home Position'
   */
  { 1024.0, 0.0 },

  /* Expression: [2*pi/4096 ; -2*pi/4096]
   * Referenced by: '<S58>/Encoder Gain'
   */
  { 0.0015339807878856412, -0.0015339807878856412 },

  /* Expression: 0
   * Referenced by: '<Root>/Speed'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S5>/Desired Force'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Desired Force'
   */
  0.0,

  /* Expression: [0;-1]
   * Referenced by: '<S5>/Desired Force'
   */
  { 0.0, -1.0 },

  /* Expression: 2
   * Referenced by: '<S5>/Reset Integrator'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Reset Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Reset Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Switch'
   */
  2.0,

  /* Expression: 1/.539
   * Referenced by: '<S6>/inv motor gain'
   */
  1.8552875695732838,

  /* Expression: [-0.035; 0.039]
   * Referenced by: '<S58>/Amp Bias Tune for each amp if needed'
   */
  { -0.035, 0.039 },

  /* Expression: [10;-10]
   * Referenced by: '<S58>/1//AmpGain'
   */
  { 10.0, -10.0 },

  /* Expression: 2
   * Referenced by: '<S58>/1//Sense Gain'
   */
  2.0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S56>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S56>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S58>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S58>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial_d
   * Referenced by: '<S58>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes_k
   * Referenced by: '<S58>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S58>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S58>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S58>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S56>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S56>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S58>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels_p
   * Referenced by: '<S58>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S58>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature_e
   * Referenced by: '<S58>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S58>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S56>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S56>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_Active_e
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate_g
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit_e
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate_c
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit_m
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate_a
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit_l
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart_b
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter_o
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart_i
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter_p
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart_j
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter_e
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart_b
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter_p
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart_k
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter_m
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset_b
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart_m
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter_m
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart_e
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter_l
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset_h
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart_j
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter_i
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart_a
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter_h
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart_a
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter_b
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart_n
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter_n
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset_d
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset_p
   * Referenced by: '<S58>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal_l
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial_d
   * Referenced by: '<S58>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<S56>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<S58>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S58>/HIL Write Analog'
   */
  false,

  /* Computed Parameter: HILReadAnalog_Active_c
   * Referenced by: '<S58>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: XYSuperimposed_Mode
   * Referenced by: '<Root>/XY Superimposed'
   */
  1U,

  /* Start of '<S56>/Bias Removal1' */
  {
    /* Computed Parameter: x_avg_n_Y0
     * Referenced by: '<S69>/x_avg_n'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S73>/unity'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S73>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S69>/Sum( k=1,n-1, x(k) )'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S70>/zero'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S70>/Constant'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S71>/Vbiased'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S72>/Vunbiased'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S61>/Step: start_time'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S61>/Step: start_time'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S61>/Step: end_time'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S61>/Step: end_time'
     */
    1.0
  }
  ,

  /* End of '<S56>/Bias Removal1' */

  /* Start of '<S56>/Bias Removal' */
  {
    /* Computed Parameter: x_avg_n_Y0
     * Referenced by: '<S64>/x_avg_n'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S68>/unity'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S68>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S64>/Sum( k=1,n-1, x(k) )'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S65>/zero'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S65>/Constant'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S66>/Vbiased'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S67>/Vunbiased'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S60>/Step: start_time'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S60>/Step: start_time'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S60>/Step: end_time'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S60>/Step: end_time'
     */
    1.0
  }
  /* End of '<S56>/Bias Removal' */
};
