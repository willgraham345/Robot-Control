/*
 * p5.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "p5".
 *
 * Model version              : 13.30
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 25 11:07:55 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "p5.h"
#include "p5_private.h"
#include "p5_dt.h"

/* Block signals (default storage) */
B_p5_T p5_B;

/* Continuous states */
X_p5_T p5_X;

/* Block states (default storage) */
DW_p5_T p5_DW;

/* Real-time model */
static RT_MODEL_p5_T p5_M_;
RT_MODEL_p5_T *const p5_M = &p5_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(p5_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(p5_M, 2);
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
  if (p5_M->Timing.TaskCounters.TID[1] == 0) {
    p5_M->Timing.RateInteraction.TID1_2 = (p5_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    p5_M->Timing.perTaskSampleHits[5] = p5_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (p5_M->Timing.TaskCounters.TID[2])++;
  if ((p5_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    p5_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  p5_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<Root>/Jacobian  Transpose1'
 *    '<Root>/Jacobian  Transpose2'
 */
void p5_JacobianTranspose1(const real_T rtu_F[2], const real_T rtu_phi[2],
  B_JacobianTranspose1_p5_T *localB)
{
  real_T tmp[4];
  real_T tau_tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_4;
  real_T tmp_5;
  int32_T i;
  int32_T tmp_3;
  static const int8_T b[4] = { 1, -1, 0, 1 };

  /* MATLAB Function 'Jacobian  Transpose1': '<S5>:1' */
  /* '<S5>:1:6' */
  /* '<S5>:1:3' */
  /* '<S5>:1:4' */
  /* '<S5>:1:6' */
  /* '<S5>:1:10' */
  tau_tmp = sin(rtu_phi[1]);
  tmp_0 = -0.15 * sin(rtu_phi[0]) - 0.15 * tau_tmp;
  tau_tmp *= -0.15;
  tmp_2 = 0.15 * cos(rtu_phi[1]);
  tmp_1 = 0.15 * cos(rtu_phi[0]) + tmp_2;
  for (i = 0; i < 2; i++) {
    localB->tau[i] = 0.0;
    tmp[i] = 0.0;
    tmp_3 = i << 1;
    tmp_4 = b[tmp_3];
    tmp[i] += tmp_4 * tmp_0;
    tmp_5 = b[tmp_3 + 1];
    tmp[i] += tmp_5 * tau_tmp;
    localB->tau[i] += tmp[i] * rtu_F[0];
    tmp[i + 2] = 0.0;
    tmp[i + 2] += tmp_4 * tmp_1;
    tmp[i + 2] += tmp_5 * tmp_2;
    localB->tau[i] += tmp[i + 2] * rtu_F[1];
  }
}

/* Model output function for TID0 */
void p5_output0(void)                  /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Sum[2];
  real_T rtb_Gain2[2];
  real_T rtb_HILReadAnalog[2];
  real_T tmp[4];
  real_T rtb_AmpSaturation[2];
  real_T rtb_Derivative1[2];
  real_T (*lastU)[2];
  real_T H12;
  real_T h;
  real_T lastTime;
  real_T t;
  real_T tmp_0;
  real_T tmp_2;
  real_T u0;
  real_T x_idx_2;
  real_T x_tmp_tmp;
  real_T x_tmp_tmp_0;
  int32_T i;
  int32_T tmp_1;
  static const int8_T b[4] = { 1, -1, 0, 1 };

  if (rtmIsMajorTimeStep(p5_M)) {
    /* set solver stop time */
    if (!(p5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&p5_M->solverInfo, ((p5_M->Timing.clockTickH0 + 1) *
        p5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&p5_M->solverInfo, ((p5_M->Timing.clockTick0 + 1) *
        p5_M->Timing.stepSize0 + p5_M->Timing.clockTickH0 *
        p5_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(p5_M)) {
    p5_M->Timing.t[0] = rtsiGetT(&p5_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(p5_M)) {
    /* S-Function (hil_read_encoder_block): '<S8>/HIL Read Encoder' */

    /* S-Function Block: p5/Real Master Robot/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(p5_DW.HILInitialize_Card,
        p5_P.HILReadEncoder_channels, 2, &p5_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = p5_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = p5_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S8>/Encoder Gain' incorporates:
     *  Constant: '<S8>/Home Position'
     *  Sum: '<S8>/Sum1'
     */
    p5_B.EncoderGain[0] = (p5_P.HomePosition_Value[0] + rtb_HILReadAnalog[0]) *
      p5_P.EncoderGain_Gain[0];
    p5_B.EncoderGain[1] = (p5_P.HomePosition_Value[1] + rtb_HILReadAnalog[1]) *
      p5_P.EncoderGain_Gain[1];
  }

  /* Integrator: '<S60>/v2p' */
  p5_B.phi[0] = p5_X.v2p_CSTATE[0];
  p5_B.phi[1] = p5_X.v2p_CSTATE[1];

  /* MATLAB Function: '<S9>/Forward Kinematics' incorporates:
   *  MATLAB Function: '<Root>/Gravity Comp Slave'
   *  MATLAB Function: '<Root>/Jacobian  Transpose'
   */
  /* MATLAB Function 'Virtual Slave and Environment/Forward Kinematics': '<S58>:1' */
  /* '<S58>:1:5' */
  /* '<S58>:1:6' */
  /* '<S58>:1:8' */
  x_tmp_tmp = cos(p5_B.phi[0]);
  x_tmp_tmp_0 = cos(p5_B.phi[1]);
  p5_B.x[0] = 0.15 * x_tmp_tmp + 0.15 * x_tmp_tmp_0;

  /* '<S58>:1:9' */
  h = sin(p5_B.phi[0]);
  H12 = sin(p5_B.phi[1]);
  p5_B.x[1] = 0.15 * h + 0.15 * H12;

  /* Derivative: '<Root>/Derivative1' incorporates:
   *  Derivative: '<Root>/Derivative'
   */
  t = p5_M->Timing.t[0];
  if ((p5_DW.TimeStampA >= t) && (p5_DW.TimeStampB >= t)) {
    rtb_Derivative1[0] = 0.0;
    rtb_Derivative1[1] = 0.0;
  } else {
    lastTime = p5_DW.TimeStampA;
    lastU = &p5_DW.LastUAtTimeA;
    if (p5_DW.TimeStampA < p5_DW.TimeStampB) {
      if (p5_DW.TimeStampB < t) {
        lastTime = p5_DW.TimeStampB;
        lastU = &p5_DW.LastUAtTimeB;
      }
    } else if (p5_DW.TimeStampA >= t) {
      lastTime = p5_DW.TimeStampB;
      lastU = &p5_DW.LastUAtTimeB;
    }

    lastTime = t - lastTime;
    rtb_Derivative1[0] = (p5_B.x[0] - (*lastU)[0]) / lastTime;
    rtb_Derivative1[1] = (p5_B.x[1] - (*lastU)[1]) / lastTime;
  }

  /* End of Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(p5_M)) {
    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S8>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S1>:1' */
    /* '<S1>:1:5' */
    /* '<S1>:1:6' */
    /* '<S1>:1:8' */
    p5_B.x_j[0] = 0.15 * cos(p5_B.EncoderGain[0]) + 0.15 * cos(p5_B.EncoderGain
      [1]);

    /* '<S1>:1:9' */
    p5_B.x_j[1] = 0.15 * sin(p5_B.EncoderGain[0]) + 0.15 * sin(p5_B.EncoderGain
      [1]);
  }

  /* Derivative: '<Root>/Derivative' */
  if ((p5_DW.TimeStampA_k >= t) && (p5_DW.TimeStampB_d >= t)) {
    rtb_AmpSaturation[0] = 0.0;
    rtb_AmpSaturation[1] = 0.0;
  } else {
    lastTime = p5_DW.TimeStampA_k;
    lastU = &p5_DW.LastUAtTimeA_b;
    if (p5_DW.TimeStampA_k < p5_DW.TimeStampB_d) {
      if (p5_DW.TimeStampB_d < t) {
        lastTime = p5_DW.TimeStampB_d;
        lastU = &p5_DW.LastUAtTimeB_c;
      }
    } else if (p5_DW.TimeStampA_k >= t) {
      lastTime = p5_DW.TimeStampB_d;
      lastU = &p5_DW.LastUAtTimeB_c;
    }

    lastTime = t - lastTime;
    rtb_AmpSaturation[0] = (p5_B.x_j[0] - (*lastU)[0]) / lastTime;
    rtb_AmpSaturation[1] = (p5_B.x_j[1] - (*lastU)[1]) / lastTime;
  }

  /* MATLAB Function: '<Root>/Jacobian  Transpose' */
  /* MATLAB Function 'Jacobian  Transpose': '<S4>:1' */
  /* '<S4>:1:6' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:6' */
  /* '<S4>:1:10' */
  lastTime = -0.15 * h - 0.15 * sin(p5_B.phi[1]);
  H12 *= -0.15;
  tmp_0 = 0.15 * cos(p5_B.phi[0]) + 0.15 * cos(p5_B.phi[1]);
  h = 0.15 * cos(p5_B.phi[1]);
  for (i = 0; i < 2; i++) {
    /* Sum: '<Root>/Subtract' */
    p5_B.Subtract[i] = rtb_Derivative1[i] - rtb_AmpSaturation[i];

    /* Sum: '<S50>/Sum' incorporates:
     *  Gain: '<S46>/Proportional Gain'
     *  Integrator: '<S41>/Integrator'
     */
    rtb_Sum[i] = p5_P.PIDController_P[i] * p5_B.Subtract[i] +
      p5_X.Integrator_CSTATE[i];

    /* MATLAB Function: '<Root>/Jacobian  Transpose' */
    tmp[i] = 0.0;
    tmp_1 = i << 1;
    tmp_2 = b[tmp_1];
    tmp[i] += tmp_2 * lastTime;
    t = b[tmp_1 + 1];
    tmp[i] += t * H12;
    tmp[i + 2] = 0.0;
    tmp[i + 2] += tmp_2 * tmp_0;
    tmp[i + 2] += t * h;
  }

  /* MATLAB Function: '<Root>/Jacobian  Transpose' */
  lastTime = tmp[0] * rtb_Sum[0] + rtb_Sum[1] * tmp[2];
  tmp_0 = rtb_Sum[0] * tmp[1] + rtb_Sum[1] * tmp[3];

  /* MATLAB Function: '<Root>/Jacobian  Transpose2' */
  p5_JacobianTranspose1(rtb_Sum, p5_B.EncoderGain, &p5_B.sf_JacobianTranspose2);

  /* MATLAB Function: '<S9>/Wall Dynamics' incorporates:
   *  Constant: '<Root>/WallStiffness'
   */
  /* MATLAB Function 'Virtual Slave and Environment/Wall Dynamics': '<S61>:1' */
  /* '<S61>:1:7' */
  /* '<S61>:1:9' */
  p5_B.F[0] = 0.0;
  p5_B.F[1] = 0.0;
  if (p5_B.x[1] < -0.025) {
    /* '<S61>:1:11' */
    /* '<S61>:1:12' */
    p5_B.F[1] = p5_P.WallStiffness_Value * 1000.0 * (p5_B.x[1] - -0.025);
  }

  /* End of MATLAB Function: '<S9>/Wall Dynamics' */

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2[0] = p5_P.Gain2_Gain * p5_B.F[0];
  rtb_Gain2[1] = p5_P.Gain2_Gain * p5_B.F[1];

  /* MATLAB Function: '<Root>/Jacobian  Transpose1' */
  p5_JacobianTranspose1(rtb_Gain2, p5_B.EncoderGain, &p5_B.sf_JacobianTranspose1);
  if (rtmIsMajorTimeStep(p5_M)) {
    /* MATLAB Function: '<Root>/Gravity Comp Master' incorporates:
     *  Gain: '<S8>/Encoder Gain'
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
    p5_B.G[0] = 0.1690892 * cos(p5_B.EncoderGain[0]);
    p5_B.G[1] = 0.027165599999999998 * cos(p5_B.EncoderGain[1]);
  }

  /* Gain: '<Root>/inv motor gain' incorporates:
   *  Sum: '<Root>/Sum3'
   *  Sum: '<Root>/Sum4'
   */
  p5_B.invmotorgain[0] = (((p5_B.sf_JacobianTranspose2.tau[0] +
    p5_B.sf_JacobianTranspose1.tau[0]) + lastTime) + p5_B.G[0]) *
    p5_P.invmotorgain_Gain;
  p5_B.invmotorgain[1] = (((p5_B.sf_JacobianTranspose2.tau[1] +
    p5_B.sf_JacobianTranspose1.tau[1]) + tmp_0) + p5_B.G[1]) *
    p5_P.invmotorgain_Gain;

  /* Gain: '<S8>/1//AmpGain' incorporates:
   *  Bias: '<S8>/Bias'
   */
  p5_B.uAmpGain[0] = (p5_B.invmotorgain[0] + p5_P.Bias_Bias[0]) *
    p5_P.uAmpGain_Gain[0];
  p5_B.uAmpGain[1] = (p5_B.invmotorgain[1] + p5_P.Bias_Bias[1]) *
    p5_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(p5_M)) {
    /* S-Function (hil_write_analog_block): '<S8>/HIL Write Analog' */

    /* S-Function Block: p5/Real Master Robot/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(p5_DW.HILInitialize_Card,
        p5_P.HILWriteAnalog_channels, 2, &p5_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S8>/HIL Read Analog' */

    /* S-Function Block: p5/Real Master Robot/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(p5_DW.HILInitialize_Card,
        p5_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
      }
    }

    /* Gain: '<S8>/1//Sense Gain' */
    p5_B.uSenseGain[0] = p5_P.uSenseGain_Gain * rtb_HILReadAnalog[0];
    p5_B.uSenseGain[1] = p5_P.uSenseGain_Gain * rtb_HILReadAnalog[1];
  }

  /* Gain: '<S38>/Integral Gain' */
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
  p5_B.IntegralGain[0] = p5_P.PIDController_I[0] * p5_B.Subtract[0];
  p5_B.IntegralGain[1] = p5_P.PIDController_I[1] * p5_B.Subtract[1];

  /* RateTransition: '<Root>/Rate Transition' */
  if (rtmIsMajorTimeStep(p5_M) && p5_M->Timing.RateInteraction.TID1_2) {
    p5_DW.RateTransition_Buffer[0] = p5_B.phi[0];
    p5_DW.RateTransition_Buffer[1] = p5_B.phi[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Gain: '<S9>/inv motor gain' incorporates:
   *  Gain: '<Root>/Gain1'
   *  MATLAB Function: '<Root>/Gravity Comp Slave'
   *  Sum: '<Root>/Sum2'
   */
  p5_B.invmotorgain_a[0] = (0.1690892 * x_tmp_tmp - lastTime) * p5_P.Gain1_Gain *
    p5_P.invmotorgain_Gain_e;
  p5_B.invmotorgain_a[1] = (0.027165599999999998 * x_tmp_tmp_0 - tmp_0) *
    p5_P.Gain1_Gain * p5_P.invmotorgain_Gain_e;
  if (rtmIsMajorTimeStep(p5_M)) {
  }

  /* Integrator: '<S60>/a2v' */
  /* MATLAB Function 'Virtual Slave and Environment/Jacobian Transpose': '<S59>:1' */
  /* '<S59>:1:4' */
  /* '<S59>:1:5' */
  /* '<S59>:1:7' */
  /* '<S59>:1:8' */
  /* '<S59>:1:9' */
  /* '<S59>:1:10' */
  /* '<S59>:1:12' */
  /* '<S59>:1:14' */
  p5_B.phidot[0] = p5_X.a2v_CSTATE[0];
  p5_B.phidot[1] = p5_X.a2v_CSTATE[1];

  /* MATLAB Function: '<S60>/Forward Dynamics' */
  /* MATLAB Function 'Virtual Slave and Environment/Robot/Forward Dynamics': '<S62>:1' */
  /* '<S62>:1:5' */
  /* '<S62>:1:7' */
  /* '<S62>:1:8' */
  /* '<S62>:1:9' */
  /* '<S62>:1:10' */
  /* '<S62>:1:15' */
  /* '<S62>:1:16' */
  /* '<S62>:1:17' */
  /* '<S62>:1:18' */
  /* '<S62>:1:19' */
  /* '<S62>:1:20' */
  /* '<S62>:1:21' */
  /* '<S62>:1:24' */
  lastTime = p5_B.phi[1] - p5_B.phi[0];
  H12 = cos(lastTime) * 0.00041579999999999997;

  /* '<S62>:1:27' */
  h = sin(lastTime) * 0.00041579999999999997;

  /* '<S62>:1:28' */
  /* '<S62>:1:29' */
  /* '<S62>:1:30' */
  /* '<S62>:1:31' */
  /* '<S62>:1:33' */
  x_idx_2 = H12;

  /* '<S62>:1:34' */
  /* '<S62>:1:35' */
  /* '<S62>:1:36' */
  /* '<S62>:1:38' */
  H12 /= 0.0055575;
  t = 1.0 / (0.0034850000000000003 - H12 * x_idx_2);
  lastTime = p5_B.phidot[0] * p5_B.phidot[0];
  tmp_0 = p5_B.phidot[1] * p5_B.phidot[1];

  /* Saturate: '<S60>/Amp Saturation' incorporates:
   *  Gain: '<S60>/Amp Gain (A//V)'
   *  Gain: '<S9>/1//AmpGain'
   *  MATLAB Function: '<S9>/Jacobian Transpose'
   */
  u0 = p5_P.uAmpGain_Gain_j * p5_B.invmotorgain_a[0] * p5_P.AmpGainAV_Gain;
  if (u0 > p5_P.AmpSaturation_UpperSat) {
    u0 = p5_P.AmpSaturation_UpperSat;
  } else if (u0 < p5_P.AmpSaturation_LowerSat) {
    u0 = p5_P.AmpSaturation_LowerSat;
  }

  /* MATLAB Function: '<S60>/Forward Dynamics' incorporates:
   *  Gain: '<S60>/Motor Gain (Nm//A) = N*kt'
   *  MATLAB Function: '<S9>/Forward Kinematics'
   *  MATLAB Function: '<S9>/Jacobian Transpose'
   *  Sum: '<S60>/Sum2'
   */
  if (p5_B.phidot[0] < 0.0) {
    tmp_2 = -1.0;
  } else if (p5_B.phidot[0] > 0.0) {
    tmp_2 = 1.0;
  } else if (p5_B.phidot[0] == 0.0) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = (rtNaN);
  }

  x_tmp_tmp = (((p5_P.MotorGainNmANkt_Gain * u0 - (-0.15 * sin(p5_B.phi[0]) *
    p5_B.F[0] + 0.15 * cos(p5_B.phi[0]) * p5_B.F[1])) - (0.0 * lastTime + -h *
    tmp_0)) - 0.1690892 * x_tmp_tmp) - (0.01519 * p5_B.phidot[0] + 0.007 * tmp_2);

  /* Saturate: '<S60>/Amp Saturation' incorporates:
   *  Gain: '<S60>/Amp Gain (A//V)'
   *  Gain: '<S9>/1//AmpGain'
   *  MATLAB Function: '<S9>/Jacobian Transpose'
   */
  u0 = p5_P.uAmpGain_Gain_j * p5_B.invmotorgain_a[1] * p5_P.AmpGainAV_Gain;
  if (u0 > p5_P.AmpSaturation_UpperSat) {
    u0 = p5_P.AmpSaturation_UpperSat;
  } else if (u0 < p5_P.AmpSaturation_LowerSat) {
    u0 = p5_P.AmpSaturation_LowerSat;
  }

  /* MATLAB Function: '<S60>/Forward Dynamics' incorporates:
   *  Gain: '<S60>/Motor Gain (Nm//A) = N*kt'
   *  MATLAB Function: '<S9>/Forward Kinematics'
   *  MATLAB Function: '<S9>/Jacobian Transpose'
   *  Sum: '<S60>/Sum2'
   */
  if (p5_B.phidot[1] < 0.0) {
    tmp_2 = -1.0;
  } else if (p5_B.phidot[1] > 0.0) {
    tmp_2 = 1.0;
  } else if (p5_B.phidot[1] == 0.0) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = (rtNaN);
  }

  tmp_0 = (((p5_P.MotorGainNmANkt_Gain * u0 - (-0.15 * sin(p5_B.phi[1]) *
              p5_B.F[0] + 0.15 * cos(p5_B.phi[1]) * p5_B.F[1])) - (h * lastTime
             + 0.0 * tmp_0)) - 0.027165599999999998 * x_tmp_tmp_0) - (0.01519 *
    p5_B.phidot[1] + 0.007 * tmp_2);
  p5_B.y[0] = 0.0;
  p5_B.y[0] += 0.627080521817364 * t * x_tmp_tmp;
  p5_B.y[0] += -x_idx_2 / 0.0055575 * t * tmp_0;
  p5_B.y[1] = 0.0;
  p5_B.y[1] += -H12 * t * x_tmp_tmp;
  p5_B.y[1] += t * tmp_0;
}

/* Model update function for TID0 */
void p5_update0(void)                  /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<Root>/Derivative1' */
  if (p5_DW.TimeStampA == (rtInf)) {
    p5_DW.TimeStampA = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeA;
  } else if (p5_DW.TimeStampB == (rtInf)) {
    p5_DW.TimeStampB = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeB;
  } else if (p5_DW.TimeStampA < p5_DW.TimeStampB) {
    p5_DW.TimeStampA = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeA;
  } else {
    p5_DW.TimeStampB = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeB;
  }

  (*lastU)[0] = p5_B.x[0];
  (*lastU)[1] = p5_B.x[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (p5_DW.TimeStampA_k == (rtInf)) {
    p5_DW.TimeStampA_k = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeA_b;
  } else if (p5_DW.TimeStampB_d == (rtInf)) {
    p5_DW.TimeStampB_d = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeB_c;
  } else if (p5_DW.TimeStampA_k < p5_DW.TimeStampB_d) {
    p5_DW.TimeStampA_k = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeA_b;
  } else {
    p5_DW.TimeStampB_d = p5_M->Timing.t[0];
    lastU = &p5_DW.LastUAtTimeB_c;
  }

  (*lastU)[0] = p5_B.x_j[0];
  (*lastU)[1] = p5_B.x_j[1];

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(p5_M)) {
    rt_ertODEUpdateContinuousStates(&p5_M->solverInfo);
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
  if (!(++p5_M->Timing.clockTick0)) {
    ++p5_M->Timing.clockTickH0;
  }

  p5_M->Timing.t[0] = rtsiGetSolverStopTime(&p5_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++p5_M->Timing.clockTick1)) {
    ++p5_M->Timing.clockTickH1;
  }

  p5_M->Timing.t[1] = p5_M->Timing.clockTick1 * p5_M->Timing.stepSize1 +
    p5_M->Timing.clockTickH1 * p5_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void p5_derivatives(void)
{
  XDot_p5_T *_rtXdot;
  _rtXdot = ((XDot_p5_T *) p5_M->derivs);

  /* Derivatives for Integrator: '<S60>/v2p' */
  _rtXdot->v2p_CSTATE[0] = p5_B.phidot[0];

  /* Derivatives for Integrator: '<S41>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = p5_B.IntegralGain[0];

  /* Derivatives for Integrator: '<S60>/a2v' */
  _rtXdot->a2v_CSTATE[0] = p5_B.y[0];

  /* Derivatives for Integrator: '<S60>/v2p' */
  _rtXdot->v2p_CSTATE[1] = p5_B.phidot[1];

  /* Derivatives for Integrator: '<S41>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = p5_B.IntegralGain[1];

  /* Derivatives for Integrator: '<S60>/a2v' */
  _rtXdot->a2v_CSTATE[1] = p5_B.y[1];
}

/* Model output function for TID2 */
void p5_output2(void)                  /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  p5_B.RateTransition[0] = p5_DW.RateTransition_Buffer[0];
  p5_B.RateTransition[1] = p5_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void p5_update2(void)                  /* Sample time: [0.1s, 0.0s] */
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
  if (!(++p5_M->Timing.clockTick2)) {
    ++p5_M->Timing.clockTickH2;
  }

  p5_M->Timing.t[2] = p5_M->Timing.clockTick2 * p5_M->Timing.stepSize2 +
    p5_M->Timing.clockTickH2 * p5_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void p5_output(int_T tid)
{
  switch (tid) {
   case 0 :
    p5_output0();
    break;

   case 2 :
    p5_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void p5_update(int_T tid)
{
  switch (tid) {
   case 0 :
    p5_update0();
    break;

   case 2 :
    p5_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void p5_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S8>/HIL Initialize' */

  /* S-Function Block: p5/Real Master Robot/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &p5_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(p5_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(p5_DW.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(p5_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(p5_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(p5_M, _rt_error_message);
      return;
    }

    if ((p5_P.HILInitialize_AIPStart && !is_switching) ||
        (p5_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &p5_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (p5_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &p5_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = p5_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_AIChannels, 8U,
        &p5_DW.HILInitialize_AIMinimums[0], &p5_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if ((p5_P.HILInitialize_AOPStart && !is_switching) ||
        (p5_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &p5_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (p5_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &p5_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = p5_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_AOChannels, 8U,
        &p5_DW.HILInitialize_AOMinimums[0], &p5_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if ((p5_P.HILInitialize_AOStart && !is_switching) ||
        (p5_P.HILInitialize_AOEnter && is_switching)) {
      p5_DW.HILInitialize_AOVoltages[0] = (p5_P.HILInitialize_AOInitial[0]);
      p5_DW.HILInitialize_AOVoltages[1] = (p5_P.HILInitialize_AOInitial[1]);
      p5_DW.HILInitialize_AOVoltages[2] = (p5_P.HILInitialize_AOInitial[2]);

      {
        int_T i1;
        real_T *dw_AOVoltages = &p5_DW.HILInitialize_AOVoltages[3];
        for (i1=0; i1 < 5; i1++) {
          dw_AOVoltages[i1] = (p5_P.HILInitialize_AOInitial[3]);
        }
      }

      result = hil_write_analog(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_AOChannels, 8U, &p5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if (p5_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &p5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = p5_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_AOChannels, 8U, &p5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if ((p5_P.HILInitialize_EIPStart && !is_switching) ||
        (p5_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &p5_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = p5_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &p5_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if ((p5_P.HILInitialize_EIStart && !is_switching) ||
        (p5_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &p5_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = p5_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_EIChannels, 8U, &p5_DW.HILInitialize_InitialEICounts
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if ((p5_P.HILInitialize_POPStart && !is_switching) ||
        (p5_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &p5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = p5_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &p5_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          p5_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &p5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            p5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            p5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              p5_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            p5_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            p5_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              p5_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(p5_DW.HILInitialize_Card,
          &p5_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &p5_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(p5_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(p5_DW.HILInitialize_Card,
          &p5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &p5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(p5_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &p5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = p5_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &p5_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = p5_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &p5_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = p5_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &p5_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &p5_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &p5_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &p5_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = p5_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &p5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = p5_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_POChannels, 8U,
        &p5_DW.HILInitialize_POSortedFreqs[0], &p5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if ((p5_P.HILInitialize_POStart && !is_switching) ||
        (p5_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &p5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = p5_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_POChannels, 8U, &p5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }

    if (p5_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &p5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = p5_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(p5_DW.HILInitialize_Card,
        p5_P.HILInitialize_POChannels, 8U, &p5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(p5_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  p5_DW.TimeStampA = (rtInf);
  p5_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  p5_DW.TimeStampA_k = (rtInf);
  p5_DW.TimeStampB_d = (rtInf);

  /* InitializeConditions for Integrator: '<S60>/v2p' */
  p5_X.v2p_CSTATE[0] = p5_P.v2p_IC[0];

  /* InitializeConditions for Integrator: '<S41>/Integrator' */
  p5_X.Integrator_CSTATE[0] = p5_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S60>/a2v' */
  p5_X.a2v_CSTATE[0] = p5_P.a2v_IC;

  /* InitializeConditions for Integrator: '<S60>/v2p' */
  p5_X.v2p_CSTATE[1] = p5_P.v2p_IC[1];

  /* InitializeConditions for Integrator: '<S41>/Integrator' */
  p5_X.Integrator_CSTATE[1] = p5_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S60>/a2v' */
  p5_X.a2v_CSTATE[1] = p5_P.a2v_IC;
}

/* Model terminate function */
void p5_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S8>/HIL Initialize' */

  /* S-Function Block: p5/Real Master Robot/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(p5_DW.HILInitialize_Card);
    hil_monitor_stop_all(p5_DW.HILInitialize_Card);
    is_switching = false;
    if ((p5_P.HILInitialize_AOTerminate && !is_switching) ||
        (p5_P.HILInitialize_AOExit && is_switching)) {
      p5_DW.HILInitialize_AOVoltages[0] = (p5_P.HILInitialize_AOFinal[0]);
      p5_DW.HILInitialize_AOVoltages[1] = (p5_P.HILInitialize_AOFinal[1]);
      p5_DW.HILInitialize_AOVoltages[2] = (p5_P.HILInitialize_AOFinal[2]);

      {
        int_T i1;
        real_T *dw_AOVoltages = &p5_DW.HILInitialize_AOVoltages[3];
        for (i1=0; i1 < 5; i1++) {
          dw_AOVoltages[i1] = (p5_P.HILInitialize_AOFinal[3]);
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((p5_P.HILInitialize_POTerminate && !is_switching) ||
        (p5_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &p5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = p5_P.HILInitialize_POFinal;
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
      result = hil_write(p5_DW.HILInitialize_Card
                         , p5_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , p5_P.HILInitialize_POChannels, num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &p5_DW.HILInitialize_AOVoltages[0]
                         , &p5_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(p5_DW.HILInitialize_Card,
            p5_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &p5_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(p5_DW.HILInitialize_Card,
            p5_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &p5_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(p5_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(p5_DW.HILInitialize_Card);
    hil_monitor_delete_all(p5_DW.HILInitialize_Card);
    hil_close(p5_DW.HILInitialize_Card);
    p5_DW.HILInitialize_Card = NULL;
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
  p5_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  p5_update(tid);
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
  p5_initialize();
}

void MdlTerminate(void)
{
  p5_terminate();
}

/* Registration function */
RT_MODEL_p5_T *p5(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)p5_M, 0,
                sizeof(RT_MODEL_p5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&p5_M->solverInfo, &p5_M->Timing.simTimeStep);
    rtsiSetTPtr(&p5_M->solverInfo, &rtmGetTPtr(p5_M));
    rtsiSetStepSizePtr(&p5_M->solverInfo, &p5_M->Timing.stepSize0);
    rtsiSetdXPtr(&p5_M->solverInfo, &p5_M->derivs);
    rtsiSetContStatesPtr(&p5_M->solverInfo, (real_T **) &p5_M->contStates);
    rtsiSetNumContStatesPtr(&p5_M->solverInfo, &p5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&p5_M->solverInfo,
      &p5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&p5_M->solverInfo,
      &p5_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&p5_M->solverInfo,
      &p5_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&p5_M->solverInfo, (&rtmGetErrorStatus(p5_M)));
    rtsiSetRTModelPtr(&p5_M->solverInfo, p5_M);
  }

  rtsiSetSimTimeStep(&p5_M->solverInfo, MAJOR_TIME_STEP);
  p5_M->intgData.f[0] = p5_M->odeF[0];
  p5_M->contStates = ((real_T *) &p5_X);
  rtsiSetSolverData(&p5_M->solverInfo, (void *)&p5_M->intgData);
  rtsiSetSolverName(&p5_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = p5_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "p5_M points to
       static memory which is guaranteed to be non-NULL" */
    p5_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    p5_M->Timing.sampleTimes = (&p5_M->Timing.sampleTimesArray[0]);
    p5_M->Timing.offsetTimes = (&p5_M->Timing.offsetTimesArray[0]);

    /* task periods */
    p5_M->Timing.sampleTimes[0] = (0.0);
    p5_M->Timing.sampleTimes[1] = (0.001);
    p5_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    p5_M->Timing.offsetTimes[0] = (0.0);
    p5_M->Timing.offsetTimes[1] = (0.0);
    p5_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(p5_M, &p5_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = p5_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = p5_M->Timing.perTaskSampleHitsArray;
    p5_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    p5_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(p5_M, 10.0);
  p5_M->Timing.stepSize0 = 0.001;
  p5_M->Timing.stepSize1 = 0.001;
  p5_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  p5_M->Sizes.checksums[0] = (455800688U);
  p5_M->Sizes.checksums[1] = (3300808064U);
  p5_M->Sizes.checksums[2] = (1522514097U);
  p5_M->Sizes.checksums[3] = (910604590U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    p5_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(p5_M->extModeInfo, &p5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(p5_M->extModeInfo, p5_M->Sizes.checksums);
    rteiSetTPtr(p5_M->extModeInfo, rtmGetTPtr(p5_M));
  }

  p5_M->solverInfoPtr = (&p5_M->solverInfo);
  p5_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&p5_M->solverInfo, 0.001);
  rtsiSetSolverMode(&p5_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  p5_M->blockIO = ((void *) &p5_B);

  {
    p5_B.EncoderGain[0] = 0.0;
    p5_B.EncoderGain[1] = 0.0;
    p5_B.phi[0] = 0.0;
    p5_B.phi[1] = 0.0;
    p5_B.Subtract[0] = 0.0;
    p5_B.Subtract[1] = 0.0;
    p5_B.invmotorgain[0] = 0.0;
    p5_B.invmotorgain[1] = 0.0;
    p5_B.uAmpGain[0] = 0.0;
    p5_B.uAmpGain[1] = 0.0;
    p5_B.uSenseGain[0] = 0.0;
    p5_B.uSenseGain[1] = 0.0;
    p5_B.IntegralGain[0] = 0.0;
    p5_B.IntegralGain[1] = 0.0;
    p5_B.invmotorgain_a[0] = 0.0;
    p5_B.invmotorgain_a[1] = 0.0;
    p5_B.phidot[0] = 0.0;
    p5_B.phidot[1] = 0.0;
    p5_B.RateTransition[0] = 0.0;
    p5_B.RateTransition[1] = 0.0;
    p5_B.F[0] = 0.0;
    p5_B.F[1] = 0.0;
    p5_B.y[0] = 0.0;
    p5_B.y[1] = 0.0;
    p5_B.x[0] = 0.0;
    p5_B.x[1] = 0.0;
    p5_B.G[0] = 0.0;
    p5_B.G[1] = 0.0;
    p5_B.x_j[0] = 0.0;
    p5_B.x_j[1] = 0.0;
    p5_B.sf_JacobianTranspose2.tau[0] = 0.0;
    p5_B.sf_JacobianTranspose2.tau[1] = 0.0;
    p5_B.sf_JacobianTranspose1.tau[0] = 0.0;
    p5_B.sf_JacobianTranspose1.tau[1] = 0.0;
  }

  /* parameters */
  p5_M->defaultParam = ((real_T *)&p5_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &p5_X;
    p5_M->contStates = (x);
    (void) memset((void *)&p5_X, 0,
                  sizeof(X_p5_T));
  }

  /* states (dwork) */
  p5_M->dwork = ((void *) &p5_DW);
  (void) memset((void *)&p5_DW, 0,
                sizeof(DW_p5_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      p5_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  p5_DW.TimeStampA = 0.0;
  p5_DW.LastUAtTimeA[0] = 0.0;
  p5_DW.LastUAtTimeA[1] = 0.0;
  p5_DW.TimeStampB = 0.0;
  p5_DW.LastUAtTimeB[0] = 0.0;
  p5_DW.LastUAtTimeB[1] = 0.0;
  p5_DW.TimeStampA_k = 0.0;
  p5_DW.LastUAtTimeA_b[0] = 0.0;
  p5_DW.LastUAtTimeA_b[1] = 0.0;
  p5_DW.TimeStampB_d = 0.0;
  p5_DW.LastUAtTimeB_c[0] = 0.0;
  p5_DW.LastUAtTimeB_c[1] = 0.0;
  p5_DW.RateTransition_Buffer[0] = 0.0;
  p5_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    p5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  p5_M->Sizes.numContStates = (6);     /* Number of continuous states */
  p5_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  p5_M->Sizes.numY = (0);              /* Number of model outputs */
  p5_M->Sizes.numU = (0);              /* Number of model inputs */
  p5_M->Sizes.sysDirFeedThru = (0);    /* The model is not direct feedthrough */
  p5_M->Sizes.numSampTimes = (3);      /* Number of sample times */
  p5_M->Sizes.numBlocks = (58);        /* Number of blocks */
  p5_M->Sizes.numBlockIO = (17);       /* Number of block outputs */
  p5_M->Sizes.numBlockPrms = (136);    /* Sum of parameter "widths" */
  return p5_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
