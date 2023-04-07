/*
 * compliance_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "compliance".
 *
 * Model version              : 8.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Apr  6 13:54:48 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "compliance.h"
#include "compliance_private.h"

/* Block parameters (default storage) */
P_compliance_T compliance_P = {
  /* Mask Parameter: PDController_D
   * Referenced by: '<S34>/Derivative Gain'
   */
  { 5.0, 10.0 },

  /* Mask Parameter: PDController_InitialConditionFo
   * Referenced by: '<S35>/Filter'
   */
  0.0,

  /* Mask Parameter: PDController_N
   * Referenced by: '<S43>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PDController_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  { 310.0, 310.0 },

  /* Mask Parameter: BiasRemoval_end_time
   * Referenced by: '<S57>/Bias Removal'
   */
  0.5,

  /* Mask Parameter: BiasRemoval1_end_time
   * Referenced by: '<S57>/Bias Removal1'
   */
  0.5,

  /* Mask Parameter: SecondOrderLowPassFilter_input_
   * Referenced by: '<S63>/wn'
   */
  10.0,

  /* Mask Parameter: SecondOrderLowPassFilter1_input
   * Referenced by: '<S64>/wn'
   */
  10.0,

  /* Mask Parameter: SecondOrderLowPassFilter_inpu_o
   * Referenced by: '<S63>/zt'
   */
  1.0,

  /* Mask Parameter: SecondOrderLowPassFilter1_inp_b
   * Referenced by: '<S64>/zt'
   */
  1.0,

  /* Mask Parameter: XYSuperimposed_maximum_x
   * Referenced by: '<S8>/XY Superimposed'
   */
  0.37,

  /* Mask Parameter: XYSuperimposed_maximum_y
   * Referenced by: '<S8>/XY Superimposed'
   */
  0.03,

  /* Mask Parameter: XYSuperimposed_minimum_x
   * Referenced by: '<S8>/XY Superimposed'
   */
  0.19,

  /* Mask Parameter: XYSuperimposed_minimum_y
   * Referenced by: '<S8>/XY Superimposed'
   */
  -0.15,

  /* Mask Parameter: BiasRemoval_start_time
   * Referenced by: '<S57>/Bias Removal'
   */
  0.1,

  /* Mask Parameter: BiasRemoval1_start_time
   * Referenced by: '<S57>/Bias Removal1'
   */
  0.1,

  /* Mask Parameter: BiasRemoval_switch_id
   * Referenced by: '<S57>/Bias Removal'
   */
  1.0,

  /* Mask Parameter: BiasRemoval1_switch_id
   * Referenced by: '<S57>/Bias Removal1'
   */
  1.0,

  /* Mask Parameter: XYSuperimposed_update_rate
   * Referenced by: '<S8>/XY Superimposed'
   */
  100,

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<S57>/HIL Read Analog'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S59>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S59>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Mask Parameter: HILReadAnalog_channels_c
   * Referenced by: '<S59>/HIL Read Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S57>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S57>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S57>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S57>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S57>/HIL Initialize'
   */
  4882.8125,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S57>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S59>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S59>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S59>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S59>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S59>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S59>/HIL Initialize'
   */
  0.0,

  /* Expression: 4000
   * Referenced by: '<S57>/X Gain (N//V)'
   */
  4000.0,

  /* Expression: 4000
   * Referenced by: '<S57>/Y Gain (N//V)'
   */
  4000.0,

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

  /* Expression: 2
   * Referenced by: '<S64>/Constant'
   */
  2.0,

  /* Expression: input_init
   * Referenced by: '<S64>/x0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S64>/Integrator2'
   */
  0.0,

  /* Expression: [1024;0]
   * Referenced by: '<S59>/Home Position'
   */
  { 1024.0, 0.0 },

  /* Expression: [2*pi/4096 ; -2*pi/4096]
   * Referenced by: '<S59>/Encoder Gain'
   */
  { 0.0015339807878856412, -0.0015339807878856412 },

  /* Expression: 0.2
   * Referenced by: '<Root>/Speed'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<Root>/x Admittance'
   */
  0.0,

  /* Computed Parameter: yAdmittance1_A
   * Referenced by: '<Root>/y Admittance1'
   */
  { -100.0, -170.0 },

  /* Computed Parameter: yAdmittance1_C
   * Referenced by: '<Root>/y Admittance1'
   */
  { 0.0, 20.0 },

  /* Expression: 1/.539
   * Referenced by: '<S6>/inv motor gain'
   */
  1.8552875695732838,

  /* Expression: [-0.035; 0.039]
   * Referenced by: '<S59>/Amp Bias Tune for each amp if needed'
   */
  { -0.035, 0.039 },

  /* Expression: [10;-10]
   * Referenced by: '<S59>/1//AmpGain'
   */
  { 10.0, -10.0 },

  /* Expression: 2
   * Referenced by: '<S59>/1//Sense Gain'
   */
  2.0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S57>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S57>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S59>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S59>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial_d
   * Referenced by: '<S59>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes_k
   * Referenced by: '<S59>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S59>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S59>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S59>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S57>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S57>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S59>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels_p
   * Referenced by: '<S59>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S59>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature_e
   * Referenced by: '<S59>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S59>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S57>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S57>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_Active_e
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate_g
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit_e
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate_c
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit_m
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate_a
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit_l
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart_b
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter_o
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart_i
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter_p
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart_j
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter_e
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart_b
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter_p
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart_k
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter_m
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset_b
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart_m
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter_m
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart_e
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter_l
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset_h
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart_j
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter_i
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart_a
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter_h
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart_a
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter_b
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart_n
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter_n
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset_d
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset_p
   * Referenced by: '<S59>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal_l
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial_d
   * Referenced by: '<S59>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<S57>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<S59>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S59>/HIL Write Analog'
   */
  false,

  /* Computed Parameter: HILReadAnalog_Active_c
   * Referenced by: '<S59>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: XYSuperimposed_Mode
   * Referenced by: '<S8>/XY Superimposed'
   */
  1U,

  /* Start of '<S57>/Bias Removal1' */
  {
    /* Computed Parameter: x_avg_n_Y0
     * Referenced by: '<S70>/x_avg_n'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S74>/unity'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S74>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S70>/Sum( k=1,n-1, x(k) )'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S71>/zero'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S71>/Constant'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S72>/Vbiased'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S73>/Vunbiased'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S62>/Step: start_time'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S62>/Step: start_time'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S62>/Step: end_time'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S62>/Step: end_time'
     */
    1.0
  }
  ,

  /* End of '<S57>/Bias Removal1' */

  /* Start of '<S57>/Bias Removal' */
  {
    /* Computed Parameter: x_avg_n_Y0
     * Referenced by: '<S65>/x_avg_n'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S69>/unity'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S69>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S65>/Sum( k=1,n-1, x(k) )'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S66>/zero'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S66>/Constant'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S67>/Vbiased'
     */
    0.0,

    /* Expression: [0]
     * Referenced by: '<S68>/Vunbiased'
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
  /* End of '<S57>/Bias Removal' */
};
