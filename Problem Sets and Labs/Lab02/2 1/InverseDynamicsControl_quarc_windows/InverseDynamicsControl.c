/*
 * InverseDynamicsControl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "InverseDynamicsControl".
 *
 * Model version              : 3.17
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 16 12:19:05 2023
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "InverseDynamicsControl.h"
#include "InverseDynamicsControl_private.h"
#include "InverseDynamicsControl_dt.h"

/* Block signals (default storage) */
B_InverseDynamicsControl_T InverseDynamicsControl_B;

/* Continuous states */
X_InverseDynamicsControl_T InverseDynamicsControl_X;

/* Block states (default storage) */
DW_InverseDynamicsControl_T InverseDynamicsControl_DW;

/* Real-time model */
static RT_MODEL_InverseDynamicsContr_T InverseDynamicsControl_M_;
RT_MODEL_InverseDynamicsContr_T *const InverseDynamicsControl_M =
  &InverseDynamicsControl_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(InverseDynamicsControl_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(InverseDynamicsControl_M, 2);
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
  if (InverseDynamicsControl_M->Timing.TaskCounters.TID[1] == 0) {
    InverseDynamicsControl_M->Timing.RateInteraction.TID1_2 =
      (InverseDynamicsControl_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    InverseDynamicsControl_M->Timing.perTaskSampleHits[5] =
      InverseDynamicsControl_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (InverseDynamicsControl_M->Timing.TaskCounters.TID[2])++;
  if ((InverseDynamicsControl_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.02s, 0.0s] */
    InverseDynamicsControl_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  InverseDynamicsControl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  InverseDynamicsControl_output0();
  InverseDynamicsControl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  InverseDynamicsControl_output0();
  InverseDynamicsControl_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
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
void InverseDynamicsControl_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];
  real_T Current_tmp;
  real_T H12;
  real_T h;
  real_T t;
  real_T theta_idx_0;
  real_T theta_idx_1;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T x_tmp;
  if (rtmIsMajorTimeStep(InverseDynamicsControl_M)) {
    /* set solver stop time */
    if (!(InverseDynamicsControl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&InverseDynamicsControl_M->solverInfo,
                            ((InverseDynamicsControl_M->Timing.clockTickH0 + 1) *
        InverseDynamicsControl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&InverseDynamicsControl_M->solverInfo,
                            ((InverseDynamicsControl_M->Timing.clockTick0 + 1) *
        InverseDynamicsControl_M->Timing.stepSize0 +
        InverseDynamicsControl_M->Timing.clockTickH0 *
        InverseDynamicsControl_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(InverseDynamicsControl_M)) {
    InverseDynamicsControl_M->Timing.t[0] = rtsiGetT
      (&InverseDynamicsControl_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Derivative: '<Root>/Derivative1'
   *  Derivative: '<Root>/Derivative2'
   */
  h = InverseDynamicsControl_M->Timing.t[0];
  if (rtmIsMajorTimeStep(InverseDynamicsControl_M)) {
    /* Constant: '<Root>/Speed' */
    InverseDynamicsControl_B.Speed = InverseDynamicsControl_P.Speed_Value;
  }

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Clock: '<Root>/Clock'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S7>:1' */
  if (h < 0.5) {
    /* '<S7>:1:6' */
    /* '<S7>:1:7' */
    x_tmp = 6.2831853071795862 * InverseDynamicsControl_B.Speed * (h * h);
    InverseDynamicsControl_B.x[0] = cos(x_tmp) * 0.075 + 0.125;

    /* '<S7>:1:8' */
    InverseDynamicsControl_B.x[1] = sin(x_tmp) * 0.075 + 0.1;
  } else {
    /* '<S7>:1:10' */
    x_tmp = 6.2831853071795862 * InverseDynamicsControl_B.Speed * (h - 0.25);
    InverseDynamicsControl_B.x[0] = cos(x_tmp) * 0.075 + 0.125;

    /* '<S7>:1:11' */
    InverseDynamicsControl_B.x[1] = sin(x_tmp) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  /* MATLAB Function 'Inverse Kinematics': '<S4>:1' */
  /* '<S4>:1:12' */
  /* '<S4>:1:4' */
  /* '<S4>:1:5' */
  /* '<S4>:1:9' */
  x_tmp = InverseDynamicsControl_B.x[0] * InverseDynamicsControl_B.x[0] +
    InverseDynamicsControl_B.x[1] * InverseDynamicsControl_B.x[1];
  theta_idx_1 = atan(sqrt((0.09 - x_tmp) / x_tmp)) * -2.0;

  /* '<S4>:1:10' */
  theta_idx_0 = rt_atan2d_snf(InverseDynamicsControl_B.x[1],
    InverseDynamicsControl_B.x[0]) - rt_atan2d_snf(0.15 * sin(theta_idx_1), 0.15
    * cos(theta_idx_1) + 0.15);

  /* '<S4>:1:12' */
  InverseDynamicsControl_B.phi_c[0] = 0.0;
  InverseDynamicsControl_B.phi_c[0] += theta_idx_0;
  InverseDynamicsControl_B.phi_c[0] += 0.0 * theta_idx_1;

  /* Integrator: '<S6>/v2p' */
  InverseDynamicsControl_B.phi[0] = InverseDynamicsControl_X.v2p_CSTATE[0];

  /* Sum: '<Root>/Sum' */
  InverseDynamicsControl_B.Sum[0] = InverseDynamicsControl_B.phi_c[0] -
    InverseDynamicsControl_B.phi[0];

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  InverseDynamicsControl_B.phi_c[1] = 0.0;
  InverseDynamicsControl_B.phi_c[1] += theta_idx_0;
  InverseDynamicsControl_B.phi_c[1] += theta_idx_1;

  /* Integrator: '<S6>/v2p' */
  InverseDynamicsControl_B.phi[1] = InverseDynamicsControl_X.v2p_CSTATE[1];

  /* Sum: '<Root>/Sum' */
  InverseDynamicsControl_B.Sum[1] = InverseDynamicsControl_B.phi_c[1] -
    InverseDynamicsControl_B.phi[1];
  if (rtmIsMajorTimeStep(InverseDynamicsControl_M)) {
  }

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<S34>/SumD'
   */
  InverseDynamicsControl_B.FilterCoefficient[0] =
    (InverseDynamicsControl_P.PIDController_D * InverseDynamicsControl_B.Sum[0]
     - InverseDynamicsControl_X.Filter_CSTATE[0]) *
    InverseDynamicsControl_P.PIDController_N;
  InverseDynamicsControl_B.FilterCoefficient[1] =
    (InverseDynamicsControl_P.PIDController_D * InverseDynamicsControl_B.Sum[1]
     - InverseDynamicsControl_X.Filter_CSTATE[1]) *
    InverseDynamicsControl_P.PIDController_N;

  /* Derivative: '<Root>/Derivative2' */
  if ((InverseDynamicsControl_DW.TimeStampA >= h) &&
      (InverseDynamicsControl_DW.TimeStampB >= h)) {
    /* Derivative: '<Root>/Derivative2' */
    InverseDynamicsControl_B.Derivative2[0] = 0.0;
    InverseDynamicsControl_B.Derivative2[1] = 0.0;
  } else {
    H12 = InverseDynamicsControl_DW.TimeStampA;
    lastU = &InverseDynamicsControl_DW.LastUAtTimeA;
    if (InverseDynamicsControl_DW.TimeStampA <
        InverseDynamicsControl_DW.TimeStampB) {
      if (InverseDynamicsControl_DW.TimeStampB < h) {
        H12 = InverseDynamicsControl_DW.TimeStampB;
        lastU = &InverseDynamicsControl_DW.LastUAtTimeB;
      }
    } else if (InverseDynamicsControl_DW.TimeStampA >= h) {
      H12 = InverseDynamicsControl_DW.TimeStampB;
      lastU = &InverseDynamicsControl_DW.LastUAtTimeB;
    }

    H12 = h - H12;

    /* Derivative: '<Root>/Derivative2' */
    InverseDynamicsControl_B.Derivative2[0] = (InverseDynamicsControl_B.phi_c[0]
      - (*lastU)[0]) / H12;
    InverseDynamicsControl_B.Derivative2[1] = (InverseDynamicsControl_B.phi_c[1]
      - (*lastU)[1]) / H12;
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((InverseDynamicsControl_DW.TimeStampA_p >= h) &&
      (InverseDynamicsControl_DW.TimeStampB_c >= h)) {
    theta_idx_0 = 0.0;
    theta_idx_1 = 0.0;
  } else {
    H12 = InverseDynamicsControl_DW.TimeStampA_p;
    lastU = &InverseDynamicsControl_DW.LastUAtTimeA_j;
    if (InverseDynamicsControl_DW.TimeStampA_p <
        InverseDynamicsControl_DW.TimeStampB_c) {
      if (InverseDynamicsControl_DW.TimeStampB_c < h) {
        H12 = InverseDynamicsControl_DW.TimeStampB_c;
        lastU = &InverseDynamicsControl_DW.LastUAtTimeB_m;
      }
    } else if (InverseDynamicsControl_DW.TimeStampA_p >= h) {
      H12 = InverseDynamicsControl_DW.TimeStampB_c;
      lastU = &InverseDynamicsControl_DW.LastUAtTimeB_m;
    }

    H12 = h - H12;
    theta_idx_0 = (InverseDynamicsControl_B.Derivative2[0] - (*lastU)[0]) / H12;
    theta_idx_1 = (InverseDynamicsControl_B.Derivative2[1] - (*lastU)[1]) / H12;
  }

  /* MATLAB Function: '<Root>/Inertia Matrix' incorporates:
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<S6>/Forward Dynamics'
   */
  /* MATLAB Function 'Inertia Matrix': '<S3>:1' */
  /* '<S3>:1:4' */
  /* '<S3>:1:7' */
  /* '<S3>:1:9' */
  /* '<S3>:1:23' */
  x_tmp = InverseDynamicsControl_B.phi[1] - InverseDynamicsControl_B.phi[0];
  h = cos(x_tmp) * 0.00041579999999999997;

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  MATLAB Function: '<Root>/Forward Kinematics'
   *  MATLAB Function: '<S6>/Forward Dynamics'
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
  x_tmp = sin(x_tmp) * 0.00041579999999999997;

  /* '<S1>:1:23' */
  /* '<S1>:1:24' */
  /* '<S1>:1:25' */
  /* '<S1>:1:26' */
  /* '<S1>:1:28' */
  /* '<S1>:1:29' */
  /* '<S1>:1:30' */
  /* '<S1>:1:32' */
  t = cos(InverseDynamicsControl_B.phi[0]);
  H12 = cos(InverseDynamicsControl_B.phi[1]);

  /* Integrator: '<S6>/a2v' */
  InverseDynamicsControl_B.phidot[0] = InverseDynamicsControl_X.a2v_CSTATE[0];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S44>/Proportional Gain'
   *  Sum: '<S48>/Sum'
   */
  theta_idx_0 += InverseDynamicsControl_P.PIDController_P *
    InverseDynamicsControl_B.Sum[0] +
    InverseDynamicsControl_B.FilterCoefficient[0];

  /* Integrator: '<S6>/a2v' */
  InverseDynamicsControl_B.phidot[1] = InverseDynamicsControl_X.a2v_CSTATE[1];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S44>/Proportional Gain'
   *  Sum: '<S48>/Sum'
   */
  tmp = (InverseDynamicsControl_P.PIDController_P *
         InverseDynamicsControl_B.Sum[1] +
         InverseDynamicsControl_B.FilterCoefficient[1]) + theta_idx_1;

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  MATLAB Function: '<S6>/Forward Dynamics'
   */
  theta_idx_1 = InverseDynamicsControl_B.phidot[0] *
    InverseDynamicsControl_B.phidot[0];
  tmp_1 = InverseDynamicsControl_B.phidot[1] * InverseDynamicsControl_B.phidot[1];
  if (InverseDynamicsControl_B.phidot[0] < 0.0) {
    tmp_0 = -1.0;
  } else if (InverseDynamicsControl_B.phidot[0] > 0.0) {
    tmp_0 = 1.0;
  } else if (InverseDynamicsControl_B.phidot[0] == 0.0) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = (rtNaN);
  }

  Current_tmp = 0.0 * theta_idx_1 + -x_tmp * tmp_1;

  /* Gain: '<Root>/1//AmpGain (V//A)1' incorporates:
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Inertia Matrix'
   *  Sum: '<Root>/Sum2'
   */
  InverseDynamicsControl_B.Current[0] = (((0.1690892 * t + Current_tmp) +
    (0.01519 * InverseDynamicsControl_B.phidot[0] + 0.007 * tmp_0)) + (0.0055575
    * theta_idx_0 + h * tmp)) * InverseDynamicsControl_P.uAmpGainVA1_Gain;

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  MATLAB Function: '<S6>/Forward Dynamics'
   */
  if (InverseDynamicsControl_B.phidot[1] < 0.0) {
    tmp_0 = -1.0;
  } else if (InverseDynamicsControl_B.phidot[1] > 0.0) {
    tmp_0 = 1.0;
  } else if (InverseDynamicsControl_B.phidot[1] == 0.0) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = (rtNaN);
  }

  x_tmp = x_tmp * theta_idx_1 + 0.0 * tmp_1;

  /* Gain: '<Root>/1//AmpGain (V//A)1' incorporates:
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Inertia Matrix'
   *  Sum: '<Root>/Sum2'
   */
  InverseDynamicsControl_B.Current[1] = (((0.027165599999999998 * H12 + x_tmp) +
    (0.01519 * InverseDynamicsControl_B.phidot[1] + 0.007 * tmp_0)) + (h *
    theta_idx_0 + 0.0034850000000000003 * tmp)) *
    InverseDynamicsControl_P.uAmpGainVA1_Gain;
  if (rtmIsMajorTimeStep(InverseDynamicsControl_M)) {
  }

  /* MATLAB Function: '<Root>/Forward Kinematics' */
  /* MATLAB Function 'Forward Kinematics': '<S2>:1' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:8' */
  InverseDynamicsControl_B.x_n[0] = 0.15 * t + 0.15 * H12;

  /* '<S2>:1:9' */
  InverseDynamicsControl_B.x_n[1] = 0.15 * sin(InverseDynamicsControl_B.phi[0])
    + 0.15 * sin(InverseDynamicsControl_B.phi[1]);

  /* RateTransition: '<Root>/Rate Transition' */
  if (rtmIsMajorTimeStep(InverseDynamicsControl_M)) {
    if (InverseDynamicsControl_M->Timing.RateInteraction.TID1_2) {
      InverseDynamicsControl_DW.RateTransition_Buffer[0] =
        InverseDynamicsControl_B.phi[0];
      InverseDynamicsControl_DW.RateTransition_Buffer[1] =
        InverseDynamicsControl_B.phi[1];
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* MATLAB Function: '<S6>/Forward Dynamics' */
  /* MATLAB Function 'Robot/Forward Dynamics': '<S56>:1' */
  /* '<S56>:1:5' */
  /* '<S56>:1:7' */
  /* '<S56>:1:8' */
  /* '<S56>:1:9' */
  /* '<S56>:1:10' */
  /* '<S56>:1:15' */
  /* '<S56>:1:16' */
  /* '<S56>:1:17' */
  /* '<S56>:1:18' */
  /* '<S56>:1:19' */
  /* '<S56>:1:20' */
  /* '<S56>:1:21' */
  /* '<S56>:1:24' */
  /* '<S56>:1:27' */
  /* '<S56>:1:28' */
  /* '<S56>:1:29' */
  /* '<S56>:1:30' */
  /* '<S56>:1:31' */
  /* '<S56>:1:33' */
  /* '<S56>:1:34' */
  /* '<S56>:1:35' */
  /* '<S56>:1:36' */
  /* '<S56>:1:38' */
  H12 = h / 0.0055575;
  t = 1.0 / (0.0034850000000000003 - H12 * h);

  /* Saturate: '<S6>/Amp Saturation' incorporates:
   *  Gain: '<Root>/1//AmpGain (V//A)'
   *  Gain: '<S6>/Amp Gain (A//V)'
   *  MATLAB Function: '<S6>/Forward Dynamics'
   */
  tmp = InverseDynamicsControl_P.uAmpGainVA_Gain *
    InverseDynamicsControl_B.Current[0] *
    InverseDynamicsControl_P.AmpGainAV_Gain;
  if (tmp > InverseDynamicsControl_P.AmpSaturation_UpperSat) {
    tmp = InverseDynamicsControl_P.AmpSaturation_UpperSat;
  } else if (tmp < InverseDynamicsControl_P.AmpSaturation_LowerSat) {
    tmp = InverseDynamicsControl_P.AmpSaturation_LowerSat;
  }

  /* MATLAB Function: '<S6>/Forward Dynamics' incorporates:
   *  Gain: '<S6>/Motor Gain (Nm//A) = N*kt'
   */
  if (InverseDynamicsControl_B.phidot[0] < 0.0) {
    tmp_0 = -1.0;
  } else if (InverseDynamicsControl_B.phidot[0] > 0.0) {
    tmp_0 = 1.0;
  } else if (InverseDynamicsControl_B.phidot[0] == 0.0) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = (rtNaN);
  }

  theta_idx_0 = ((InverseDynamicsControl_P.MotorGainNmANkt_Gain * tmp -
                  Current_tmp) - 0.1690892 * cos(InverseDynamicsControl_B.phi[0]))
    - (0.01519 * InverseDynamicsControl_B.phidot[0] + 0.007 * tmp_0);

  /* Saturate: '<S6>/Amp Saturation' incorporates:
   *  Gain: '<Root>/1//AmpGain (V//A)'
   *  Gain: '<S6>/Amp Gain (A//V)'
   *  MATLAB Function: '<S6>/Forward Dynamics'
   */
  tmp = InverseDynamicsControl_P.uAmpGainVA_Gain *
    InverseDynamicsControl_B.Current[1] *
    InverseDynamicsControl_P.AmpGainAV_Gain;
  if (tmp > InverseDynamicsControl_P.AmpSaturation_UpperSat) {
    tmp = InverseDynamicsControl_P.AmpSaturation_UpperSat;
  } else if (tmp < InverseDynamicsControl_P.AmpSaturation_LowerSat) {
    tmp = InverseDynamicsControl_P.AmpSaturation_LowerSat;
  }

  /* MATLAB Function: '<S6>/Forward Dynamics' incorporates:
   *  Gain: '<S6>/Motor Gain (Nm//A) = N*kt'
   */
  if (InverseDynamicsControl_B.phidot[1] < 0.0) {
    tmp_0 = -1.0;
  } else if (InverseDynamicsControl_B.phidot[1] > 0.0) {
    tmp_0 = 1.0;
  } else if (InverseDynamicsControl_B.phidot[1] == 0.0) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = (rtNaN);
  }

  tmp = ((InverseDynamicsControl_P.MotorGainNmANkt_Gain * tmp - x_tmp) -
         0.027165599999999998 * cos(InverseDynamicsControl_B.phi[1])) - (0.01519
    * InverseDynamicsControl_B.phidot[1] + 0.007 * tmp_0);
  InverseDynamicsControl_B.y[0] = 0.0;
  InverseDynamicsControl_B.y[0] += 0.627080521817364 * t * theta_idx_0;
  InverseDynamicsControl_B.y[0] += -h / 0.0055575 * t * tmp;
  InverseDynamicsControl_B.y[1] = 0.0;
  InverseDynamicsControl_B.y[1] += -H12 * t * theta_idx_0;
  InverseDynamicsControl_B.y[1] += t * tmp;
}

/* Model update function for TID0 */
void InverseDynamicsControl_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<Root>/Derivative2' */
  if (InverseDynamicsControl_DW.TimeStampA == (rtInf)) {
    InverseDynamicsControl_DW.TimeStampA = InverseDynamicsControl_M->Timing.t[0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeA;
  } else if (InverseDynamicsControl_DW.TimeStampB == (rtInf)) {
    InverseDynamicsControl_DW.TimeStampB = InverseDynamicsControl_M->Timing.t[0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeB;
  } else if (InverseDynamicsControl_DW.TimeStampA <
             InverseDynamicsControl_DW.TimeStampB) {
    InverseDynamicsControl_DW.TimeStampA = InverseDynamicsControl_M->Timing.t[0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeA;
  } else {
    InverseDynamicsControl_DW.TimeStampB = InverseDynamicsControl_M->Timing.t[0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeB;
  }

  (*lastU)[0] = InverseDynamicsControl_B.phi_c[0];
  (*lastU)[1] = InverseDynamicsControl_B.phi_c[1];

  /* End of Update for Derivative: '<Root>/Derivative2' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (InverseDynamicsControl_DW.TimeStampA_p == (rtInf)) {
    InverseDynamicsControl_DW.TimeStampA_p = InverseDynamicsControl_M->Timing.t
      [0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeA_j;
  } else if (InverseDynamicsControl_DW.TimeStampB_c == (rtInf)) {
    InverseDynamicsControl_DW.TimeStampB_c = InverseDynamicsControl_M->Timing.t
      [0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeB_m;
  } else if (InverseDynamicsControl_DW.TimeStampA_p <
             InverseDynamicsControl_DW.TimeStampB_c) {
    InverseDynamicsControl_DW.TimeStampA_p = InverseDynamicsControl_M->Timing.t
      [0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeA_j;
  } else {
    InverseDynamicsControl_DW.TimeStampB_c = InverseDynamicsControl_M->Timing.t
      [0];
    lastU = &InverseDynamicsControl_DW.LastUAtTimeB_m;
  }

  (*lastU)[0] = InverseDynamicsControl_B.Derivative2[0];
  (*lastU)[1] = InverseDynamicsControl_B.Derivative2[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(InverseDynamicsControl_M)) {
    rt_ertODEUpdateContinuousStates(&InverseDynamicsControl_M->solverInfo);
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
  if (!(++InverseDynamicsControl_M->Timing.clockTick0)) {
    ++InverseDynamicsControl_M->Timing.clockTickH0;
  }

  InverseDynamicsControl_M->Timing.t[0] = rtsiGetSolverStopTime
    (&InverseDynamicsControl_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++InverseDynamicsControl_M->Timing.clockTick1)) {
    ++InverseDynamicsControl_M->Timing.clockTickH1;
  }

  InverseDynamicsControl_M->Timing.t[1] =
    InverseDynamicsControl_M->Timing.clockTick1 *
    InverseDynamicsControl_M->Timing.stepSize1 +
    InverseDynamicsControl_M->Timing.clockTickH1 *
    InverseDynamicsControl_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void InverseDynamicsControl_derivatives(void)
{
  XDot_InverseDynamicsControl_T *_rtXdot;
  _rtXdot = ((XDot_InverseDynamicsControl_T *) InverseDynamicsControl_M->derivs);

  /* Derivatives for Integrator: '<S6>/v2p' */
  _rtXdot->v2p_CSTATE[0] = InverseDynamicsControl_B.phidot[0];

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE[0] = InverseDynamicsControl_B.FilterCoefficient[0];

  /* Derivatives for Integrator: '<S6>/a2v' */
  _rtXdot->a2v_CSTATE[0] = InverseDynamicsControl_B.y[0];

  /* Derivatives for Integrator: '<S6>/v2p' */
  _rtXdot->v2p_CSTATE[1] = InverseDynamicsControl_B.phidot[1];

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE[1] = InverseDynamicsControl_B.FilterCoefficient[1];

  /* Derivatives for Integrator: '<S6>/a2v' */
  _rtXdot->a2v_CSTATE[1] = InverseDynamicsControl_B.y[1];
}

/* Model output function for TID2 */
void InverseDynamicsControl_output2(void) /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  InverseDynamicsControl_B.RateTransition[0] =
    InverseDynamicsControl_DW.RateTransition_Buffer[0];
  InverseDynamicsControl_B.RateTransition[1] =
    InverseDynamicsControl_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void InverseDynamicsControl_update2(void) /* Sample time: [0.02s, 0.0s] */
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
  if (!(++InverseDynamicsControl_M->Timing.clockTick2)) {
    ++InverseDynamicsControl_M->Timing.clockTickH2;
  }

  InverseDynamicsControl_M->Timing.t[2] =
    InverseDynamicsControl_M->Timing.clockTick2 *
    InverseDynamicsControl_M->Timing.stepSize2 +
    InverseDynamicsControl_M->Timing.clockTickH2 *
    InverseDynamicsControl_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void InverseDynamicsControl_output(int_T tid)
{
  switch (tid) {
   case 0 :
    InverseDynamicsControl_output0();
    break;

   case 2 :
    InverseDynamicsControl_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void InverseDynamicsControl_update(int_T tid)
{
  switch (tid) {
   case 0 :
    InverseDynamicsControl_update0();
    break;

   case 2 :
    InverseDynamicsControl_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void InverseDynamicsControl_initialize(void)
{
  /* Start for Constant: '<Root>/Speed' */
  InverseDynamicsControl_B.Speed = InverseDynamicsControl_P.Speed_Value;

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  InverseDynamicsControl_DW.TimeStampA = (rtInf);
  InverseDynamicsControl_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  InverseDynamicsControl_DW.TimeStampA_p = (rtInf);
  InverseDynamicsControl_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Integrator: '<S6>/v2p' */
  InverseDynamicsControl_X.v2p_CSTATE[0] = InverseDynamicsControl_P.v2p_IC[0];

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  InverseDynamicsControl_X.Filter_CSTATE[0] =
    InverseDynamicsControl_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S6>/a2v' */
  InverseDynamicsControl_X.a2v_CSTATE[0] = InverseDynamicsControl_P.a2v_IC;

  /* InitializeConditions for Integrator: '<S6>/v2p' */
  InverseDynamicsControl_X.v2p_CSTATE[1] = InverseDynamicsControl_P.v2p_IC[1];

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  InverseDynamicsControl_X.Filter_CSTATE[1] =
    InverseDynamicsControl_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S6>/a2v' */
  InverseDynamicsControl_X.a2v_CSTATE[1] = InverseDynamicsControl_P.a2v_IC;
}

/* Model terminate function */
void InverseDynamicsControl_terminate(void)
{
  /* (no terminate code required) */
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
  InverseDynamicsControl_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  InverseDynamicsControl_update(tid);
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
  InverseDynamicsControl_initialize();
}

void MdlTerminate(void)
{
  InverseDynamicsControl_terminate();
}

/* Registration function */
RT_MODEL_InverseDynamicsContr_T *InverseDynamicsControl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)InverseDynamicsControl_M, 0,
                sizeof(RT_MODEL_InverseDynamicsContr_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&InverseDynamicsControl_M->solverInfo,
                          &InverseDynamicsControl_M->Timing.simTimeStep);
    rtsiSetTPtr(&InverseDynamicsControl_M->solverInfo, &rtmGetTPtr
                (InverseDynamicsControl_M));
    rtsiSetStepSizePtr(&InverseDynamicsControl_M->solverInfo,
                       &InverseDynamicsControl_M->Timing.stepSize0);
    rtsiSetdXPtr(&InverseDynamicsControl_M->solverInfo,
                 &InverseDynamicsControl_M->derivs);
    rtsiSetContStatesPtr(&InverseDynamicsControl_M->solverInfo, (real_T **)
                         &InverseDynamicsControl_M->contStates);
    rtsiSetNumContStatesPtr(&InverseDynamicsControl_M->solverInfo,
      &InverseDynamicsControl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&InverseDynamicsControl_M->solverInfo,
      &InverseDynamicsControl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&InverseDynamicsControl_M->solverInfo,
      &InverseDynamicsControl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&InverseDynamicsControl_M->solverInfo,
      &InverseDynamicsControl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&InverseDynamicsControl_M->solverInfo,
                          (&rtmGetErrorStatus(InverseDynamicsControl_M)));
    rtsiSetRTModelPtr(&InverseDynamicsControl_M->solverInfo,
                      InverseDynamicsControl_M);
  }

  rtsiSetSimTimeStep(&InverseDynamicsControl_M->solverInfo, MAJOR_TIME_STEP);
  InverseDynamicsControl_M->intgData.y = InverseDynamicsControl_M->odeY;
  InverseDynamicsControl_M->intgData.f[0] = InverseDynamicsControl_M->odeF[0];
  InverseDynamicsControl_M->intgData.f[1] = InverseDynamicsControl_M->odeF[1];
  InverseDynamicsControl_M->intgData.f[2] = InverseDynamicsControl_M->odeF[2];
  InverseDynamicsControl_M->contStates = ((real_T *) &InverseDynamicsControl_X);
  rtsiSetSolverData(&InverseDynamicsControl_M->solverInfo, (void *)
                    &InverseDynamicsControl_M->intgData);
  rtsiSetSolverName(&InverseDynamicsControl_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = InverseDynamicsControl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "InverseDynamicsControl_M points to
       static memory which is guaranteed to be non-NULL" */
    InverseDynamicsControl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    InverseDynamicsControl_M->Timing.sampleTimes =
      (&InverseDynamicsControl_M->Timing.sampleTimesArray[0]);
    InverseDynamicsControl_M->Timing.offsetTimes =
      (&InverseDynamicsControl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    InverseDynamicsControl_M->Timing.sampleTimes[0] = (0.0);
    InverseDynamicsControl_M->Timing.sampleTimes[1] = (0.002);
    InverseDynamicsControl_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    InverseDynamicsControl_M->Timing.offsetTimes[0] = (0.0);
    InverseDynamicsControl_M->Timing.offsetTimes[1] = (0.0);
    InverseDynamicsControl_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(InverseDynamicsControl_M, &InverseDynamicsControl_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = InverseDynamicsControl_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      InverseDynamicsControl_M->Timing.perTaskSampleHitsArray;
    InverseDynamicsControl_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits
      [0]);
    mdlSampleHits[0] = 1;
    InverseDynamicsControl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(InverseDynamicsControl_M, 5.5);
  InverseDynamicsControl_M->Timing.stepSize0 = 0.002;
  InverseDynamicsControl_M->Timing.stepSize1 = 0.002;
  InverseDynamicsControl_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  InverseDynamicsControl_M->Sizes.checksums[0] = (2684942465U);
  InverseDynamicsControl_M->Sizes.checksums[1] = (1769496732U);
  InverseDynamicsControl_M->Sizes.checksums[2] = (2519266669U);
  InverseDynamicsControl_M->Sizes.checksums[3] = (1094552739U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    InverseDynamicsControl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(InverseDynamicsControl_M->extModeInfo,
      &InverseDynamicsControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(InverseDynamicsControl_M->extModeInfo,
                        InverseDynamicsControl_M->Sizes.checksums);
    rteiSetTPtr(InverseDynamicsControl_M->extModeInfo, rtmGetTPtr
                (InverseDynamicsControl_M));
  }

  InverseDynamicsControl_M->solverInfoPtr =
    (&InverseDynamicsControl_M->solverInfo);
  InverseDynamicsControl_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&InverseDynamicsControl_M->solverInfo, 0.002);
  rtsiSetSolverMode(&InverseDynamicsControl_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  InverseDynamicsControl_M->blockIO = ((void *) &InverseDynamicsControl_B);

  {
    InverseDynamicsControl_B.Speed = 0.0;
    InverseDynamicsControl_B.phi[0] = 0.0;
    InverseDynamicsControl_B.phi[1] = 0.0;
    InverseDynamicsControl_B.Sum[0] = 0.0;
    InverseDynamicsControl_B.Sum[1] = 0.0;
    InverseDynamicsControl_B.FilterCoefficient[0] = 0.0;
    InverseDynamicsControl_B.FilterCoefficient[1] = 0.0;
    InverseDynamicsControl_B.Derivative2[0] = 0.0;
    InverseDynamicsControl_B.Derivative2[1] = 0.0;
    InverseDynamicsControl_B.phidot[0] = 0.0;
    InverseDynamicsControl_B.phidot[1] = 0.0;
    InverseDynamicsControl_B.Current[0] = 0.0;
    InverseDynamicsControl_B.Current[1] = 0.0;
    InverseDynamicsControl_B.RateTransition[0] = 0.0;
    InverseDynamicsControl_B.RateTransition[1] = 0.0;
    InverseDynamicsControl_B.x[0] = 0.0;
    InverseDynamicsControl_B.x[1] = 0.0;
    InverseDynamicsControl_B.y[0] = 0.0;
    InverseDynamicsControl_B.y[1] = 0.0;
    InverseDynamicsControl_B.phi_c[0] = 0.0;
    InverseDynamicsControl_B.phi_c[1] = 0.0;
    InverseDynamicsControl_B.x_n[0] = 0.0;
    InverseDynamicsControl_B.x_n[1] = 0.0;
  }

  /* parameters */
  InverseDynamicsControl_M->defaultParam = ((real_T *)&InverseDynamicsControl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &InverseDynamicsControl_X;
    InverseDynamicsControl_M->contStates = (x);
    (void) memset((void *)&InverseDynamicsControl_X, 0,
                  sizeof(X_InverseDynamicsControl_T));
  }

  /* states (dwork) */
  InverseDynamicsControl_M->dwork = ((void *) &InverseDynamicsControl_DW);
  (void) memset((void *)&InverseDynamicsControl_DW, 0,
                sizeof(DW_InverseDynamicsControl_T));
  InverseDynamicsControl_DW.TimeStampA = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeA[0] = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeA[1] = 0.0;
  InverseDynamicsControl_DW.TimeStampB = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeB[0] = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeB[1] = 0.0;
  InverseDynamicsControl_DW.TimeStampA_p = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeA_j[0] = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeA_j[1] = 0.0;
  InverseDynamicsControl_DW.TimeStampB_c = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeB_m[0] = 0.0;
  InverseDynamicsControl_DW.LastUAtTimeB_m[1] = 0.0;
  InverseDynamicsControl_DW.RateTransition_Buffer[0] = 0.0;
  InverseDynamicsControl_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    InverseDynamicsControl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  InverseDynamicsControl_M->Sizes.numContStates = (6);/* Number of continuous states */
  InverseDynamicsControl_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  InverseDynamicsControl_M->Sizes.numY = (0);/* Number of model outputs */
  InverseDynamicsControl_M->Sizes.numU = (0);/* Number of model inputs */
  InverseDynamicsControl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  InverseDynamicsControl_M->Sizes.numSampTimes = (3);/* Number of sample times */
  InverseDynamicsControl_M->Sizes.numBlocks = (39);/* Number of blocks */
  InverseDynamicsControl_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  InverseDynamicsControl_M->Sizes.numBlockPrms = (14);/* Sum of parameter "widths" */
  return InverseDynamicsControl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
