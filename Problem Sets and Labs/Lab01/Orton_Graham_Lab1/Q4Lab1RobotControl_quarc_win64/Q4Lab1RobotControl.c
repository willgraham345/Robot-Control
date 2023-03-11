/*
 * Q4Lab1RobotControl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Q4Lab1RobotControl".
 *
 * Model version              : 1.20
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Mar 11 13:59:56 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Q4Lab1RobotControl.h"
#include "Q4Lab1RobotControl_private.h"
#include "Q4Lab1RobotControl_dt.h"

/* Block signals (default storage) */
B_Q4Lab1RobotControl_T Q4Lab1RobotControl_B;

/* Continuous states */
X_Q4Lab1RobotControl_T Q4Lab1RobotControl_X;

/* Block states (default storage) */
DW_Q4Lab1RobotControl_T Q4Lab1RobotControl_DW;

/* Real-time model */
static RT_MODEL_Q4Lab1RobotControl_T Q4Lab1RobotControl_M_;
RT_MODEL_Q4Lab1RobotControl_T *const Q4Lab1RobotControl_M =
  &Q4Lab1RobotControl_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Q4Lab1RobotControl_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Q4Lab1RobotControl_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog;
  real_T rtb_CommandBias;
  real_T rtb_Derivative;
  real_T *lastU;
  if (rtmIsMajorTimeStep(Q4Lab1RobotControl_M)) {
    /* set solver stop time */
    if (!(Q4Lab1RobotControl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Q4Lab1RobotControl_M->solverInfo,
                            ((Q4Lab1RobotControl_M->Timing.clockTickH0 + 1) *
        Q4Lab1RobotControl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Q4Lab1RobotControl_M->solverInfo,
                            ((Q4Lab1RobotControl_M->Timing.clockTick0 + 1) *
        Q4Lab1RobotControl_M->Timing.stepSize0 +
        Q4Lab1RobotControl_M->Timing.clockTickH0 *
        Q4Lab1RobotControl_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Q4Lab1RobotControl_M)) {
    Q4Lab1RobotControl_M->Timing.t[0] = rtsiGetT
      (&Q4Lab1RobotControl_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Q4Lab1RobotControl_M)) {
  }

  /* Step: '<Root>/Step' */
  if (Q4Lab1RobotControl_M->Timing.t[0] < Q4Lab1RobotControl_P.Step_Time) {
    /* Step: '<Root>/Step' */
    Q4Lab1RobotControl_B.Step = Q4Lab1RobotControl_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    Q4Lab1RobotControl_B.Step = Q4Lab1RobotControl_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
  if (rtmIsMajorTimeStep(Q4Lab1RobotControl_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Q4Lab1RobotControl/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Q4Lab1RobotControl_DW.HILInitialize_Card,
        &Q4Lab1RobotControl_P.HILReadEncoder_channels, 1,
        &Q4Lab1RobotControl_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog = Q4Lab1RobotControl_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/Counts to rad [rad//count]' */
    Q4Lab1RobotControl_B.Countstoradradcount =
      Q4Lab1RobotControl_P.Countstoradradcount_Gain * rtb_HILReadAnalog;
  }

  /* Bias: '<Root>/Command Bias' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_CommandBias = (Q4Lab1RobotControl_B.Step -
                     Q4Lab1RobotControl_B.Countstoradradcount) +
    Q4Lab1RobotControl_P.CommandBias_Bias;

  /* Derivative: '<Root>/Derivative' */
  rtb_Derivative = Q4Lab1RobotControl_M->Timing.t[0];
  if ((Q4Lab1RobotControl_DW.TimeStampA >= rtb_Derivative) &&
      (Q4Lab1RobotControl_DW.TimeStampB >= rtb_Derivative)) {
    rtb_Derivative = 0.0;
  } else {
    real_T lastTime;
    lastTime = Q4Lab1RobotControl_DW.TimeStampA;
    lastU = &Q4Lab1RobotControl_DW.LastUAtTimeA;
    if (Q4Lab1RobotControl_DW.TimeStampA < Q4Lab1RobotControl_DW.TimeStampB) {
      if (Q4Lab1RobotControl_DW.TimeStampB < rtb_Derivative) {
        lastTime = Q4Lab1RobotControl_DW.TimeStampB;
        lastU = &Q4Lab1RobotControl_DW.LastUAtTimeB;
      }
    } else if (Q4Lab1RobotControl_DW.TimeStampA >= rtb_Derivative) {
      lastTime = Q4Lab1RobotControl_DW.TimeStampB;
      lastU = &Q4Lab1RobotControl_DW.LastUAtTimeB;
    }

    rtb_Derivative = (Q4Lab1RobotControl_B.Countstoradradcount - *lastU) /
      (rtb_Derivative - lastTime);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Gain: '<Root>/1//AmpGain [V//A]' incorporates:
   *  Gain: '<Root>/Kv'
   *  Gain: '<S39>/Proportional Gain'
   *  Integrator: '<S34>/Integrator'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S43>/Sum'
   */
  Q4Lab1RobotControl_B.uAmpGainVA = ((Q4Lab1RobotControl_P.PIDController_P *
    rtb_CommandBias + Q4Lab1RobotControl_X.Integrator_CSTATE) -
    Q4Lab1RobotControl_P.Kv_Gain * rtb_Derivative) *
    Q4Lab1RobotControl_P.uAmpGainVA_Gain;
  if (rtmIsMajorTimeStep(Q4Lab1RobotControl_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Q4Lab1RobotControl/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Q4Lab1RobotControl_DW.HILInitialize_Card,
        &Q4Lab1RobotControl_P.HILWriteAnalog_channels, 1,
        &Q4Lab1RobotControl_B.uAmpGainVA);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
      }
    }

    /* Gain: '<S2>/Gain' */
    Q4Lab1RobotControl_B.Gain = Q4Lab1RobotControl_P.Gain_Gain *
      Q4Lab1RobotControl_B.Countstoradradcount;
  }

  /* Gain: '<S31>/Integral Gain' */
  Q4Lab1RobotControl_B.IntegralGain = Q4Lab1RobotControl_P.PIDController_I *
    rtb_CommandBias;
  if (rtmIsMajorTimeStep(Q4Lab1RobotControl_M)) {
    /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

    /* S-Function Block: Q4Lab1RobotControl/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(Q4Lab1RobotControl_DW.HILInitialize_Card,
        &Q4Lab1RobotControl_P.HILReadAnalog_channels, 1,
        &Q4Lab1RobotControl_DW.HILReadAnalog_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
      }

      rtb_HILReadAnalog = Q4Lab1RobotControl_DW.HILReadAnalog_Buffer;
    }

    /* Bias: '<Root>/Sense Bias' incorporates:
     *  Gain: '<Root>/1//SenseGain [A//V]'
     */
    Q4Lab1RobotControl_B.SenseBias = Q4Lab1RobotControl_P.uSenseGainAV_Gain *
      rtb_HILReadAnalog + Q4Lab1RobotControl_P.SenseBias_Bias;
  }
}

/* Model update function */
void Q4Lab1RobotControl_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (Q4Lab1RobotControl_DW.TimeStampA == (rtInf)) {
    Q4Lab1RobotControl_DW.TimeStampA = Q4Lab1RobotControl_M->Timing.t[0];
    lastU = &Q4Lab1RobotControl_DW.LastUAtTimeA;
  } else if (Q4Lab1RobotControl_DW.TimeStampB == (rtInf)) {
    Q4Lab1RobotControl_DW.TimeStampB = Q4Lab1RobotControl_M->Timing.t[0];
    lastU = &Q4Lab1RobotControl_DW.LastUAtTimeB;
  } else if (Q4Lab1RobotControl_DW.TimeStampA < Q4Lab1RobotControl_DW.TimeStampB)
  {
    Q4Lab1RobotControl_DW.TimeStampA = Q4Lab1RobotControl_M->Timing.t[0];
    lastU = &Q4Lab1RobotControl_DW.LastUAtTimeA;
  } else {
    Q4Lab1RobotControl_DW.TimeStampB = Q4Lab1RobotControl_M->Timing.t[0];
    lastU = &Q4Lab1RobotControl_DW.LastUAtTimeB;
  }

  *lastU = Q4Lab1RobotControl_B.Countstoradradcount;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(Q4Lab1RobotControl_M)) {
    rt_ertODEUpdateContinuousStates(&Q4Lab1RobotControl_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Q4Lab1RobotControl_M->Timing.clockTick0)) {
    ++Q4Lab1RobotControl_M->Timing.clockTickH0;
  }

  Q4Lab1RobotControl_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Q4Lab1RobotControl_M->solverInfo);

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
    if (!(++Q4Lab1RobotControl_M->Timing.clockTick1)) {
      ++Q4Lab1RobotControl_M->Timing.clockTickH1;
    }

    Q4Lab1RobotControl_M->Timing.t[1] = Q4Lab1RobotControl_M->Timing.clockTick1 *
      Q4Lab1RobotControl_M->Timing.stepSize1 +
      Q4Lab1RobotControl_M->Timing.clockTickH1 *
      Q4Lab1RobotControl_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Q4Lab1RobotControl_derivatives(void)
{
  XDot_Q4Lab1RobotControl_T *_rtXdot;
  _rtXdot = ((XDot_Q4Lab1RobotControl_T *) Q4Lab1RobotControl_M->derivs);

  /* Derivatives for Integrator: '<S34>/Integrator' */
  _rtXdot->Integrator_CSTATE = Q4Lab1RobotControl_B.IntegralGain;
}

/* Model initialize function */
void Q4Lab1RobotControl_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Q4Lab1RobotControl/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Q4Lab1RobotControl_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Q4Lab1RobotControl_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Q4Lab1RobotControl_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
      return;
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_AIPStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Q4Lab1RobotControl_DW.HILInitialize_AIMinimums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (Q4Lab1RobotControl_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Q4Lab1RobotControl_DW.HILInitialize_AIMaximums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Q4Lab1RobotControl_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Q4Lab1RobotControl_DW.HILInitialize_Card,
         Q4Lab1RobotControl_P.HILInitialize_AIChannels, 8U,
         &Q4Lab1RobotControl_DW.HILInitialize_AIMinimums[0],
         &Q4Lab1RobotControl_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_AOPStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (Q4Lab1RobotControl_DW.HILInitialize_Card,
         &Q4Lab1RobotControl_P.HILInitialize_AOChannels, 1U,
         &Q4Lab1RobotControl_P.HILInitialize_AOLow,
         &Q4Lab1RobotControl_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_AOStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Q4Lab1RobotControl_DW.HILInitialize_Card,
        &Q4Lab1RobotControl_P.HILInitialize_AOChannels, 1U,
        &Q4Lab1RobotControl_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if (Q4Lab1RobotControl_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Q4Lab1RobotControl_DW.HILInitialize_Card,
         &Q4Lab1RobotControl_P.HILInitialize_AOChannels, 1U,
         &Q4Lab1RobotControl_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_EIPStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Q4Lab1RobotControl_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            Q4Lab1RobotControl_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (Q4Lab1RobotControl_DW.HILInitialize_Card,
         Q4Lab1RobotControl_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &Q4Lab1RobotControl_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_EIStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Q4Lab1RobotControl_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Q4Lab1RobotControl_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Q4Lab1RobotControl_DW.HILInitialize_Card,
        Q4Lab1RobotControl_P.HILInitialize_EIChannels, 8U,
        &Q4Lab1RobotControl_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_POPStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Q4Lab1RobotControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Q4Lab1RobotControl_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(Q4Lab1RobotControl_DW.HILInitialize_Card,
        Q4Lab1RobotControl_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Q4Lab1RobotControl_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Q4Lab1RobotControl_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &Q4Lab1RobotControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Q4Lab1RobotControl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            Q4Lab1RobotControl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Q4Lab1RobotControl_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Q4Lab1RobotControl_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            Q4Lab1RobotControl_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Q4Lab1RobotControl_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Q4Lab1RobotControl_DW.HILInitialize_Card,
          &Q4Lab1RobotControl_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &Q4Lab1RobotControl_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Q4Lab1RobotControl_DW.HILInitialize_Card,
          &Q4Lab1RobotControl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Q4Lab1RobotControl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Q4Lab1RobotControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Q4Lab1RobotControl_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Q4Lab1RobotControl_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Q4Lab1RobotControl_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Q4Lab1RobotControl_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Q4Lab1RobotControl_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (Q4Lab1RobotControl_DW.HILInitialize_Card,
         Q4Lab1RobotControl_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &Q4Lab1RobotControl_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *) &Q4Lab1RobotControl_DW.HILInitialize_POAlignValues
         [0],
         (t_pwm_polarity *) &Q4Lab1RobotControl_DW.HILInitialize_POPolarityVals
         [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &Q4Lab1RobotControl_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Q4Lab1RobotControl_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Q4Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q4Lab1RobotControl_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(Q4Lab1RobotControl_DW.HILInitialize_Card,
        Q4Lab1RobotControl_P.HILInitialize_POChannels, 8U,
        &Q4Lab1RobotControl_DW.HILInitialize_POSortedFreqs[0],
        &Q4Lab1RobotControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_POStart && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Q4Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q4Lab1RobotControl_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Q4Lab1RobotControl_DW.HILInitialize_Card,
        Q4Lab1RobotControl_P.HILInitialize_POChannels, 8U,
        &Q4Lab1RobotControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }

    if (Q4Lab1RobotControl_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Q4Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q4Lab1RobotControl_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Q4Lab1RobotControl_DW.HILInitialize_Card,
         Q4Lab1RobotControl_P.HILInitialize_POChannels, 8U,
         &Q4Lab1RobotControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<S34>/Integrator' */
  Q4Lab1RobotControl_X.Integrator_CSTATE =
    Q4Lab1RobotControl_P.PIDController_InitialConditionF;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Q4Lab1RobotControl_DW.TimeStampA = (rtInf);
  Q4Lab1RobotControl_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void Q4Lab1RobotControl_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Q4Lab1RobotControl/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Q4Lab1RobotControl_DW.HILInitialize_Card);
    hil_monitor_stop_all(Q4Lab1RobotControl_DW.HILInitialize_Card);
    is_switching = false;
    if ((Q4Lab1RobotControl_P.HILInitialize_AOTerminate && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Q4Lab1RobotControl_P.HILInitialize_POTerminate && !is_switching) ||
        (Q4Lab1RobotControl_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Q4Lab1RobotControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Q4Lab1RobotControl_P.HILInitialize_POFinal;
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
      result = hil_write(Q4Lab1RobotControl_DW.HILInitialize_Card
                         , &Q4Lab1RobotControl_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , Q4Lab1RobotControl_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Q4Lab1RobotControl_P.HILInitialize_AOFinal
                         , &Q4Lab1RobotControl_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Q4Lab1RobotControl_DW.HILInitialize_Card,
             &Q4Lab1RobotControl_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &Q4Lab1RobotControl_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Q4Lab1RobotControl_DW.HILInitialize_Card,
            Q4Lab1RobotControl_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Q4Lab1RobotControl_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Q4Lab1RobotControl_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Q4Lab1RobotControl_DW.HILInitialize_Card);
    hil_monitor_delete_all(Q4Lab1RobotControl_DW.HILInitialize_Card);
    hil_close(Q4Lab1RobotControl_DW.HILInitialize_Card);
    Q4Lab1RobotControl_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Q4Lab1RobotControl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Q4Lab1RobotControl_update();
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
  Q4Lab1RobotControl_initialize();
}

void MdlTerminate(void)
{
  Q4Lab1RobotControl_terminate();
}

/* Registration function */
RT_MODEL_Q4Lab1RobotControl_T *Q4Lab1RobotControl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Q4Lab1RobotControl_M, 0,
                sizeof(RT_MODEL_Q4Lab1RobotControl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Q4Lab1RobotControl_M->solverInfo,
                          &Q4Lab1RobotControl_M->Timing.simTimeStep);
    rtsiSetTPtr(&Q4Lab1RobotControl_M->solverInfo, &rtmGetTPtr
                (Q4Lab1RobotControl_M));
    rtsiSetStepSizePtr(&Q4Lab1RobotControl_M->solverInfo,
                       &Q4Lab1RobotControl_M->Timing.stepSize0);
    rtsiSetdXPtr(&Q4Lab1RobotControl_M->solverInfo,
                 &Q4Lab1RobotControl_M->derivs);
    rtsiSetContStatesPtr(&Q4Lab1RobotControl_M->solverInfo, (real_T **)
                         &Q4Lab1RobotControl_M->contStates);
    rtsiSetNumContStatesPtr(&Q4Lab1RobotControl_M->solverInfo,
      &Q4Lab1RobotControl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Q4Lab1RobotControl_M->solverInfo,
      &Q4Lab1RobotControl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Q4Lab1RobotControl_M->solverInfo,
      &Q4Lab1RobotControl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Q4Lab1RobotControl_M->solverInfo,
      &Q4Lab1RobotControl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Q4Lab1RobotControl_M->solverInfo, (&rtmGetErrorStatus
      (Q4Lab1RobotControl_M)));
    rtsiSetRTModelPtr(&Q4Lab1RobotControl_M->solverInfo, Q4Lab1RobotControl_M);
  }

  rtsiSetSimTimeStep(&Q4Lab1RobotControl_M->solverInfo, MAJOR_TIME_STEP);
  Q4Lab1RobotControl_M->intgData.f[0] = Q4Lab1RobotControl_M->odeF[0];
  Q4Lab1RobotControl_M->contStates = ((real_T *) &Q4Lab1RobotControl_X);
  rtsiSetSolverData(&Q4Lab1RobotControl_M->solverInfo, (void *)
                    &Q4Lab1RobotControl_M->intgData);
  rtsiSetSolverName(&Q4Lab1RobotControl_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Q4Lab1RobotControl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Q4Lab1RobotControl_M points to
       static memory which is guaranteed to be non-NULL" */
    Q4Lab1RobotControl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Q4Lab1RobotControl_M->Timing.sampleTimes =
      (&Q4Lab1RobotControl_M->Timing.sampleTimesArray[0]);
    Q4Lab1RobotControl_M->Timing.offsetTimes =
      (&Q4Lab1RobotControl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Q4Lab1RobotControl_M->Timing.sampleTimes[0] = (0.0);
    Q4Lab1RobotControl_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Q4Lab1RobotControl_M->Timing.offsetTimes[0] = (0.0);
    Q4Lab1RobotControl_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Q4Lab1RobotControl_M, &Q4Lab1RobotControl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Q4Lab1RobotControl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Q4Lab1RobotControl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Q4Lab1RobotControl_M, 3.0);
  Q4Lab1RobotControl_M->Timing.stepSize0 = 0.001;
  Q4Lab1RobotControl_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Q4Lab1RobotControl_M->Sizes.checksums[0] = (1206798417U);
  Q4Lab1RobotControl_M->Sizes.checksums[1] = (2747399878U);
  Q4Lab1RobotControl_M->Sizes.checksums[2] = (2066181671U);
  Q4Lab1RobotControl_M->Sizes.checksums[3] = (2172409586U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Q4Lab1RobotControl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Q4Lab1RobotControl_M->extModeInfo,
      &Q4Lab1RobotControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Q4Lab1RobotControl_M->extModeInfo,
                        Q4Lab1RobotControl_M->Sizes.checksums);
    rteiSetTPtr(Q4Lab1RobotControl_M->extModeInfo, rtmGetTPtr
                (Q4Lab1RobotControl_M));
  }

  Q4Lab1RobotControl_M->solverInfoPtr = (&Q4Lab1RobotControl_M->solverInfo);
  Q4Lab1RobotControl_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Q4Lab1RobotControl_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Q4Lab1RobotControl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Q4Lab1RobotControl_M->blockIO = ((void *) &Q4Lab1RobotControl_B);
  (void) memset(((void *) &Q4Lab1RobotControl_B), 0,
                sizeof(B_Q4Lab1RobotControl_T));

  /* parameters */
  Q4Lab1RobotControl_M->defaultParam = ((real_T *)&Q4Lab1RobotControl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Q4Lab1RobotControl_X;
    Q4Lab1RobotControl_M->contStates = (x);
    (void) memset((void *)&Q4Lab1RobotControl_X, 0,
                  sizeof(X_Q4Lab1RobotControl_T));
  }

  /* states (dwork) */
  Q4Lab1RobotControl_M->dwork = ((void *) &Q4Lab1RobotControl_DW);
  (void) memset((void *)&Q4Lab1RobotControl_DW, 0,
                sizeof(DW_Q4Lab1RobotControl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Q4Lab1RobotControl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Q4Lab1RobotControl_M->Sizes.numContStates = (1);/* Number of continuous states */
  Q4Lab1RobotControl_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Q4Lab1RobotControl_M->Sizes.numY = (0);/* Number of model outputs */
  Q4Lab1RobotControl_M->Sizes.numU = (0);/* Number of model inputs */
  Q4Lab1RobotControl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Q4Lab1RobotControl_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Q4Lab1RobotControl_M->Sizes.numBlocks = (23);/* Number of blocks */
  Q4Lab1RobotControl_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  Q4Lab1RobotControl_M->Sizes.numBlockPrms = (106);/* Sum of parameter "widths" */
  return Q4Lab1RobotControl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
