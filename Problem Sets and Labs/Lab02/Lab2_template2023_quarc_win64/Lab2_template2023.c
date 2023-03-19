/*
 * Lab2_template2023.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab2_template2023".
 *
 * Model version              : 8.3
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 16 11:48:29 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab2_template2023.h"
#include "Lab2_template2023_private.h"
#include "Lab2_template2023_dt.h"

/* Block signals (default storage) */
B_Lab2_template2023_T Lab2_template2023_B;

/* Continuous states */
X_Lab2_template2023_T Lab2_template2023_X;

/* Block states (default storage) */
DW_Lab2_template2023_T Lab2_template2023_DW;

/* Real-time model */
static RT_MODEL_Lab2_template2023_T Lab2_template2023_M_;
RT_MODEL_Lab2_template2023_T *const Lab2_template2023_M = &Lab2_template2023_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Lab2_template2023_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Lab2_template2023_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Lab2_template2023_M->Timing.TaskCounters.TID[1] == 0) {
    Lab2_template2023_M->Timing.RateInteraction.TID1_2 =
      (Lab2_template2023_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Lab2_template2023_M->Timing.perTaskSampleHits[5] =
      Lab2_template2023_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Lab2_template2023_M->Timing.TaskCounters.TID[2])++;
  if ((Lab2_template2023_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    Lab2_template2023_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Lab2_template2023_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function for TID0 */
void Lab2_template2023_output0(void)   /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T rtb_Clock;
  real_T theta_idx_0;
  if (rtmIsMajorTimeStep(Lab2_template2023_M)) {
    /* set solver stop time */
    if (!(Lab2_template2023_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Lab2_template2023_M->solverInfo,
                            ((Lab2_template2023_M->Timing.clockTickH0 + 1) *
        Lab2_template2023_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Lab2_template2023_M->solverInfo,
                            ((Lab2_template2023_M->Timing.clockTick0 + 1) *
        Lab2_template2023_M->Timing.stepSize0 +
        Lab2_template2023_M->Timing.clockTickH0 *
        Lab2_template2023_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab2_template2023_M)) {
    Lab2_template2023_M->Timing.t[0] = rtsiGetT(&Lab2_template2023_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab2_template2023_M)) {
    /* S-Function (hil_read_encoder_block): '<S4>/HIL Read Encoder' */

    /* S-Function Block: Lab2_template2023/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILReadEncoder_channels, 2,
        &Lab2_template2023_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = Lab2_template2023_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = Lab2_template2023_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S4>/Encoder Gain' incorporates:
     *  Constant: '<S4>/Home Position'
     *  Sum: '<S4>/Sum1'
     */
    Lab2_template2023_B.EncoderGain[0] =
      (Lab2_template2023_P.HomePosition_Value[0] + rtb_HILReadAnalog[0]) *
      Lab2_template2023_P.EncoderGain_Gain[0];
    Lab2_template2023_B.EncoderGain[1] =
      (Lab2_template2023_P.HomePosition_Value[1] + rtb_HILReadAnalog[1]) *
      Lab2_template2023_P.EncoderGain_Gain[1];
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Lab2_template2023_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Constant: '<Root>/Speed'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S5>:1' */
  if (rtb_Clock < 1.0) {
    /* '<S5>:1:6' */
    /* '<S5>:1:7' */
    rtb_Clock = (1.0 - cos(3.1415926535897931 * rtb_Clock)) * 0.025;
    Lab2_template2023_B.x[0] = rtb_Clock + 0.15;

    /* '<S5>:1:8' */
    Lab2_template2023_B.x[1] = 0.15 - rtb_Clock;
  } else if (rtb_Clock < 1.5) {
    /* '<S5>:1:9' */
    /* '<S5>:1:10' */
    rtb_Clock = (rtb_Clock - 1.0) * (rtb_Clock - 1.0) * (6.2831853071795862 *
      Lab2_template2023_P.Speed_Value);
    Lab2_template2023_B.x[0] = cos(rtb_Clock) * 0.075 + 0.125;

    /* '<S5>:1:11' */
    Lab2_template2023_B.x[1] = sin(rtb_Clock) * 0.075 + 0.1;
  } else {
    /* '<S5>:1:13' */
    rtb_Clock = 6.2831853071795862 * Lab2_template2023_P.Speed_Value *
      (rtb_Clock - 1.25);
    Lab2_template2023_B.x[0] = cos(rtb_Clock) * 0.075 + 0.125;

    /* '<S5>:1:14' */
    Lab2_template2023_B.x[1] = sin(rtb_Clock) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  /* MATLAB Function 'Inverse Kinematics': '<S2>:1' */
  /* '<S2>:1:10' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:8' */
  rtb_Clock = Lab2_template2023_B.x[0] * Lab2_template2023_B.x[0] +
    Lab2_template2023_B.x[1] * Lab2_template2023_B.x[1];
  rtb_Clock = atan(sqrt((0.09 - rtb_Clock) / rtb_Clock)) * -2.0;

  /* '<S2>:1:9' */
  theta_idx_0 = rt_atan2d_snf(Lab2_template2023_B.x[1], Lab2_template2023_B.x[0])
    - rt_atan2d_snf(0.15 * sin(rtb_Clock), 0.15 * cos(rtb_Clock) + 0.15);

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S4>/Encoder Gain'
   *  MATLAB Function: '<Root>/Inverse Kinematics'
   */
  /* '<S2>:1:10' */
  Lab2_template2023_B.Sum[0] = (0.0 * rtb_Clock + theta_idx_0) -
    Lab2_template2023_B.EncoderGain[0];

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S33>/SumD'
   */
  Lab2_template2023_B.FilterCoefficient[0] =
    (Lab2_template2023_P.PDController_D[0] * Lab2_template2023_B.Sum[0] -
     Lab2_template2023_X.Filter_CSTATE[0]) * Lab2_template2023_P.PDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S41>/Filter Coefficient'
   *  Gain: '<S43>/Proportional Gain'
   *  Sum: '<Root>/Sum'
   */
  Lab2_template2023_B.Sum_b[0] = Lab2_template2023_P.PDController_P[0] *
    Lab2_template2023_B.Sum[0] + Lab2_template2023_B.FilterCoefficient[0];

  /* Gain: '<S4>/1//AmpGain' incorporates:
   *  Bias: '<S4>/Amp Bias Tune for each  amp//channel if needed'
   *  Sum: '<S47>/Sum'
   */
  Lab2_template2023_B.uAmpGain[0] = (Lab2_template2023_B.Sum_b[0] +
    Lab2_template2023_P.AmpBiasTuneforeachampchannelifn[0]) *
    Lab2_template2023_P.uAmpGain_Gain[0];

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S4>/Encoder Gain'
   *  MATLAB Function: '<Root>/Inverse Kinematics'
   */
  Lab2_template2023_B.Sum[1] = (theta_idx_0 + rtb_Clock) -
    Lab2_template2023_B.EncoderGain[1];

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S33>/SumD'
   */
  Lab2_template2023_B.FilterCoefficient[1] =
    (Lab2_template2023_P.PDController_D[1] * Lab2_template2023_B.Sum[1] -
     Lab2_template2023_X.Filter_CSTATE[1]) * Lab2_template2023_P.PDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S41>/Filter Coefficient'
   *  Gain: '<S43>/Proportional Gain'
   *  Sum: '<Root>/Sum'
   */
  Lab2_template2023_B.Sum_b[1] = Lab2_template2023_P.PDController_P[1] *
    Lab2_template2023_B.Sum[1] + Lab2_template2023_B.FilterCoefficient[1];

  /* Gain: '<S4>/1//AmpGain' incorporates:
   *  Bias: '<S4>/Amp Bias Tune for each  amp//channel if needed'
   *  Sum: '<S47>/Sum'
   */
  Lab2_template2023_B.uAmpGain[1] = (Lab2_template2023_B.Sum_b[1] +
    Lab2_template2023_P.AmpBiasTuneforeachampchannelifn[1]) *
    Lab2_template2023_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(Lab2_template2023_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: Lab2_template2023/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILWriteAnalog_channels, 2,
        &Lab2_template2023_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S4>/HIL Read Analog' */

    /* S-Function Block: Lab2_template2023/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
      }
    }

    /* Bias: '<S4>/Current Sense Bias Tune for each amp//channel if needed' incorporates:
     *  Gain: '<S4>/1//Sense Gain'
     */
    Lab2_template2023_B.CurrentSenseBiasTuneforeachampc[0] =
      Lab2_template2023_P.uSenseGain_Gain * rtb_HILReadAnalog[0] +
      Lab2_template2023_P.CurrentSenseBiasTuneforeachampc[0];
    Lab2_template2023_B.CurrentSenseBiasTuneforeachampc[1] =
      Lab2_template2023_P.uSenseGain_Gain * rtb_HILReadAnalog[1] +
      Lab2_template2023_P.CurrentSenseBiasTuneforeachampc[1];

    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S4>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S1>:1' */
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    /* '<S1>:1:7' */
    Lab2_template2023_B.x_b[0] = 0.15 * cos(Lab2_template2023_B.EncoderGain[0])
      + 0.15 * cos(Lab2_template2023_B.EncoderGain[1]);

    /* '<S1>:1:8' */
    Lab2_template2023_B.x_b[1] = 0.15 * sin(Lab2_template2023_B.EncoderGain[0])
      + 0.15 * sin(Lab2_template2023_B.EncoderGain[1]);

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S4>/Encoder Gain'
     */
    if (Lab2_template2023_M->Timing.RateInteraction.TID1_2) {
      Lab2_template2023_DW.RateTransition_Buffer[0] =
        Lab2_template2023_B.EncoderGain[0];
      Lab2_template2023_DW.RateTransition_Buffer[1] =
        Lab2_template2023_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void Lab2_template2023_update0(void)   /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Lab2_template2023_M)) {
    rt_ertODEUpdateContinuousStates(&Lab2_template2023_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab2_template2023_M->Timing.clockTick0)) {
    ++Lab2_template2023_M->Timing.clockTickH0;
  }

  Lab2_template2023_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Lab2_template2023_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab2_template2023_M->Timing.clockTick1)) {
    ++Lab2_template2023_M->Timing.clockTickH1;
  }

  Lab2_template2023_M->Timing.t[1] = Lab2_template2023_M->Timing.clockTick1 *
    Lab2_template2023_M->Timing.stepSize1 +
    Lab2_template2023_M->Timing.clockTickH1 *
    Lab2_template2023_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Lab2_template2023_derivatives(void)
{
  XDot_Lab2_template2023_T *_rtXdot;
  _rtXdot = ((XDot_Lab2_template2023_T *) Lab2_template2023_M->derivs);

  /* Derivatives for Integrator: '<S33>/Filter' incorporates:
   *  Gain: '<S41>/Filter Coefficient'
   */
  _rtXdot->Filter_CSTATE[0] = Lab2_template2023_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = Lab2_template2023_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void Lab2_template2023_output2(void)   /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  Lab2_template2023_B.RateTransition[0] =
    Lab2_template2023_DW.RateTransition_Buffer[0];
  Lab2_template2023_B.RateTransition[1] =
    Lab2_template2023_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void Lab2_template2023_update2(void)   /* Sample time: [0.02s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab2_template2023_M->Timing.clockTick2)) {
    ++Lab2_template2023_M->Timing.clockTickH2;
  }

  Lab2_template2023_M->Timing.t[2] = Lab2_template2023_M->Timing.clockTick2 *
    Lab2_template2023_M->Timing.stepSize2 +
    Lab2_template2023_M->Timing.clockTickH2 *
    Lab2_template2023_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Lab2_template2023_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Lab2_template2023_output0();
    break;

   case 2 :
    Lab2_template2023_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Lab2_template2023_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Lab2_template2023_update0();
    break;

   case 2 :
    Lab2_template2023_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Lab2_template2023_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: Lab2_template2023/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Lab2_template2023_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Lab2_template2023_DW.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Lab2_template2023_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
      return;
    }

    if ((Lab2_template2023_P.HILInitialize_AIPStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Lab2_template2023_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (Lab2_template2023_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Lab2_template2023_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Lab2_template2023_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (Lab2_template2023_DW.HILInitialize_Card,
         Lab2_template2023_P.HILInitialize_AIChannels, 8U,
         &Lab2_template2023_DW.HILInitialize_AIMinimums[0],
         &Lab2_template2023_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if ((Lab2_template2023_P.HILInitialize_AOPStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Lab2_template2023_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (Lab2_template2023_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Lab2_template2023_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Lab2_template2023_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (Lab2_template2023_DW.HILInitialize_Card,
         Lab2_template2023_P.HILInitialize_AOChannels, 8U,
         &Lab2_template2023_DW.HILInitialize_AOMinimums[0],
         &Lab2_template2023_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if ((Lab2_template2023_P.HILInitialize_AOStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab2_template2023_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab2_template2023_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILInitialize_AOChannels, 8U,
        &Lab2_template2023_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if (Lab2_template2023_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab2_template2023_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab2_template2023_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Lab2_template2023_DW.HILInitialize_Card,
         Lab2_template2023_P.HILInitialize_AOChannels, 8U,
         &Lab2_template2023_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if ((Lab2_template2023_P.HILInitialize_EIPStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Lab2_template2023_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            Lab2_template2023_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (Lab2_template2023_DW.HILInitialize_Card,
         Lab2_template2023_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &Lab2_template2023_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if ((Lab2_template2023_P.HILInitialize_EIStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Lab2_template2023_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Lab2_template2023_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILInitialize_EIChannels, 8U,
        &Lab2_template2023_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if ((Lab2_template2023_P.HILInitialize_POPStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Lab2_template2023_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Lab2_template2023_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &Lab2_template2023_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          Lab2_template2023_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &Lab2_template2023_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            Lab2_template2023_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            Lab2_template2023_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Lab2_template2023_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            Lab2_template2023_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            Lab2_template2023_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Lab2_template2023_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Lab2_template2023_DW.HILInitialize_Card,
          &Lab2_template2023_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &Lab2_template2023_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Lab2_template2023_DW.HILInitialize_Card,
          &Lab2_template2023_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Lab2_template2023_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Lab2_template2023_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Lab2_template2023_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Lab2_template2023_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Lab2_template2023_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Lab2_template2023_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Lab2_template2023_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *)
        &Lab2_template2023_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Lab2_template2023_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Lab2_template2023_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &Lab2_template2023_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Lab2_template2023_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Lab2_template2023_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab2_template2023_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILInitialize_POChannels, 8U,
        &Lab2_template2023_DW.HILInitialize_POSortedFreqs[0],
        &Lab2_template2023_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if ((Lab2_template2023_P.HILInitialize_POStart && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab2_template2023_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab2_template2023_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(Lab2_template2023_DW.HILInitialize_Card,
        Lab2_template2023_P.HILInitialize_POChannels, 8U,
        &Lab2_template2023_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }

    if (Lab2_template2023_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab2_template2023_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab2_template2023_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Lab2_template2023_DW.HILInitialize_Card,
         Lab2_template2023_P.HILInitialize_POChannels, 8U,
         &Lab2_template2023_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  Lab2_template2023_X.Filter_CSTATE[0] =
    Lab2_template2023_P.PDController_InitialConditionFo;
  Lab2_template2023_X.Filter_CSTATE[1] =
    Lab2_template2023_P.PDController_InitialConditionFo;
}

/* Model terminate function */
void Lab2_template2023_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: Lab2_template2023/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Lab2_template2023_DW.HILInitialize_Card);
    hil_monitor_stop_all(Lab2_template2023_DW.HILInitialize_Card);
    is_switching = false;
    if ((Lab2_template2023_P.HILInitialize_AOTerminate && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab2_template2023_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab2_template2023_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Lab2_template2023_P.HILInitialize_POTerminate && !is_switching) ||
        (Lab2_template2023_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab2_template2023_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab2_template2023_P.HILInitialize_POFinal;
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
      result = hil_write(Lab2_template2023_DW.HILInitialize_Card
                         , Lab2_template2023_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , Lab2_template2023_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Lab2_template2023_DW.HILInitialize_AOVoltages[0]
                         , &Lab2_template2023_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Lab2_template2023_DW.HILInitialize_Card,
             Lab2_template2023_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &Lab2_template2023_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Lab2_template2023_DW.HILInitialize_Card,
            Lab2_template2023_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &Lab2_template2023_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab2_template2023_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Lab2_template2023_DW.HILInitialize_Card);
    hil_monitor_delete_all(Lab2_template2023_DW.HILInitialize_Card);
    hil_close(Lab2_template2023_DW.HILInitialize_Card);
    Lab2_template2023_DW.HILInitialize_Card = NULL;
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
  if (tid == 1)
    tid = 0;
  Lab2_template2023_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Lab2_template2023_update(tid);
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
  Lab2_template2023_initialize();
}

void MdlTerminate(void)
{
  Lab2_template2023_terminate();
}

/* Registration function */
RT_MODEL_Lab2_template2023_T *Lab2_template2023(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab2_template2023_M, 0,
                sizeof(RT_MODEL_Lab2_template2023_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab2_template2023_M->solverInfo,
                          &Lab2_template2023_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab2_template2023_M->solverInfo, &rtmGetTPtr
                (Lab2_template2023_M));
    rtsiSetStepSizePtr(&Lab2_template2023_M->solverInfo,
                       &Lab2_template2023_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab2_template2023_M->solverInfo, &Lab2_template2023_M->derivs);
    rtsiSetContStatesPtr(&Lab2_template2023_M->solverInfo, (real_T **)
                         &Lab2_template2023_M->contStates);
    rtsiSetNumContStatesPtr(&Lab2_template2023_M->solverInfo,
      &Lab2_template2023_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Lab2_template2023_M->solverInfo,
      &Lab2_template2023_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Lab2_template2023_M->solverInfo,
      &Lab2_template2023_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Lab2_template2023_M->solverInfo,
      &Lab2_template2023_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Lab2_template2023_M->solverInfo, (&rtmGetErrorStatus
      (Lab2_template2023_M)));
    rtsiSetRTModelPtr(&Lab2_template2023_M->solverInfo, Lab2_template2023_M);
  }

  rtsiSetSimTimeStep(&Lab2_template2023_M->solverInfo, MAJOR_TIME_STEP);
  Lab2_template2023_M->intgData.f[0] = Lab2_template2023_M->odeF[0];
  Lab2_template2023_M->contStates = ((real_T *) &Lab2_template2023_X);
  rtsiSetSolverData(&Lab2_template2023_M->solverInfo, (void *)
                    &Lab2_template2023_M->intgData);
  rtsiSetSolverName(&Lab2_template2023_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab2_template2023_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Lab2_template2023_M points to
       static memory which is guaranteed to be non-NULL" */
    Lab2_template2023_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab2_template2023_M->Timing.sampleTimes =
      (&Lab2_template2023_M->Timing.sampleTimesArray[0]);
    Lab2_template2023_M->Timing.offsetTimes =
      (&Lab2_template2023_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab2_template2023_M->Timing.sampleTimes[0] = (0.0);
    Lab2_template2023_M->Timing.sampleTimes[1] = (0.001);
    Lab2_template2023_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    Lab2_template2023_M->Timing.offsetTimes[0] = (0.0);
    Lab2_template2023_M->Timing.offsetTimes[1] = (0.0);
    Lab2_template2023_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Lab2_template2023_M, &Lab2_template2023_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab2_template2023_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Lab2_template2023_M->Timing.perTaskSampleHitsArray;
    Lab2_template2023_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Lab2_template2023_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab2_template2023_M, 10.0);
  Lab2_template2023_M->Timing.stepSize0 = 0.001;
  Lab2_template2023_M->Timing.stepSize1 = 0.001;
  Lab2_template2023_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  Lab2_template2023_M->Sizes.checksums[0] = (2948296055U);
  Lab2_template2023_M->Sizes.checksums[1] = (499376397U);
  Lab2_template2023_M->Sizes.checksums[2] = (4132013352U);
  Lab2_template2023_M->Sizes.checksums[3] = (2760775297U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Lab2_template2023_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lab2_template2023_M->extModeInfo,
      &Lab2_template2023_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lab2_template2023_M->extModeInfo,
                        Lab2_template2023_M->Sizes.checksums);
    rteiSetTPtr(Lab2_template2023_M->extModeInfo, rtmGetTPtr(Lab2_template2023_M));
  }

  Lab2_template2023_M->solverInfoPtr = (&Lab2_template2023_M->solverInfo);
  Lab2_template2023_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab2_template2023_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab2_template2023_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Lab2_template2023_M->blockIO = ((void *) &Lab2_template2023_B);

  {
    Lab2_template2023_B.EncoderGain[0] = 0.0;
    Lab2_template2023_B.EncoderGain[1] = 0.0;
    Lab2_template2023_B.Sum[0] = 0.0;
    Lab2_template2023_B.Sum[1] = 0.0;
    Lab2_template2023_B.FilterCoefficient[0] = 0.0;
    Lab2_template2023_B.FilterCoefficient[1] = 0.0;
    Lab2_template2023_B.Sum_b[0] = 0.0;
    Lab2_template2023_B.Sum_b[1] = 0.0;
    Lab2_template2023_B.uAmpGain[0] = 0.0;
    Lab2_template2023_B.uAmpGain[1] = 0.0;
    Lab2_template2023_B.CurrentSenseBiasTuneforeachampc[0] = 0.0;
    Lab2_template2023_B.CurrentSenseBiasTuneforeachampc[1] = 0.0;
    Lab2_template2023_B.RateTransition[0] = 0.0;
    Lab2_template2023_B.RateTransition[1] = 0.0;
    Lab2_template2023_B.x[0] = 0.0;
    Lab2_template2023_B.x[1] = 0.0;
    Lab2_template2023_B.x_b[0] = 0.0;
    Lab2_template2023_B.x_b[1] = 0.0;
  }

  /* parameters */
  Lab2_template2023_M->defaultParam = ((real_T *)&Lab2_template2023_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Lab2_template2023_X;
    Lab2_template2023_M->contStates = (x);
    (void) memset((void *)&Lab2_template2023_X, 0,
                  sizeof(X_Lab2_template2023_T));
  }

  /* states (dwork) */
  Lab2_template2023_M->dwork = ((void *) &Lab2_template2023_DW);
  (void) memset((void *)&Lab2_template2023_DW, 0,
                sizeof(DW_Lab2_template2023_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Lab2_template2023_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      Lab2_template2023_DW.XYSuperimposed_XBuffer[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      Lab2_template2023_DW.XYSuperimposed_YBuffer[i] = 0.0;
    }
  }

  Lab2_template2023_DW.RateTransition_Buffer[0] = 0.0;
  Lab2_template2023_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lab2_template2023_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Lab2_template2023_M->Sizes.numContStates = (2);/* Number of continuous states */
  Lab2_template2023_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Lab2_template2023_M->Sizes.numY = (0);/* Number of model outputs */
  Lab2_template2023_M->Sizes.numU = (0);/* Number of model inputs */
  Lab2_template2023_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lab2_template2023_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Lab2_template2023_M->Sizes.numBlocks = (34);/* Number of blocks */
  Lab2_template2023_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  Lab2_template2023_M->Sizes.numBlockPrms = (127);/* Sum of parameter "widths" */
  return Lab2_template2023_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
