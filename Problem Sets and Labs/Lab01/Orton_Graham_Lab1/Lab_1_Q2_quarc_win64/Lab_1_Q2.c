/*
 * Lab_1_Q2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab_1_Q2".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Mar 11 12:40:55 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab_1_Q2.h"
#include "Lab_1_Q2_private.h"
#include "Lab_1_Q2_dt.h"

/* Block signals (default storage) */
B_Lab_1_Q2_T Lab_1_Q2_B;

/* Block states (default storage) */
DW_Lab_1_Q2_T Lab_1_Q2_DW;

/* Real-time model */
static RT_MODEL_Lab_1_Q2_T Lab_1_Q2_M_;
RT_MODEL_Lab_1_Q2_T *const Lab_1_Q2_M = &Lab_1_Q2_M_;

/* Model output function */
void Lab_1_Q2_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder;

  /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

  /* S-Function Block: Lab_1_Q2/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(Lab_1_Q2_DW.HILInitialize_Card,
      &Lab_1_Q2_P.HILReadAnalog_channels, 1, &Lab_1_Q2_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
    }

    rtb_HILReadEncoder = Lab_1_Q2_DW.HILReadAnalog_Buffer;
  }

  /* Bias: '<Root>/Bias1' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  Lab_1_Q2_B.Bias1 = Lab_1_Q2_P.Gain2_Gain * rtb_HILReadEncoder +
    Lab_1_Q2_P.Bias1_Bias;

  /* Step: '<Root>/Step' */
  if (Lab_1_Q2_M->Timing.t[0] < Lab_1_Q2_P.Step_Time) {
    /* Step: '<Root>/Step' */
    Lab_1_Q2_B.Step = Lab_1_Q2_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    Lab_1_Q2_B.Step = Lab_1_Q2_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Lab_1_Q2/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Lab_1_Q2_DW.HILInitialize_Card,
      &Lab_1_Q2_P.HILReadEncoder_channels, 1, &Lab_1_Q2_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder = Lab_1_Q2_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  Lab_1_Q2_B.Gain = Lab_1_Q2_P.Gain_Gain * rtb_HILReadEncoder;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Bias: '<Root>/Bias'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S40>/Proportional Gain'
   *  Sum: '<Root>/Sum'
   */
  Lab_1_Q2_B.Gain1 = ((Lab_1_Q2_P.Gain1_Gain * Lab_1_Q2_B.Step - Lab_1_Q2_B.Gain)
                      * Lab_1_Q2_P.PIDController_P + Lab_1_Q2_P.Bias_Bias) *
    Lab_1_Q2_P.Gain1_Gain_m;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Lab_1_Q2/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Lab_1_Q2_DW.HILInitialize_Card,
      &Lab_1_Q2_P.HILWriteAnalog_channels, 1, &Lab_1_Q2_B.Gain1);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
    }
  }

  /* Gain: '<S3>/Gain' */
  Lab_1_Q2_B.Gain_c = Lab_1_Q2_P.Gain_Gain_n * Lab_1_Q2_B.Gain;
}

