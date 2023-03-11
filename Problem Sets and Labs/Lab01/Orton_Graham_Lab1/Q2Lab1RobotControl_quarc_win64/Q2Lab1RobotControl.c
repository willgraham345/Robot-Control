/*
 * Q2Lab1RobotControl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Q2Lab1RobotControl".
 *
 * Model version              : 1.12
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Mar 11 12:47:41 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Q2Lab1RobotControl.h"
#include "Q2Lab1RobotControl_private.h"
#include "Q2Lab1RobotControl_dt.h"

/* Block signals (default storage) */
B_Q2Lab1RobotControl_T Q2Lab1RobotControl_B;

/* Block states (default storage) */
DW_Q2Lab1RobotControl_T Q2Lab1RobotControl_DW;

/* Real-time model */
static RT_MODEL_Q2Lab1RobotControl_T Q2Lab1RobotControl_M_;
RT_MODEL_Q2Lab1RobotControl_T *const Q2Lab1RobotControl_M =
  &Q2Lab1RobotControl_M_;

/* Model output function */
void Q2Lab1RobotControl_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog;

  /* Step: '<Root>/Step' */
  if (Q2Lab1RobotControl_M->Timing.t[0] < Q2Lab1RobotControl_P.Step_Time) {
    /* Step: '<Root>/Step' */
    Q2Lab1RobotControl_B.Step = Q2Lab1RobotControl_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    Q2Lab1RobotControl_B.Step = Q2Lab1RobotControl_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Q2Lab1RobotControl/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Q2Lab1RobotControl_DW.HILInitialize_Card,
      &Q2Lab1RobotControl_P.HILReadEncoder_channels, 1,
      &Q2Lab1RobotControl_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
    } else {
      rtb_HILReadAnalog = Q2Lab1RobotControl_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Counts to deg [deg//count]' */
  Q2Lab1RobotControl_B.Countstodegdegcount =
    Q2Lab1RobotControl_P.Countstodegdegcount_Gain * rtb_HILReadAnalog;

  /* Gain: '<Root>/1//AmpGain [V//A]' incorporates:
   *  Bias: '<Root>/Command Bias'
   *  Gain: '<S39>/Proportional Gain'
   *  Sum: '<Root>/Sum'
   */
  Q2Lab1RobotControl_B.uAmpGainVA = ((Q2Lab1RobotControl_B.Step -
    Q2Lab1RobotControl_B.Countstodegdegcount) +
    Q2Lab1RobotControl_P.CommandBias_Bias) *
    Q2Lab1RobotControl_P.PIDController_P * Q2Lab1RobotControl_P.uAmpGainVA_Gain;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Q2Lab1RobotControl/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Q2Lab1RobotControl_DW.HILInitialize_Card,
      &Q2Lab1RobotControl_P.HILWriteAnalog_channels, 1,
      &Q2Lab1RobotControl_B.uAmpGainVA);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
    }
  }

  /* Gain: '<S2>/Gain' */
  Q2Lab1RobotControl_B.Gain = Q2Lab1RobotControl_P.Gain_Gain *
    Q2Lab1RobotControl_B.Countstodegdegcount;

  /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

  /* S-Function Block: Q2Lab1RobotControl/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(Q2Lab1RobotControl_DW.HILInitialize_Card,
      &Q2Lab1RobotControl_P.HILReadAnalog_channels, 1,
      &Q2Lab1RobotControl_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
    }

    rtb_HILReadAnalog = Q2Lab1RobotControl_DW.HILReadAnalog_Buffer;
  }

  /* Bias: '<Root>/Sense Bias' incorporates:
   *  Gain: '<Root>/1//SenseGain [A//V]'
   */
  Q2Lab1RobotControl_B.SenseBias = Q2Lab1RobotControl_P.uSenseGainAV_Gain *
    rtb_HILReadAnalog + Q2Lab1RobotControl_P.SenseBias_Bias;
}

