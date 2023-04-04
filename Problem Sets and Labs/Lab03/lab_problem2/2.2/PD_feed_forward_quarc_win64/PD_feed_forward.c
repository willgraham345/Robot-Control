/*
 * PD_feed_forward.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PD_feed_forward".
 *
 * Model version              : 8.12
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 23 11:37:23 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PD_feed_forward.h"
#include "PD_feed_forward_private.h"
#include "PD_feed_forward_dt.h"

/* Block signals (default storage) */
B_PD_feed_forward_T PD_feed_forward_B;

/* Continuous states */
X_PD_feed_forward_T PD_feed_forward_X;

/* Block states (default storage) */
DW_PD_feed_forward_T PD_feed_forward_DW;

/* Real-time model */
static RT_MODEL_PD_feed_forward_T PD_feed_forward_M_;
RT_MODEL_PD_feed_forward_T *const PD_feed_forward_M = &PD_feed_forward_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(PD_feed_forward_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(PD_feed_forward_M, 2);
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
  if (PD_feed_forward_M->Timing.TaskCounters.TID[1] == 0) {
    PD_feed_forward_M->Timing.RateInteraction.TID1_2 =
      (PD_feed_forward_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    PD_feed_forward_M->Timing.perTaskSampleHits[5] =
      PD_feed_forward_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PD_feed_forward_M->Timing.TaskCounters.TID[2])++;
  if ((PD_feed_forward_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    PD_feed_forward_M->Timing.TaskCounters.TID[2] = 0;
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
  PD_feed_forward_derivatives();
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
void PD_feed_forward_output0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T (*lastU)[2];
  real_T H12;
  real_T h;
  real_T rtb_Derivative1_idx_0;
  real_T rtb_Derivative1_idx_1;
  real_T theta_idx_0;
  real_T theta_idx_0_0;
  real_T theta_idx_0_1;
  real_T theta_idx_1;
  real_T theta_idx_1_0;
  if (rtmIsMajorTimeStep(PD_feed_forward_M)) {
    /* set solver stop time */
    if (!(PD_feed_forward_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PD_feed_forward_M->solverInfo,
                            ((PD_feed_forward_M->Timing.clockTickH0 + 1) *
        PD_feed_forward_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PD_feed_forward_M->solverInfo,
                            ((PD_feed_forward_M->Timing.clockTick0 + 1) *
        PD_feed_forward_M->Timing.stepSize0 +
        PD_feed_forward_M->Timing.clockTickH0 *
        PD_feed_forward_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PD_feed_forward_M)) {
    PD_feed_forward_M->Timing.t[0] = rtsiGetT(&PD_feed_forward_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(PD_feed_forward_M)) {
    /* S-Function (hil_read_encoder_block): '<S4>/HIL Read Encoder' */

    /* S-Function Block: PD_feed_forward/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILReadEncoder_channels, 2,
        &PD_feed_forward_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = PD_feed_forward_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = PD_feed_forward_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S4>/Encoder Gain' incorporates:
     *  Constant: '<S4>/Home Position'
     *  Sum: '<S4>/Sum1'
     */
    PD_feed_forward_B.EncoderGain[0] = (PD_feed_forward_P.HomePosition_Value[0]
      + rtb_HILReadAnalog[0]) * PD_feed_forward_P.EncoderGain_Gain[0];
    PD_feed_forward_B.EncoderGain[1] = (PD_feed_forward_P.HomePosition_Value[1]
      + rtb_HILReadAnalog[1]) * PD_feed_forward_P.EncoderGain_Gain[1];

    /* Constant: '<Root>/Speed' */
    PD_feed_forward_B.Speed = PD_feed_forward_P.Speed_Value;
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Derivative: '<Root>/Derivative'
   *  Derivative: '<Root>/Derivative1'
   *  Derivative: '<Root>/Derivative2'
   */
  H12 = PD_feed_forward_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Clock: '<Root>/Clock'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S6>:1' */
  if (H12 < 1.0) {
    /* '<S6>:1:6' */
    /* '<S6>:1:7' */
    theta_idx_1 = (1.0 - cos(3.1415926535897931 * H12)) * 0.025;
    PD_feed_forward_B.x[0] = theta_idx_1 + 0.15;

    /* '<S6>:1:8' */
    PD_feed_forward_B.x[1] = 0.15 - theta_idx_1;
  } else if (H12 < 1.5) {
    /* '<S6>:1:9' */
    /* '<S6>:1:10' */
    theta_idx_1 = (H12 - 1.0) * (H12 - 1.0) * (6.2831853071795862 *
      PD_feed_forward_B.Speed);
    PD_feed_forward_B.x[0] = cos(theta_idx_1) * 0.075 + 0.125;

    /* '<S6>:1:11' */
    PD_feed_forward_B.x[1] = sin(theta_idx_1) * 0.075 + 0.1;
  } else {
    /* '<S6>:1:13' */
    theta_idx_1 = 6.2831853071795862 * PD_feed_forward_B.Speed * (H12 - 1.25);
    PD_feed_forward_B.x[0] = cos(theta_idx_1) * 0.075 + 0.125;

    /* '<S6>:1:14' */
    PD_feed_forward_B.x[1] = sin(theta_idx_1) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  /* MATLAB Function 'Inverse Kinematics': '<S2>:1' */
  /* '<S2>:1:10' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:8' */
  theta_idx_1 = PD_feed_forward_B.x[0] * PD_feed_forward_B.x[0] +
    PD_feed_forward_B.x[1] * PD_feed_forward_B.x[1];
  theta_idx_1 = atan(sqrt((0.09 - theta_idx_1) / theta_idx_1)) * -2.0;

  /* '<S2>:1:9' */
  theta_idx_0 = rt_atan2d_snf(PD_feed_forward_B.x[1], PD_feed_forward_B.x[0]) -
    rt_atan2d_snf(0.15 * sin(theta_idx_1), 0.15 * cos(theta_idx_1) + 0.15);

  /* '<S2>:1:10' */
  PD_feed_forward_B.phi[0] = 0.0;
  PD_feed_forward_B.phi[0] += theta_idx_0;
  PD_feed_forward_B.phi[0] += 0.0 * theta_idx_1;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S4>/Encoder Gain'
   */
  PD_feed_forward_B.Sum[0] = PD_feed_forward_B.phi[0] -
    PD_feed_forward_B.EncoderGain[0];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S34>/SumD'
   */
  PD_feed_forward_B.FilterCoefficient[0] = (PD_feed_forward_P.PDController_D *
    PD_feed_forward_B.Sum[0] - PD_feed_forward_X.Filter_CSTATE[0]) *
    PD_feed_forward_P.PDController_N;

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  PD_feed_forward_B.phi[1] = 0.0;
  PD_feed_forward_B.phi[1] += theta_idx_0;
  PD_feed_forward_B.phi[1] += theta_idx_1;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S4>/Encoder Gain'
   */
  PD_feed_forward_B.Sum[1] = PD_feed_forward_B.phi[1] -
    PD_feed_forward_B.EncoderGain[1];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S34>/SumD'
   */
  PD_feed_forward_B.FilterCoefficient[1] = (PD_feed_forward_P.PDController_D *
    PD_feed_forward_B.Sum[1] - PD_feed_forward_X.Filter_CSTATE[1]) *
    PD_feed_forward_P.PDController_N;

  /* Derivative: '<Root>/Derivative' */
  if ((PD_feed_forward_DW.TimeStampA >= H12) && (PD_feed_forward_DW.TimeStampB >=
       H12)) {
    theta_idx_0 = 0.0;
    theta_idx_1 = 0.0;
  } else {
    h = PD_feed_forward_DW.TimeStampA;
    lastU = &PD_feed_forward_DW.LastUAtTimeA;
    if (PD_feed_forward_DW.TimeStampA < PD_feed_forward_DW.TimeStampB) {
      if (PD_feed_forward_DW.TimeStampB < H12) {
        h = PD_feed_forward_DW.TimeStampB;
        lastU = &PD_feed_forward_DW.LastUAtTimeB;
      }
    } else if (PD_feed_forward_DW.TimeStampA >= H12) {
      h = PD_feed_forward_DW.TimeStampB;
      lastU = &PD_feed_forward_DW.LastUAtTimeB;
    }

    h = H12 - h;
    theta_idx_0 = (PD_feed_forward_B.phi[0] - (*lastU)[0]) / h;
    theta_idx_1 = (PD_feed_forward_B.phi[1] - (*lastU)[1]) / h;
  }

  /* Derivative: '<Root>/Derivative2' */
  if ((PD_feed_forward_DW.TimeStampA_b >= H12) &&
      (PD_feed_forward_DW.TimeStampB_g >= H12)) {
    /* Derivative: '<Root>/Derivative2' */
    PD_feed_forward_B.Derivative2[0] = 0.0;
    PD_feed_forward_B.Derivative2[1] = 0.0;
  } else {
    h = PD_feed_forward_DW.TimeStampA_b;
    lastU = &PD_feed_forward_DW.LastUAtTimeA_b;
    if (PD_feed_forward_DW.TimeStampA_b < PD_feed_forward_DW.TimeStampB_g) {
      if (PD_feed_forward_DW.TimeStampB_g < H12) {
        h = PD_feed_forward_DW.TimeStampB_g;
        lastU = &PD_feed_forward_DW.LastUAtTimeB_a;
      }
    } else if (PD_feed_forward_DW.TimeStampA_b >= H12) {
      h = PD_feed_forward_DW.TimeStampB_g;
      lastU = &PD_feed_forward_DW.LastUAtTimeB_a;
    }

    h = H12 - h;

    /* Derivative: '<Root>/Derivative2' */
    PD_feed_forward_B.Derivative2[0] = (PD_feed_forward_B.phi[0] - (*lastU)[0]) /
      h;
    PD_feed_forward_B.Derivative2[1] = (PD_feed_forward_B.phi[1] - (*lastU)[1]) /
      h;
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((PD_feed_forward_DW.TimeStampA_j >= H12) &&
      (PD_feed_forward_DW.TimeStampB_m >= H12)) {
    rtb_Derivative1_idx_0 = 0.0;
    rtb_Derivative1_idx_1 = 0.0;
  } else {
    h = PD_feed_forward_DW.TimeStampA_j;
    lastU = &PD_feed_forward_DW.LastUAtTimeA_bl;
    if (PD_feed_forward_DW.TimeStampA_j < PD_feed_forward_DW.TimeStampB_m) {
      if (PD_feed_forward_DW.TimeStampB_m < H12) {
        h = PD_feed_forward_DW.TimeStampB_m;
        lastU = &PD_feed_forward_DW.LastUAtTimeB_c;
      }
    } else if (PD_feed_forward_DW.TimeStampA_j >= H12) {
      h = PD_feed_forward_DW.TimeStampB_m;
      lastU = &PD_feed_forward_DW.LastUAtTimeB_c;
    }

    h = H12 - h;
    rtb_Derivative1_idx_0 = (PD_feed_forward_B.Derivative2[0] - (*lastU)[0]) / h;
    rtb_Derivative1_idx_1 = (PD_feed_forward_B.Derivative2[1] - (*lastU)[1]) / h;
  }

  /* MATLAB Function: '<Root>/Torque Feedforward' */
  /* MATLAB Function 'Torque Feedforward': '<S5>:1' */
  /* '<S5>:1:5' */
  /* '<S5>:1:7' */
  /* '<S5>:1:8' */
  /* '<S5>:1:9' */
  /* '<S5>:1:10' */
  /* '<S5>:1:15' */
  /* '<S5>:1:16' */
  /* '<S5>:1:17' */
  /* '<S5>:1:18' */
  /* '<S5>:1:19' */
  /* '<S5>:1:20' */
  /* '<S5>:1:21' */
  /* '<S5>:1:24' */
  h = PD_feed_forward_B.phi[1] - PD_feed_forward_B.phi[0];
  H12 = cos(h) * 0.00041579999999999997;

  /* '<S5>:1:27' */
  h = sin(h) * 0.00041579999999999997;

  /* '<S5>:1:28' */
  /* '<S5>:1:29' */
  /* '<S5>:1:30' */
  /* '<S5>:1:31' */
  /* '<S5>:1:33' */
  /* '<S5>:1:34' */
  /* '<S5>:1:35' */
  /* '<S5>:1:36' */
  /* '<S5>:1:38' */
  theta_idx_0_0 = theta_idx_0 * theta_idx_0;
  theta_idx_1_0 = theta_idx_1 * theta_idx_1;
  if (theta_idx_0 < 0.0) {
    theta_idx_0_1 = -1.0;
  } else if (theta_idx_0 > 0.0) {
    theta_idx_0_1 = 1.0;
  } else if (theta_idx_0 == 0.0) {
    theta_idx_0_1 = 0.0;
  } else {
    theta_idx_0_1 = (rtNaN);
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/1//MotorGain '
   *  Gain: '<S42>/Filter Coefficient'
   *  Gain: '<S44>/Proportional Gain'
   *  MATLAB Function: '<Root>/Torque Feedforward'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S48>/Sum'
   */
  PD_feed_forward_B.Current[0] = ((((0.0055575 * rtb_Derivative1_idx_0 + H12 *
    rtb_Derivative1_idx_1) + (0.0 * theta_idx_0_0 + -h * theta_idx_1_0)) +
    0.1690892 * cos(PD_feed_forward_B.phi[0])) + (0.01519 * theta_idx_0 + 0.007 *
    theta_idx_0_1)) * PD_feed_forward_P.uMotorGain_Gain +
    (PD_feed_forward_P.PDController_P * PD_feed_forward_B.Sum[0] +
     PD_feed_forward_B.FilterCoefficient[0]);

  /* Gain: '<S4>/1//AmpGain' incorporates:
   *  Bias: '<S4>/Amp Bias Tune for each  amp//channel if needed'
   *  Sum: '<Root>/Sum1'
   */
  PD_feed_forward_B.uAmpGain[0] = (PD_feed_forward_B.Current[0] +
    PD_feed_forward_P.AmpBiasTuneforeachampchannelifn[0]) *
    PD_feed_forward_P.uAmpGain_Gain[0];

  /* MATLAB Function: '<Root>/Torque Feedforward' */
  if (theta_idx_1 < 0.0) {
    theta_idx_0 = -1.0;
  } else if (theta_idx_1 > 0.0) {
    theta_idx_0 = 1.0;
  } else if (theta_idx_1 == 0.0) {
    theta_idx_0 = 0.0;
  } else {
    theta_idx_0 = (rtNaN);
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/1//MotorGain '
   *  Gain: '<S42>/Filter Coefficient'
   *  Gain: '<S44>/Proportional Gain'
   *  MATLAB Function: '<Root>/Torque Feedforward'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S48>/Sum'
   */
  PD_feed_forward_B.Current[1] = ((((H12 * rtb_Derivative1_idx_0 +
    0.0034850000000000003 * rtb_Derivative1_idx_1) + (h * theta_idx_0_0 + 0.0 *
    theta_idx_1_0)) + 0.027165599999999998 * cos(PD_feed_forward_B.phi[1])) +
    (0.01519 * theta_idx_1 + 0.007 * theta_idx_0)) *
    PD_feed_forward_P.uMotorGain_Gain + (PD_feed_forward_P.PDController_P *
    PD_feed_forward_B.Sum[1] + PD_feed_forward_B.FilterCoefficient[1]);

  /* Gain: '<S4>/1//AmpGain' incorporates:
   *  Bias: '<S4>/Amp Bias Tune for each  amp//channel if needed'
   *  Sum: '<Root>/Sum1'
   */
  PD_feed_forward_B.uAmpGain[1] = (PD_feed_forward_B.Current[1] +
    PD_feed_forward_P.AmpBiasTuneforeachampchannelifn[1]) *
    PD_feed_forward_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(PD_feed_forward_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: PD_feed_forward/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILWriteAnalog_channels, 2,
        &PD_feed_forward_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S4>/HIL Read Analog' */

    /* S-Function Block: PD_feed_forward/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
      }
    }

    /* Bias: '<S4>/Current Sense Bias Tune for each amp//channel if needed' incorporates:
     *  Gain: '<S4>/1//Sense Gain'
     */
    PD_feed_forward_B.CurrentSenseBiasTuneforeachampc[0] =
      PD_feed_forward_P.uSenseGain_Gain * rtb_HILReadAnalog[0] +
      PD_feed_forward_P.CurrentSenseBiasTuneforeachampc[0];
    PD_feed_forward_B.CurrentSenseBiasTuneforeachampc[1] =
      PD_feed_forward_P.uSenseGain_Gain * rtb_HILReadAnalog[1] +
      PD_feed_forward_P.CurrentSenseBiasTuneforeachampc[1];

    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S4>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S1>:1' */
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    /* '<S1>:1:7' */
    PD_feed_forward_B.x_b[0] = 0.15 * cos(PD_feed_forward_B.EncoderGain[0]) +
      0.15 * cos(PD_feed_forward_B.EncoderGain[1]);

    /* '<S1>:1:8' */
    PD_feed_forward_B.x_b[1] = 0.15 * sin(PD_feed_forward_B.EncoderGain[0]) +
      0.15 * sin(PD_feed_forward_B.EncoderGain[1]);

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S4>/Encoder Gain'
     */
    if (PD_feed_forward_M->Timing.RateInteraction.TID1_2) {
      PD_feed_forward_DW.RateTransition_Buffer[0] =
        PD_feed_forward_B.EncoderGain[0];
      PD_feed_forward_DW.RateTransition_Buffer[1] =
        PD_feed_forward_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void PD_feed_forward_update0(void)     /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<Root>/Derivative' */
  if (PD_feed_forward_DW.TimeStampA == (rtInf)) {
    PD_feed_forward_DW.TimeStampA = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeA;
  } else if (PD_feed_forward_DW.TimeStampB == (rtInf)) {
    PD_feed_forward_DW.TimeStampB = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeB;
  } else if (PD_feed_forward_DW.TimeStampA < PD_feed_forward_DW.TimeStampB) {
    PD_feed_forward_DW.TimeStampA = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeA;
  } else {
    PD_feed_forward_DW.TimeStampB = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeB;
  }

  (*lastU)[0] = PD_feed_forward_B.phi[0];
  (*lastU)[1] = PD_feed_forward_B.phi[1];

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative2' */
  if (PD_feed_forward_DW.TimeStampA_b == (rtInf)) {
    PD_feed_forward_DW.TimeStampA_b = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeA_b;
  } else if (PD_feed_forward_DW.TimeStampB_g == (rtInf)) {
    PD_feed_forward_DW.TimeStampB_g = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeB_a;
  } else if (PD_feed_forward_DW.TimeStampA_b < PD_feed_forward_DW.TimeStampB_g)
  {
    PD_feed_forward_DW.TimeStampA_b = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeA_b;
  } else {
    PD_feed_forward_DW.TimeStampB_g = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeB_a;
  }

  (*lastU)[0] = PD_feed_forward_B.phi[0];
  (*lastU)[1] = PD_feed_forward_B.phi[1];

  /* End of Update for Derivative: '<Root>/Derivative2' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (PD_feed_forward_DW.TimeStampA_j == (rtInf)) {
    PD_feed_forward_DW.TimeStampA_j = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeA_bl;
  } else if (PD_feed_forward_DW.TimeStampB_m == (rtInf)) {
    PD_feed_forward_DW.TimeStampB_m = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeB_c;
  } else if (PD_feed_forward_DW.TimeStampA_j < PD_feed_forward_DW.TimeStampB_m)
  {
    PD_feed_forward_DW.TimeStampA_j = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeA_bl;
  } else {
    PD_feed_forward_DW.TimeStampB_m = PD_feed_forward_M->Timing.t[0];
    lastU = &PD_feed_forward_DW.LastUAtTimeB_c;
  }

  (*lastU)[0] = PD_feed_forward_B.Derivative2[0];
  (*lastU)[1] = PD_feed_forward_B.Derivative2[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(PD_feed_forward_M)) {
    rt_ertODEUpdateContinuousStates(&PD_feed_forward_M->solverInfo);
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
  if (!(++PD_feed_forward_M->Timing.clockTick0)) {
    ++PD_feed_forward_M->Timing.clockTickH0;
  }

  PD_feed_forward_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PD_feed_forward_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PD_feed_forward_M->Timing.clockTick1)) {
    ++PD_feed_forward_M->Timing.clockTickH1;
  }

  PD_feed_forward_M->Timing.t[1] = PD_feed_forward_M->Timing.clockTick1 *
    PD_feed_forward_M->Timing.stepSize1 + PD_feed_forward_M->Timing.clockTickH1 *
    PD_feed_forward_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void PD_feed_forward_derivatives(void)
{
  XDot_PD_feed_forward_T *_rtXdot;
  _rtXdot = ((XDot_PD_feed_forward_T *) PD_feed_forward_M->derivs);

  /* Derivatives for Integrator: '<S34>/Filter' incorporates:
   *  Gain: '<S42>/Filter Coefficient'
   */
  _rtXdot->Filter_CSTATE[0] = PD_feed_forward_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = PD_feed_forward_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void PD_feed_forward_output2(void)     /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  PD_feed_forward_B.RateTransition[0] =
    PD_feed_forward_DW.RateTransition_Buffer[0];
  PD_feed_forward_B.RateTransition[1] =
    PD_feed_forward_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void PD_feed_forward_update2(void)     /* Sample time: [0.02s, 0.0s] */
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
  if (!(++PD_feed_forward_M->Timing.clockTick2)) {
    ++PD_feed_forward_M->Timing.clockTickH2;
  }

  PD_feed_forward_M->Timing.t[2] = PD_feed_forward_M->Timing.clockTick2 *
    PD_feed_forward_M->Timing.stepSize2 + PD_feed_forward_M->Timing.clockTickH2 *
    PD_feed_forward_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PD_feed_forward_output(int_T tid)
{
  switch (tid) {
   case 0 :
    PD_feed_forward_output0();
    break;

   case 2 :
    PD_feed_forward_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PD_feed_forward_update(int_T tid)
{
  switch (tid) {
   case 0 :
    PD_feed_forward_update0();
    break;

   case 2 :
    PD_feed_forward_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void PD_feed_forward_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: PD_feed_forward/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &PD_feed_forward_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(PD_feed_forward_DW.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(PD_feed_forward_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
      return;
    }

    if ((PD_feed_forward_P.HILInitialize_AIPStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &PD_feed_forward_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (PD_feed_forward_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &PD_feed_forward_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = PD_feed_forward_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_AIChannels, 8U,
        &PD_feed_forward_DW.HILInitialize_AIMinimums[0],
        &PD_feed_forward_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if ((PD_feed_forward_P.HILInitialize_AOPStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &PD_feed_forward_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (PD_feed_forward_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &PD_feed_forward_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = PD_feed_forward_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (PD_feed_forward_DW.HILInitialize_Card,
         PD_feed_forward_P.HILInitialize_AOChannels, 8U,
         &PD_feed_forward_DW.HILInitialize_AOMinimums[0],
         &PD_feed_forward_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if ((PD_feed_forward_P.HILInitialize_AOStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PD_feed_forward_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PD_feed_forward_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_AOChannels, 8U,
        &PD_feed_forward_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if (PD_feed_forward_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PD_feed_forward_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PD_feed_forward_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (PD_feed_forward_DW.HILInitialize_Card,
         PD_feed_forward_P.HILInitialize_AOChannels, 8U,
         &PD_feed_forward_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if ((PD_feed_forward_P.HILInitialize_EIPStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &PD_feed_forward_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = PD_feed_forward_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (PD_feed_forward_DW.HILInitialize_Card,
         PD_feed_forward_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &PD_feed_forward_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if ((PD_feed_forward_P.HILInitialize_EIStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &PD_feed_forward_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = PD_feed_forward_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_EIChannels, 8U,
        &PD_feed_forward_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if ((PD_feed_forward_P.HILInitialize_POPStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &PD_feed_forward_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PD_feed_forward_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &PD_feed_forward_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          PD_feed_forward_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &PD_feed_forward_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            PD_feed_forward_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            PD_feed_forward_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = PD_feed_forward_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            PD_feed_forward_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            PD_feed_forward_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = PD_feed_forward_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(PD_feed_forward_DW.HILInitialize_Card,
          &PD_feed_forward_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes, &PD_feed_forward_DW.HILInitialize_POSortedFreqs
          [0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(PD_feed_forward_DW.HILInitialize_Card,
          &PD_feed_forward_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &PD_feed_forward_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &PD_feed_forward_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PD_feed_forward_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &PD_feed_forward_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = PD_feed_forward_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &PD_feed_forward_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = PD_feed_forward_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &PD_feed_forward_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &PD_feed_forward_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &PD_feed_forward_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &PD_feed_forward_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = PD_feed_forward_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &PD_feed_forward_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_feed_forward_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_POChannels, 8U,
        &PD_feed_forward_DW.HILInitialize_POSortedFreqs[0],
        &PD_feed_forward_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if ((PD_feed_forward_P.HILInitialize_POStart && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PD_feed_forward_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_feed_forward_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(PD_feed_forward_DW.HILInitialize_Card,
        PD_feed_forward_P.HILInitialize_POChannels, 8U,
        &PD_feed_forward_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }

    if (PD_feed_forward_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &PD_feed_forward_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_feed_forward_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (PD_feed_forward_DW.HILInitialize_Card,
         PD_feed_forward_P.HILInitialize_POChannels, 8U,
         &PD_feed_forward_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Constant: '<Root>/Speed' */
  PD_feed_forward_B.Speed = PD_feed_forward_P.Speed_Value;

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  PD_feed_forward_X.Filter_CSTATE[0] =
    PD_feed_forward_P.PDController_InitialConditionFo;
  PD_feed_forward_X.Filter_CSTATE[1] =
    PD_feed_forward_P.PDController_InitialConditionFo;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  PD_feed_forward_DW.TimeStampA = (rtInf);
  PD_feed_forward_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  PD_feed_forward_DW.TimeStampA_b = (rtInf);
  PD_feed_forward_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  PD_feed_forward_DW.TimeStampA_j = (rtInf);
  PD_feed_forward_DW.TimeStampB_m = (rtInf);
}

/* Model terminate function */
void PD_feed_forward_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: PD_feed_forward/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(PD_feed_forward_DW.HILInitialize_Card);
    hil_monitor_stop_all(PD_feed_forward_DW.HILInitialize_Card);
    is_switching = false;
    if ((PD_feed_forward_P.HILInitialize_AOTerminate && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PD_feed_forward_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PD_feed_forward_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((PD_feed_forward_P.HILInitialize_POTerminate && !is_switching) ||
        (PD_feed_forward_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PD_feed_forward_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_feed_forward_P.HILInitialize_POFinal;
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
      result = hil_write(PD_feed_forward_DW.HILInitialize_Card
                         , PD_feed_forward_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , PD_feed_forward_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &PD_feed_forward_DW.HILInitialize_AOVoltages[0]
                         , &PD_feed_forward_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(PD_feed_forward_DW.HILInitialize_Card,
            PD_feed_forward_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &PD_feed_forward_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(PD_feed_forward_DW.HILInitialize_Card,
            PD_feed_forward_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &PD_feed_forward_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PD_feed_forward_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(PD_feed_forward_DW.HILInitialize_Card);
    hil_monitor_delete_all(PD_feed_forward_DW.HILInitialize_Card);
    hil_close(PD_feed_forward_DW.HILInitialize_Card);
    PD_feed_forward_DW.HILInitialize_Card = NULL;
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
  PD_feed_forward_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  PD_feed_forward_update(tid);
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
  PD_feed_forward_initialize();
}

void MdlTerminate(void)
{
  PD_feed_forward_terminate();
}

/* Registration function */
RT_MODEL_PD_feed_forward_T *PD_feed_forward(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PD_feed_forward_M, 0,
                sizeof(RT_MODEL_PD_feed_forward_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PD_feed_forward_M->solverInfo,
                          &PD_feed_forward_M->Timing.simTimeStep);
    rtsiSetTPtr(&PD_feed_forward_M->solverInfo, &rtmGetTPtr(PD_feed_forward_M));
    rtsiSetStepSizePtr(&PD_feed_forward_M->solverInfo,
                       &PD_feed_forward_M->Timing.stepSize0);
    rtsiSetdXPtr(&PD_feed_forward_M->solverInfo, &PD_feed_forward_M->derivs);
    rtsiSetContStatesPtr(&PD_feed_forward_M->solverInfo, (real_T **)
                         &PD_feed_forward_M->contStates);
    rtsiSetNumContStatesPtr(&PD_feed_forward_M->solverInfo,
      &PD_feed_forward_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PD_feed_forward_M->solverInfo,
      &PD_feed_forward_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PD_feed_forward_M->solverInfo,
      &PD_feed_forward_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PD_feed_forward_M->solverInfo,
      &PD_feed_forward_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PD_feed_forward_M->solverInfo, (&rtmGetErrorStatus
      (PD_feed_forward_M)));
    rtsiSetRTModelPtr(&PD_feed_forward_M->solverInfo, PD_feed_forward_M);
  }

  rtsiSetSimTimeStep(&PD_feed_forward_M->solverInfo, MAJOR_TIME_STEP);
  PD_feed_forward_M->intgData.f[0] = PD_feed_forward_M->odeF[0];
  PD_feed_forward_M->contStates = ((real_T *) &PD_feed_forward_X);
  rtsiSetSolverData(&PD_feed_forward_M->solverInfo, (void *)
                    &PD_feed_forward_M->intgData);
  rtsiSetSolverName(&PD_feed_forward_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PD_feed_forward_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "PD_feed_forward_M points to
       static memory which is guaranteed to be non-NULL" */
    PD_feed_forward_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PD_feed_forward_M->Timing.sampleTimes =
      (&PD_feed_forward_M->Timing.sampleTimesArray[0]);
    PD_feed_forward_M->Timing.offsetTimes =
      (&PD_feed_forward_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PD_feed_forward_M->Timing.sampleTimes[0] = (0.0);
    PD_feed_forward_M->Timing.sampleTimes[1] = (0.001);
    PD_feed_forward_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    PD_feed_forward_M->Timing.offsetTimes[0] = (0.0);
    PD_feed_forward_M->Timing.offsetTimes[1] = (0.0);
    PD_feed_forward_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(PD_feed_forward_M, &PD_feed_forward_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PD_feed_forward_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      PD_feed_forward_M->Timing.perTaskSampleHitsArray;
    PD_feed_forward_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    PD_feed_forward_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PD_feed_forward_M, 10.0);
  PD_feed_forward_M->Timing.stepSize0 = 0.001;
  PD_feed_forward_M->Timing.stepSize1 = 0.001;
  PD_feed_forward_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  PD_feed_forward_M->Sizes.checksums[0] = (3804058126U);
  PD_feed_forward_M->Sizes.checksums[1] = (3159809058U);
  PD_feed_forward_M->Sizes.checksums[2] = (2392361912U);
  PD_feed_forward_M->Sizes.checksums[3] = (2863846140U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    PD_feed_forward_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PD_feed_forward_M->extModeInfo,
      &PD_feed_forward_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PD_feed_forward_M->extModeInfo,
                        PD_feed_forward_M->Sizes.checksums);
    rteiSetTPtr(PD_feed_forward_M->extModeInfo, rtmGetTPtr(PD_feed_forward_M));
  }

  PD_feed_forward_M->solverInfoPtr = (&PD_feed_forward_M->solverInfo);
  PD_feed_forward_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PD_feed_forward_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PD_feed_forward_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  PD_feed_forward_M->blockIO = ((void *) &PD_feed_forward_B);

  {
    PD_feed_forward_B.EncoderGain[0] = 0.0;
    PD_feed_forward_B.EncoderGain[1] = 0.0;
    PD_feed_forward_B.Speed = 0.0;
    PD_feed_forward_B.Sum[0] = 0.0;
    PD_feed_forward_B.Sum[1] = 0.0;
    PD_feed_forward_B.FilterCoefficient[0] = 0.0;
    PD_feed_forward_B.FilterCoefficient[1] = 0.0;
    PD_feed_forward_B.Derivative2[0] = 0.0;
    PD_feed_forward_B.Derivative2[1] = 0.0;
    PD_feed_forward_B.Current[0] = 0.0;
    PD_feed_forward_B.Current[1] = 0.0;
    PD_feed_forward_B.uAmpGain[0] = 0.0;
    PD_feed_forward_B.uAmpGain[1] = 0.0;
    PD_feed_forward_B.CurrentSenseBiasTuneforeachampc[0] = 0.0;
    PD_feed_forward_B.CurrentSenseBiasTuneforeachampc[1] = 0.0;
    PD_feed_forward_B.RateTransition[0] = 0.0;
    PD_feed_forward_B.RateTransition[1] = 0.0;
    PD_feed_forward_B.x[0] = 0.0;
    PD_feed_forward_B.x[1] = 0.0;
    PD_feed_forward_B.phi[0] = 0.0;
    PD_feed_forward_B.phi[1] = 0.0;
    PD_feed_forward_B.x_b[0] = 0.0;
    PD_feed_forward_B.x_b[1] = 0.0;
  }

  /* parameters */
  PD_feed_forward_M->defaultParam = ((real_T *)&PD_feed_forward_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PD_feed_forward_X;
    PD_feed_forward_M->contStates = (x);
    (void) memset((void *)&PD_feed_forward_X, 0,
                  sizeof(X_PD_feed_forward_T));
  }

  /* states (dwork) */
  PD_feed_forward_M->dwork = ((void *) &PD_feed_forward_DW);
  (void) memset((void *)&PD_feed_forward_DW, 0,
                sizeof(DW_PD_feed_forward_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_feed_forward_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  PD_feed_forward_DW.TimeStampA = 0.0;
  PD_feed_forward_DW.LastUAtTimeA[0] = 0.0;
  PD_feed_forward_DW.LastUAtTimeA[1] = 0.0;
  PD_feed_forward_DW.TimeStampB = 0.0;
  PD_feed_forward_DW.LastUAtTimeB[0] = 0.0;
  PD_feed_forward_DW.LastUAtTimeB[1] = 0.0;
  PD_feed_forward_DW.TimeStampA_b = 0.0;
  PD_feed_forward_DW.LastUAtTimeA_b[0] = 0.0;
  PD_feed_forward_DW.LastUAtTimeA_b[1] = 0.0;
  PD_feed_forward_DW.TimeStampB_g = 0.0;
  PD_feed_forward_DW.LastUAtTimeB_a[0] = 0.0;
  PD_feed_forward_DW.LastUAtTimeB_a[1] = 0.0;
  PD_feed_forward_DW.TimeStampA_j = 0.0;
  PD_feed_forward_DW.LastUAtTimeA_bl[0] = 0.0;
  PD_feed_forward_DW.LastUAtTimeA_bl[1] = 0.0;
  PD_feed_forward_DW.TimeStampB_m = 0.0;
  PD_feed_forward_DW.LastUAtTimeB_c[0] = 0.0;
  PD_feed_forward_DW.LastUAtTimeB_c[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      PD_feed_forward_DW.XYSuperimposed_XBuffer[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      PD_feed_forward_DW.XYSuperimposed_YBuffer[i] = 0.0;
    }
  }

  PD_feed_forward_DW.RateTransition_Buffer[0] = 0.0;
  PD_feed_forward_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PD_feed_forward_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PD_feed_forward_M->Sizes.numContStates = (2);/* Number of continuous states */
  PD_feed_forward_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PD_feed_forward_M->Sizes.numY = (0); /* Number of model outputs */
  PD_feed_forward_M->Sizes.numU = (0); /* Number of model inputs */
  PD_feed_forward_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PD_feed_forward_M->Sizes.numSampTimes = (3);/* Number of sample times */
  PD_feed_forward_M->Sizes.numBlocks = (43);/* Number of blocks */
  PD_feed_forward_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  PD_feed_forward_M->Sizes.numBlockPrms = (126);/* Sum of parameter "widths" */
  return PD_feed_forward_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
