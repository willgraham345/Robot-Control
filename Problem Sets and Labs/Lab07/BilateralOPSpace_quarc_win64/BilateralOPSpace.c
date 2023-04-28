/*
 * BilateralOPSpace.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BilateralOPSpace".
 *
 * Model version              : 13.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 25 11:06:52 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BilateralOPSpace.h"
#include "BilateralOPSpace_private.h"
#include "BilateralOPSpace_dt.h"

/* Block signals (default storage) */
B_BilateralOPSpace_T BilateralOPSpace_B;

/* Continuous states */
X_BilateralOPSpace_T BilateralOPSpace_X;

/* Block states (default storage) */
DW_BilateralOPSpace_T BilateralOPSpace_DW;

/* Real-time model */
static RT_MODEL_BilateralOPSpace_T BilateralOPSpace_M_;
RT_MODEL_BilateralOPSpace_T *const BilateralOPSpace_M = &BilateralOPSpace_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(BilateralOPSpace_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(BilateralOPSpace_M, 2);
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
  if (BilateralOPSpace_M->Timing.TaskCounters.TID[1] == 0) {
    BilateralOPSpace_M->Timing.RateInteraction.TID1_2 =
      (BilateralOPSpace_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    BilateralOPSpace_M->Timing.perTaskSampleHits[5] =
      BilateralOPSpace_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (BilateralOPSpace_M->Timing.TaskCounters.TID[2])++;
  if ((BilateralOPSpace_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    BilateralOPSpace_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  BilateralOPSpace_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void BilateralOPSpace_output0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T tmp[4];
  real_T tmp_0[2];
  real_T H12;
  real_T h;
  real_T rtb_Sum_c;
  real_T rtb_Sum_idx_0;
  real_T rtb_Sum_idx_1;
  real_T rtb_Sum_l_idx_0;
  real_T rtb_x_idx_0;
  real_T rtb_x_idx_1;
  real_T rtb_x_tmp;
  real_T t;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T tmp_7;
  int32_T i;
  int32_T i_0;
  static const int8_T b[4] = { 1, -1, 0, 1 };

  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
    /* set solver stop time */
    if (!(BilateralOPSpace_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&BilateralOPSpace_M->solverInfo,
                            ((BilateralOPSpace_M->Timing.clockTickH0 + 1) *
        BilateralOPSpace_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&BilateralOPSpace_M->solverInfo,
                            ((BilateralOPSpace_M->Timing.clockTick0 + 1) *
        BilateralOPSpace_M->Timing.stepSize0 +
        BilateralOPSpace_M->Timing.clockTickH0 *
        BilateralOPSpace_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BilateralOPSpace_M)) {
    BilateralOPSpace_M->Timing.t[0] = rtsiGetT(&BilateralOPSpace_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
    /* S-Function (hil_read_encoder_block): '<S7>/HIL Read Encoder' */

    /* S-Function Block: BilateralOPSpace/Real Master Robot/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILReadEncoder_channels, 2,
        &BilateralOPSpace_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = BilateralOPSpace_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = BilateralOPSpace_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S7>/Encoder Gain' incorporates:
     *  Constant: '<S7>/Home Position'
     *  Sum: '<S7>/Sum1'
     */
    BilateralOPSpace_B.EncoderGain[0] = (BilateralOPSpace_P.HomePosition_Value[0]
      + rtb_HILReadAnalog[0]) * BilateralOPSpace_P.EncoderGain_Gain[0];
    BilateralOPSpace_B.EncoderGain[1] = (BilateralOPSpace_P.HomePosition_Value[1]
      + rtb_HILReadAnalog[1]) * BilateralOPSpace_P.EncoderGain_Gain[1];

    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S7>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S1>:1' */
    /* '<S1>:1:5' */
    /* '<S1>:1:6' */
    /* '<S1>:1:8' */
    BilateralOPSpace_B.x[0] = 0.15 * cos(BilateralOPSpace_B.EncoderGain[0]) +
      0.15 * cos(BilateralOPSpace_B.EncoderGain[1]);

    /* '<S1>:1:9' */
    BilateralOPSpace_B.x[1] = 0.15 * sin(BilateralOPSpace_B.EncoderGain[0]) +
      0.15 * sin(BilateralOPSpace_B.EncoderGain[1]);
  }

  /* Integrator: '<S59>/v2p' */
  BilateralOPSpace_B.phi[0] = BilateralOPSpace_X.v2p_CSTATE[0];
  BilateralOPSpace_B.phi[1] = BilateralOPSpace_X.v2p_CSTATE[1];

  /* MATLAB Function: '<S8>/Forward Kinematics' incorporates:
   *  MATLAB Function: '<Root>/Gravity Comp Slave'
   *  MATLAB Function: '<Root>/Jacobian  Transpose'
   */
  /* MATLAB Function 'Virtual Slave and Environment/Forward Kinematics': '<S57>:1' */
  /* '<S57>:1:5' */
  /* '<S57>:1:6' */
  /* '<S57>:1:8' */
  h = cos(BilateralOPSpace_B.phi[0]);
  H12 = cos(BilateralOPSpace_B.phi[1]);
  rtb_x_idx_0 = 0.15 * h + 0.15 * H12;

  /* '<S57>:1:9' */
  t = sin(BilateralOPSpace_B.phi[0]);
  rtb_x_tmp = sin(BilateralOPSpace_B.phi[1]);
  rtb_x_idx_1 = 0.15 * t + 0.15 * rtb_x_tmp;

  /* Sum: '<Root>/Sum' */
  rtb_Sum_c = rtb_x_idx_0 - BilateralOPSpace_B.x[0];

  /* Gain: '<S43>/Filter Coefficient' incorporates:
   *  Gain: '<S34>/Derivative Gain'
   *  Integrator: '<S35>/Filter'
   *  Sum: '<S35>/SumD'
   */
  BilateralOPSpace_B.FilterCoefficient[0] = (BilateralOPSpace_P.PIDController_D
    [0] * rtb_Sum_c - BilateralOPSpace_X.Filter_CSTATE[0]) *
    BilateralOPSpace_P.PIDController_N;

  /* Sum: '<S49>/Sum' incorporates:
   *  Gain: '<S45>/Proportional Gain'
   *  Integrator: '<S40>/Integrator'
   */
  rtb_Sum_idx_0 = (BilateralOPSpace_P.PIDController_P[0] * rtb_Sum_c +
                   BilateralOPSpace_X.Integrator_CSTATE[0]) +
    BilateralOPSpace_B.FilterCoefficient[0];

  /* Sum: '<Root>/Sum' */
  rtb_Sum_l_idx_0 = rtb_Sum_c;
  rtb_Sum_c = rtb_x_idx_1 - BilateralOPSpace_B.x[1];

  /* Gain: '<S43>/Filter Coefficient' incorporates:
   *  Gain: '<S34>/Derivative Gain'
   *  Integrator: '<S35>/Filter'
   *  Sum: '<S35>/SumD'
   */
  BilateralOPSpace_B.FilterCoefficient[1] = (BilateralOPSpace_P.PIDController_D
    [1] * rtb_Sum_c - BilateralOPSpace_X.Filter_CSTATE[1]) *
    BilateralOPSpace_P.PIDController_N;

  /* Sum: '<S49>/Sum' incorporates:
   *  Gain: '<S45>/Proportional Gain'
   *  Integrator: '<S40>/Integrator'
   */
  rtb_Sum_idx_1 = (BilateralOPSpace_P.PIDController_P[1] * rtb_Sum_c +
                   BilateralOPSpace_X.Integrator_CSTATE[1]) +
    BilateralOPSpace_B.FilterCoefficient[1];

  /* MATLAB Function 'Jacobian  Transpose1': '<S5>:1' */
  /* '<S5>:1:6' */
  /* '<S5>:1:3' */
  /* '<S5>:1:4' */
  /* '<S5>:1:6' */
  /* '<S5>:1:10' */
  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
    /* MATLAB Function: '<Root>/Gravity Comp Master' incorporates:
     *  Gain: '<S7>/Encoder Gain'
     */
    /* MATLAB Function 'Gravity Comp Master': '<S2>:1' */
    /* '<S2>:1:6' */
    /* '<S2>:1:8' */
    /* '<S2>:1:9' */
    /* '<S2>:1:10' */
    /* '<S2>:1:11' */
    /* '<S2>:1:12' */
    /* '<S2>:1:16' */
    /* '<S2>:1:17' */
    /* '<S2>:1:19' */
    BilateralOPSpace_B.G[0] = 0.1690892 * cos(BilateralOPSpace_B.EncoderGain[0]);
    BilateralOPSpace_B.G[1] = 0.027165599999999998 * cos
      (BilateralOPSpace_B.EncoderGain[1]);
  }

  /* MATLAB Function: '<Root>/Jacobian  Transpose1' incorporates:
   *  Gain: '<S7>/Encoder Gain'
   */
  tmp_2 = -0.15 * sin(BilateralOPSpace_B.EncoderGain[0]) - 0.15 * sin
    (BilateralOPSpace_B.EncoderGain[1]);
  tmp_3 = -0.15 * sin(BilateralOPSpace_B.EncoderGain[1]);
  tmp_4 = 0.15 * cos(BilateralOPSpace_B.EncoderGain[0]) + 0.15 * cos
    (BilateralOPSpace_B.EncoderGain[1]);
  tmp_5 = 0.15 * cos(BilateralOPSpace_B.EncoderGain[1]);
  for (i = 0; i < 2; i++) {
    tmp[i] = 0.0;
    i_0 = i << 1;
    tmp_6 = b[i_0];
    tmp[i] += tmp_6 * tmp_2;
    tmp_7 = b[i_0 + 1];
    tmp[i] += tmp_7 * tmp_3;

    /* Sum: '<Root>/Sum3' */
    tmp_1 = tmp[i] * rtb_Sum_idx_0;
    tmp[i + 2] = 0.0;
    tmp[i + 2] += tmp_6 * tmp_4;
    tmp[i + 2] += tmp_7 * tmp_5;

    /* Gain: '<Root>/inv motor gain' incorporates:
     *  Sum: '<Root>/Sum3'
     */
    BilateralOPSpace_B.invmotorgain[i] = ((tmp[i + 2] * rtb_Sum_idx_1 + tmp_1) +
      BilateralOPSpace_B.G[i]) * BilateralOPSpace_P.invmotorgain_Gain;

    /* Gain: '<S7>/1//AmpGain' incorporates:
     *  Bias: '<S7>/Bias'
     */
    BilateralOPSpace_B.uAmpGain[i] = (BilateralOPSpace_B.invmotorgain[i] +
      BilateralOPSpace_P.Bias_Bias[i]) * BilateralOPSpace_P.uAmpGain_Gain[i];
  }

  /* End of MATLAB Function: '<Root>/Jacobian  Transpose1' */
  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
    /* S-Function (hil_write_analog_block): '<S7>/HIL Write Analog' */

    /* S-Function Block: BilateralOPSpace/Real Master Robot/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILWriteAnalog_channels, 2,
        &BilateralOPSpace_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S7>/HIL Read Analog' */

    /* S-Function Block: BilateralOPSpace/Real Master Robot/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
      }
    }

    /* Gain: '<S7>/1//Sense Gain' */
    BilateralOPSpace_B.uSenseGain[0] = BilateralOPSpace_P.uSenseGain_Gain *
      rtb_HILReadAnalog[0];
    BilateralOPSpace_B.uSenseGain[1] = BilateralOPSpace_P.uSenseGain_Gain *
      rtb_HILReadAnalog[1];
  }

  /* MATLAB Function: '<S8>/Wall Dynamics' incorporates:
   *  Constant: '<Root>/WallStiffness'
   */
  /* MATLAB Function 'Virtual Slave and Environment/Wall Dynamics': '<S60>:1' */
  /* '<S60>:1:7' */
  /* '<S60>:1:9' */
  BilateralOPSpace_B.F[0] = 0.0;
  BilateralOPSpace_B.F[1] = 0.0;
  if (rtb_x_idx_1 < -0.025) {
    /* '<S60>:1:11' */
    /* '<S60>:1:12' */
    BilateralOPSpace_B.F[1] = BilateralOPSpace_P.WallStiffness_Value * 1000.0 *
      (rtb_x_idx_1 - -0.025);
  }

  /* End of MATLAB Function: '<S8>/Wall Dynamics' */
  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
  }

  /* Sum: '<Root>/Subtract' */
  BilateralOPSpace_B.Subtract[0] = BilateralOPSpace_B.x[0] - rtb_x_idx_0;
  BilateralOPSpace_B.Subtract[1] = BilateralOPSpace_B.x[1] - rtb_x_idx_1;
  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
  }

  /* Gain: '<S37>/Integral Gain' */
  /* MATLAB Function 'Jacobian  Transpose': '<S4>:1' */
  /* '<S4>:1:6' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:6' */
  /* '<S4>:1:10' */
  /* MATLAB Function 'Gravity Comp Slave': '<S3>:1' */
  /* '<S3>:1:6' */
  /* '<S3>:1:8' */
  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  /* '<S3>:1:11' */
  /* '<S3>:1:12' */
  /* '<S3>:1:16' */
  /* '<S3>:1:17' */
  /* '<S3>:1:19' */
  BilateralOPSpace_B.IntegralGain[0] = BilateralOPSpace_P.PIDController_I *
    rtb_Sum_l_idx_0;
  BilateralOPSpace_B.IntegralGain[1] = BilateralOPSpace_P.PIDController_I *
    rtb_Sum_c;

  /* RateTransition: '<Root>/Rate Transition' */
  if (rtmIsMajorTimeStep(BilateralOPSpace_M) &&
      BilateralOPSpace_M->Timing.RateInteraction.TID1_2) {
    BilateralOPSpace_DW.RateTransition_Buffer[0] = BilateralOPSpace_B.phi[0];
    BilateralOPSpace_DW.RateTransition_Buffer[1] = BilateralOPSpace_B.phi[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* MATLAB Function: '<Root>/Jacobian  Transpose' */
  tmp_2 = -0.15 * t - 0.15 * sin(BilateralOPSpace_B.phi[1]);
  tmp_3 = -0.15 * rtb_x_tmp;
  tmp_4 = 0.15 * cos(BilateralOPSpace_B.phi[0]) + 0.15 * cos
    (BilateralOPSpace_B.phi[1]);
  tmp_5 = 0.15 * cos(BilateralOPSpace_B.phi[1]);

  /* MATLAB Function: '<Root>/Gravity Comp Slave' */
  tmp_0[0] = 0.1690892 * h;
  tmp_0[1] = 0.027165599999999998 * H12;
  for (i_0 = 0; i_0 < 2; i_0++) {
    /* MATLAB Function: '<Root>/Jacobian  Transpose' incorporates:
     *  Gain: '<Root>/Gain'
     */
    tmp[i_0] = 0.0;
    i = i_0 << 1;
    tmp_6 = b[i];
    tmp[i_0] += tmp_6 * tmp_2;
    tmp_7 = b[i + 1];
    tmp[i_0] += tmp_7 * tmp_3;
    tmp_1 = BilateralOPSpace_P.Gain_Gain * rtb_Sum_idx_0 * tmp[i_0];
    tmp[i_0 + 2] = 0.0;
    tmp[i_0 + 2] += tmp_6 * tmp_4;
    tmp[i_0 + 2] += tmp_7 * tmp_5;

    /* Gain: '<S8>/inv motor gain' incorporates:
     *  Gain: '<Root>/Gain'
     *  Gain: '<Root>/Gain1'
     *  MATLAB Function: '<Root>/Jacobian  Transpose'
     *  Sum: '<Root>/Sum2'
     */
    BilateralOPSpace_B.invmotorgain_a[i_0] = ((tmp[i_0 + 2] *
      (BilateralOPSpace_P.Gain_Gain * rtb_Sum_idx_1) + tmp_1) + tmp_0[i_0]) *
      BilateralOPSpace_P.Gain1_Gain * BilateralOPSpace_P.invmotorgain_Gain_e;
  }

  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
  }

  /* Integrator: '<S59>/a2v' */
  /* MATLAB Function 'Virtual Slave and Environment/Jacobian Transpose': '<S58>:1' */
  /* '<S58>:1:4' */
  /* '<S58>:1:5' */
  /* '<S58>:1:7' */
  /* '<S58>:1:8' */
  /* '<S58>:1:9' */
  /* '<S58>:1:10' */
  /* '<S58>:1:12' */
  /* '<S58>:1:14' */
  BilateralOPSpace_B.phidot[0] = BilateralOPSpace_X.a2v_CSTATE[0];
  BilateralOPSpace_B.phidot[1] = BilateralOPSpace_X.a2v_CSTATE[1];

  /* MATLAB Function: '<S59>/Forward Dynamics' */
  /* MATLAB Function 'Virtual Slave and Environment/Robot/Forward Dynamics': '<S61>:1' */
  /* '<S61>:1:5' */
  /* '<S61>:1:7' */
  /* '<S61>:1:8' */
  /* '<S61>:1:9' */
  /* '<S61>:1:10' */
  /* '<S61>:1:15' */
  /* '<S61>:1:16' */
  /* '<S61>:1:17' */
  /* '<S61>:1:18' */
  /* '<S61>:1:19' */
  /* '<S61>:1:20' */
  /* '<S61>:1:21' */
  /* '<S61>:1:24' */
  h = BilateralOPSpace_B.phi[1] - BilateralOPSpace_B.phi[0];
  H12 = cos(h) * 0.00041579999999999997;

  /* '<S61>:1:27' */
  h = sin(h) * 0.00041579999999999997;

  /* '<S61>:1:28' */
  /* '<S61>:1:29' */
  /* '<S61>:1:30' */
  /* '<S61>:1:31' */
  /* '<S61>:1:33' */
  rtb_x_idx_0 = H12;

  /* '<S61>:1:34' */
  /* '<S61>:1:35' */
  /* '<S61>:1:36' */
  /* '<S61>:1:38' */
  H12 /= 0.0055575;
  t = 1.0 / (0.0034850000000000003 - H12 * rtb_x_idx_0);
  tmp_2 = BilateralOPSpace_B.phidot[0] * BilateralOPSpace_B.phidot[0];
  tmp_4 = BilateralOPSpace_B.phidot[1] * BilateralOPSpace_B.phidot[1];

  /* Saturate: '<S59>/Amp Saturation' incorporates:
   *  Gain: '<S59>/Amp Gain (A//V)'
   *  Gain: '<S8>/1//AmpGain'
   *  MATLAB Function: '<S8>/Jacobian Transpose'
   */
  rtb_x_tmp = BilateralOPSpace_P.uAmpGain_Gain_j *
    BilateralOPSpace_B.invmotorgain_a[0] * BilateralOPSpace_P.AmpGainAV_Gain;
  if (rtb_x_tmp > BilateralOPSpace_P.AmpSaturation_UpperSat) {
    rtb_x_tmp = BilateralOPSpace_P.AmpSaturation_UpperSat;
  } else if (rtb_x_tmp < BilateralOPSpace_P.AmpSaturation_LowerSat) {
    rtb_x_tmp = BilateralOPSpace_P.AmpSaturation_LowerSat;
  }

  /* MATLAB Function: '<S59>/Forward Dynamics' incorporates:
   *  Gain: '<S59>/Motor Gain (Nm//A) = N*kt'
   *  MATLAB Function: '<S8>/Jacobian Transpose'
   *  Sum: '<S59>/Sum2'
   */
  if (BilateralOPSpace_B.phidot[0] < 0.0) {
    tmp_6 = -1.0;
  } else if (BilateralOPSpace_B.phidot[0] > 0.0) {
    tmp_6 = 1.0;
  } else if (BilateralOPSpace_B.phidot[0] == 0.0) {
    tmp_6 = 0.0;
  } else {
    tmp_6 = (rtNaN);
  }

  rtb_x_idx_1 = (((BilateralOPSpace_P.MotorGainNmANkt_Gain * rtb_x_tmp - (-0.15 *
    sin(BilateralOPSpace_B.phi[0]) * BilateralOPSpace_B.F[0] + 0.15 * cos
    (BilateralOPSpace_B.phi[0]) * BilateralOPSpace_B.F[1])) - (0.0 * tmp_2 + -h *
    tmp_4)) - 0.1690892 * cos(BilateralOPSpace_B.phi[0])) - (0.01519 *
    BilateralOPSpace_B.phidot[0] + 0.007 * tmp_6);

  /* Saturate: '<S59>/Amp Saturation' incorporates:
   *  Gain: '<S59>/Amp Gain (A//V)'
   *  Gain: '<S8>/1//AmpGain'
   *  MATLAB Function: '<S8>/Jacobian Transpose'
   */
  rtb_x_tmp = BilateralOPSpace_P.uAmpGain_Gain_j *
    BilateralOPSpace_B.invmotorgain_a[1] * BilateralOPSpace_P.AmpGainAV_Gain;
  if (rtb_x_tmp > BilateralOPSpace_P.AmpSaturation_UpperSat) {
    rtb_x_tmp = BilateralOPSpace_P.AmpSaturation_UpperSat;
  } else if (rtb_x_tmp < BilateralOPSpace_P.AmpSaturation_LowerSat) {
    rtb_x_tmp = BilateralOPSpace_P.AmpSaturation_LowerSat;
  }

  /* MATLAB Function: '<S59>/Forward Dynamics' incorporates:
   *  Gain: '<S59>/Motor Gain (Nm//A) = N*kt'
   *  MATLAB Function: '<S8>/Jacobian Transpose'
   *  Sum: '<S59>/Sum2'
   */
  if (BilateralOPSpace_B.phidot[1] < 0.0) {
    tmp_6 = -1.0;
  } else if (BilateralOPSpace_B.phidot[1] > 0.0) {
    tmp_6 = 1.0;
  } else if (BilateralOPSpace_B.phidot[1] == 0.0) {
    tmp_6 = 0.0;
  } else {
    tmp_6 = (rtNaN);
  }

  tmp_4 = (((BilateralOPSpace_P.MotorGainNmANkt_Gain * rtb_x_tmp - (-0.15 * sin
              (BilateralOPSpace_B.phi[1]) * BilateralOPSpace_B.F[0] + 0.15 * cos
              (BilateralOPSpace_B.phi[1]) * BilateralOPSpace_B.F[1])) - (h *
             tmp_2 + 0.0 * tmp_4)) - 0.027165599999999998 * cos
           (BilateralOPSpace_B.phi[1])) - (0.01519 * BilateralOPSpace_B.phidot[1]
    + 0.007 * tmp_6);
  BilateralOPSpace_B.y[0] = 0.0;
  BilateralOPSpace_B.y[0] += 0.627080521817364 * t * rtb_x_idx_1;
  BilateralOPSpace_B.y[0] += -rtb_x_idx_0 / 0.0055575 * t * tmp_4;
  BilateralOPSpace_B.y[1] = 0.0;
  BilateralOPSpace_B.y[1] += -H12 * t * rtb_x_idx_1;
  BilateralOPSpace_B.y[1] += t * tmp_4;
}

/* Model update function for TID0 */
void BilateralOPSpace_update0(void)    /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(BilateralOPSpace_M)) {
    rt_ertODEUpdateContinuousStates(&BilateralOPSpace_M->solverInfo);
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
  if (!(++BilateralOPSpace_M->Timing.clockTick0)) {
    ++BilateralOPSpace_M->Timing.clockTickH0;
  }

  BilateralOPSpace_M->Timing.t[0] = rtsiGetSolverStopTime
    (&BilateralOPSpace_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++BilateralOPSpace_M->Timing.clockTick1)) {
    ++BilateralOPSpace_M->Timing.clockTickH1;
  }

  BilateralOPSpace_M->Timing.t[1] = BilateralOPSpace_M->Timing.clockTick1 *
    BilateralOPSpace_M->Timing.stepSize1 +
    BilateralOPSpace_M->Timing.clockTickH1 *
    BilateralOPSpace_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void BilateralOPSpace_derivatives(void)
{
  XDot_BilateralOPSpace_T *_rtXdot;
  _rtXdot = ((XDot_BilateralOPSpace_T *) BilateralOPSpace_M->derivs);

  /* Derivatives for Integrator: '<S59>/v2p' */
  _rtXdot->v2p_CSTATE[0] = BilateralOPSpace_B.phidot[0];

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = BilateralOPSpace_B.IntegralGain[0];

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE[0] = BilateralOPSpace_B.FilterCoefficient[0];

  /* Derivatives for Integrator: '<S59>/a2v' */
  _rtXdot->a2v_CSTATE[0] = BilateralOPSpace_B.y[0];

  /* Derivatives for Integrator: '<S59>/v2p' */
  _rtXdot->v2p_CSTATE[1] = BilateralOPSpace_B.phidot[1];

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = BilateralOPSpace_B.IntegralGain[1];

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE[1] = BilateralOPSpace_B.FilterCoefficient[1];

  /* Derivatives for Integrator: '<S59>/a2v' */
  _rtXdot->a2v_CSTATE[1] = BilateralOPSpace_B.y[1];
}

/* Model output function for TID2 */
void BilateralOPSpace_output2(void)    /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  BilateralOPSpace_B.RateTransition[0] =
    BilateralOPSpace_DW.RateTransition_Buffer[0];
  BilateralOPSpace_B.RateTransition[1] =
    BilateralOPSpace_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void BilateralOPSpace_update2(void)    /* Sample time: [0.1s, 0.0s] */
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
  if (!(++BilateralOPSpace_M->Timing.clockTick2)) {
    ++BilateralOPSpace_M->Timing.clockTickH2;
  }

  BilateralOPSpace_M->Timing.t[2] = BilateralOPSpace_M->Timing.clockTick2 *
    BilateralOPSpace_M->Timing.stepSize2 +
    BilateralOPSpace_M->Timing.clockTickH2 *
    BilateralOPSpace_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void BilateralOPSpace_output(int_T tid)
{
  switch (tid) {
   case 0 :
    BilateralOPSpace_output0();
    break;

   case 2 :
    BilateralOPSpace_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void BilateralOPSpace_update(int_T tid)
{
  switch (tid) {
   case 0 :
    BilateralOPSpace_update0();
    break;

   case 2 :
    BilateralOPSpace_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void BilateralOPSpace_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S7>/HIL Initialize' */

  /* S-Function Block: BilateralOPSpace/Real Master Robot/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &BilateralOPSpace_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (BilateralOPSpace_DW.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(BilateralOPSpace_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
      return;
    }

    if ((BilateralOPSpace_P.HILInitialize_AIPStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &BilateralOPSpace_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (BilateralOPSpace_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &BilateralOPSpace_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = BilateralOPSpace_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (BilateralOPSpace_DW.HILInitialize_Card,
         BilateralOPSpace_P.HILInitialize_AIChannels, 8U,
         &BilateralOPSpace_DW.HILInitialize_AIMinimums[0],
         &BilateralOPSpace_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if ((BilateralOPSpace_P.HILInitialize_AOPStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &BilateralOPSpace_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (BilateralOPSpace_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &BilateralOPSpace_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = BilateralOPSpace_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (BilateralOPSpace_DW.HILInitialize_Card,
         BilateralOPSpace_P.HILInitialize_AOChannels, 8U,
         &BilateralOPSpace_DW.HILInitialize_AOMinimums[0],
         &BilateralOPSpace_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if ((BilateralOPSpace_P.HILInitialize_AOStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_AOEnter && is_switching)) {
      BilateralOPSpace_DW.HILInitialize_AOVoltages[0] =
        (BilateralOPSpace_P.HILInitialize_AOInitial[0]);
      BilateralOPSpace_DW.HILInitialize_AOVoltages[1] =
        (BilateralOPSpace_P.HILInitialize_AOInitial[1]);
      BilateralOPSpace_DW.HILInitialize_AOVoltages[2] =
        (BilateralOPSpace_P.HILInitialize_AOInitial[2]);

      {
        int_T i1;
        real_T *dw_AOVoltages = &BilateralOPSpace_DW.HILInitialize_AOVoltages[3];
        for (i1=0; i1 < 5; i1++) {
          dw_AOVoltages[i1] = (BilateralOPSpace_P.HILInitialize_AOInitial[3]);
        }
      }

      result = hil_write_analog(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILInitialize_AOChannels, 8U,
        &BilateralOPSpace_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if (BilateralOPSpace_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &BilateralOPSpace_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = BilateralOPSpace_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (BilateralOPSpace_DW.HILInitialize_Card,
         BilateralOPSpace_P.HILInitialize_AOChannels, 8U,
         &BilateralOPSpace_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if ((BilateralOPSpace_P.HILInitialize_EIPStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &BilateralOPSpace_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = BilateralOPSpace_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (BilateralOPSpace_DW.HILInitialize_Card,
         BilateralOPSpace_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &BilateralOPSpace_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if ((BilateralOPSpace_P.HILInitialize_EIStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &BilateralOPSpace_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = BilateralOPSpace_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILInitialize_EIChannels, 8U,
        &BilateralOPSpace_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if ((BilateralOPSpace_P.HILInitialize_POPStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &BilateralOPSpace_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = BilateralOPSpace_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &BilateralOPSpace_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          BilateralOPSpace_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &BilateralOPSpace_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            BilateralOPSpace_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            BilateralOPSpace_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = BilateralOPSpace_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            BilateralOPSpace_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            BilateralOPSpace_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              BilateralOPSpace_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(BilateralOPSpace_DW.HILInitialize_Card,
          &BilateralOPSpace_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &BilateralOPSpace_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(BilateralOPSpace_DW.HILInitialize_Card,
          &BilateralOPSpace_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &BilateralOPSpace_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &BilateralOPSpace_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = BilateralOPSpace_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &BilateralOPSpace_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = BilateralOPSpace_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &BilateralOPSpace_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = BilateralOPSpace_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &BilateralOPSpace_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &BilateralOPSpace_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &BilateralOPSpace_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &BilateralOPSpace_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = BilateralOPSpace_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &BilateralOPSpace_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = BilateralOPSpace_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILInitialize_POChannels, 8U,
        &BilateralOPSpace_DW.HILInitialize_POSortedFreqs[0],
        &BilateralOPSpace_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if ((BilateralOPSpace_P.HILInitialize_POStart && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &BilateralOPSpace_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = BilateralOPSpace_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(BilateralOPSpace_DW.HILInitialize_Card,
        BilateralOPSpace_P.HILInitialize_POChannels, 8U,
        &BilateralOPSpace_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }

    if (BilateralOPSpace_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &BilateralOPSpace_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = BilateralOPSpace_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (BilateralOPSpace_DW.HILInitialize_Card,
         BilateralOPSpace_P.HILInitialize_POChannels, 8U,
         &BilateralOPSpace_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<S59>/v2p' */
  BilateralOPSpace_X.v2p_CSTATE[0] = BilateralOPSpace_P.v2p_IC[0];

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  BilateralOPSpace_X.Integrator_CSTATE[0] =
    BilateralOPSpace_P.PIDController_InitialConditio_b;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  BilateralOPSpace_X.Filter_CSTATE[0] =
    BilateralOPSpace_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S59>/a2v' */
  BilateralOPSpace_X.a2v_CSTATE[0] = BilateralOPSpace_P.a2v_IC;

  /* InitializeConditions for Integrator: '<S59>/v2p' */
  BilateralOPSpace_X.v2p_CSTATE[1] = BilateralOPSpace_P.v2p_IC[1];

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  BilateralOPSpace_X.Integrator_CSTATE[1] =
    BilateralOPSpace_P.PIDController_InitialConditio_b;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  BilateralOPSpace_X.Filter_CSTATE[1] =
    BilateralOPSpace_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S59>/a2v' */
  BilateralOPSpace_X.a2v_CSTATE[1] = BilateralOPSpace_P.a2v_IC;
}

/* Model terminate function */
void BilateralOPSpace_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S7>/HIL Initialize' */

  /* S-Function Block: BilateralOPSpace/Real Master Robot/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(BilateralOPSpace_DW.HILInitialize_Card);
    hil_monitor_stop_all(BilateralOPSpace_DW.HILInitialize_Card);
    is_switching = false;
    if ((BilateralOPSpace_P.HILInitialize_AOTerminate && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_AOExit && is_switching)) {
      BilateralOPSpace_DW.HILInitialize_AOVoltages[0] =
        (BilateralOPSpace_P.HILInitialize_AOFinal[0]);
      BilateralOPSpace_DW.HILInitialize_AOVoltages[1] =
        (BilateralOPSpace_P.HILInitialize_AOFinal[1]);
      BilateralOPSpace_DW.HILInitialize_AOVoltages[2] =
        (BilateralOPSpace_P.HILInitialize_AOFinal[2]);

      {
        int_T i1;
        real_T *dw_AOVoltages = &BilateralOPSpace_DW.HILInitialize_AOVoltages[3];
        for (i1=0; i1 < 5; i1++) {
          dw_AOVoltages[i1] = (BilateralOPSpace_P.HILInitialize_AOFinal[3]);
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((BilateralOPSpace_P.HILInitialize_POTerminate && !is_switching) ||
        (BilateralOPSpace_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &BilateralOPSpace_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = BilateralOPSpace_P.HILInitialize_POFinal;
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
      result = hil_write(BilateralOPSpace_DW.HILInitialize_Card
                         , BilateralOPSpace_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , BilateralOPSpace_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &BilateralOPSpace_DW.HILInitialize_AOVoltages[0]
                         , &BilateralOPSpace_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(BilateralOPSpace_DW.HILInitialize_Card,
            BilateralOPSpace_P.HILInitialize_AOChannels,
            num_final_analog_outputs,
            &BilateralOPSpace_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(BilateralOPSpace_DW.HILInitialize_Card,
            BilateralOPSpace_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &BilateralOPSpace_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(BilateralOPSpace_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(BilateralOPSpace_DW.HILInitialize_Card);
    hil_monitor_delete_all(BilateralOPSpace_DW.HILInitialize_Card);
    hil_close(BilateralOPSpace_DW.HILInitialize_Card);
    BilateralOPSpace_DW.HILInitialize_Card = NULL;
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
  BilateralOPSpace_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  BilateralOPSpace_update(tid);
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
  BilateralOPSpace_initialize();
}

void MdlTerminate(void)
{
  BilateralOPSpace_terminate();
}

/* Registration function */
RT_MODEL_BilateralOPSpace_T *BilateralOPSpace(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)BilateralOPSpace_M, 0,
                sizeof(RT_MODEL_BilateralOPSpace_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BilateralOPSpace_M->solverInfo,
                          &BilateralOPSpace_M->Timing.simTimeStep);
    rtsiSetTPtr(&BilateralOPSpace_M->solverInfo, &rtmGetTPtr(BilateralOPSpace_M));
    rtsiSetStepSizePtr(&BilateralOPSpace_M->solverInfo,
                       &BilateralOPSpace_M->Timing.stepSize0);
    rtsiSetdXPtr(&BilateralOPSpace_M->solverInfo, &BilateralOPSpace_M->derivs);
    rtsiSetContStatesPtr(&BilateralOPSpace_M->solverInfo, (real_T **)
                         &BilateralOPSpace_M->contStates);
    rtsiSetNumContStatesPtr(&BilateralOPSpace_M->solverInfo,
      &BilateralOPSpace_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&BilateralOPSpace_M->solverInfo,
      &BilateralOPSpace_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&BilateralOPSpace_M->solverInfo,
      &BilateralOPSpace_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&BilateralOPSpace_M->solverInfo,
      &BilateralOPSpace_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&BilateralOPSpace_M->solverInfo, (&rtmGetErrorStatus
      (BilateralOPSpace_M)));
    rtsiSetRTModelPtr(&BilateralOPSpace_M->solverInfo, BilateralOPSpace_M);
  }

  rtsiSetSimTimeStep(&BilateralOPSpace_M->solverInfo, MAJOR_TIME_STEP);
  BilateralOPSpace_M->intgData.f[0] = BilateralOPSpace_M->odeF[0];
  BilateralOPSpace_M->contStates = ((real_T *) &BilateralOPSpace_X);
  rtsiSetSolverData(&BilateralOPSpace_M->solverInfo, (void *)
                    &BilateralOPSpace_M->intgData);
  rtsiSetSolverName(&BilateralOPSpace_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = BilateralOPSpace_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "BilateralOPSpace_M points to
       static memory which is guaranteed to be non-NULL" */
    BilateralOPSpace_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    BilateralOPSpace_M->Timing.sampleTimes =
      (&BilateralOPSpace_M->Timing.sampleTimesArray[0]);
    BilateralOPSpace_M->Timing.offsetTimes =
      (&BilateralOPSpace_M->Timing.offsetTimesArray[0]);

    /* task periods */
    BilateralOPSpace_M->Timing.sampleTimes[0] = (0.0);
    BilateralOPSpace_M->Timing.sampleTimes[1] = (0.001);
    BilateralOPSpace_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    BilateralOPSpace_M->Timing.offsetTimes[0] = (0.0);
    BilateralOPSpace_M->Timing.offsetTimes[1] = (0.0);
    BilateralOPSpace_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(BilateralOPSpace_M, &BilateralOPSpace_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = BilateralOPSpace_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      BilateralOPSpace_M->Timing.perTaskSampleHitsArray;
    BilateralOPSpace_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    BilateralOPSpace_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(BilateralOPSpace_M, 10.0);
  BilateralOPSpace_M->Timing.stepSize0 = 0.001;
  BilateralOPSpace_M->Timing.stepSize1 = 0.001;
  BilateralOPSpace_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  BilateralOPSpace_M->Sizes.checksums[0] = (532984354U);
  BilateralOPSpace_M->Sizes.checksums[1] = (100942290U);
  BilateralOPSpace_M->Sizes.checksums[2] = (2098091256U);
  BilateralOPSpace_M->Sizes.checksums[3] = (1082497223U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    BilateralOPSpace_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BilateralOPSpace_M->extModeInfo,
      &BilateralOPSpace_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BilateralOPSpace_M->extModeInfo,
                        BilateralOPSpace_M->Sizes.checksums);
    rteiSetTPtr(BilateralOPSpace_M->extModeInfo, rtmGetTPtr(BilateralOPSpace_M));
  }

  BilateralOPSpace_M->solverInfoPtr = (&BilateralOPSpace_M->solverInfo);
  BilateralOPSpace_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&BilateralOPSpace_M->solverInfo, 0.001);
  rtsiSetSolverMode(&BilateralOPSpace_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  BilateralOPSpace_M->blockIO = ((void *) &BilateralOPSpace_B);

  {
    BilateralOPSpace_B.EncoderGain[0] = 0.0;
    BilateralOPSpace_B.EncoderGain[1] = 0.0;
    BilateralOPSpace_B.phi[0] = 0.0;
    BilateralOPSpace_B.phi[1] = 0.0;
    BilateralOPSpace_B.FilterCoefficient[0] = 0.0;
    BilateralOPSpace_B.FilterCoefficient[1] = 0.0;
    BilateralOPSpace_B.invmotorgain[0] = 0.0;
    BilateralOPSpace_B.invmotorgain[1] = 0.0;
    BilateralOPSpace_B.uAmpGain[0] = 0.0;
    BilateralOPSpace_B.uAmpGain[1] = 0.0;
    BilateralOPSpace_B.uSenseGain[0] = 0.0;
    BilateralOPSpace_B.uSenseGain[1] = 0.0;
    BilateralOPSpace_B.Subtract[0] = 0.0;
    BilateralOPSpace_B.Subtract[1] = 0.0;
    BilateralOPSpace_B.IntegralGain[0] = 0.0;
    BilateralOPSpace_B.IntegralGain[1] = 0.0;
    BilateralOPSpace_B.invmotorgain_a[0] = 0.0;
    BilateralOPSpace_B.invmotorgain_a[1] = 0.0;
    BilateralOPSpace_B.phidot[0] = 0.0;
    BilateralOPSpace_B.phidot[1] = 0.0;
    BilateralOPSpace_B.RateTransition[0] = 0.0;
    BilateralOPSpace_B.RateTransition[1] = 0.0;
    BilateralOPSpace_B.F[0] = 0.0;
    BilateralOPSpace_B.F[1] = 0.0;
    BilateralOPSpace_B.y[0] = 0.0;
    BilateralOPSpace_B.y[1] = 0.0;
    BilateralOPSpace_B.G[0] = 0.0;
    BilateralOPSpace_B.G[1] = 0.0;
    BilateralOPSpace_B.x[0] = 0.0;
    BilateralOPSpace_B.x[1] = 0.0;
  }

  /* parameters */
  BilateralOPSpace_M->defaultParam = ((real_T *)&BilateralOPSpace_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &BilateralOPSpace_X;
    BilateralOPSpace_M->contStates = (x);
    (void) memset((void *)&BilateralOPSpace_X, 0,
                  sizeof(X_BilateralOPSpace_T));
  }

  /* states (dwork) */
  BilateralOPSpace_M->dwork = ((void *) &BilateralOPSpace_DW);
  (void) memset((void *)&BilateralOPSpace_DW, 0,
                sizeof(DW_BilateralOPSpace_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      BilateralOPSpace_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  BilateralOPSpace_DW.RateTransition_Buffer[0] = 0.0;
  BilateralOPSpace_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BilateralOPSpace_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  BilateralOPSpace_M->Sizes.numContStates = (8);/* Number of continuous states */
  BilateralOPSpace_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  BilateralOPSpace_M->Sizes.numY = (0);/* Number of model outputs */
  BilateralOPSpace_M->Sizes.numU = (0);/* Number of model inputs */
  BilateralOPSpace_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  BilateralOPSpace_M->Sizes.numSampTimes = (3);/* Number of sample times */
  BilateralOPSpace_M->Sizes.numBlocks = (59);/* Number of blocks */
  BilateralOPSpace_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  BilateralOPSpace_M->Sizes.numBlockPrms = (139);/* Sum of parameter "widths" */
  return BilateralOPSpace_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
