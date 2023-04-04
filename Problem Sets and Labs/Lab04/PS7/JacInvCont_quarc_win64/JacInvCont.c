/*
 * JacInvCont.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "JacInvCont".
 *
 * Model version              : 8.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Apr  1 12:51:00 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "JacInvCont.h"
#include "JacInvCont_private.h"
#include "JacInvCont_dt.h"

/* Block signals (default storage) */
B_JacInvCont_T JacInvCont_B;

/* Continuous states */
X_JacInvCont_T JacInvCont_X;

/* Block states (default storage) */
DW_JacInvCont_T JacInvCont_DW;

/* Real-time model */
static RT_MODEL_JacInvCont_T JacInvCont_M_;
RT_MODEL_JacInvCont_T *const JacInvCont_M = &JacInvCont_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(JacInvCont_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(JacInvCont_M, 2);
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
  if (JacInvCont_M->Timing.TaskCounters.TID[1] == 0) {
    JacInvCont_M->Timing.RateInteraction.TID1_2 =
      (JacInvCont_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    JacInvCont_M->Timing.perTaskSampleHits[5] =
      JacInvCont_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (JacInvCont_M->Timing.TaskCounters.TID[2])++;
  if ((JacInvCont_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    JacInvCont_M->Timing.TaskCounters.TID[2] = 0;
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
  JacInvCont_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void JacInvCont_output0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T tmp[4];
  real_T x[4];
  real_T Jinv_idx_0;
  real_T Jinv_idx_1;
  real_T Jinv_idx_2;
  real_T rtb_Clock;
  real_T t;
  int32_T i;
  if (rtmIsMajorTimeStep(JacInvCont_M)) {
    /* set solver stop time */
    if (!(JacInvCont_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&JacInvCont_M->solverInfo,
                            ((JacInvCont_M->Timing.clockTickH0 + 1) *
        JacInvCont_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&JacInvCont_M->solverInfo,
                            ((JacInvCont_M->Timing.clockTick0 + 1) *
        JacInvCont_M->Timing.stepSize0 + JacInvCont_M->Timing.clockTickH0 *
        JacInvCont_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(JacInvCont_M)) {
    JacInvCont_M->Timing.t[0] = rtsiGetT(&JacInvCont_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(JacInvCont_M)) {
    /* S-Function (hil_read_encoder_block): '<S4>/HIL Read Encoder' */

    /* S-Function Block: JacInvCont/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILReadEncoder_channels, 2,
        &JacInvCont_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = JacInvCont_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = JacInvCont_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S4>/Encoder Gain' incorporates:
     *  Constant: '<S4>/Home Position'
     *  Sum: '<S4>/Sum1'
     */
    JacInvCont_B.EncoderGain[0] = (JacInvCont_P.HomePosition_Value[0] +
      rtb_HILReadAnalog[0]) * JacInvCont_P.EncoderGain_Gain[0];
    JacInvCont_B.EncoderGain[1] = (JacInvCont_P.HomePosition_Value[1] +
      rtb_HILReadAnalog[1]) * JacInvCont_P.EncoderGain_Gain[1];

    /* Constant: '<Root>/Speed' */
    JacInvCont_B.Speed = JacInvCont_P.Speed_Value;
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = JacInvCont_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Trajectory  Generator' */
  /* MATLAB Function 'Trajectory  Generator': '<S5>:1' */
  if (rtb_Clock < 1.0) {
    /* '<S5>:1:6' */
    /* '<S5>:1:7' */
    rtb_Clock = (1.0 - cos(3.1415926535897931 * rtb_Clock)) * 0.025;
    JacInvCont_B.x[0] = rtb_Clock + 0.15;

    /* '<S5>:1:8' */
    JacInvCont_B.x[1] = 0.15 - rtb_Clock;
  } else if (rtb_Clock < 1.5) {
    /* '<S5>:1:9' */
    /* '<S5>:1:10' */
    rtb_Clock = (rtb_Clock - 1.0) * (rtb_Clock - 1.0) * (6.2831853071795862 *
      JacInvCont_B.Speed);
    JacInvCont_B.x[0] = cos(rtb_Clock) * 0.075 + 0.125;

    /* '<S5>:1:11' */
    JacInvCont_B.x[1] = sin(rtb_Clock) * 0.075 + 0.1;
  } else {
    /* '<S5>:1:13' */
    rtb_Clock = 6.2831853071795862 * JacInvCont_B.Speed * (rtb_Clock - 1.25);
    JacInvCont_B.x[0] = cos(rtb_Clock) * 0.075 + 0.125;

    /* '<S5>:1:14' */
    JacInvCont_B.x[1] = sin(rtb_Clock) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */
  if (rtmIsMajorTimeStep(JacInvCont_M)) {
    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S4>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S1>:1' */
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    /* '<S1>:1:7' */
    JacInvCont_B.x_b[0] = 0.15 * cos(JacInvCont_B.EncoderGain[0]) + 0.15 * cos
      (JacInvCont_B.EncoderGain[1]);

    /* '<S1>:1:8' */
    JacInvCont_B.x_b[1] = 0.15 * sin(JacInvCont_B.EncoderGain[0]) + 0.15 * sin
      (JacInvCont_B.EncoderGain[1]);
  }

  /* MATLAB Function: '<Root>/Inverse Jacobian1' incorporates:
   *  Gain: '<S4>/Encoder Gain'
   */
  /* MATLAB Function 'Inverse Jacobian1': '<S2>:1' */
  /* '<S2>:1:6' */
  /* '<S2>:1:3' */
  /* '<S2>:1:4' */
  /* '<S2>:1:6' */
  tmp[0] = -0.15 * sin(JacInvCont_B.EncoderGain[0]) - 0.15 * sin
    (JacInvCont_B.EncoderGain[1]);
  tmp[2] = -0.15 * sin(JacInvCont_B.EncoderGain[1]);
  tmp[1] = 0.15 * cos(JacInvCont_B.EncoderGain[0]) + 0.15 * cos
    (JacInvCont_B.EncoderGain[1]);
  tmp[3] = 0.15 * cos(JacInvCont_B.EncoderGain[1]);
  for (i = 0; i < 2; i++) {
    /* Sum: '<Root>/Sum' */
    JacInvCont_B.Sum[i] = JacInvCont_B.x[i] - JacInvCont_B.x_b[i];

    /* MATLAB Function: '<Root>/Inverse Jacobian1' */
    x[i] = 0.0;
    x[i] += tmp[i];
    rtb_Clock = tmp[i + 2];
    x[i] += -rtb_Clock;
    x[i + 2] = 0.0;
    x[i + 2] += tmp[i] * 0.0;
    x[i + 2] += rtb_Clock;
  }

  /* MATLAB Function: '<Root>/Inverse Jacobian1' */
  /* '<S2>:1:8' */
  if (fabs(x[1]) > fabs(x[0])) {
    rtb_Clock = x[0] / x[1];
    t = 1.0 / (rtb_Clock * x[3] - x[2]);
    Jinv_idx_0 = x[3] / x[1] * t;
    Jinv_idx_1 = -t;
    Jinv_idx_2 = -x[2] / x[1] * t;
    t *= rtb_Clock;
  } else {
    rtb_Clock = x[1] / x[0];
    t = 1.0 / (x[3] - rtb_Clock * x[2]);
    Jinv_idx_0 = x[3] / x[0] * t;
    Jinv_idx_1 = -rtb_Clock * t;
    Jinv_idx_2 = -x[2] / x[0] * t;
  }

  /* '<S2>:1:10' */
  JacInvCont_B.phi_err[0] = 0.0;
  JacInvCont_B.phi_err[0] += Jinv_idx_0 * JacInvCont_B.Sum[0];
  JacInvCont_B.phi_err[0] += Jinv_idx_2 * JacInvCont_B.Sum[1];

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  JacInvCont_B.FilterCoefficient[0] = (JacInvCont_P.PDController_D[0] *
    JacInvCont_B.phi_err[0] - JacInvCont_X.Filter_CSTATE[0]) *
    JacInvCont_P.PDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   */
  JacInvCont_B.Sum_b[0] = JacInvCont_P.PDController_P[0] * JacInvCont_B.phi_err
    [0] + JacInvCont_B.FilterCoefficient[0];

  /* Gain: '<S4>/1//AmpGain' incorporates:
   *  Bias: '<S4>/Amp Bias Tune for each  amp//channel if needed'
   */
  JacInvCont_B.uAmpGain[0] = (JacInvCont_B.Sum_b[0] +
    JacInvCont_P.AmpBiasTuneforeachampchannelifn[0]) *
    JacInvCont_P.uAmpGain_Gain[0];

  /* MATLAB Function: '<Root>/Inverse Jacobian1' */
  JacInvCont_B.phi_err[1] = 0.0;
  JacInvCont_B.phi_err[1] += Jinv_idx_1 * JacInvCont_B.Sum[0];
  JacInvCont_B.phi_err[1] += t * JacInvCont_B.Sum[1];

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  JacInvCont_B.FilterCoefficient[1] = (JacInvCont_P.PDController_D[1] *
    JacInvCont_B.phi_err[1] - JacInvCont_X.Filter_CSTATE[1]) *
    JacInvCont_P.PDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   */
  JacInvCont_B.Sum_b[1] = JacInvCont_P.PDController_P[1] * JacInvCont_B.phi_err
    [1] + JacInvCont_B.FilterCoefficient[1];

  /* Gain: '<S4>/1//AmpGain' incorporates:
   *  Bias: '<S4>/Amp Bias Tune for each  amp//channel if needed'
   */
  JacInvCont_B.uAmpGain[1] = (JacInvCont_B.Sum_b[1] +
    JacInvCont_P.AmpBiasTuneforeachampchannelifn[1]) *
    JacInvCont_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(JacInvCont_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: JacInvCont/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILWriteAnalog_channels, 2, &JacInvCont_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S4>/HIL Read Analog' */

    /* S-Function Block: JacInvCont/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
      }
    }

    /* Bias: '<S4>/Current Sense Bias Tune for each amp//channel if needed' incorporates:
     *  Gain: '<S4>/1//Sense Gain'
     */
    JacInvCont_B.CurrentSenseBiasTuneforeachampc[0] =
      JacInvCont_P.uSenseGain_Gain * rtb_HILReadAnalog[0] +
      JacInvCont_P.CurrentSenseBiasTuneforeachampc[0];
    JacInvCont_B.CurrentSenseBiasTuneforeachampc[1] =
      JacInvCont_P.uSenseGain_Gain * rtb_HILReadAnalog[1] +
      JacInvCont_P.CurrentSenseBiasTuneforeachampc[1];

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S4>/Encoder Gain'
     */
    if (JacInvCont_M->Timing.RateInteraction.TID1_2) {
      JacInvCont_DW.RateTransition_Buffer[0] = JacInvCont_B.EncoderGain[0];
      JacInvCont_DW.RateTransition_Buffer[1] = JacInvCont_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void JacInvCont_update0(void)          /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(JacInvCont_M)) {
    rt_ertODEUpdateContinuousStates(&JacInvCont_M->solverInfo);
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
  if (!(++JacInvCont_M->Timing.clockTick0)) {
    ++JacInvCont_M->Timing.clockTickH0;
  }

  JacInvCont_M->Timing.t[0] = rtsiGetSolverStopTime(&JacInvCont_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++JacInvCont_M->Timing.clockTick1)) {
    ++JacInvCont_M->Timing.clockTickH1;
  }

  JacInvCont_M->Timing.t[1] = JacInvCont_M->Timing.clockTick1 *
    JacInvCont_M->Timing.stepSize1 + JacInvCont_M->Timing.clockTickH1 *
    JacInvCont_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void JacInvCont_derivatives(void)
{
  XDot_JacInvCont_T *_rtXdot;
  _rtXdot = ((XDot_JacInvCont_T *) JacInvCont_M->derivs);

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE[0] = JacInvCont_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = JacInvCont_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void JacInvCont_output2(void)          /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  JacInvCont_B.RateTransition[0] = JacInvCont_DW.RateTransition_Buffer[0];
  JacInvCont_B.RateTransition[1] = JacInvCont_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void JacInvCont_update2(void)          /* Sample time: [0.02s, 0.0s] */
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
  if (!(++JacInvCont_M->Timing.clockTick2)) {
    ++JacInvCont_M->Timing.clockTickH2;
  }

  JacInvCont_M->Timing.t[2] = JacInvCont_M->Timing.clockTick2 *
    JacInvCont_M->Timing.stepSize2 + JacInvCont_M->Timing.clockTickH2 *
    JacInvCont_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void JacInvCont_output(int_T tid)
{
  switch (tid) {
   case 0 :
    JacInvCont_output0();
    break;

   case 2 :
    JacInvCont_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void JacInvCont_update(int_T tid)
{
  switch (tid) {
   case 0 :
    JacInvCont_update0();
    break;

   case 2 :
    JacInvCont_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void JacInvCont_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: JacInvCont/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &JacInvCont_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(JacInvCont_DW.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(JacInvCont_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
      return;
    }

    if ((JacInvCont_P.HILInitialize_AIPStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &JacInvCont_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (JacInvCont_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &JacInvCont_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = JacInvCont_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_AIChannels, 8U,
        &JacInvCont_DW.HILInitialize_AIMinimums[0],
        &JacInvCont_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if ((JacInvCont_P.HILInitialize_AOPStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &JacInvCont_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (JacInvCont_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &JacInvCont_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = JacInvCont_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_AOChannels, 8U,
        &JacInvCont_DW.HILInitialize_AOMinimums[0],
        &JacInvCont_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if ((JacInvCont_P.HILInitialize_AOStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &JacInvCont_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = JacInvCont_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_AOChannels, 8U,
        &JacInvCont_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if (JacInvCont_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &JacInvCont_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = JacInvCont_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (JacInvCont_DW.HILInitialize_Card, JacInvCont_P.HILInitialize_AOChannels,
         8U, &JacInvCont_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if ((JacInvCont_P.HILInitialize_EIPStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &JacInvCont_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = JacInvCont_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &JacInvCont_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if ((JacInvCont_P.HILInitialize_EIStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &JacInvCont_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = JacInvCont_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_EIChannels, 8U,
        &JacInvCont_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if ((JacInvCont_P.HILInitialize_POPStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &JacInvCont_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = JacInvCont_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &JacInvCont_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          JacInvCont_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &JacInvCont_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            JacInvCont_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            JacInvCont_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              JacInvCont_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            JacInvCont_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            JacInvCont_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              JacInvCont_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(JacInvCont_DW.HILInitialize_Card,
          &JacInvCont_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &JacInvCont_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(JacInvCont_DW.HILInitialize_Card,
          &JacInvCont_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &JacInvCont_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &JacInvCont_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = JacInvCont_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &JacInvCont_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = JacInvCont_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &JacInvCont_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = JacInvCont_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &JacInvCont_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &JacInvCont_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &JacInvCont_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &JacInvCont_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = JacInvCont_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &JacInvCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = JacInvCont_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_POChannels, 8U,
        &JacInvCont_DW.HILInitialize_POSortedFreqs[0],
        &JacInvCont_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if ((JacInvCont_P.HILInitialize_POStart && !is_switching) ||
        (JacInvCont_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &JacInvCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = JacInvCont_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(JacInvCont_DW.HILInitialize_Card,
        JacInvCont_P.HILInitialize_POChannels, 8U,
        &JacInvCont_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }

    if (JacInvCont_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &JacInvCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = JacInvCont_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (JacInvCont_DW.HILInitialize_Card, JacInvCont_P.HILInitialize_POChannels,
         8U, &JacInvCont_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Constant: '<Root>/Speed' */
  JacInvCont_B.Speed = JacInvCont_P.Speed_Value;

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  JacInvCont_X.Filter_CSTATE[0] = JacInvCont_P.PDController_InitialConditionFo;
  JacInvCont_X.Filter_CSTATE[1] = JacInvCont_P.PDController_InitialConditionFo;
}

/* Model terminate function */
void JacInvCont_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: JacInvCont/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(JacInvCont_DW.HILInitialize_Card);
    hil_monitor_stop_all(JacInvCont_DW.HILInitialize_Card);
    is_switching = false;
    if ((JacInvCont_P.HILInitialize_AOTerminate && !is_switching) ||
        (JacInvCont_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &JacInvCont_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = JacInvCont_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((JacInvCont_P.HILInitialize_POTerminate && !is_switching) ||
        (JacInvCont_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &JacInvCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = JacInvCont_P.HILInitialize_POFinal;
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
      result = hil_write(JacInvCont_DW.HILInitialize_Card
                         , JacInvCont_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , JacInvCont_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &JacInvCont_DW.HILInitialize_AOVoltages[0]
                         , &JacInvCont_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(JacInvCont_DW.HILInitialize_Card,
            JacInvCont_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &JacInvCont_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(JacInvCont_DW.HILInitialize_Card,
            JacInvCont_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &JacInvCont_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(JacInvCont_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(JacInvCont_DW.HILInitialize_Card);
    hil_monitor_delete_all(JacInvCont_DW.HILInitialize_Card);
    hil_close(JacInvCont_DW.HILInitialize_Card);
    JacInvCont_DW.HILInitialize_Card = NULL;
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
  JacInvCont_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  JacInvCont_update(tid);
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
  JacInvCont_initialize();
}

void MdlTerminate(void)
{
  JacInvCont_terminate();
}

/* Registration function */
RT_MODEL_JacInvCont_T *JacInvCont(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)JacInvCont_M, 0,
                sizeof(RT_MODEL_JacInvCont_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&JacInvCont_M->solverInfo,
                          &JacInvCont_M->Timing.simTimeStep);
    rtsiSetTPtr(&JacInvCont_M->solverInfo, &rtmGetTPtr(JacInvCont_M));
    rtsiSetStepSizePtr(&JacInvCont_M->solverInfo,
                       &JacInvCont_M->Timing.stepSize0);
    rtsiSetdXPtr(&JacInvCont_M->solverInfo, &JacInvCont_M->derivs);
    rtsiSetContStatesPtr(&JacInvCont_M->solverInfo, (real_T **)
                         &JacInvCont_M->contStates);
    rtsiSetNumContStatesPtr(&JacInvCont_M->solverInfo,
      &JacInvCont_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&JacInvCont_M->solverInfo,
      &JacInvCont_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&JacInvCont_M->solverInfo,
      &JacInvCont_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&JacInvCont_M->solverInfo,
      &JacInvCont_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&JacInvCont_M->solverInfo, (&rtmGetErrorStatus
      (JacInvCont_M)));
    rtsiSetRTModelPtr(&JacInvCont_M->solverInfo, JacInvCont_M);
  }

  rtsiSetSimTimeStep(&JacInvCont_M->solverInfo, MAJOR_TIME_STEP);
  JacInvCont_M->intgData.f[0] = JacInvCont_M->odeF[0];
  JacInvCont_M->contStates = ((real_T *) &JacInvCont_X);
  rtsiSetSolverData(&JacInvCont_M->solverInfo, (void *)&JacInvCont_M->intgData);
  rtsiSetSolverName(&JacInvCont_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = JacInvCont_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "JacInvCont_M points to
       static memory which is guaranteed to be non-NULL" */
    JacInvCont_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    JacInvCont_M->Timing.sampleTimes = (&JacInvCont_M->Timing.sampleTimesArray[0]);
    JacInvCont_M->Timing.offsetTimes = (&JacInvCont_M->Timing.offsetTimesArray[0]);

    /* task periods */
    JacInvCont_M->Timing.sampleTimes[0] = (0.0);
    JacInvCont_M->Timing.sampleTimes[1] = (0.001);
    JacInvCont_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    JacInvCont_M->Timing.offsetTimes[0] = (0.0);
    JacInvCont_M->Timing.offsetTimes[1] = (0.0);
    JacInvCont_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(JacInvCont_M, &JacInvCont_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = JacInvCont_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = JacInvCont_M->Timing.perTaskSampleHitsArray;
    JacInvCont_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    JacInvCont_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(JacInvCont_M, 10.0);
  JacInvCont_M->Timing.stepSize0 = 0.001;
  JacInvCont_M->Timing.stepSize1 = 0.001;
  JacInvCont_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  JacInvCont_M->Sizes.checksums[0] = (2380990085U);
  JacInvCont_M->Sizes.checksums[1] = (3685544549U);
  JacInvCont_M->Sizes.checksums[2] = (956938372U);
  JacInvCont_M->Sizes.checksums[3] = (141144414U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    JacInvCont_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(JacInvCont_M->extModeInfo,
      &JacInvCont_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(JacInvCont_M->extModeInfo, JacInvCont_M->Sizes.checksums);
    rteiSetTPtr(JacInvCont_M->extModeInfo, rtmGetTPtr(JacInvCont_M));
  }

  JacInvCont_M->solverInfoPtr = (&JacInvCont_M->solverInfo);
  JacInvCont_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&JacInvCont_M->solverInfo, 0.001);
  rtsiSetSolverMode(&JacInvCont_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  JacInvCont_M->blockIO = ((void *) &JacInvCont_B);

  {
    JacInvCont_B.EncoderGain[0] = 0.0;
    JacInvCont_B.EncoderGain[1] = 0.0;
    JacInvCont_B.Speed = 0.0;
    JacInvCont_B.Sum[0] = 0.0;
    JacInvCont_B.Sum[1] = 0.0;
    JacInvCont_B.FilterCoefficient[0] = 0.0;
    JacInvCont_B.FilterCoefficient[1] = 0.0;
    JacInvCont_B.Sum_b[0] = 0.0;
    JacInvCont_B.Sum_b[1] = 0.0;
    JacInvCont_B.uAmpGain[0] = 0.0;
    JacInvCont_B.uAmpGain[1] = 0.0;
    JacInvCont_B.CurrentSenseBiasTuneforeachampc[0] = 0.0;
    JacInvCont_B.CurrentSenseBiasTuneforeachampc[1] = 0.0;
    JacInvCont_B.RateTransition[0] = 0.0;
    JacInvCont_B.RateTransition[1] = 0.0;
    JacInvCont_B.x[0] = 0.0;
    JacInvCont_B.x[1] = 0.0;
    JacInvCont_B.phi_err[0] = 0.0;
    JacInvCont_B.phi_err[1] = 0.0;
    JacInvCont_B.x_b[0] = 0.0;
    JacInvCont_B.x_b[1] = 0.0;
  }

  /* parameters */
  JacInvCont_M->defaultParam = ((real_T *)&JacInvCont_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &JacInvCont_X;
    JacInvCont_M->contStates = (x);
    (void) memset((void *)&JacInvCont_X, 0,
                  sizeof(X_JacInvCont_T));
  }

  /* states (dwork) */
  JacInvCont_M->dwork = ((void *) &JacInvCont_DW);
  (void) memset((void *)&JacInvCont_DW, 0,
                sizeof(DW_JacInvCont_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      JacInvCont_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      JacInvCont_DW.XYSuperimposed_XBuffer[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      JacInvCont_DW.XYSuperimposed_YBuffer[i] = 0.0;
    }
  }

  JacInvCont_DW.RateTransition_Buffer[0] = 0.0;
  JacInvCont_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    JacInvCont_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  JacInvCont_M->Sizes.numContStates = (2);/* Number of continuous states */
  JacInvCont_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  JacInvCont_M->Sizes.numY = (0);      /* Number of model outputs */
  JacInvCont_M->Sizes.numU = (0);      /* Number of model inputs */
  JacInvCont_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  JacInvCont_M->Sizes.numSampTimes = (3);/* Number of sample times */
  JacInvCont_M->Sizes.numBlocks = (36);/* Number of blocks */
  JacInvCont_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  JacInvCont_M->Sizes.numBlockPrms = (127);/* Sum of parameter "widths" */
  return JacInvCont_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
