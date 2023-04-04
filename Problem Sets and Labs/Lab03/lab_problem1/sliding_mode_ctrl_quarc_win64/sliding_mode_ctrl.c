/*
 * sliding_mode_ctrl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sliding_mode_ctrl".
 *
 * Model version              : 8.17
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 23 11:14:56 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sliding_mode_ctrl.h"
#include "sliding_mode_ctrl_private.h"
#include "sliding_mode_ctrl_dt.h"

/* Block signals (default storage) */
B_sliding_mode_ctrl_T sliding_mode_ctrl_B;

/* Continuous states */
X_sliding_mode_ctrl_T sliding_mode_ctrl_X;

/* Block states (default storage) */
DW_sliding_mode_ctrl_T sliding_mode_ctrl_DW;

/* Real-time model */
static RT_MODEL_sliding_mode_ctrl_T sliding_mode_ctrl_M_;
RT_MODEL_sliding_mode_ctrl_T *const sliding_mode_ctrl_M = &sliding_mode_ctrl_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(sliding_mode_ctrl_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(sliding_mode_ctrl_M, 2);
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
  if (sliding_mode_ctrl_M->Timing.TaskCounters.TID[1] == 0) {
    sliding_mode_ctrl_M->Timing.RateInteraction.TID1_2 =
      (sliding_mode_ctrl_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    sliding_mode_ctrl_M->Timing.perTaskSampleHits[5] =
      sliding_mode_ctrl_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (sliding_mode_ctrl_M->Timing.TaskCounters.TID[2])++;
  if ((sliding_mode_ctrl_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    sliding_mode_ctrl_M->Timing.TaskCounters.TID[2] = 0;
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
  sliding_mode_ctrl_derivatives();
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
void sliding_mode_ctrl_output0(void)   /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T (*lastU)[2];
  real_T Current_tmp;
  real_T Current_tmp_0;
  real_T H12;
  real_T h;
  real_T rtb_Derivative_idx_0;
  real_T rtb_Derivative_idx_0_0;
  real_T rtb_Derivative_idx_0_1;
  real_T rtb_Derivative_idx_1;
  real_T rtb_Derivative_idx_1_0;
  real_T theta_idx_0;
  real_T theta_idx_1;
  if (rtmIsMajorTimeStep(sliding_mode_ctrl_M)) {
    /* set solver stop time */
    if (!(sliding_mode_ctrl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sliding_mode_ctrl_M->solverInfo,
                            ((sliding_mode_ctrl_M->Timing.clockTickH0 + 1) *
        sliding_mode_ctrl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sliding_mode_ctrl_M->solverInfo,
                            ((sliding_mode_ctrl_M->Timing.clockTick0 + 1) *
        sliding_mode_ctrl_M->Timing.stepSize0 +
        sliding_mode_ctrl_M->Timing.clockTickH0 *
        sliding_mode_ctrl_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sliding_mode_ctrl_M)) {
    sliding_mode_ctrl_M->Timing.t[0] = rtsiGetT(&sliding_mode_ctrl_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(sliding_mode_ctrl_M)) {
    /* S-Function (hil_read_encoder_block): '<S6>/HIL Read Encoder' */

    /* S-Function Block: sliding_mode_ctrl/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILReadEncoder_channels, 2,
        &sliding_mode_ctrl_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = sliding_mode_ctrl_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = sliding_mode_ctrl_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S6>/Encoder Gain' incorporates:
     *  Constant: '<S6>/Home Position'
     *  Sum: '<S6>/Sum1'
     */
    sliding_mode_ctrl_B.EncoderGain[0] =
      (sliding_mode_ctrl_P.HomePosition_Value[0] + rtb_HILReadAnalog[0]) *
      sliding_mode_ctrl_P.EncoderGain_Gain[0];
    sliding_mode_ctrl_B.EncoderGain[1] =
      (sliding_mode_ctrl_P.HomePosition_Value[1] + rtb_HILReadAnalog[1]) *
      sliding_mode_ctrl_P.EncoderGain_Gain[1];
  }

  /* Derivative: '<S6>/Derivative' incorporates:
   *  Clock: '<Root>/Clock'
   *  Derivative: '<Root>/Derivative'
   *  Derivative: '<Root>/Derivative1'
   *  Derivative: '<Root>/Derivative2'
   *  Gain: '<S6>/Encoder Gain'
   */
  H12 = sliding_mode_ctrl_M->Timing.t[0];
  if ((sliding_mode_ctrl_DW.TimeStampA >= H12) &&
      (sliding_mode_ctrl_DW.TimeStampB >= H12)) {
    rtb_Derivative_idx_0 = 0.0;
    rtb_Derivative_idx_1 = 0.0;
  } else {
    h = sliding_mode_ctrl_DW.TimeStampA;
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA;
    if (sliding_mode_ctrl_DW.TimeStampA < sliding_mode_ctrl_DW.TimeStampB) {
      if (sliding_mode_ctrl_DW.TimeStampB < H12) {
        h = sliding_mode_ctrl_DW.TimeStampB;
        lastU = &sliding_mode_ctrl_DW.LastUAtTimeB;
      }
    } else if (sliding_mode_ctrl_DW.TimeStampA >= H12) {
      h = sliding_mode_ctrl_DW.TimeStampB;
      lastU = &sliding_mode_ctrl_DW.LastUAtTimeB;
    }

    h = H12 - h;
    rtb_Derivative_idx_0 = (sliding_mode_ctrl_B.EncoderGain[0] - (*lastU)[0]) /
      h;
    rtb_Derivative_idx_1 = (sliding_mode_ctrl_B.EncoderGain[1] - (*lastU)[1]) /
      h;
  }

  /* End of Derivative: '<S6>/Derivative' */

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Constant: '<Root>/Speed'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S7>:1' */
  if (H12 < 1.0) {
    /* '<S7>:1:6' */
    /* '<S7>:1:7' */
    h = (1.0 - cos(3.1415926535897931 * H12)) * 0.025;
    sliding_mode_ctrl_B.x[0] = h + 0.15;

    /* '<S7>:1:8' */
    sliding_mode_ctrl_B.x[1] = 0.15 - h;
  } else if (H12 < 1.5) {
    /* '<S7>:1:9' */
    /* '<S7>:1:10' */
    h = (H12 - 1.0) * (H12 - 1.0) * (6.2831853071795862 *
      sliding_mode_ctrl_P.Speed_Value);
    sliding_mode_ctrl_B.x[0] = cos(h) * 0.075 + 0.125;

    /* '<S7>:1:11' */
    sliding_mode_ctrl_B.x[1] = sin(h) * 0.075 + 0.1;
  } else {
    /* '<S7>:1:13' */
    h = 6.2831853071795862 * sliding_mode_ctrl_P.Speed_Value * (H12 - 1.25);
    sliding_mode_ctrl_B.x[0] = cos(h) * 0.075 + 0.125;

    /* '<S7>:1:14' */
    sliding_mode_ctrl_B.x[1] = sin(h) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  /* MATLAB Function 'Inverse Kinematics': '<S4>:1' */
  /* '<S4>:1:10' */
  /* '<S4>:1:4' */
  /* '<S4>:1:5' */
  /* '<S4>:1:8' */
  h = sliding_mode_ctrl_B.x[0] * sliding_mode_ctrl_B.x[0] +
    sliding_mode_ctrl_B.x[1] * sliding_mode_ctrl_B.x[1];
  theta_idx_1 = atan(sqrt((0.09 - h) / h)) * -2.0;

  /* '<S4>:1:9' */
  theta_idx_0 = rt_atan2d_snf(sliding_mode_ctrl_B.x[1], sliding_mode_ctrl_B.x[0])
    - rt_atan2d_snf(0.15 * sin(theta_idx_1), 0.15 * cos(theta_idx_1) + 0.15);

  /* '<S4>:1:10' */
  sliding_mode_ctrl_B.phi[0] = 0.0;
  sliding_mode_ctrl_B.phi[0] += theta_idx_0;
  sliding_mode_ctrl_B.phi[0] += 0.0 * theta_idx_1;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S6>/Encoder Gain'
   */
  sliding_mode_ctrl_B.Sum2[0] = sliding_mode_ctrl_B.phi[0] -
    sliding_mode_ctrl_B.EncoderGain[0];

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  sliding_mode_ctrl_B.phi[1] = 0.0;
  sliding_mode_ctrl_B.phi[1] += theta_idx_0;
  sliding_mode_ctrl_B.phi[1] += theta_idx_1;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S6>/Encoder Gain'
   */
  sliding_mode_ctrl_B.Sum2[1] = sliding_mode_ctrl_B.phi[1] -
    sliding_mode_ctrl_B.EncoderGain[1];

  /* Derivative: '<Root>/Derivative' incorporates:
   *  Derivative: '<Root>/Derivative1'
   *  Sum: '<Root>/Sum2'
   */
  if ((sliding_mode_ctrl_DW.TimeStampA_a >= H12) &&
      (sliding_mode_ctrl_DW.TimeStampB_f >= H12)) {
    theta_idx_0 = 0.0;
    theta_idx_1 = 0.0;
  } else {
    h = sliding_mode_ctrl_DW.TimeStampA_a;
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_e;
    if (sliding_mode_ctrl_DW.TimeStampA_a < sliding_mode_ctrl_DW.TimeStampB_f) {
      if (sliding_mode_ctrl_DW.TimeStampB_f < H12) {
        h = sliding_mode_ctrl_DW.TimeStampB_f;
        lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_d;
      }
    } else if (sliding_mode_ctrl_DW.TimeStampA_a >= H12) {
      h = sliding_mode_ctrl_DW.TimeStampB_f;
      lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_d;
    }

    h = H12 - h;
    theta_idx_0 = (sliding_mode_ctrl_B.Sum2[0] - (*lastU)[0]) / h;
    theta_idx_1 = (sliding_mode_ctrl_B.Sum2[1] - (*lastU)[1]) / h;
  }

  /* Gain: '<Root>/1//eps' incorporates:
   *  Derivative: '<Root>/Derivative1'
   *  Gain: '<Root>/Lambda'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum2'
   */
  sliding_mode_ctrl_B.ueps[0] = (sliding_mode_ctrl_P.Lambda_Gain *
    sliding_mode_ctrl_B.Sum2[0] + theta_idx_0) * sliding_mode_ctrl_P.ueps_Gain;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Gain: '<Root>/1//eps'
   */
  if (sliding_mode_ctrl_B.ueps[0] > sliding_mode_ctrl_P.Saturation_UpperSat) {
    h = sliding_mode_ctrl_P.Saturation_UpperSat;
  } else if (sliding_mode_ctrl_B.ueps[0] <
             sliding_mode_ctrl_P.Saturation_LowerSat) {
    h = sliding_mode_ctrl_P.Saturation_LowerSat;
  } else {
    h = sliding_mode_ctrl_B.ueps[0];
  }

  /* Gain: '<Root>/rho' */
  sliding_mode_ctrl_B.rho[0] = sliding_mode_ctrl_P.rho_Gain * h;

  /* Gain: '<S43>/Filter Coefficient' incorporates:
   *  Gain: '<S34>/Derivative Gain'
   *  Integrator: '<S35>/Filter'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S35>/SumD'
   */
  sliding_mode_ctrl_B.FilterCoefficient[0] =
    (sliding_mode_ctrl_P.PIDController_D * sliding_mode_ctrl_B.Sum2[0] -
     sliding_mode_ctrl_X.Filter_CSTATE[0]) * sliding_mode_ctrl_P.PIDController_N;

  /* Gain: '<Root>/1//eps' incorporates:
   *  Derivative: '<Root>/Derivative1'
   *  Gain: '<Root>/Lambda'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum2'
   */
  sliding_mode_ctrl_B.ueps[1] = (sliding_mode_ctrl_P.Lambda_Gain *
    sliding_mode_ctrl_B.Sum2[1] + theta_idx_1) * sliding_mode_ctrl_P.ueps_Gain;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Gain: '<Root>/1//eps'
   */
  if (sliding_mode_ctrl_B.ueps[1] > sliding_mode_ctrl_P.Saturation_UpperSat) {
    h = sliding_mode_ctrl_P.Saturation_UpperSat;
  } else if (sliding_mode_ctrl_B.ueps[1] <
             sliding_mode_ctrl_P.Saturation_LowerSat) {
    h = sliding_mode_ctrl_P.Saturation_LowerSat;
  } else {
    h = sliding_mode_ctrl_B.ueps[1];
  }

  /* Gain: '<Root>/rho' */
  sliding_mode_ctrl_B.rho[1] = sliding_mode_ctrl_P.rho_Gain * h;

  /* Gain: '<S43>/Filter Coefficient' incorporates:
   *  Gain: '<S34>/Derivative Gain'
   *  Integrator: '<S35>/Filter'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S35>/SumD'
   */
  sliding_mode_ctrl_B.FilterCoefficient[1] =
    (sliding_mode_ctrl_P.PIDController_D * sliding_mode_ctrl_B.Sum2[1] -
     sliding_mode_ctrl_X.Filter_CSTATE[1]) * sliding_mode_ctrl_P.PIDController_N;

  /* Derivative: '<Root>/Derivative2' */
  if ((sliding_mode_ctrl_DW.TimeStampA_b >= H12) &&
      (sliding_mode_ctrl_DW.TimeStampB_c >= H12)) {
    /* Derivative: '<Root>/Derivative2' */
    sliding_mode_ctrl_B.Derivative2[0] = 0.0;
    sliding_mode_ctrl_B.Derivative2[1] = 0.0;
  } else {
    h = sliding_mode_ctrl_DW.TimeStampA_b;
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_c;
    if (sliding_mode_ctrl_DW.TimeStampA_b < sliding_mode_ctrl_DW.TimeStampB_c) {
      if (sliding_mode_ctrl_DW.TimeStampB_c < H12) {
        h = sliding_mode_ctrl_DW.TimeStampB_c;
        lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_a;
      }
    } else if (sliding_mode_ctrl_DW.TimeStampA_b >= H12) {
      h = sliding_mode_ctrl_DW.TimeStampB_c;
      lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_a;
    }

    h = H12 - h;

    /* Derivative: '<Root>/Derivative2' */
    sliding_mode_ctrl_B.Derivative2[0] = (sliding_mode_ctrl_B.phi[0] - (*lastU)
      [0]) / h;
    sliding_mode_ctrl_B.Derivative2[1] = (sliding_mode_ctrl_B.phi[1] - (*lastU)
      [1]) / h;
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((sliding_mode_ctrl_DW.TimeStampA_l >= H12) &&
      (sliding_mode_ctrl_DW.TimeStampB_m >= H12)) {
    theta_idx_0 = 0.0;
    theta_idx_1 = 0.0;
  } else {
    h = sliding_mode_ctrl_DW.TimeStampA_l;
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_f;
    if (sliding_mode_ctrl_DW.TimeStampA_l < sliding_mode_ctrl_DW.TimeStampB_m) {
      if (sliding_mode_ctrl_DW.TimeStampB_m < H12) {
        h = sliding_mode_ctrl_DW.TimeStampB_m;
        lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_b;
      }
    } else if (sliding_mode_ctrl_DW.TimeStampA_l >= H12) {
      h = sliding_mode_ctrl_DW.TimeStampB_m;
      lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_b;
    }

    h = H12 - h;
    theta_idx_0 = (sliding_mode_ctrl_B.Derivative2[0] - (*lastU)[0]) / h;
    theta_idx_1 = (sliding_mode_ctrl_B.Derivative2[1] - (*lastU)[1]) / h;
  }

  /* MATLAB Function: '<Root>/Inertia Matrix' incorporates:
   *  Gain: '<S6>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   */
  /* MATLAB Function 'Inertia Matrix': '<S3>:1' */
  /* '<S3>:1:4' */
  /* '<S3>:1:7' */
  /* '<S3>:1:9' */
  /* '<S3>:1:23' */
  h = sliding_mode_ctrl_B.EncoderGain[1] - sliding_mode_ctrl_B.EncoderGain[0];
  H12 = cos(h) * 0.00041579999999999997;

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S6>/Derivative'
   *  Gain: '<S6>/Encoder Gain'
   *  MATLAB Function: '<Root>/Forward Kinematics'
   */
  /* '<S3>:1:27' */
  /* '<S3>:1:29' */
  /* MATLAB Function 'Feedback Comp': '<S1>:1' */
  /* '<S1>:1:4' */
  /* '<S1>:1:6' */
  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /* '<S1>:1:9' */
  /* '<S1>:1:14' */
  /* '<S1>:1:15' */
  /* '<S1>:1:16' */
  /* '<S1>:1:17' */
  /* '<S1>:1:18' */
  /* '<S1>:1:19' */
  /* '<S1>:1:20' */
  /* '<S1>:1:22' */
  h = sin(h) * 0.00041579999999999997;

  /* '<S1>:1:23' */
  /* '<S1>:1:24' */
  /* '<S1>:1:25' */
  /* '<S1>:1:26' */
  /* '<S1>:1:28' */
  /* '<S1>:1:29' */
  /* '<S1>:1:30' */
  /* '<S1>:1:32' */
  Current_tmp = cos(sliding_mode_ctrl_B.EncoderGain[0]);
  Current_tmp_0 = cos(sliding_mode_ctrl_B.EncoderGain[1]);
  rtb_Derivative_idx_0_0 = rtb_Derivative_idx_0 * rtb_Derivative_idx_0;
  rtb_Derivative_idx_1_0 = rtb_Derivative_idx_1 * rtb_Derivative_idx_1;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/rho'
   *  Gain: '<S43>/Filter Coefficient'
   *  Gain: '<S45>/Proportional Gain'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S49>/Sum'
   */
  theta_idx_0 += (sliding_mode_ctrl_P.PIDController_P *
                  sliding_mode_ctrl_B.Sum2[0] +
                  sliding_mode_ctrl_B.FilterCoefficient[0]) +
    sliding_mode_ctrl_B.rho[0];
  theta_idx_1 += (sliding_mode_ctrl_P.PIDController_P *
                  sliding_mode_ctrl_B.Sum2[1] +
                  sliding_mode_ctrl_B.FilterCoefficient[1]) +
    sliding_mode_ctrl_B.rho[1];

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S6>/Derivative'
   */
  if (rtb_Derivative_idx_0 < 0.0) {
    rtb_Derivative_idx_0_1 = -1.0;
  } else if (rtb_Derivative_idx_0 > 0.0) {
    rtb_Derivative_idx_0_1 = 1.0;
  } else if (rtb_Derivative_idx_0 == 0.0) {
    rtb_Derivative_idx_0_1 = 0.0;
  } else {
    rtb_Derivative_idx_0_1 = (rtNaN);
  }

  /* Gain: '<Root>/1//AmpGain (V//A)1' incorporates:
   *  Derivative: '<S6>/Derivative'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Inertia Matrix'
   *  Sum: '<Root>/Sum4'
   */
  sliding_mode_ctrl_B.Current[0] = ((((0.0 * rtb_Derivative_idx_0_0 + -h *
    rtb_Derivative_idx_1_0) + 0.1690892 * Current_tmp) + (0.01519 *
    rtb_Derivative_idx_0 + 0.007 * rtb_Derivative_idx_0_1)) + (0.0055575 *
    theta_idx_0 + H12 * theta_idx_1)) * sliding_mode_ctrl_P.uAmpGainVA1_Gain;

  /* Gain: '<S6>/1//AmpGain' incorporates:
   *  Bias: '<S6>/Amp Bias Tune for each  amp//channel if needed'
   */
  sliding_mode_ctrl_B.uAmpGain[0] = (sliding_mode_ctrl_B.Current[0] +
    sliding_mode_ctrl_P.AmpBiasTuneforeachampchannelifn[0]) *
    sliding_mode_ctrl_P.uAmpGain_Gain[0];

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S6>/Derivative'
   */
  if (rtb_Derivative_idx_1 < 0.0) {
    rtb_Derivative_idx_0 = -1.0;
  } else if (rtb_Derivative_idx_1 > 0.0) {
    rtb_Derivative_idx_0 = 1.0;
  } else if (rtb_Derivative_idx_1 == 0.0) {
    rtb_Derivative_idx_0 = 0.0;
  } else {
    rtb_Derivative_idx_0 = (rtNaN);
  }

  /* Gain: '<Root>/1//AmpGain (V//A)1' incorporates:
   *  Derivative: '<S6>/Derivative'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Inertia Matrix'
   *  Sum: '<Root>/Sum4'
   */
  sliding_mode_ctrl_B.Current[1] = ((((h * rtb_Derivative_idx_0_0 + 0.0 *
    rtb_Derivative_idx_1_0) + 0.027165599999999998 * Current_tmp_0) + (0.01519 *
    rtb_Derivative_idx_1 + 0.007 * rtb_Derivative_idx_0)) + (H12 * theta_idx_0 +
    0.0034850000000000003 * theta_idx_1)) * sliding_mode_ctrl_P.uAmpGainVA1_Gain;

  /* Gain: '<S6>/1//AmpGain' incorporates:
   *  Bias: '<S6>/Amp Bias Tune for each  amp//channel if needed'
   */
  sliding_mode_ctrl_B.uAmpGain[1] = (sliding_mode_ctrl_B.Current[1] +
    sliding_mode_ctrl_P.AmpBiasTuneforeachampchannelifn[1]) *
    sliding_mode_ctrl_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(sliding_mode_ctrl_M)) {
    /* S-Function (hil_write_analog_block): '<S6>/HIL Write Analog' */

    /* S-Function Block: sliding_mode_ctrl/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILWriteAnalog_channels, 2,
        &sliding_mode_ctrl_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S6>/HIL Read Analog' */

    /* S-Function Block: sliding_mode_ctrl/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
      }
    }

    /* Bias: '<S6>/Current Sense Bias Tune for each amp//channel if needed' incorporates:
     *  Gain: '<S6>/1//Sense Gain'
     */
    sliding_mode_ctrl_B.CurrentSenseBiasTuneforeachampc[0] =
      sliding_mode_ctrl_P.uSenseGain_Gain * rtb_HILReadAnalog[0] +
      sliding_mode_ctrl_P.CurrentSenseBiasTuneforeachampc[0];
    sliding_mode_ctrl_B.CurrentSenseBiasTuneforeachampc[1] =
      sliding_mode_ctrl_P.uSenseGain_Gain * rtb_HILReadAnalog[1] +
      sliding_mode_ctrl_P.CurrentSenseBiasTuneforeachampc[1];

    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S6>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S2>:1' */
    /* '<S2>:1:4' */
    /* '<S2>:1:5' */
    /* '<S2>:1:7' */
    sliding_mode_ctrl_B.x_b[0] = 0.15 * Current_tmp + 0.15 * Current_tmp_0;

    /* '<S2>:1:8' */
    sliding_mode_ctrl_B.x_b[1] = 0.15 * sin(sliding_mode_ctrl_B.EncoderGain[0])
      + 0.15 * sin(sliding_mode_ctrl_B.EncoderGain[1]);

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S6>/Encoder Gain'
     */
    if (sliding_mode_ctrl_M->Timing.RateInteraction.TID1_2) {
      sliding_mode_ctrl_DW.RateTransition_Buffer[0] =
        sliding_mode_ctrl_B.EncoderGain[0];
      sliding_mode_ctrl_DW.RateTransition_Buffer[1] =
        sliding_mode_ctrl_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void sliding_mode_ctrl_update0(void)   /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<S6>/Derivative' incorporates:
   *  Gain: '<S6>/Encoder Gain'
   */
  if (sliding_mode_ctrl_DW.TimeStampA == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampA = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA;
  } else if (sliding_mode_ctrl_DW.TimeStampB == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampB = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB;
  } else if (sliding_mode_ctrl_DW.TimeStampA < sliding_mode_ctrl_DW.TimeStampB)
  {
    sliding_mode_ctrl_DW.TimeStampA = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA;
  } else {
    sliding_mode_ctrl_DW.TimeStampB = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB;
  }

  (*lastU)[0] = sliding_mode_ctrl_B.EncoderGain[0];
  (*lastU)[1] = sliding_mode_ctrl_B.EncoderGain[1];

  /* End of Update for Derivative: '<S6>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  if (sliding_mode_ctrl_DW.TimeStampA_a == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampA_a = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_e;
  } else if (sliding_mode_ctrl_DW.TimeStampB_f == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampB_f = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_d;
  } else if (sliding_mode_ctrl_DW.TimeStampA_a <
             sliding_mode_ctrl_DW.TimeStampB_f) {
    sliding_mode_ctrl_DW.TimeStampA_a = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_e;
  } else {
    sliding_mode_ctrl_DW.TimeStampB_f = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_d;
  }

  (*lastU)[0] = sliding_mode_ctrl_B.Sum2[0];
  (*lastU)[1] = sliding_mode_ctrl_B.Sum2[1];

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative2' */
  if (sliding_mode_ctrl_DW.TimeStampA_b == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampA_b = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_c;
  } else if (sliding_mode_ctrl_DW.TimeStampB_c == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampB_c = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_a;
  } else if (sliding_mode_ctrl_DW.TimeStampA_b <
             sliding_mode_ctrl_DW.TimeStampB_c) {
    sliding_mode_ctrl_DW.TimeStampA_b = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_c;
  } else {
    sliding_mode_ctrl_DW.TimeStampB_c = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_a;
  }

  (*lastU)[0] = sliding_mode_ctrl_B.phi[0];
  (*lastU)[1] = sliding_mode_ctrl_B.phi[1];

  /* End of Update for Derivative: '<Root>/Derivative2' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (sliding_mode_ctrl_DW.TimeStampA_l == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampA_l = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_f;
  } else if (sliding_mode_ctrl_DW.TimeStampB_m == (rtInf)) {
    sliding_mode_ctrl_DW.TimeStampB_m = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_b;
  } else if (sliding_mode_ctrl_DW.TimeStampA_l <
             sliding_mode_ctrl_DW.TimeStampB_m) {
    sliding_mode_ctrl_DW.TimeStampA_l = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeA_f;
  } else {
    sliding_mode_ctrl_DW.TimeStampB_m = sliding_mode_ctrl_M->Timing.t[0];
    lastU = &sliding_mode_ctrl_DW.LastUAtTimeB_b;
  }

  (*lastU)[0] = sliding_mode_ctrl_B.Derivative2[0];
  (*lastU)[1] = sliding_mode_ctrl_B.Derivative2[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(sliding_mode_ctrl_M)) {
    rt_ertODEUpdateContinuousStates(&sliding_mode_ctrl_M->solverInfo);
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
  if (!(++sliding_mode_ctrl_M->Timing.clockTick0)) {
    ++sliding_mode_ctrl_M->Timing.clockTickH0;
  }

  sliding_mode_ctrl_M->Timing.t[0] = rtsiGetSolverStopTime
    (&sliding_mode_ctrl_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sliding_mode_ctrl_M->Timing.clockTick1)) {
    ++sliding_mode_ctrl_M->Timing.clockTickH1;
  }

  sliding_mode_ctrl_M->Timing.t[1] = sliding_mode_ctrl_M->Timing.clockTick1 *
    sliding_mode_ctrl_M->Timing.stepSize1 +
    sliding_mode_ctrl_M->Timing.clockTickH1 *
    sliding_mode_ctrl_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void sliding_mode_ctrl_derivatives(void)
{
  XDot_sliding_mode_ctrl_T *_rtXdot;
  _rtXdot = ((XDot_sliding_mode_ctrl_T *) sliding_mode_ctrl_M->derivs);

  /* Derivatives for Integrator: '<S35>/Filter' incorporates:
   *  Gain: '<S43>/Filter Coefficient'
   */
  _rtXdot->Filter_CSTATE[0] = sliding_mode_ctrl_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = sliding_mode_ctrl_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void sliding_mode_ctrl_output2(void)   /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  sliding_mode_ctrl_B.RateTransition[0] =
    sliding_mode_ctrl_DW.RateTransition_Buffer[0];
  sliding_mode_ctrl_B.RateTransition[1] =
    sliding_mode_ctrl_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void sliding_mode_ctrl_update2(void)   /* Sample time: [0.02s, 0.0s] */
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
  if (!(++sliding_mode_ctrl_M->Timing.clockTick2)) {
    ++sliding_mode_ctrl_M->Timing.clockTickH2;
  }

  sliding_mode_ctrl_M->Timing.t[2] = sliding_mode_ctrl_M->Timing.clockTick2 *
    sliding_mode_ctrl_M->Timing.stepSize2 +
    sliding_mode_ctrl_M->Timing.clockTickH2 *
    sliding_mode_ctrl_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void sliding_mode_ctrl_output(int_T tid)
{
  switch (tid) {
   case 0 :
    sliding_mode_ctrl_output0();
    break;

   case 2 :
    sliding_mode_ctrl_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void sliding_mode_ctrl_update(int_T tid)
{
  switch (tid) {
   case 0 :
    sliding_mode_ctrl_update0();
    break;

   case 2 :
    sliding_mode_ctrl_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void sliding_mode_ctrl_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S6>/HIL Initialize' */

  /* S-Function Block: sliding_mode_ctrl/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &sliding_mode_ctrl_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (sliding_mode_ctrl_DW.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(sliding_mode_ctrl_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
      return;
    }

    if ((sliding_mode_ctrl_P.HILInitialize_AIPStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &sliding_mode_ctrl_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (sliding_mode_ctrl_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &sliding_mode_ctrl_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = sliding_mode_ctrl_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (sliding_mode_ctrl_DW.HILInitialize_Card,
         sliding_mode_ctrl_P.HILInitialize_AIChannels, 8U,
         &sliding_mode_ctrl_DW.HILInitialize_AIMinimums[0],
         &sliding_mode_ctrl_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if ((sliding_mode_ctrl_P.HILInitialize_AOPStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &sliding_mode_ctrl_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (sliding_mode_ctrl_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &sliding_mode_ctrl_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = sliding_mode_ctrl_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (sliding_mode_ctrl_DW.HILInitialize_Card,
         sliding_mode_ctrl_P.HILInitialize_AOChannels, 8U,
         &sliding_mode_ctrl_DW.HILInitialize_AOMinimums[0],
         &sliding_mode_ctrl_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if ((sliding_mode_ctrl_P.HILInitialize_AOStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = sliding_mode_ctrl_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILInitialize_AOChannels, 8U,
        &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if (sliding_mode_ctrl_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = sliding_mode_ctrl_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (sliding_mode_ctrl_DW.HILInitialize_Card,
         sliding_mode_ctrl_P.HILInitialize_AOChannels, 8U,
         &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if ((sliding_mode_ctrl_P.HILInitialize_EIPStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &sliding_mode_ctrl_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            sliding_mode_ctrl_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (sliding_mode_ctrl_DW.HILInitialize_Card,
         sliding_mode_ctrl_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &sliding_mode_ctrl_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if ((sliding_mode_ctrl_P.HILInitialize_EIStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &sliding_mode_ctrl_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = sliding_mode_ctrl_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILInitialize_EIChannels, 8U,
        &sliding_mode_ctrl_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if ((sliding_mode_ctrl_P.HILInitialize_POPStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &sliding_mode_ctrl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = sliding_mode_ctrl_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &sliding_mode_ctrl_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          sliding_mode_ctrl_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &sliding_mode_ctrl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            sliding_mode_ctrl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = sliding_mode_ctrl_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            sliding_mode_ctrl_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              sliding_mode_ctrl_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(sliding_mode_ctrl_DW.HILInitialize_Card,
          &sliding_mode_ctrl_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(sliding_mode_ctrl_DW.HILInitialize_Card,
          &sliding_mode_ctrl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &sliding_mode_ctrl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            sliding_mode_ctrl_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &sliding_mode_ctrl_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = sliding_mode_ctrl_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &sliding_mode_ctrl_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = sliding_mode_ctrl_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *)
        &sliding_mode_ctrl_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &sliding_mode_ctrl_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &sliding_mode_ctrl_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = sliding_mode_ctrl_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &sliding_mode_ctrl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = sliding_mode_ctrl_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILInitialize_POChannels, 8U,
        &sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[0],
        &sliding_mode_ctrl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if ((sliding_mode_ctrl_P.HILInitialize_POStart && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &sliding_mode_ctrl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = sliding_mode_ctrl_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(sliding_mode_ctrl_DW.HILInitialize_Card,
        sliding_mode_ctrl_P.HILInitialize_POChannels, 8U,
        &sliding_mode_ctrl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }

    if (sliding_mode_ctrl_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &sliding_mode_ctrl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = sliding_mode_ctrl_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (sliding_mode_ctrl_DW.HILInitialize_Card,
         sliding_mode_ctrl_P.HILInitialize_POChannels, 8U,
         &sliding_mode_ctrl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Derivative: '<S6>/Derivative' */
  sliding_mode_ctrl_DW.TimeStampA = (rtInf);
  sliding_mode_ctrl_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  sliding_mode_ctrl_DW.TimeStampA_a = (rtInf);
  sliding_mode_ctrl_DW.TimeStampB_f = (rtInf);

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  sliding_mode_ctrl_X.Filter_CSTATE[0] =
    sliding_mode_ctrl_P.PIDController_InitialConditionF;
  sliding_mode_ctrl_X.Filter_CSTATE[1] =
    sliding_mode_ctrl_P.PIDController_InitialConditionF;

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  sliding_mode_ctrl_DW.TimeStampA_b = (rtInf);
  sliding_mode_ctrl_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  sliding_mode_ctrl_DW.TimeStampA_l = (rtInf);
  sliding_mode_ctrl_DW.TimeStampB_m = (rtInf);
}

/* Model terminate function */
void sliding_mode_ctrl_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S6>/HIL Initialize' */

  /* S-Function Block: sliding_mode_ctrl/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(sliding_mode_ctrl_DW.HILInitialize_Card);
    hil_monitor_stop_all(sliding_mode_ctrl_DW.HILInitialize_Card);
    is_switching = false;
    if ((sliding_mode_ctrl_P.HILInitialize_AOTerminate && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = sliding_mode_ctrl_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((sliding_mode_ctrl_P.HILInitialize_POTerminate && !is_switching) ||
        (sliding_mode_ctrl_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &sliding_mode_ctrl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = sliding_mode_ctrl_P.HILInitialize_POFinal;
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
      result = hil_write(sliding_mode_ctrl_DW.HILInitialize_Card
                         , sliding_mode_ctrl_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , sliding_mode_ctrl_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0]
                         , &sliding_mode_ctrl_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (sliding_mode_ctrl_DW.HILInitialize_Card,
             sliding_mode_ctrl_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &sliding_mode_ctrl_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(sliding_mode_ctrl_DW.HILInitialize_Card,
            sliding_mode_ctrl_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &sliding_mode_ctrl_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(sliding_mode_ctrl_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(sliding_mode_ctrl_DW.HILInitialize_Card);
    hil_monitor_delete_all(sliding_mode_ctrl_DW.HILInitialize_Card);
    hil_close(sliding_mode_ctrl_DW.HILInitialize_Card);
    sliding_mode_ctrl_DW.HILInitialize_Card = NULL;
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
  sliding_mode_ctrl_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  sliding_mode_ctrl_update(tid);
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
  sliding_mode_ctrl_initialize();
}

void MdlTerminate(void)
{
  sliding_mode_ctrl_terminate();
}

/* Registration function */
RT_MODEL_sliding_mode_ctrl_T *sliding_mode_ctrl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sliding_mode_ctrl_M, 0,
                sizeof(RT_MODEL_sliding_mode_ctrl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sliding_mode_ctrl_M->solverInfo,
                          &sliding_mode_ctrl_M->Timing.simTimeStep);
    rtsiSetTPtr(&sliding_mode_ctrl_M->solverInfo, &rtmGetTPtr
                (sliding_mode_ctrl_M));
    rtsiSetStepSizePtr(&sliding_mode_ctrl_M->solverInfo,
                       &sliding_mode_ctrl_M->Timing.stepSize0);
    rtsiSetdXPtr(&sliding_mode_ctrl_M->solverInfo, &sliding_mode_ctrl_M->derivs);
    rtsiSetContStatesPtr(&sliding_mode_ctrl_M->solverInfo, (real_T **)
                         &sliding_mode_ctrl_M->contStates);
    rtsiSetNumContStatesPtr(&sliding_mode_ctrl_M->solverInfo,
      &sliding_mode_ctrl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sliding_mode_ctrl_M->solverInfo,
      &sliding_mode_ctrl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sliding_mode_ctrl_M->solverInfo,
      &sliding_mode_ctrl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sliding_mode_ctrl_M->solverInfo,
      &sliding_mode_ctrl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&sliding_mode_ctrl_M->solverInfo, (&rtmGetErrorStatus
      (sliding_mode_ctrl_M)));
    rtsiSetRTModelPtr(&sliding_mode_ctrl_M->solverInfo, sliding_mode_ctrl_M);
  }

  rtsiSetSimTimeStep(&sliding_mode_ctrl_M->solverInfo, MAJOR_TIME_STEP);
  sliding_mode_ctrl_M->intgData.f[0] = sliding_mode_ctrl_M->odeF[0];
  sliding_mode_ctrl_M->contStates = ((real_T *) &sliding_mode_ctrl_X);
  rtsiSetSolverData(&sliding_mode_ctrl_M->solverInfo, (void *)
                    &sliding_mode_ctrl_M->intgData);
  rtsiSetSolverName(&sliding_mode_ctrl_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sliding_mode_ctrl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "sliding_mode_ctrl_M points to
       static memory which is guaranteed to be non-NULL" */
    sliding_mode_ctrl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sliding_mode_ctrl_M->Timing.sampleTimes =
      (&sliding_mode_ctrl_M->Timing.sampleTimesArray[0]);
    sliding_mode_ctrl_M->Timing.offsetTimes =
      (&sliding_mode_ctrl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sliding_mode_ctrl_M->Timing.sampleTimes[0] = (0.0);
    sliding_mode_ctrl_M->Timing.sampleTimes[1] = (0.001);
    sliding_mode_ctrl_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    sliding_mode_ctrl_M->Timing.offsetTimes[0] = (0.0);
    sliding_mode_ctrl_M->Timing.offsetTimes[1] = (0.0);
    sliding_mode_ctrl_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(sliding_mode_ctrl_M, &sliding_mode_ctrl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sliding_mode_ctrl_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      sliding_mode_ctrl_M->Timing.perTaskSampleHitsArray;
    sliding_mode_ctrl_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    sliding_mode_ctrl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sliding_mode_ctrl_M, 10.0);
  sliding_mode_ctrl_M->Timing.stepSize0 = 0.001;
  sliding_mode_ctrl_M->Timing.stepSize1 = 0.001;
  sliding_mode_ctrl_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  sliding_mode_ctrl_M->Sizes.checksums[0] = (1678831309U);
  sliding_mode_ctrl_M->Sizes.checksums[1] = (4032333847U);
  sliding_mode_ctrl_M->Sizes.checksums[2] = (4028664030U);
  sliding_mode_ctrl_M->Sizes.checksums[3] = (3716787866U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    sliding_mode_ctrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sliding_mode_ctrl_M->extModeInfo,
      &sliding_mode_ctrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sliding_mode_ctrl_M->extModeInfo,
                        sliding_mode_ctrl_M->Sizes.checksums);
    rteiSetTPtr(sliding_mode_ctrl_M->extModeInfo, rtmGetTPtr(sliding_mode_ctrl_M));
  }

  sliding_mode_ctrl_M->solverInfoPtr = (&sliding_mode_ctrl_M->solverInfo);
  sliding_mode_ctrl_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&sliding_mode_ctrl_M->solverInfo, 0.001);
  rtsiSetSolverMode(&sliding_mode_ctrl_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  sliding_mode_ctrl_M->blockIO = ((void *) &sliding_mode_ctrl_B);

  {
    sliding_mode_ctrl_B.EncoderGain[0] = 0.0;
    sliding_mode_ctrl_B.EncoderGain[1] = 0.0;
    sliding_mode_ctrl_B.Sum2[0] = 0.0;
    sliding_mode_ctrl_B.Sum2[1] = 0.0;
    sliding_mode_ctrl_B.ueps[0] = 0.0;
    sliding_mode_ctrl_B.ueps[1] = 0.0;
    sliding_mode_ctrl_B.rho[0] = 0.0;
    sliding_mode_ctrl_B.rho[1] = 0.0;
    sliding_mode_ctrl_B.FilterCoefficient[0] = 0.0;
    sliding_mode_ctrl_B.FilterCoefficient[1] = 0.0;
    sliding_mode_ctrl_B.Derivative2[0] = 0.0;
    sliding_mode_ctrl_B.Derivative2[1] = 0.0;
    sliding_mode_ctrl_B.Current[0] = 0.0;
    sliding_mode_ctrl_B.Current[1] = 0.0;
    sliding_mode_ctrl_B.uAmpGain[0] = 0.0;
    sliding_mode_ctrl_B.uAmpGain[1] = 0.0;
    sliding_mode_ctrl_B.CurrentSenseBiasTuneforeachampc[0] = 0.0;
    sliding_mode_ctrl_B.CurrentSenseBiasTuneforeachampc[1] = 0.0;
    sliding_mode_ctrl_B.RateTransition[0] = 0.0;
    sliding_mode_ctrl_B.RateTransition[1] = 0.0;
    sliding_mode_ctrl_B.x[0] = 0.0;
    sliding_mode_ctrl_B.x[1] = 0.0;
    sliding_mode_ctrl_B.phi[0] = 0.0;
    sliding_mode_ctrl_B.phi[1] = 0.0;
    sliding_mode_ctrl_B.x_b[0] = 0.0;
    sliding_mode_ctrl_B.x_b[1] = 0.0;
  }

  /* parameters */
  sliding_mode_ctrl_M->defaultParam = ((real_T *)&sliding_mode_ctrl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &sliding_mode_ctrl_X;
    sliding_mode_ctrl_M->contStates = (x);
    (void) memset((void *)&sliding_mode_ctrl_X, 0,
                  sizeof(X_sliding_mode_ctrl_T));
  }

  /* states (dwork) */
  sliding_mode_ctrl_M->dwork = ((void *) &sliding_mode_ctrl_DW);
  (void) memset((void *)&sliding_mode_ctrl_DW, 0,
                sizeof(DW_sliding_mode_ctrl_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sliding_mode_ctrl_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  sliding_mode_ctrl_DW.TimeStampA = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampB = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampA_a = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA_e[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA_e[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampB_f = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB_d[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB_d[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampA_b = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA_c[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA_c[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampB_c = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB_a[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB_a[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampA_l = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA_f[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeA_f[1] = 0.0;
  sliding_mode_ctrl_DW.TimeStampB_m = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB_b[0] = 0.0;
  sliding_mode_ctrl_DW.LastUAtTimeB_b[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      sliding_mode_ctrl_DW.XYSuperimposed_XBuffer[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      sliding_mode_ctrl_DW.XYSuperimposed_YBuffer[i] = 0.0;
    }
  }

  sliding_mode_ctrl_DW.RateTransition_Buffer[0] = 0.0;
  sliding_mode_ctrl_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sliding_mode_ctrl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  sliding_mode_ctrl_M->Sizes.numContStates = (2);/* Number of continuous states */
  sliding_mode_ctrl_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  sliding_mode_ctrl_M->Sizes.numY = (0);/* Number of model outputs */
  sliding_mode_ctrl_M->Sizes.numU = (0);/* Number of model inputs */
  sliding_mode_ctrl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sliding_mode_ctrl_M->Sizes.numSampTimes = (3);/* Number of sample times */
  sliding_mode_ctrl_M->Sizes.numBlocks = (53);/* Number of blocks */
  sliding_mode_ctrl_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  sliding_mode_ctrl_M->Sizes.numBlockPrms = (131);/* Sum of parameter "widths" */
  return sliding_mode_ctrl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