/* Model update function */
void Q2Lab1RobotControl_update(void)
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
  if (!(++Q2Lab1RobotControl_M->Timing.clockTick0)) {
    ++Q2Lab1RobotControl_M->Timing.clockTickH0;
  }

  Q2Lab1RobotControl_M->Timing.t[0] = Q2Lab1RobotControl_M->Timing.clockTick0 *
    Q2Lab1RobotControl_M->Timing.stepSize0 +
    Q2Lab1RobotControl_M->Timing.clockTickH0 *
    Q2Lab1RobotControl_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Q2Lab1RobotControl_M->Timing.clockTick1)) {
      ++Q2Lab1RobotControl_M->Timing.clockTickH1;
    }

    Q2Lab1RobotControl_M->Timing.t[1] = Q2Lab1RobotControl_M->Timing.clockTick1 *
      Q2Lab1RobotControl_M->Timing.stepSize1 +
      Q2Lab1RobotControl_M->Timing.clockTickH1 *
      Q2Lab1RobotControl_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Q2Lab1RobotControl_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Q2Lab1RobotControl/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Q2Lab1RobotControl_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Q2Lab1RobotControl_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Q2Lab1RobotControl_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
      return;
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_AIPStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Q2Lab1RobotControl_DW.HILInitialize_AIMinimums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (Q2Lab1RobotControl_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Q2Lab1RobotControl_DW.HILInitialize_AIMaximums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Q2Lab1RobotControl_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Q2Lab1RobotControl_DW.HILInitialize_Card,
         Q2Lab1RobotControl_P.HILInitialize_AIChannels, 8U,
         &Q2Lab1RobotControl_DW.HILInitialize_AIMinimums[0],
         &Q2Lab1RobotControl_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_AOPStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (Q2Lab1RobotControl_DW.HILInitialize_Card,
         &Q2Lab1RobotControl_P.HILInitialize_AOChannels, 1U,
         &Q2Lab1RobotControl_P.HILInitialize_AOLow,
         &Q2Lab1RobotControl_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_AOStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Q2Lab1RobotControl_DW.HILInitialize_Card,
        &Q2Lab1RobotControl_P.HILInitialize_AOChannels, 1U,
        &Q2Lab1RobotControl_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if (Q2Lab1RobotControl_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Q2Lab1RobotControl_DW.HILInitialize_Card,
         &Q2Lab1RobotControl_P.HILInitialize_AOChannels, 1U,
         &Q2Lab1RobotControl_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_EIPStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Q2Lab1RobotControl_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            Q2Lab1RobotControl_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (Q2Lab1RobotControl_DW.HILInitialize_Card,
         Q2Lab1RobotControl_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &Q2Lab1RobotControl_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_EIStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Q2Lab1RobotControl_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Q2Lab1RobotControl_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Q2Lab1RobotControl_DW.HILInitialize_Card,
        Q2Lab1RobotControl_P.HILInitialize_EIChannels, 8U,
        &Q2Lab1RobotControl_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_POPStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Q2Lab1RobotControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Q2Lab1RobotControl_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(Q2Lab1RobotControl_DW.HILInitialize_Card,
        Q2Lab1RobotControl_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Q2Lab1RobotControl_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Q2Lab1RobotControl_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &Q2Lab1RobotControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Q2Lab1RobotControl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            Q2Lab1RobotControl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Q2Lab1RobotControl_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Q2Lab1RobotControl_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            Q2Lab1RobotControl_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Q2Lab1RobotControl_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Q2Lab1RobotControl_DW.HILInitialize_Card,
          &Q2Lab1RobotControl_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &Q2Lab1RobotControl_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Q2Lab1RobotControl_DW.HILInitialize_Card,
          &Q2Lab1RobotControl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Q2Lab1RobotControl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Q2Lab1RobotControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Q2Lab1RobotControl_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Q2Lab1RobotControl_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Q2Lab1RobotControl_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Q2Lab1RobotControl_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Q2Lab1RobotControl_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (Q2Lab1RobotControl_DW.HILInitialize_Card,
         Q2Lab1RobotControl_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &Q2Lab1RobotControl_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *) &Q2Lab1RobotControl_DW.HILInitialize_POAlignValues
         [0],
         (t_pwm_polarity *) &Q2Lab1RobotControl_DW.HILInitialize_POPolarityVals
         [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &Q2Lab1RobotControl_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Q2Lab1RobotControl_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Q2Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q2Lab1RobotControl_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(Q2Lab1RobotControl_DW.HILInitialize_Card,
        Q2Lab1RobotControl_P.HILInitialize_POChannels, 8U,
        &Q2Lab1RobotControl_DW.HILInitialize_POSortedFreqs[0],
        &Q2Lab1RobotControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_POStart && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Q2Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q2Lab1RobotControl_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Q2Lab1RobotControl_DW.HILInitialize_Card,
        Q2Lab1RobotControl_P.HILInitialize_POChannels, 8U,
        &Q2Lab1RobotControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if (Q2Lab1RobotControl_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Q2Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q2Lab1RobotControl_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Q2Lab1RobotControl_DW.HILInitialize_Card,
         Q2Lab1RobotControl_P.HILInitialize_POChannels, 8U,
         &Q2Lab1RobotControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Q2Lab1RobotControl_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Q2Lab1RobotControl/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Q2Lab1RobotControl_DW.HILInitialize_Card);
    hil_monitor_stop_all(Q2Lab1RobotControl_DW.HILInitialize_Card);
    is_switching = false;
    if ((Q2Lab1RobotControl_P.HILInitialize_AOTerminate && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Q2Lab1RobotControl_P.HILInitialize_POTerminate && !is_switching) ||
        (Q2Lab1RobotControl_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Q2Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q2Lab1RobotControl_P.HILInitialize_POFinal;
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
      result = hil_write(Q2Lab1RobotControl_DW.HILInitialize_Card
                         , &Q2Lab1RobotControl_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , Q2Lab1RobotControl_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Q2Lab1RobotControl_P.HILInitialize_AOFinal
                         , &Q2Lab1RobotControl_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Q2Lab1RobotControl_DW.HILInitialize_Card,
             &Q2Lab1RobotControl_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &Q2Lab1RobotControl_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Q2Lab1RobotControl_DW.HILInitialize_Card,
            Q2Lab1RobotControl_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Q2Lab1RobotControl_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Q2Lab1RobotControl_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Q2Lab1RobotControl_DW.HILInitialize_Card);
    hil_monitor_delete_all(Q2Lab1RobotControl_DW.HILInitialize_Card);
    hil_close(Q2Lab1RobotControl_DW.HILInitialize_Card);
    Q2Lab1RobotControl_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Q2Lab1RobotControl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Q2Lab1RobotControl_update();
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
  Q2Lab1RobotControl_initialize();
}

void MdlTerminate(void)
{
  Q2Lab1RobotControl_terminate();
}

/* Registration function */
RT_MODEL_Q2Lab1RobotControl_T *Q2Lab1RobotControl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Q2Lab1RobotControl_M, 0,
                sizeof(RT_MODEL_Q2Lab1RobotControl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Q2Lab1RobotControl_M->solverInfo,
                          &Q2Lab1RobotControl_M->Timing.simTimeStep);
    rtsiSetTPtr(&Q2Lab1RobotControl_M->solverInfo, &rtmGetTPtr
                (Q2Lab1RobotControl_M));
    rtsiSetStepSizePtr(&Q2Lab1RobotControl_M->solverInfo,
                       &Q2Lab1RobotControl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Q2Lab1RobotControl_M->solverInfo, (&rtmGetErrorStatus
      (Q2Lab1RobotControl_M)));
    rtsiSetRTModelPtr(&Q2Lab1RobotControl_M->solverInfo, Q2Lab1RobotControl_M);
  }

  rtsiSetSimTimeStep(&Q2Lab1RobotControl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Q2Lab1RobotControl_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Q2Lab1RobotControl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Q2Lab1RobotControl_M points to
       static memory which is guaranteed to be non-NULL" */
    Q2Lab1RobotControl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Q2Lab1RobotControl_M->Timing.sampleTimes =
      (&Q2Lab1RobotControl_M->Timing.sampleTimesArray[0]);
    Q2Lab1RobotControl_M->Timing.offsetTimes =
      (&Q2Lab1RobotControl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Q2Lab1RobotControl_M->Timing.sampleTimes[0] = (0.0);
    Q2Lab1RobotControl_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Q2Lab1RobotControl_M->Timing.offsetTimes[0] = (0.0);
    Q2Lab1RobotControl_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Q2Lab1RobotControl_M, &Q2Lab1RobotControl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Q2Lab1RobotControl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Q2Lab1RobotControl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Q2Lab1RobotControl_M, 3.0);
  Q2Lab1RobotControl_M->Timing.stepSize0 = 0.001;
  Q2Lab1RobotControl_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Q2Lab1RobotControl_M->Sizes.checksums[0] = (109377525U);
  Q2Lab1RobotControl_M->Sizes.checksums[1] = (2292473037U);
  Q2Lab1RobotControl_M->Sizes.checksums[2] = (424089389U);
  Q2Lab1RobotControl_M->Sizes.checksums[3] = (3535429650U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Q2Lab1RobotControl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Q2Lab1RobotControl_M->extModeInfo,
      &Q2Lab1RobotControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Q2Lab1RobotControl_M->extModeInfo,
                        Q2Lab1RobotControl_M->Sizes.checksums);
    rteiSetTPtr(Q2Lab1RobotControl_M->extModeInfo, rtmGetTPtr
                (Q2Lab1RobotControl_M));
  }

  Q2Lab1RobotControl_M->solverInfoPtr = (&Q2Lab1RobotControl_M->solverInfo);
  Q2Lab1RobotControl_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Q2Lab1RobotControl_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Q2Lab1RobotControl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Q2Lab1RobotControl_M->blockIO = ((void *) &Q2Lab1RobotControl_B);
  (void) memset(((void *) &Q2Lab1RobotControl_B), 0,
                sizeof(B_Q2Lab1RobotControl_T));

  /* parameters */
  Q2Lab1RobotControl_M->defaultParam = ((real_T *)&Q2Lab1RobotControl_P);

  /* states (dwork) */
  Q2Lab1RobotControl_M->dwork = ((void *) &Q2Lab1RobotControl_DW);
  (void) memset((void *)&Q2Lab1RobotControl_DW, 0,
                sizeof(DW_Q2Lab1RobotControl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Q2Lab1RobotControl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Q2Lab1RobotControl_M->Sizes.numContStates = (0);/* Number of continuous states */
  Q2Lab1RobotControl_M->Sizes.numY = (0);/* Number of model outputs */
  Q2Lab1RobotControl_M->Sizes.numU = (0);/* Number of model inputs */
  Q2Lab1RobotControl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Q2Lab1RobotControl_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Q2Lab1RobotControl_M->Sizes.numBlocks = (17);/* Number of blocks */
  Q2Lab1RobotControl_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  Q2Lab1RobotControl_M->Sizes.numBlockPrms = (103);/* Sum of parameter "widths" */
  return Q2Lab1RobotControl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
