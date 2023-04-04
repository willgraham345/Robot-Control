/*
 * IDC_OS_lab.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IDC_OS_lab".
 *
 * Model version              : 8.14
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Apr  1 13:17:11 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IDC_OS_lab.h"
#include "IDC_OS_lab_private.h"
#include "IDC_OS_lab_dt.h"

/* Block signals (default storage) */
B_IDC_OS_lab_T IDC_OS_lab_B;

/* Continuous states */
X_IDC_OS_lab_T IDC_OS_lab_X;

/* Block states (default storage) */
DW_IDC_OS_lab_T IDC_OS_lab_DW;

/* Real-time model */
static RT_MODEL_IDC_OS_lab_T IDC_OS_lab_M_;
RT_MODEL_IDC_OS_lab_T *const IDC_OS_lab_M = &IDC_OS_lab_M_;

/* Forward declaration for local functions */
static void IDC_OS_lab_inv(const real_T x[4], real_T y[4]);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(IDC_OS_lab_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(IDC_OS_lab_M, 2);
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
  if (IDC_OS_lab_M->Timing.TaskCounters.TID[1] == 0) {
    IDC_OS_lab_M->Timing.RateInteraction.TID1_2 =
      (IDC_OS_lab_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    IDC_OS_lab_M->Timing.perTaskSampleHits[5] =
      IDC_OS_lab_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (IDC_OS_lab_M->Timing.TaskCounters.TID[2])++;
  if ((IDC_OS_lab_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    IDC_OS_lab_M->Timing.TaskCounters.TID[2] = 0;
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
  IDC_OS_lab_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/Hx Matrix' */
static void IDC_OS_lab_inv(const real_T x[4], real_T y[4])
{
  real_T r;
  real_T t;
  if (fabs(x[1]) > fabs(x[0])) {
    r = x[0] / x[1];
    t = 1.0 / (r * x[3] - x[2]);
    y[0] = x[3] / x[1] * t;
    y[1] = -t;
    y[2] = -x[2] / x[1] * t;
    y[3] = r * t;
  } else {
    r = x[1] / x[0];
    t = 1.0 / (x[3] - r * x[2]);
    y[0] = x[3] / x[0] * t;
    y[1] = -r * t;
    y[2] = -x[2] / x[0] * t;
    y[3] = t;
  }
}

/* Model output function for TID0 */
void IDC_OS_lab_output0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T J[4];
  real_T J_0[4];
  real_T tmp[4];
  real_T tmp_0[4];
  real_T tmp_1[4];
  real_T rtb_Derivative1[2];
  real_T rtb_Derivative1_0[2];
  real_T tmp_2[2];
  real_T (*lastU)[2];
  real_T Current_tmp;
  real_T H12;
  real_T H12_tmp;
  real_T J_tmp;
  real_T h;
  real_T rtb_Derivative_idx_0;
  real_T rtb_Derivative_idx_1;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T x_tmp;
  int32_T J_tmp_0;
  int32_T i;
  static const int8_T b[4] = { 1, -1, 0, 1 };

  if (rtmIsMajorTimeStep(IDC_OS_lab_M)) {
    /* set solver stop time */
    if (!(IDC_OS_lab_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&IDC_OS_lab_M->solverInfo,
                            ((IDC_OS_lab_M->Timing.clockTickH0 + 1) *
        IDC_OS_lab_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&IDC_OS_lab_M->solverInfo,
                            ((IDC_OS_lab_M->Timing.clockTick0 + 1) *
        IDC_OS_lab_M->Timing.stepSize0 + IDC_OS_lab_M->Timing.clockTickH0 *
        IDC_OS_lab_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(IDC_OS_lab_M)) {
    IDC_OS_lab_M->Timing.t[0] = rtsiGetT(&IDC_OS_lab_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(IDC_OS_lab_M)) {
    /* S-Function (hil_read_encoder_block): '<S7>/HIL Read Encoder' */

    /* S-Function Block: IDC_OS_lab/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILReadEncoder_channels, 2,
        &IDC_OS_lab_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = IDC_OS_lab_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = IDC_OS_lab_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S7>/Encoder Gain' incorporates:
     *  Constant: '<S7>/Home Position'
     *  Sum: '<S7>/Sum1'
     */
    IDC_OS_lab_B.EncoderGain[0] = (IDC_OS_lab_P.HomePosition_Value[0] +
      rtb_HILReadAnalog[0]) * IDC_OS_lab_P.EncoderGain_Gain[0];
    IDC_OS_lab_B.EncoderGain[1] = (IDC_OS_lab_P.HomePosition_Value[1] +
      rtb_HILReadAnalog[1]) * IDC_OS_lab_P.EncoderGain_Gain[1];
  }

  /* Derivative: '<S7>/Derivative' incorporates:
   *  Clock: '<Root>/Clock'
   *  Derivative: '<Root>/Derivative1'
   *  Derivative: '<Root>/Derivative2'
   *  Gain: '<S7>/Encoder Gain'
   */
  H12 = IDC_OS_lab_M->Timing.t[0];
  if ((IDC_OS_lab_DW.TimeStampA >= H12) && (IDC_OS_lab_DW.TimeStampB >= H12)) {
    rtb_Derivative_idx_0 = 0.0;
    rtb_Derivative_idx_1 = 0.0;
  } else {
    h = IDC_OS_lab_DW.TimeStampA;
    lastU = &IDC_OS_lab_DW.LastUAtTimeA;
    if (IDC_OS_lab_DW.TimeStampA < IDC_OS_lab_DW.TimeStampB) {
      if (IDC_OS_lab_DW.TimeStampB < H12) {
        h = IDC_OS_lab_DW.TimeStampB;
        lastU = &IDC_OS_lab_DW.LastUAtTimeB;
      }
    } else if (IDC_OS_lab_DW.TimeStampA >= H12) {
      h = IDC_OS_lab_DW.TimeStampB;
      lastU = &IDC_OS_lab_DW.LastUAtTimeB;
    }

    h = H12 - h;
    rtb_Derivative_idx_0 = (IDC_OS_lab_B.EncoderGain[0] - (*lastU)[0]) / h;
    rtb_Derivative_idx_1 = (IDC_OS_lab_B.EncoderGain[1] - (*lastU)[1]) / h;
  }

  /* End of Derivative: '<S7>/Derivative' */
  if (rtmIsMajorTimeStep(IDC_OS_lab_M)) {
    /* Constant: '<Root>/Speed' */
    IDC_OS_lab_B.Speed = IDC_OS_lab_P.Speed_Value;
  }

  /* MATLAB Function: '<Root>/Trajectory  Generator' */
  /* MATLAB Function 'Trajectory  Generator': '<S8>:1' */
  if (H12 < 1.0) {
    /* '<S8>:1:6' */
    /* '<S8>:1:7' */
    x_tmp = (1.0 - cos(3.1415926535897931 * H12)) * 0.025;
    IDC_OS_lab_B.x[0] = x_tmp + 0.15;

    /* '<S8>:1:8' */
    IDC_OS_lab_B.x[1] = 0.15 - x_tmp;
  } else if (H12 < 1.5) {
    /* '<S8>:1:9' */
    /* '<S8>:1:10' */
    x_tmp = (H12 - 1.0) * (H12 - 1.0) * (6.2831853071795862 * IDC_OS_lab_B.Speed);
    IDC_OS_lab_B.x[0] = cos(x_tmp) * 0.075 + 0.125;

    /* '<S8>:1:11' */
    IDC_OS_lab_B.x[1] = sin(x_tmp) * 0.075 + 0.1;
  } else {
    /* '<S8>:1:13' */
    x_tmp = 6.2831853071795862 * IDC_OS_lab_B.Speed * (H12 - 1.25);
    IDC_OS_lab_B.x[0] = cos(x_tmp) * 0.075 + 0.125;

    /* '<S8>:1:14' */
    IDC_OS_lab_B.x[1] = sin(x_tmp) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* Derivative: '<Root>/Derivative2' */
  if ((IDC_OS_lab_DW.TimeStampA_b >= H12) && (IDC_OS_lab_DW.TimeStampB_c >= H12))
  {
    /* Derivative: '<Root>/Derivative2' */
    IDC_OS_lab_B.Derivative2[0] = 0.0;
    IDC_OS_lab_B.Derivative2[1] = 0.0;
  } else {
    h = IDC_OS_lab_DW.TimeStampA_b;
    lastU = &IDC_OS_lab_DW.LastUAtTimeA_c;
    if (IDC_OS_lab_DW.TimeStampA_b < IDC_OS_lab_DW.TimeStampB_c) {
      if (IDC_OS_lab_DW.TimeStampB_c < H12) {
        h = IDC_OS_lab_DW.TimeStampB_c;
        lastU = &IDC_OS_lab_DW.LastUAtTimeB_a;
      }
    } else if (IDC_OS_lab_DW.TimeStampA_b >= H12) {
      h = IDC_OS_lab_DW.TimeStampB_c;
      lastU = &IDC_OS_lab_DW.LastUAtTimeB_a;
    }

    h = H12 - h;

    /* Derivative: '<Root>/Derivative2' */
    IDC_OS_lab_B.Derivative2[0] = (IDC_OS_lab_B.x[0] - (*lastU)[0]) / h;
    IDC_OS_lab_B.Derivative2[1] = (IDC_OS_lab_B.x[1] - (*lastU)[1]) / h;
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((IDC_OS_lab_DW.TimeStampA_l >= H12) && (IDC_OS_lab_DW.TimeStampB_m >= H12))
  {
    rtb_Derivative1[0] = 0.0;
    rtb_Derivative1[1] = 0.0;
  } else {
    h = IDC_OS_lab_DW.TimeStampA_l;
    lastU = &IDC_OS_lab_DW.LastUAtTimeA_f;
    if (IDC_OS_lab_DW.TimeStampA_l < IDC_OS_lab_DW.TimeStampB_m) {
      if (IDC_OS_lab_DW.TimeStampB_m < H12) {
        h = IDC_OS_lab_DW.TimeStampB_m;
        lastU = &IDC_OS_lab_DW.LastUAtTimeB_b;
      }
    } else if (IDC_OS_lab_DW.TimeStampA_l >= H12) {
      h = IDC_OS_lab_DW.TimeStampB_m;
      lastU = &IDC_OS_lab_DW.LastUAtTimeB_b;
    }

    h = H12 - h;
    rtb_Derivative1[0] = (IDC_OS_lab_B.Derivative2[0] - (*lastU)[0]) / h;
    rtb_Derivative1[1] = (IDC_OS_lab_B.Derivative2[1] - (*lastU)[1]) / h;
  }

  if (rtmIsMajorTimeStep(IDC_OS_lab_M)) {
    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S7>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S2>:1' */
    /* '<S2>:1:4' */
    /* '<S2>:1:5' */
    /* '<S2>:1:7' */
    IDC_OS_lab_B.x_b[0] = 0.15 * cos(IDC_OS_lab_B.EncoderGain[0]) + 0.15 * cos
      (IDC_OS_lab_B.EncoderGain[1]);

    /* '<S2>:1:8' */
    IDC_OS_lab_B.x_b[1] = 0.15 * sin(IDC_OS_lab_B.EncoderGain[0]) + 0.15 * sin
      (IDC_OS_lab_B.EncoderGain[1]);
  }

  /* MATLAB Function: '<Root>/Hx Matrix' incorporates:
   *  Gain: '<S7>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  MATLAB Function: '<Root>/Jacobiandot'
   */
  /* MATLAB Function 'Jacobiandot': '<S5>:1' */
  /* '<S5>:1:3' */
  /* '<S5>:1:4' */
  /* '<S5>:1:6' */
  /* '<S5>:1:10' */
  /* MATLAB Function 'Hx Matrix': '<S3>:1' */
  /* '<S3>:1:30' */
  /* '<S3>:1:4' */
  /* '<S3>:1:5' */
  /* '<S3>:1:7' */
  /* '<S3>:1:9' */
  /* '<S3>:1:23' */
  H12_tmp = IDC_OS_lab_B.EncoderGain[1] - IDC_OS_lab_B.EncoderGain[0];
  H12 = cos(H12_tmp) * 0.00041579999999999997;

  /* '<S3>:1:27' */
  /* '<S3>:1:30' */
  x_tmp = -0.15 * sin(IDC_OS_lab_B.EncoderGain[0]);
  tmp_3 = x_tmp - 0.15 * sin(IDC_OS_lab_B.EncoderGain[1]);
  tmp[0] = tmp_3;
  tmp_4 = -0.15 * sin(IDC_OS_lab_B.EncoderGain[1]);
  tmp[2] = tmp_4;
  tmp_5 = 0.15 * cos(IDC_OS_lab_B.EncoderGain[0]) + 0.15 * cos
    (IDC_OS_lab_B.EncoderGain[1]);
  tmp[1] = tmp_5;
  tmp_6 = 0.15 * cos(IDC_OS_lab_B.EncoderGain[1]);
  tmp[3] = tmp_6;

  /* MATLAB Function: '<Root>/Feedback Comp' */
  /* '<S3>:1:32' */
  /* '<S3>:1:33' */
  /* '<S3>:1:37' */
  /* MATLAB Function 'Jacobian Transpose': '<S4>:1' */
  /* '<S4>:1:6' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:6' */
  /* '<S4>:1:10' */
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
  h = sin(H12_tmp) * 0.00041579999999999997;

  /* MATLAB Function: '<Root>/Jacobiandot' incorporates:
   *  Gain: '<S7>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   */
  /* '<S1>:1:23' */
  /* '<S1>:1:24' */
  /* '<S1>:1:25' */
  /* '<S1>:1:26' */
  /* '<S1>:1:28' */
  /* '<S1>:1:29' */
  /* '<S1>:1:30' */
  /* '<S1>:1:32' */
  H12_tmp = cos(IDC_OS_lab_B.EncoderGain[0]);
  Current_tmp = cos(IDC_OS_lab_B.EncoderGain[1]);
  for (i = 0; i < 2; i++) {
    /* Sum: '<Root>/Sum2' */
    IDC_OS_lab_B.Sum2[i] = IDC_OS_lab_B.x[i] - IDC_OS_lab_B.x_b[i];

    /* Gain: '<S44>/Filter Coefficient' incorporates:
     *  Gain: '<S35>/Derivative Gain'
     *  Integrator: '<S36>/Filter'
     *  Sum: '<S36>/SumD'
     */
    IDC_OS_lab_B.FilterCoefficient[i] = (IDC_OS_lab_P.PIDController_D *
      IDC_OS_lab_B.Sum2[i] - IDC_OS_lab_X.Filter_CSTATE[i]) *
      IDC_OS_lab_P.PIDController_N;

    /* MATLAB Function: '<Root>/Hx Matrix' */
    J[i] = 0.0;
    J[i] += tmp[i];
    J_tmp = tmp[i + 2];
    J[i] += -J_tmp;
    J_tmp_0 = i << 1;
    J_0[J_tmp_0] = J[i];
    J[i + 2] = 0.0;
    J[i + 2] += tmp[i] * 0.0;
    J[i + 2] += J_tmp;
    J_0[J_tmp_0 + 1] = J[i + 2];
  }

  /* MATLAB Function: '<Root>/Hx Matrix' */
  IDC_OS_lab_inv(J_0, tmp);
  IDC_OS_lab_inv(J, J_0);

  /* MATLAB Function: '<Root>/Jacobiandot' */
  tmp_0[0] = -0.15 * H12_tmp;
  tmp_0[2] = -0.15 * Current_tmp;
  tmp_0[1] = x_tmp;
  tmp_0[3] = tmp_4;
  for (i = 0; i < 2; i++) {
    /* MATLAB Function: '<Root>/Hx Matrix' */
    J[i] = 0.0;
    J[i] += tmp[i] * 0.0055575;
    x_tmp = tmp[i + 2];
    J[i] += x_tmp * H12;
    J[i + 2] = 0.0;
    J[i + 2] += tmp[i] * H12;
    J[i + 2] += x_tmp * 0.0034850000000000003;
    tmp_1[i] = 0.0;
    tmp_1[i] += J[i] * J_0[0];
    tmp_1[i] += J[i + 2] * J_0[1];
    tmp_1[i + 2] = 0.0;
    tmp_1[i + 2] += J[i] * J_0[2];
    tmp_1[i + 2] += J[i + 2] * J_0[3];

    /* Sum: '<Root>/Sum3' incorporates:
     *  Derivative: '<S7>/Derivative'
     *  Gain: '<S46>/Proportional Gain'
     *  MATLAB Function: '<Root>/Jacobiandot'
     *  Sum: '<S50>/Sum'
     */
    rtb_Derivative1_0[i] = ((IDC_OS_lab_P.PIDController_P * IDC_OS_lab_B.Sum2[i]
      + IDC_OS_lab_B.FilterCoefficient[i]) + rtb_Derivative1[i]) - (tmp_0[i + 2]
      * rtb_Derivative_idx_1 + tmp_0[i] * rtb_Derivative_idx_0);
  }

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S7>/Derivative'
   */
  J_0[0] = 0.0;
  J_0[2] = -h;
  J_0[1] = h;
  J_0[3] = 0.0;
  H12 = rtb_Derivative_idx_0 * rtb_Derivative_idx_0;
  h = rtb_Derivative_idx_1 * rtb_Derivative_idx_1;
  for (i = 0; i < 2; i++) {
    /* MATLAB Function: '<Root>/Jacobian Transpose' */
    tmp[i] = 0.0;
    J_tmp_0 = i << 1;
    x_tmp = b[J_tmp_0];
    tmp[i] += x_tmp * tmp_3;
    J_tmp = b[J_tmp_0 + 1];
    tmp[i] += J_tmp * tmp_4;
    tmp[i + 2] = 0.0;
    tmp[i + 2] += x_tmp * tmp_5;
    tmp[i + 2] += J_tmp * tmp_6;

    /* MATLAB Function: '<Root>/Hx Matrix' */
    rtb_Derivative1[i] = tmp_1[i + 2] * rtb_Derivative1_0[1] + tmp_1[i] *
      rtb_Derivative1_0[0];

    /* MATLAB Function: '<Root>/Feedback Comp' */
    tmp_2[i] = J_0[i + 2] * h + J_0[i] * H12;
  }

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S7>/Derivative'
   */
  if (rtb_Derivative_idx_0 < 0.0) {
    H12 = -1.0;
  } else if (rtb_Derivative_idx_0 > 0.0) {
    H12 = 1.0;
  } else if (rtb_Derivative_idx_0 == 0.0) {
    H12 = 0.0;
  } else {
    H12 = (rtNaN);
  }

  /* Gain: '<Root>/1//AmpGain (V//A)1' incorporates:
   *  Derivative: '<S7>/Derivative'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum4'
   */
  IDC_OS_lab_B.Current[0] = (((0.1690892 * H12_tmp + tmp_2[0]) + (0.01519 *
    rtb_Derivative_idx_0 + 0.007 * H12)) + (tmp[0] * rtb_Derivative1[0] +
    rtb_Derivative1[1] * tmp[2])) * IDC_OS_lab_P.uAmpGainVA1_Gain;

  /* Gain: '<S7>/1//AmpGain' incorporates:
   *  Bias: '<S7>/Amp Bias Tune for each  amp//channel if needed'
   */
  IDC_OS_lab_B.uAmpGain[0] = (IDC_OS_lab_B.Current[0] +
    IDC_OS_lab_P.AmpBiasTuneforeachampchannelifn[0]) *
    IDC_OS_lab_P.uAmpGain_Gain[0];

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S7>/Derivative'
   */
  if (rtb_Derivative_idx_1 < 0.0) {
    h = -1.0;
  } else if (rtb_Derivative_idx_1 > 0.0) {
    h = 1.0;
  } else if (rtb_Derivative_idx_1 == 0.0) {
    h = 0.0;
  } else {
    h = (rtNaN);
  }

  /* Gain: '<Root>/1//AmpGain (V//A)1' incorporates:
   *  Derivative: '<S7>/Derivative'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum4'
   */
  IDC_OS_lab_B.Current[1] = (((0.027165599999999998 * Current_tmp + tmp_2[1]) +
    (0.01519 * rtb_Derivative_idx_1 + 0.007 * h)) + (rtb_Derivative1[0] * tmp[1]
    + rtb_Derivative1[1] * tmp[3])) * IDC_OS_lab_P.uAmpGainVA1_Gain;

  /* Gain: '<S7>/1//AmpGain' incorporates:
   *  Bias: '<S7>/Amp Bias Tune for each  amp//channel if needed'
   */
  IDC_OS_lab_B.uAmpGain[1] = (IDC_OS_lab_B.Current[1] +
    IDC_OS_lab_P.AmpBiasTuneforeachampchannelifn[1]) *
    IDC_OS_lab_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(IDC_OS_lab_M)) {
    /* S-Function (hil_write_analog_block): '<S7>/HIL Write Analog' */

    /* S-Function Block: IDC_OS_lab/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILWriteAnalog_channels, 2, &IDC_OS_lab_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S7>/HIL Read Analog' */

    /* S-Function Block: IDC_OS_lab/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
      }
    }

    /* Bias: '<S7>/Current Sense Bias Tune for each amp//channel if needed' incorporates:
     *  Gain: '<S7>/1//Sense Gain'
     */
    IDC_OS_lab_B.CurrentSenseBiasTuneforeachampc[0] =
      IDC_OS_lab_P.uSenseGain_Gain * rtb_HILReadAnalog[0] +
      IDC_OS_lab_P.CurrentSenseBiasTuneforeachampc[0];
    IDC_OS_lab_B.CurrentSenseBiasTuneforeachampc[1] =
      IDC_OS_lab_P.uSenseGain_Gain * rtb_HILReadAnalog[1] +
      IDC_OS_lab_P.CurrentSenseBiasTuneforeachampc[1];

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S7>/Encoder Gain'
     */
    if (IDC_OS_lab_M->Timing.RateInteraction.TID1_2) {
      IDC_OS_lab_DW.RateTransition_Buffer[0] = IDC_OS_lab_B.EncoderGain[0];
      IDC_OS_lab_DW.RateTransition_Buffer[1] = IDC_OS_lab_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void IDC_OS_lab_update0(void)          /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<S7>/Derivative' incorporates:
   *  Gain: '<S7>/Encoder Gain'
   */
  if (IDC_OS_lab_DW.TimeStampA == (rtInf)) {
    IDC_OS_lab_DW.TimeStampA = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeA;
  } else if (IDC_OS_lab_DW.TimeStampB == (rtInf)) {
    IDC_OS_lab_DW.TimeStampB = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeB;
  } else if (IDC_OS_lab_DW.TimeStampA < IDC_OS_lab_DW.TimeStampB) {
    IDC_OS_lab_DW.TimeStampA = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeA;
  } else {
    IDC_OS_lab_DW.TimeStampB = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeB;
  }

  (*lastU)[0] = IDC_OS_lab_B.EncoderGain[0];
  (*lastU)[1] = IDC_OS_lab_B.EncoderGain[1];

  /* End of Update for Derivative: '<S7>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative2' */
  if (IDC_OS_lab_DW.TimeStampA_b == (rtInf)) {
    IDC_OS_lab_DW.TimeStampA_b = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeA_c;
  } else if (IDC_OS_lab_DW.TimeStampB_c == (rtInf)) {
    IDC_OS_lab_DW.TimeStampB_c = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeB_a;
  } else if (IDC_OS_lab_DW.TimeStampA_b < IDC_OS_lab_DW.TimeStampB_c) {
    IDC_OS_lab_DW.TimeStampA_b = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeA_c;
  } else {
    IDC_OS_lab_DW.TimeStampB_c = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeB_a;
  }

  (*lastU)[0] = IDC_OS_lab_B.x[0];
  (*lastU)[1] = IDC_OS_lab_B.x[1];

  /* End of Update for Derivative: '<Root>/Derivative2' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (IDC_OS_lab_DW.TimeStampA_l == (rtInf)) {
    IDC_OS_lab_DW.TimeStampA_l = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeA_f;
  } else if (IDC_OS_lab_DW.TimeStampB_m == (rtInf)) {
    IDC_OS_lab_DW.TimeStampB_m = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeB_b;
  } else if (IDC_OS_lab_DW.TimeStampA_l < IDC_OS_lab_DW.TimeStampB_m) {
    IDC_OS_lab_DW.TimeStampA_l = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeA_f;
  } else {
    IDC_OS_lab_DW.TimeStampB_m = IDC_OS_lab_M->Timing.t[0];
    lastU = &IDC_OS_lab_DW.LastUAtTimeB_b;
  }

  (*lastU)[0] = IDC_OS_lab_B.Derivative2[0];
  (*lastU)[1] = IDC_OS_lab_B.Derivative2[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(IDC_OS_lab_M)) {
    rt_ertODEUpdateContinuousStates(&IDC_OS_lab_M->solverInfo);
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
  if (!(++IDC_OS_lab_M->Timing.clockTick0)) {
    ++IDC_OS_lab_M->Timing.clockTickH0;
  }

  IDC_OS_lab_M->Timing.t[0] = rtsiGetSolverStopTime(&IDC_OS_lab_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IDC_OS_lab_M->Timing.clockTick1)) {
    ++IDC_OS_lab_M->Timing.clockTickH1;
  }

  IDC_OS_lab_M->Timing.t[1] = IDC_OS_lab_M->Timing.clockTick1 *
    IDC_OS_lab_M->Timing.stepSize1 + IDC_OS_lab_M->Timing.clockTickH1 *
    IDC_OS_lab_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void IDC_OS_lab_derivatives(void)
{
  XDot_IDC_OS_lab_T *_rtXdot;
  _rtXdot = ((XDot_IDC_OS_lab_T *) IDC_OS_lab_M->derivs);

  /* Derivatives for Integrator: '<S36>/Filter' */
  _rtXdot->Filter_CSTATE[0] = IDC_OS_lab_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = IDC_OS_lab_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void IDC_OS_lab_output2(void)          /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  IDC_OS_lab_B.RateTransition[0] = IDC_OS_lab_DW.RateTransition_Buffer[0];
  IDC_OS_lab_B.RateTransition[1] = IDC_OS_lab_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void IDC_OS_lab_update2(void)          /* Sample time: [0.02s, 0.0s] */
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
  if (!(++IDC_OS_lab_M->Timing.clockTick2)) {
    ++IDC_OS_lab_M->Timing.clockTickH2;
  }

  IDC_OS_lab_M->Timing.t[2] = IDC_OS_lab_M->Timing.clockTick2 *
    IDC_OS_lab_M->Timing.stepSize2 + IDC_OS_lab_M->Timing.clockTickH2 *
    IDC_OS_lab_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void IDC_OS_lab_output(int_T tid)
{
  switch (tid) {
   case 0 :
    IDC_OS_lab_output0();
    break;

   case 2 :
    IDC_OS_lab_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void IDC_OS_lab_update(int_T tid)
{
  switch (tid) {
   case 0 :
    IDC_OS_lab_update0();
    break;

   case 2 :
    IDC_OS_lab_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void IDC_OS_lab_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S7>/HIL Initialize' */

  /* S-Function Block: IDC_OS_lab/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &IDC_OS_lab_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(IDC_OS_lab_DW.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(IDC_OS_lab_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
      return;
    }

    if ((IDC_OS_lab_P.HILInitialize_AIPStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &IDC_OS_lab_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (IDC_OS_lab_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &IDC_OS_lab_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = IDC_OS_lab_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_AIChannels, 8U,
        &IDC_OS_lab_DW.HILInitialize_AIMinimums[0],
        &IDC_OS_lab_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if ((IDC_OS_lab_P.HILInitialize_AOPStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &IDC_OS_lab_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (IDC_OS_lab_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &IDC_OS_lab_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = IDC_OS_lab_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_AOChannels, 8U,
        &IDC_OS_lab_DW.HILInitialize_AOMinimums[0],
        &IDC_OS_lab_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if ((IDC_OS_lab_P.HILInitialize_AOStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &IDC_OS_lab_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = IDC_OS_lab_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_AOChannels, 8U,
        &IDC_OS_lab_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if (IDC_OS_lab_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &IDC_OS_lab_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = IDC_OS_lab_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (IDC_OS_lab_DW.HILInitialize_Card, IDC_OS_lab_P.HILInitialize_AOChannels,
         8U, &IDC_OS_lab_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if ((IDC_OS_lab_P.HILInitialize_EIPStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &IDC_OS_lab_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = IDC_OS_lab_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &IDC_OS_lab_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if ((IDC_OS_lab_P.HILInitialize_EIStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &IDC_OS_lab_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = IDC_OS_lab_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_EIChannels, 8U,
        &IDC_OS_lab_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if ((IDC_OS_lab_P.HILInitialize_POPStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &IDC_OS_lab_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = IDC_OS_lab_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &IDC_OS_lab_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          IDC_OS_lab_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &IDC_OS_lab_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            IDC_OS_lab_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            IDC_OS_lab_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              IDC_OS_lab_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            IDC_OS_lab_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            IDC_OS_lab_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              IDC_OS_lab_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(IDC_OS_lab_DW.HILInitialize_Card,
          &IDC_OS_lab_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &IDC_OS_lab_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(IDC_OS_lab_DW.HILInitialize_Card,
          &IDC_OS_lab_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &IDC_OS_lab_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &IDC_OS_lab_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = IDC_OS_lab_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &IDC_OS_lab_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = IDC_OS_lab_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &IDC_OS_lab_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = IDC_OS_lab_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &IDC_OS_lab_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &IDC_OS_lab_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &IDC_OS_lab_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &IDC_OS_lab_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = IDC_OS_lab_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &IDC_OS_lab_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = IDC_OS_lab_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_POChannels, 8U,
        &IDC_OS_lab_DW.HILInitialize_POSortedFreqs[0],
        &IDC_OS_lab_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if ((IDC_OS_lab_P.HILInitialize_POStart && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &IDC_OS_lab_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = IDC_OS_lab_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(IDC_OS_lab_DW.HILInitialize_Card,
        IDC_OS_lab_P.HILInitialize_POChannels, 8U,
        &IDC_OS_lab_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }

    if (IDC_OS_lab_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &IDC_OS_lab_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = IDC_OS_lab_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (IDC_OS_lab_DW.HILInitialize_Card, IDC_OS_lab_P.HILInitialize_POChannels,
         8U, &IDC_OS_lab_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Constant: '<Root>/Speed' */
  IDC_OS_lab_B.Speed = IDC_OS_lab_P.Speed_Value;

  /* InitializeConditions for Derivative: '<S7>/Derivative' */
  IDC_OS_lab_DW.TimeStampA = (rtInf);
  IDC_OS_lab_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  IDC_OS_lab_DW.TimeStampA_b = (rtInf);
  IDC_OS_lab_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  IDC_OS_lab_DW.TimeStampA_l = (rtInf);
  IDC_OS_lab_DW.TimeStampB_m = (rtInf);

  /* InitializeConditions for Integrator: '<S36>/Filter' */
  IDC_OS_lab_X.Filter_CSTATE[0] = IDC_OS_lab_P.PIDController_InitialConditionF;
  IDC_OS_lab_X.Filter_CSTATE[1] = IDC_OS_lab_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void IDC_OS_lab_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S7>/HIL Initialize' */

  /* S-Function Block: IDC_OS_lab/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(IDC_OS_lab_DW.HILInitialize_Card);
    hil_monitor_stop_all(IDC_OS_lab_DW.HILInitialize_Card);
    is_switching = false;
    if ((IDC_OS_lab_P.HILInitialize_AOTerminate && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &IDC_OS_lab_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = IDC_OS_lab_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((IDC_OS_lab_P.HILInitialize_POTerminate && !is_switching) ||
        (IDC_OS_lab_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &IDC_OS_lab_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = IDC_OS_lab_P.HILInitialize_POFinal;
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
      result = hil_write(IDC_OS_lab_DW.HILInitialize_Card
                         , IDC_OS_lab_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , IDC_OS_lab_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &IDC_OS_lab_DW.HILInitialize_AOVoltages[0]
                         , &IDC_OS_lab_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(IDC_OS_lab_DW.HILInitialize_Card,
            IDC_OS_lab_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &IDC_OS_lab_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(IDC_OS_lab_DW.HILInitialize_Card,
            IDC_OS_lab_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &IDC_OS_lab_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(IDC_OS_lab_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(IDC_OS_lab_DW.HILInitialize_Card);
    hil_monitor_delete_all(IDC_OS_lab_DW.HILInitialize_Card);
    hil_close(IDC_OS_lab_DW.HILInitialize_Card);
    IDC_OS_lab_DW.HILInitialize_Card = NULL;
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
  IDC_OS_lab_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  IDC_OS_lab_update(tid);
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
  IDC_OS_lab_initialize();
}

void MdlTerminate(void)
{
  IDC_OS_lab_terminate();
}

/* Registration function */
RT_MODEL_IDC_OS_lab_T *IDC_OS_lab(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)IDC_OS_lab_M, 0,
                sizeof(RT_MODEL_IDC_OS_lab_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&IDC_OS_lab_M->solverInfo,
                          &IDC_OS_lab_M->Timing.simTimeStep);
    rtsiSetTPtr(&IDC_OS_lab_M->solverInfo, &rtmGetTPtr(IDC_OS_lab_M));
    rtsiSetStepSizePtr(&IDC_OS_lab_M->solverInfo,
                       &IDC_OS_lab_M->Timing.stepSize0);
    rtsiSetdXPtr(&IDC_OS_lab_M->solverInfo, &IDC_OS_lab_M->derivs);
    rtsiSetContStatesPtr(&IDC_OS_lab_M->solverInfo, (real_T **)
                         &IDC_OS_lab_M->contStates);
    rtsiSetNumContStatesPtr(&IDC_OS_lab_M->solverInfo,
      &IDC_OS_lab_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&IDC_OS_lab_M->solverInfo,
      &IDC_OS_lab_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&IDC_OS_lab_M->solverInfo,
      &IDC_OS_lab_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&IDC_OS_lab_M->solverInfo,
      &IDC_OS_lab_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&IDC_OS_lab_M->solverInfo, (&rtmGetErrorStatus
      (IDC_OS_lab_M)));
    rtsiSetRTModelPtr(&IDC_OS_lab_M->solverInfo, IDC_OS_lab_M);
  }

  rtsiSetSimTimeStep(&IDC_OS_lab_M->solverInfo, MAJOR_TIME_STEP);
  IDC_OS_lab_M->intgData.f[0] = IDC_OS_lab_M->odeF[0];
  IDC_OS_lab_M->contStates = ((real_T *) &IDC_OS_lab_X);
  rtsiSetSolverData(&IDC_OS_lab_M->solverInfo, (void *)&IDC_OS_lab_M->intgData);
  rtsiSetSolverName(&IDC_OS_lab_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = IDC_OS_lab_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "IDC_OS_lab_M points to
       static memory which is guaranteed to be non-NULL" */
    IDC_OS_lab_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IDC_OS_lab_M->Timing.sampleTimes = (&IDC_OS_lab_M->Timing.sampleTimesArray[0]);
    IDC_OS_lab_M->Timing.offsetTimes = (&IDC_OS_lab_M->Timing.offsetTimesArray[0]);

    /* task periods */
    IDC_OS_lab_M->Timing.sampleTimes[0] = (0.0);
    IDC_OS_lab_M->Timing.sampleTimes[1] = (0.001);
    IDC_OS_lab_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    IDC_OS_lab_M->Timing.offsetTimes[0] = (0.0);
    IDC_OS_lab_M->Timing.offsetTimes[1] = (0.0);
    IDC_OS_lab_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(IDC_OS_lab_M, &IDC_OS_lab_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = IDC_OS_lab_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = IDC_OS_lab_M->Timing.perTaskSampleHitsArray;
    IDC_OS_lab_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    IDC_OS_lab_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IDC_OS_lab_M, 10.0);
  IDC_OS_lab_M->Timing.stepSize0 = 0.001;
  IDC_OS_lab_M->Timing.stepSize1 = 0.001;
  IDC_OS_lab_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  IDC_OS_lab_M->Sizes.checksums[0] = (1635277475U);
  IDC_OS_lab_M->Sizes.checksums[1] = (2039053169U);
  IDC_OS_lab_M->Sizes.checksums[2] = (4200572679U);
  IDC_OS_lab_M->Sizes.checksums[3] = (129682479U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    IDC_OS_lab_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(IDC_OS_lab_M->extModeInfo,
      &IDC_OS_lab_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IDC_OS_lab_M->extModeInfo, IDC_OS_lab_M->Sizes.checksums);
    rteiSetTPtr(IDC_OS_lab_M->extModeInfo, rtmGetTPtr(IDC_OS_lab_M));
  }

  IDC_OS_lab_M->solverInfoPtr = (&IDC_OS_lab_M->solverInfo);
  IDC_OS_lab_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&IDC_OS_lab_M->solverInfo, 0.001);
  rtsiSetSolverMode(&IDC_OS_lab_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  IDC_OS_lab_M->blockIO = ((void *) &IDC_OS_lab_B);

  {
    IDC_OS_lab_B.EncoderGain[0] = 0.0;
    IDC_OS_lab_B.EncoderGain[1] = 0.0;
    IDC_OS_lab_B.Speed = 0.0;
    IDC_OS_lab_B.Derivative2[0] = 0.0;
    IDC_OS_lab_B.Derivative2[1] = 0.0;
    IDC_OS_lab_B.Sum2[0] = 0.0;
    IDC_OS_lab_B.Sum2[1] = 0.0;
    IDC_OS_lab_B.FilterCoefficient[0] = 0.0;
    IDC_OS_lab_B.FilterCoefficient[1] = 0.0;
    IDC_OS_lab_B.Current[0] = 0.0;
    IDC_OS_lab_B.Current[1] = 0.0;
    IDC_OS_lab_B.uAmpGain[0] = 0.0;
    IDC_OS_lab_B.uAmpGain[1] = 0.0;
    IDC_OS_lab_B.CurrentSenseBiasTuneforeachampc[0] = 0.0;
    IDC_OS_lab_B.CurrentSenseBiasTuneforeachampc[1] = 0.0;
    IDC_OS_lab_B.RateTransition[0] = 0.0;
    IDC_OS_lab_B.RateTransition[1] = 0.0;
    IDC_OS_lab_B.x[0] = 0.0;
    IDC_OS_lab_B.x[1] = 0.0;
    IDC_OS_lab_B.x_b[0] = 0.0;
    IDC_OS_lab_B.x_b[1] = 0.0;
  }

  /* parameters */
  IDC_OS_lab_M->defaultParam = ((real_T *)&IDC_OS_lab_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &IDC_OS_lab_X;
    IDC_OS_lab_M->contStates = (x);
    (void) memset((void *)&IDC_OS_lab_X, 0,
                  sizeof(X_IDC_OS_lab_T));
  }

  /* states (dwork) */
  IDC_OS_lab_M->dwork = ((void *) &IDC_OS_lab_DW);
  (void) memset((void *)&IDC_OS_lab_DW, 0,
                sizeof(DW_IDC_OS_lab_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      IDC_OS_lab_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  IDC_OS_lab_DW.TimeStampA = 0.0;
  IDC_OS_lab_DW.LastUAtTimeA[0] = 0.0;
  IDC_OS_lab_DW.LastUAtTimeA[1] = 0.0;
  IDC_OS_lab_DW.TimeStampB = 0.0;
  IDC_OS_lab_DW.LastUAtTimeB[0] = 0.0;
  IDC_OS_lab_DW.LastUAtTimeB[1] = 0.0;
  IDC_OS_lab_DW.TimeStampA_b = 0.0;
  IDC_OS_lab_DW.LastUAtTimeA_c[0] = 0.0;
  IDC_OS_lab_DW.LastUAtTimeA_c[1] = 0.0;
  IDC_OS_lab_DW.TimeStampB_c = 0.0;
  IDC_OS_lab_DW.LastUAtTimeB_a[0] = 0.0;
  IDC_OS_lab_DW.LastUAtTimeB_a[1] = 0.0;
  IDC_OS_lab_DW.TimeStampA_l = 0.0;
  IDC_OS_lab_DW.LastUAtTimeA_f[0] = 0.0;
  IDC_OS_lab_DW.LastUAtTimeA_f[1] = 0.0;
  IDC_OS_lab_DW.TimeStampB_m = 0.0;
  IDC_OS_lab_DW.LastUAtTimeB_b[0] = 0.0;
  IDC_OS_lab_DW.LastUAtTimeB_b[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      IDC_OS_lab_DW.XYSuperimposed_XBuffer[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      IDC_OS_lab_DW.XYSuperimposed_YBuffer[i] = 0.0;
    }
  }

  IDC_OS_lab_DW.RateTransition_Buffer[0] = 0.0;
  IDC_OS_lab_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    IDC_OS_lab_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  IDC_OS_lab_M->Sizes.numContStates = (2);/* Number of continuous states */
  IDC_OS_lab_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  IDC_OS_lab_M->Sizes.numY = (0);      /* Number of model outputs */
  IDC_OS_lab_M->Sizes.numU = (0);      /* Number of model inputs */
  IDC_OS_lab_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  IDC_OS_lab_M->Sizes.numSampTimes = (3);/* Number of sample times */
  IDC_OS_lab_M->Sizes.numBlocks = (47);/* Number of blocks */
  IDC_OS_lab_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  IDC_OS_lab_M->Sizes.numBlockPrms = (126);/* Sum of parameter "widths" */
  return IDC_OS_lab_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