/* Model update function */
void Lab_1_Q2_update(void)
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
  if (!(++Lab_1_Q2_M->Timing.clockTick0)) {
    ++Lab_1_Q2_M->Timing.clockTickH0;
  }

  Lab_1_Q2_M->Timing.t[0] = Lab_1_Q2_M->Timing.clockTick0 *
    Lab_1_Q2_M->Timing.stepSize0 + Lab_1_Q2_M->Timing.clockTickH0 *
    Lab_1_Q2_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Lab_1_Q2_M->Timing.clockTick1)) {
      ++Lab_1_Q2_M->Timing.clockTickH1;
    }

    Lab_1_Q2_M->Timing.t[1] = Lab_1_Q2_M->Timing.clockTick1 *
      Lab_1_Q2_M->Timing.stepSize1 + Lab_1_Q2_M->Timing.clockTickH1 *
      Lab_1_Q2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Lab_1_Q2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab_1_Q2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Lab_1_Q2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Lab_1_Q2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Lab_1_Q2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
      return;
    }

    if ((Lab_1_Q2_P.HILInitialize_AIPStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Lab_1_Q2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (Lab_1_Q2_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Lab_1_Q2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Lab_1_Q2_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_AIChannels, 8U,
        &Lab_1_Q2_DW.HILInitialize_AIMinimums[0],
        &Lab_1_Q2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_1_Q2_P.HILInitialize_AOPStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Lab_1_Q2_DW.HILInitialize_Card,
        &Lab_1_Q2_P.HILInitialize_AOChannels, 1U,
        &Lab_1_Q2_P.HILInitialize_AOLow, &Lab_1_Q2_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_1_Q2_P.HILInitialize_AOStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Lab_1_Q2_DW.HILInitialize_Card,
        &Lab_1_Q2_P.HILInitialize_AOChannels, 1U,
        &Lab_1_Q2_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if (Lab_1_Q2_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Lab_1_Q2_DW.HILInitialize_Card, &Lab_1_Q2_P.HILInitialize_AOChannels,
         1U, &Lab_1_Q2_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_1_Q2_P.HILInitialize_EIPStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Lab_1_Q2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Lab_1_Q2_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &Lab_1_Q2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_1_Q2_P.HILInitialize_EIStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Lab_1_Q2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Lab_1_Q2_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_EIChannels, 8U,
        &Lab_1_Q2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_1_Q2_P.HILInitialize_POPStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &Lab_1_Q2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Lab_1_Q2_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Lab_1_Q2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Lab_1_Q2_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &Lab_1_Q2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Lab_1_Q2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            Lab_1_Q2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Lab_1_Q2_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Lab_1_Q2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            Lab_1_Q2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              Lab_1_Q2_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Lab_1_Q2_DW.HILInitialize_Card,
          &Lab_1_Q2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Lab_1_Q2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Lab_1_Q2_DW.HILInitialize_Card,
          &Lab_1_Q2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Lab_1_Q2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Lab_1_Q2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Lab_1_Q2_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &Lab_1_Q2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Lab_1_Q2_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &Lab_1_Q2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Lab_1_Q2_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &Lab_1_Q2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Lab_1_Q2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Lab_1_Q2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &Lab_1_Q2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Lab_1_Q2_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Lab_1_Q2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_1_Q2_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_POChannels, 8U,
        &Lab_1_Q2_DW.HILInitialize_POSortedFreqs[0],
        &Lab_1_Q2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_1_Q2_P.HILInitialize_POStart && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab_1_Q2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_1_Q2_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Lab_1_Q2_DW.HILInitialize_Card,
        Lab_1_Q2_P.HILInitialize_POChannels, 8U,
        &Lab_1_Q2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }

    if (Lab_1_Q2_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab_1_Q2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_1_Q2_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Lab_1_Q2_DW.HILInitialize_Card, Lab_1_Q2_P.HILInitialize_POChannels, 8U,
         &Lab_1_Q2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Lab_1_Q2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab_1_Q2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Lab_1_Q2_DW.HILInitialize_Card);
    hil_monitor_stop_all(Lab_1_Q2_DW.HILInitialize_Card);
    is_switching = false;
    if ((Lab_1_Q2_P.HILInitialize_AOTerminate && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Lab_1_Q2_P.HILInitialize_POTerminate && !is_switching) ||
        (Lab_1_Q2_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab_1_Q2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_1_Q2_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Lab_1_Q2_DW.HILInitialize_Card
                         , &Lab_1_Q2_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , Lab_1_Q2_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Lab_1_Q2_P.HILInitialize_AOFinal
                         , &Lab_1_Q2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Lab_1_Q2_DW.HILInitialize_Card,
            &Lab_1_Q2_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Lab_1_Q2_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Lab_1_Q2_DW.HILInitialize_Card,
            Lab_1_Q2_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Lab_1_Q2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab_1_Q2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Lab_1_Q2_DW.HILInitialize_Card);
    hil_monitor_delete_all(Lab_1_Q2_DW.HILInitialize_Card);
    hil_close(Lab_1_Q2_DW.HILInitialize_Card);
    Lab_1_Q2_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lab_1_Q2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Lab_1_Q2_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Lab_1_Q2_initialize();
}

void MdlTerminate(void)
{
  Lab_1_Q2_terminate();
}

/* Registration function */
RT_MODEL_Lab_1_Q2_T *Lab_1_Q2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab_1_Q2_M, 0,
                sizeof(RT_MODEL_Lab_1_Q2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab_1_Q2_M->solverInfo,
                          &Lab_1_Q2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab_1_Q2_M->solverInfo, &rtmGetTPtr(Lab_1_Q2_M));
    rtsiSetStepSizePtr(&Lab_1_Q2_M->solverInfo, &Lab_1_Q2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Lab_1_Q2_M->solverInfo, (&rtmGetErrorStatus
      (Lab_1_Q2_M)));
    rtsiSetRTModelPtr(&Lab_1_Q2_M->solverInfo, Lab_1_Q2_M);
  }

  rtsiSetSimTimeStep(&Lab_1_Q2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Lab_1_Q2_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab_1_Q2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Lab_1_Q2_M points to
       static memory which is guaranteed to be non-NULL" */
    Lab_1_Q2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab_1_Q2_M->Timing.sampleTimes = (&Lab_1_Q2_M->Timing.sampleTimesArray[0]);
    Lab_1_Q2_M->Timing.offsetTimes = (&Lab_1_Q2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab_1_Q2_M->Timing.sampleTimes[0] = (0.0);
    Lab_1_Q2_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab_1_Q2_M->Timing.offsetTimes[0] = (0.0);
    Lab_1_Q2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab_1_Q2_M, &Lab_1_Q2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab_1_Q2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab_1_Q2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab_1_Q2_M, 5.0);
  Lab_1_Q2_M->Timing.stepSize0 = 0.001;
  Lab_1_Q2_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Lab_1_Q2_M->Sizes.checksums[0] = (2714758272U);
  Lab_1_Q2_M->Sizes.checksums[1] = (2012440549U);
  Lab_1_Q2_M->Sizes.checksums[2] = (4098135222U);
  Lab_1_Q2_M->Sizes.checksums[3] = (3331747485U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab_1_Q2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lab_1_Q2_M->extModeInfo,
      &Lab_1_Q2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lab_1_Q2_M->extModeInfo, Lab_1_Q2_M->Sizes.checksums);
    rteiSetTPtr(Lab_1_Q2_M->extModeInfo, rtmGetTPtr(Lab_1_Q2_M));
  }

  Lab_1_Q2_M->solverInfoPtr = (&Lab_1_Q2_M->solverInfo);
  Lab_1_Q2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab_1_Q2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab_1_Q2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab_1_Q2_M->blockIO = ((void *) &Lab_1_Q2_B);
  (void) memset(((void *) &Lab_1_Q2_B), 0,
                sizeof(B_Lab_1_Q2_T));

  /* parameters */
  Lab_1_Q2_M->defaultParam = ((real_T *)&Lab_1_Q2_P);

  /* states (dwork) */
  Lab_1_Q2_M->dwork = ((void *) &Lab_1_Q2_DW);
  (void) memset((void *)&Lab_1_Q2_DW, 0,
                sizeof(DW_Lab_1_Q2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lab_1_Q2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Lab_1_Q2_M->Sizes.numContStates = (0);/* Number of continuous states */
  Lab_1_Q2_M->Sizes.numY = (0);        /* Number of model outputs */
  Lab_1_Q2_M->Sizes.numU = (0);        /* Number of model inputs */
  Lab_1_Q2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lab_1_Q2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Lab_1_Q2_M->Sizes.numBlocks = (18);  /* Number of blocks */
  Lab_1_Q2_M->Sizes.numBlockIO = (5);  /* Number of block outputs */
  Lab_1_Q2_M->Sizes.numBlockPrms = (104);/* Sum of parameter "widths" */
  return Lab_1_Q2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
