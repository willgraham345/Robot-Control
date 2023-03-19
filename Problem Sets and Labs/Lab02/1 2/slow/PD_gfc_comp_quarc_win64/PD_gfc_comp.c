/*
 * PD_gfc_comp.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PD_gfc_comp".
 *
 * Model version              : 8.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 16 12:07:21 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PD_gfc_comp.h"
#include "PD_gfc_comp_private.h"
#include "PD_gfc_comp_dt.h"

/* Block signals (default storage) */
B_PD_gfc_comp_T PD_gfc_comp_B;

/* Continuous states */
X_PD_gfc_comp_T PD_gfc_comp_X;

/* Block states (default storage) */
DW_PD_gfc_comp_T PD_gfc_comp_DW;

/* Real-time model */
static RT_MODEL_PD_gfc_comp_T PD_gfc_comp_M_;
RT_MODEL_PD_gfc_comp_T *const PD_gfc_comp_M = &PD_gfc_comp_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(PD_gfc_comp_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(PD_gfc_comp_M, 2);
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
  if (PD_gfc_comp_M->Timing.TaskCounters.TID[1] == 0) {
    PD_gfc_comp_M->Timing.RateInteraction.TID1_2 =
      (PD_gfc_comp_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    PD_gfc_comp_M->Timing.perTaskSampleHits[5] =
      PD_gfc_comp_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PD_gfc_comp_M->Timing.TaskCounters.TID[2])++;
  if ((PD_gfc_comp_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    PD_gfc_comp_M->Timing.TaskCounters.TID[2] = 0;
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
  PD_gfc_comp_derivatives();
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
void PD_gfc_comp_output0(void)         /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog[2];
  real_T (*lastU)[2];
  real_T Current_tmp;
  real_T h;
  real_T rtb_Derivative_idx_0;
  real_T rtb_Derivative_idx_0_0;
  real_T rtb_Derivative_idx_0_1;
  real_T rtb_Derivative_idx_1;
  real_T rtb_Derivative_idx_1_0;
  real_T theta_idx_0;
  if (rtmIsMajorTimeStep(PD_gfc_comp_M)) {
    /* set solver stop time */
    if (!(PD_gfc_comp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PD_gfc_comp_M->solverInfo,
                            ((PD_gfc_comp_M->Timing.clockTickH0 + 1) *
        PD_gfc_comp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PD_gfc_comp_M->solverInfo,
                            ((PD_gfc_comp_M->Timing.clockTick0 + 1) *
        PD_gfc_comp_M->Timing.stepSize0 + PD_gfc_comp_M->Timing.clockTickH0 *
        PD_gfc_comp_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PD_gfc_comp_M)) {
    PD_gfc_comp_M->Timing.t[0] = rtsiGetT(&PD_gfc_comp_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(PD_gfc_comp_M)) {
    /* S-Function (hil_read_encoder_block): '<S5>/HIL Read Encoder' */

    /* S-Function Block: PD_gfc_comp/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILReadEncoder_channels, 2,
        &PD_gfc_comp_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = PD_gfc_comp_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = PD_gfc_comp_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S5>/Encoder Gain' incorporates:
     *  Constant: '<S5>/Home Position'
     *  Sum: '<S5>/Sum1'
     */
    PD_gfc_comp_B.EncoderGain[0] = (PD_gfc_comp_P.HomePosition_Value[0] +
      rtb_HILReadAnalog[0]) * PD_gfc_comp_P.EncoderGain_Gain[0];
    PD_gfc_comp_B.EncoderGain[1] = (PD_gfc_comp_P.HomePosition_Value[1] +
      rtb_HILReadAnalog[1]) * PD_gfc_comp_P.EncoderGain_Gain[1];
  }

  /* Derivative: '<S5>/Derivative' incorporates:
   *  Clock: '<Root>/Clock'
   *  Gain: '<S5>/Encoder Gain'
   */
  h = PD_gfc_comp_M->Timing.t[0];
  if ((PD_gfc_comp_DW.TimeStampA >= h) && (PD_gfc_comp_DW.TimeStampB >= h)) {
    rtb_Derivative_idx_0 = 0.0;
    rtb_Derivative_idx_1 = 0.0;
  } else {
    theta_idx_0 = PD_gfc_comp_DW.TimeStampA;
    lastU = &PD_gfc_comp_DW.LastUAtTimeA;
    if (PD_gfc_comp_DW.TimeStampA < PD_gfc_comp_DW.TimeStampB) {
      if (PD_gfc_comp_DW.TimeStampB < h) {
        theta_idx_0 = PD_gfc_comp_DW.TimeStampB;
        lastU = &PD_gfc_comp_DW.LastUAtTimeB;
      }
    } else if (PD_gfc_comp_DW.TimeStampA >= h) {
      theta_idx_0 = PD_gfc_comp_DW.TimeStampB;
      lastU = &PD_gfc_comp_DW.LastUAtTimeB;
    }

    theta_idx_0 = h - theta_idx_0;
    rtb_Derivative_idx_0 = (PD_gfc_comp_B.EncoderGain[0] - (*lastU)[0]) /
      theta_idx_0;
    rtb_Derivative_idx_1 = (PD_gfc_comp_B.EncoderGain[1] - (*lastU)[1]) /
      theta_idx_0;
  }

  /* End of Derivative: '<S5>/Derivative' */

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Constant: '<Root>/Speed'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S6>:1' */
  if (h < 1.0) {
    /* '<S6>:1:6' */
    /* '<S6>:1:7' */
    h = (1.0 - cos(3.1415926535897931 * h)) * 0.025;
    PD_gfc_comp_B.x[0] = h + 0.15;

    /* '<S6>:1:8' */
    PD_gfc_comp_B.x[1] = 0.15 - h;
  } else if (h < 1.5) {
    /* '<S6>:1:9' */
    /* '<S6>:1:10' */
    h = (h - 1.0) * (h - 1.0) * (6.2831853071795862 * PD_gfc_comp_P.Speed_Value);
    PD_gfc_comp_B.x[0] = cos(h) * 0.075 + 0.125;

    /* '<S6>:1:11' */
    PD_gfc_comp_B.x[1] = sin(h) * 0.075 + 0.1;
  } else {
    /* '<S6>:1:13' */
    h = 6.2831853071795862 * PD_gfc_comp_P.Speed_Value * (h - 1.25);
    PD_gfc_comp_B.x[0] = cos(h) * 0.075 + 0.125;

    /* '<S6>:1:14' */
    PD_gfc_comp_B.x[1] = sin(h) * 0.075 + 0.1;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* MATLAB Function: '<Root>/Inverse Kinematics' */
  /* MATLAB Function 'Inverse Kinematics': '<S3>:1' */
  /* '<S3>:1:10' */
  /* '<S3>:1:4' */
  /* '<S3>:1:5' */
  /* '<S3>:1:8' */
  h = PD_gfc_comp_B.x[0] * PD_gfc_comp_B.x[0] + PD_gfc_comp_B.x[1] *
    PD_gfc_comp_B.x[1];
  h = atan(sqrt((0.09 - h) / h)) * -2.0;

  /* '<S3>:1:9' */
  theta_idx_0 = rt_atan2d_snf(PD_gfc_comp_B.x[1], PD_gfc_comp_B.x[0]) -
    rt_atan2d_snf(0.15 * sin(h), 0.15 * cos(h) + 0.15);

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S5>/Encoder Gain'
   *  MATLAB Function: '<Root>/Inverse Kinematics'
   */
  /* '<S3>:1:10' */
  PD_gfc_comp_B.Sum[0] = (0.0 * h + theta_idx_0) - PD_gfc_comp_B.EncoderGain[0];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S34>/SumD'
   */
  PD_gfc_comp_B.FilterCoefficient[0] = (PD_gfc_comp_P.PDController_D *
    PD_gfc_comp_B.Sum[0] - PD_gfc_comp_X.Filter_CSTATE[0]) *
    PD_gfc_comp_P.PDController_N;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S5>/Encoder Gain'
   *  MATLAB Function: '<Root>/Inverse Kinematics'
   */
  PD_gfc_comp_B.Sum[1] = (theta_idx_0 + h) - PD_gfc_comp_B.EncoderGain[1];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S34>/SumD'
   */
  PD_gfc_comp_B.FilterCoefficient[1] = (PD_gfc_comp_P.PDController_D *
    PD_gfc_comp_B.Sum[1] - PD_gfc_comp_X.Filter_CSTATE[1]) *
    PD_gfc_comp_P.PDController_N;

  /* MATLAB Function: '<Root>/Feedback Comp1' incorporates:
   *  Derivative: '<S5>/Derivative'
   *  Gain: '<S5>/Encoder Gain'
   *  MATLAB Function: '<Root>/Forward Kinematics'
   */
  /* MATLAB Function 'Feedback Comp1': '<S1>:1' */
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
  h = sin(PD_gfc_comp_B.EncoderGain[1] - PD_gfc_comp_B.EncoderGain[0]) *
    0.00041579999999999997;

  /* '<S1>:1:23' */
  /* '<S1>:1:24' */
  /* '<S1>:1:25' */
  /* '<S1>:1:26' */
  /* '<S1>:1:28' */
  /* '<S1>:1:29' */
  /* '<S1>:1:30' */
  /* '<S1>:1:32' */
  theta_idx_0 = cos(PD_gfc_comp_B.EncoderGain[0]);
  Current_tmp = cos(PD_gfc_comp_B.EncoderGain[1]);
  rtb_Derivative_idx_0_0 = rtb_Derivative_idx_0 * rtb_Derivative_idx_0;
  rtb_Derivative_idx_1_0 = rtb_Derivative_idx_1 * rtb_Derivative_idx_1;
  if (rtb_Derivative_idx_0 < 0.0) {
    rtb_Derivative_idx_0_1 = -1.0;
  } else if (rtb_Derivative_idx_0 > 0.0) {
    rtb_Derivative_idx_0_1 = 1.0;
  } else if (rtb_Derivative_idx_0 == 0.0) {
    rtb_Derivative_idx_0_1 = 0.0;
  } else {
    rtb_Derivative_idx_0_1 = (rtNaN);
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Derivative: '<S5>/Derivative'
   *  Gain: '<Root>/1//MotorGain '
   *  Gain: '<S42>/Filter Coefficient'
   *  Gain: '<S44>/Proportional Gain'
   *  MATLAB Function: '<Root>/Feedback Comp1'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S48>/Sum'
   */
  PD_gfc_comp_B.Current[0] = (((0.0 * rtb_Derivative_idx_0_0 + -h *
    rtb_Derivative_idx_1_0) + 0.1690892 * theta_idx_0) + (0.01519 *
    rtb_Derivative_idx_0 + 0.007 * rtb_Derivative_idx_0_1)) *
    PD_gfc_comp_P.uMotorGain_Gain + (PD_gfc_comp_P.PDController_P *
    PD_gfc_comp_B.Sum[0] + PD_gfc_comp_B.FilterCoefficient[0]);

  /* Gain: '<S5>/1//AmpGain' incorporates:
   *  Bias: '<S5>/Amp Bias Tune for each  amp//channel if needed'
   *  Sum: '<Root>/Sum1'
   */
  PD_gfc_comp_B.uAmpGain[0] = (PD_gfc_comp_B.Current[0] +
    PD_gfc_comp_P.AmpBiasTuneforeachampchannelifn[0]) *
    PD_gfc_comp_P.uAmpGain_Gain[0];

  /* MATLAB Function: '<Root>/Feedback Comp1' incorporates:
   *  Derivative: '<S5>/Derivative'
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

  /* Sum: '<Root>/Sum1' incorporates:
   *  Derivative: '<S5>/Derivative'
   *  Gain: '<Root>/1//MotorGain '
   *  Gain: '<S42>/Filter Coefficient'
   *  Gain: '<S44>/Proportional Gain'
   *  MATLAB Function: '<Root>/Feedback Comp1'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S48>/Sum'
   */
  PD_gfc_comp_B.Current[1] = (((h * rtb_Derivative_idx_0_0 + 0.0 *
    rtb_Derivative_idx_1_0) + 0.027165599999999998 * Current_tmp) + (0.01519 *
    rtb_Derivative_idx_1 + 0.007 * rtb_Derivative_idx_0)) *
    PD_gfc_comp_P.uMotorGain_Gain + (PD_gfc_comp_P.PDController_P *
    PD_gfc_comp_B.Sum[1] + PD_gfc_comp_B.FilterCoefficient[1]);

  /* Gain: '<S5>/1//AmpGain' incorporates:
   *  Bias: '<S5>/Amp Bias Tune for each  amp//channel if needed'
   *  Sum: '<Root>/Sum1'
   */
  PD_gfc_comp_B.uAmpGain[1] = (PD_gfc_comp_B.Current[1] +
    PD_gfc_comp_P.AmpBiasTuneforeachampchannelifn[1]) *
    PD_gfc_comp_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(PD_gfc_comp_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: PD_gfc_comp/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILWriteAnalog_channels, 2, &PD_gfc_comp_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S5>/HIL Read Analog' */

    /* S-Function Block: PD_gfc_comp/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILReadAnalog_channels, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
      }
    }

    /* Bias: '<S5>/Current Sense Bias Tune for each amp//channel if needed' incorporates:
     *  Gain: '<S5>/1//Sense Gain'
     */
    PD_gfc_comp_B.CurrentSenseBiasTuneforeachampc[0] =
      PD_gfc_comp_P.uSenseGain_Gain * rtb_HILReadAnalog[0] +
      PD_gfc_comp_P.CurrentSenseBiasTuneforeachampc[0];
    PD_gfc_comp_B.CurrentSenseBiasTuneforeachampc[1] =
      PD_gfc_comp_P.uSenseGain_Gain * rtb_HILReadAnalog[1] +
      PD_gfc_comp_P.CurrentSenseBiasTuneforeachampc[1];

    /* MATLAB Function: '<Root>/Forward Kinematics' incorporates:
     *  Gain: '<S5>/Encoder Gain'
     */
    /* MATLAB Function 'Forward Kinematics': '<S2>:1' */
    /* '<S2>:1:4' */
    /* '<S2>:1:5' */
    /* '<S2>:1:7' */
    PD_gfc_comp_B.x_b[0] = 0.15 * theta_idx_0 + 0.15 * Current_tmp;

    /* '<S2>:1:8' */
    PD_gfc_comp_B.x_b[1] = 0.15 * sin(PD_gfc_comp_B.EncoderGain[0]) + 0.15 * sin
      (PD_gfc_comp_B.EncoderGain[1]);

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S5>/Encoder Gain'
     */
    if (PD_gfc_comp_M->Timing.RateInteraction.TID1_2) {
      PD_gfc_comp_DW.RateTransition_Buffer[0] = PD_gfc_comp_B.EncoderGain[0];
      PD_gfc_comp_DW.RateTransition_Buffer[1] = PD_gfc_comp_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void PD_gfc_comp_update0(void)         /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<S5>/Derivative' incorporates:
   *  Gain: '<S5>/Encoder Gain'
   */
  if (PD_gfc_comp_DW.TimeStampA == (rtInf)) {
    PD_gfc_comp_DW.TimeStampA = PD_gfc_comp_M->Timing.t[0];
    lastU = &PD_gfc_comp_DW.LastUAtTimeA;
  } else if (PD_gfc_comp_DW.TimeStampB == (rtInf)) {
    PD_gfc_comp_DW.TimeStampB = PD_gfc_comp_M->Timing.t[0];
    lastU = &PD_gfc_comp_DW.LastUAtTimeB;
  } else if (PD_gfc_comp_DW.TimeStampA < PD_gfc_comp_DW.TimeStampB) {
    PD_gfc_comp_DW.TimeStampA = PD_gfc_comp_M->Timing.t[0];
    lastU = &PD_gfc_comp_DW.LastUAtTimeA;
  } else {
    PD_gfc_comp_DW.TimeStampB = PD_gfc_comp_M->Timing.t[0];
    lastU = &PD_gfc_comp_DW.LastUAtTimeB;
  }

  (*lastU)[0] = PD_gfc_comp_B.EncoderGain[0];
  (*lastU)[1] = PD_gfc_comp_B.EncoderGain[1];

  /* End of Update for Derivative: '<S5>/Derivative' */
  if (rtmIsMajorTimeStep(PD_gfc_comp_M)) {
    rt_ertODEUpdateContinuousStates(&PD_gfc_comp_M->solverInfo);
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
  if (!(++PD_gfc_comp_M->Timing.clockTick0)) {
    ++PD_gfc_comp_M->Timing.clockTickH0;
  }

  PD_gfc_comp_M->Timing.t[0] = rtsiGetSolverStopTime(&PD_gfc_comp_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PD_gfc_comp_M->Timing.clockTick1)) {
    ++PD_gfc_comp_M->Timing.clockTickH1;
  }

  PD_gfc_comp_M->Timing.t[1] = PD_gfc_comp_M->Timing.clockTick1 *
    PD_gfc_comp_M->Timing.stepSize1 + PD_gfc_comp_M->Timing.clockTickH1 *
    PD_gfc_comp_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void PD_gfc_comp_derivatives(void)
{
  XDot_PD_gfc_comp_T *_rtXdot;
  _rtXdot = ((XDot_PD_gfc_comp_T *) PD_gfc_comp_M->derivs);

  /* Derivatives for Integrator: '<S34>/Filter' incorporates:
   *  Gain: '<S42>/Filter Coefficient'
   */
  _rtXdot->Filter_CSTATE[0] = PD_gfc_comp_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = PD_gfc_comp_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void PD_gfc_comp_output2(void)         /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  PD_gfc_comp_B.RateTransition[0] = PD_gfc_comp_DW.RateTransition_Buffer[0];
  PD_gfc_comp_B.RateTransition[1] = PD_gfc_comp_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void PD_gfc_comp_update2(void)         /* Sample time: [0.02s, 0.0s] */
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
  if (!(++PD_gfc_comp_M->Timing.clockTick2)) {
    ++PD_gfc_comp_M->Timing.clockTickH2;
  }

  PD_gfc_comp_M->Timing.t[2] = PD_gfc_comp_M->Timing.clockTick2 *
    PD_gfc_comp_M->Timing.stepSize2 + PD_gfc_comp_M->Timing.clockTickH2 *
    PD_gfc_comp_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PD_gfc_comp_output(int_T tid)
{
  switch (tid) {
   case 0 :
    PD_gfc_comp_output0();
    break;

   case 2 :
    PD_gfc_comp_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PD_gfc_comp_update(int_T tid)
{
  switch (tid) {
   case 0 :
    PD_gfc_comp_update0();
    break;

   case 2 :
    PD_gfc_comp_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void PD_gfc_comp_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: PD_gfc_comp/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &PD_gfc_comp_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(PD_gfc_comp_DW.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(PD_gfc_comp_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
      return;
    }

    if ((PD_gfc_comp_P.HILInitialize_AIPStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &PD_gfc_comp_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (PD_gfc_comp_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &PD_gfc_comp_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = PD_gfc_comp_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_AIChannels, 8U,
        &PD_gfc_comp_DW.HILInitialize_AIMinimums[0],
        &PD_gfc_comp_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if ((PD_gfc_comp_P.HILInitialize_AOPStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &PD_gfc_comp_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (PD_gfc_comp_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &PD_gfc_comp_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = PD_gfc_comp_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_AOChannels, 8U,
        &PD_gfc_comp_DW.HILInitialize_AOMinimums[0],
        &PD_gfc_comp_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if ((PD_gfc_comp_P.HILInitialize_AOStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PD_gfc_comp_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PD_gfc_comp_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_AOChannels, 8U,
        &PD_gfc_comp_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if (PD_gfc_comp_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PD_gfc_comp_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PD_gfc_comp_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (PD_gfc_comp_DW.HILInitialize_Card,
         PD_gfc_comp_P.HILInitialize_AOChannels, 8U,
         &PD_gfc_comp_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if ((PD_gfc_comp_P.HILInitialize_EIPStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &PD_gfc_comp_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = PD_gfc_comp_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &PD_gfc_comp_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if ((PD_gfc_comp_P.HILInitialize_EIStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &PD_gfc_comp_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = PD_gfc_comp_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_EIChannels, 8U,
        &PD_gfc_comp_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if ((PD_gfc_comp_P.HILInitialize_POPStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &PD_gfc_comp_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PD_gfc_comp_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &PD_gfc_comp_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          PD_gfc_comp_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &PD_gfc_comp_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            PD_gfc_comp_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            PD_gfc_comp_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              PD_gfc_comp_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            PD_gfc_comp_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = (p_HILInitialize_POChannels[i1]);
            PD_gfc_comp_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = PD_gfc_comp_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(PD_gfc_comp_DW.HILInitialize_Card,
          &PD_gfc_comp_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &PD_gfc_comp_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(PD_gfc_comp_DW.HILInitialize_Card,
          &PD_gfc_comp_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &PD_gfc_comp_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &PD_gfc_comp_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PD_gfc_comp_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &PD_gfc_comp_DW.HILInitialize_POAlignValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = PD_gfc_comp_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &PD_gfc_comp_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = PD_gfc_comp_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &PD_gfc_comp_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &PD_gfc_comp_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &PD_gfc_comp_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &PD_gfc_comp_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = PD_gfc_comp_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &PD_gfc_comp_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_gfc_comp_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_POChannels, 8U,
        &PD_gfc_comp_DW.HILInitialize_POSortedFreqs[0],
        &PD_gfc_comp_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if ((PD_gfc_comp_P.HILInitialize_POStart && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PD_gfc_comp_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_gfc_comp_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(PD_gfc_comp_DW.HILInitialize_Card,
        PD_gfc_comp_P.HILInitialize_POChannels, 8U,
        &PD_gfc_comp_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }

    if (PD_gfc_comp_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &PD_gfc_comp_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_gfc_comp_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (PD_gfc_comp_DW.HILInitialize_Card,
         PD_gfc_comp_P.HILInitialize_POChannels, 8U,
         &PD_gfc_comp_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  PD_gfc_comp_DW.TimeStampA = (rtInf);
  PD_gfc_comp_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  PD_gfc_comp_X.Filter_CSTATE[0] = PD_gfc_comp_P.PDController_InitialConditionFo;
  PD_gfc_comp_X.Filter_CSTATE[1] = PD_gfc_comp_P.PDController_InitialConditionFo;
}

/* Model terminate function */
void PD_gfc_comp_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: PD_gfc_comp/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(PD_gfc_comp_DW.HILInitialize_Card);
    hil_monitor_stop_all(PD_gfc_comp_DW.HILInitialize_Card);
    is_switching = false;
    if ((PD_gfc_comp_P.HILInitialize_AOTerminate && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PD_gfc_comp_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PD_gfc_comp_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((PD_gfc_comp_P.HILInitialize_POTerminate && !is_switching) ||
        (PD_gfc_comp_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PD_gfc_comp_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PD_gfc_comp_P.HILInitialize_POFinal;
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
      result = hil_write(PD_gfc_comp_DW.HILInitialize_Card
                         , PD_gfc_comp_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , PD_gfc_comp_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &PD_gfc_comp_DW.HILInitialize_AOVoltages[0]
                         , &PD_gfc_comp_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(PD_gfc_comp_DW.HILInitialize_Card,
            PD_gfc_comp_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &PD_gfc_comp_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(PD_gfc_comp_DW.HILInitialize_Card,
            PD_gfc_comp_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &PD_gfc_comp_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PD_gfc_comp_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(PD_gfc_comp_DW.HILInitialize_Card);
    hil_monitor_delete_all(PD_gfc_comp_DW.HILInitialize_Card);
    hil_close(PD_gfc_comp_DW.HILInitialize_Card);
    PD_gfc_comp_DW.HILInitialize_Card = NULL;
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
  PD_gfc_comp_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  PD_gfc_comp_update(tid);
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
  PD_gfc_comp_initialize();
}

void MdlTerminate(void)
{
  PD_gfc_comp_terminate();
}

/* Registration function */
RT_MODEL_PD_gfc_comp_T *PD_gfc_comp(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PD_gfc_comp_M, 0,
                sizeof(RT_MODEL_PD_gfc_comp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PD_gfc_comp_M->solverInfo,
                          &PD_gfc_comp_M->Timing.simTimeStep);
    rtsiSetTPtr(&PD_gfc_comp_M->solverInfo, &rtmGetTPtr(PD_gfc_comp_M));
    rtsiSetStepSizePtr(&PD_gfc_comp_M->solverInfo,
                       &PD_gfc_comp_M->Timing.stepSize0);
    rtsiSetdXPtr(&PD_gfc_comp_M->solverInfo, &PD_gfc_comp_M->derivs);
    rtsiSetContStatesPtr(&PD_gfc_comp_M->solverInfo, (real_T **)
                         &PD_gfc_comp_M->contStates);
    rtsiSetNumContStatesPtr(&PD_gfc_comp_M->solverInfo,
      &PD_gfc_comp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PD_gfc_comp_M->solverInfo,
      &PD_gfc_comp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PD_gfc_comp_M->solverInfo,
      &PD_gfc_comp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PD_gfc_comp_M->solverInfo,
      &PD_gfc_comp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PD_gfc_comp_M->solverInfo, (&rtmGetErrorStatus
      (PD_gfc_comp_M)));
    rtsiSetRTModelPtr(&PD_gfc_comp_M->solverInfo, PD_gfc_comp_M);
  }

  rtsiSetSimTimeStep(&PD_gfc_comp_M->solverInfo, MAJOR_TIME_STEP);
  PD_gfc_comp_M->intgData.f[0] = PD_gfc_comp_M->odeF[0];
  PD_gfc_comp_M->contStates = ((real_T *) &PD_gfc_comp_X);
  rtsiSetSolverData(&PD_gfc_comp_M->solverInfo, (void *)&PD_gfc_comp_M->intgData);
  rtsiSetSolverName(&PD_gfc_comp_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PD_gfc_comp_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "PD_gfc_comp_M points to
       static memory which is guaranteed to be non-NULL" */
    PD_gfc_comp_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PD_gfc_comp_M->Timing.sampleTimes = (&PD_gfc_comp_M->
      Timing.sampleTimesArray[0]);
    PD_gfc_comp_M->Timing.offsetTimes = (&PD_gfc_comp_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    PD_gfc_comp_M->Timing.sampleTimes[0] = (0.0);
    PD_gfc_comp_M->Timing.sampleTimes[1] = (0.001);
    PD_gfc_comp_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    PD_gfc_comp_M->Timing.offsetTimes[0] = (0.0);
    PD_gfc_comp_M->Timing.offsetTimes[1] = (0.0);
    PD_gfc_comp_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(PD_gfc_comp_M, &PD_gfc_comp_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PD_gfc_comp_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = PD_gfc_comp_M->Timing.perTaskSampleHitsArray;
    PD_gfc_comp_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    PD_gfc_comp_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PD_gfc_comp_M, 10.0);
  PD_gfc_comp_M->Timing.stepSize0 = 0.001;
  PD_gfc_comp_M->Timing.stepSize1 = 0.001;
  PD_gfc_comp_M->Timing.stepSize2 = 0.02;

  /* External mode info */
  PD_gfc_comp_M->Sizes.checksums[0] = (334636997U);
  PD_gfc_comp_M->Sizes.checksums[1] = (338275746U);
  PD_gfc_comp_M->Sizes.checksums[2] = (4048283786U);
  PD_gfc_comp_M->Sizes.checksums[3] = (714736065U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    PD_gfc_comp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PD_gfc_comp_M->extModeInfo,
      &PD_gfc_comp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PD_gfc_comp_M->extModeInfo,
                        PD_gfc_comp_M->Sizes.checksums);
    rteiSetTPtr(PD_gfc_comp_M->extModeInfo, rtmGetTPtr(PD_gfc_comp_M));
  }

  PD_gfc_comp_M->solverInfoPtr = (&PD_gfc_comp_M->solverInfo);
  PD_gfc_comp_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PD_gfc_comp_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PD_gfc_comp_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  PD_gfc_comp_M->blockIO = ((void *) &PD_gfc_comp_B);

  {
    PD_gfc_comp_B.EncoderGain[0] = 0.0;
    PD_gfc_comp_B.EncoderGain[1] = 0.0;
    PD_gfc_comp_B.Sum[0] = 0.0;
    PD_gfc_comp_B.Sum[1] = 0.0;
    PD_gfc_comp_B.FilterCoefficient[0] = 0.0;
    PD_gfc_comp_B.FilterCoefficient[1] = 0.0;
    PD_gfc_comp_B.Current[0] = 0.0;
    PD_gfc_comp_B.Current[1] = 0.0;
    PD_gfc_comp_B.uAmpGain[0] = 0.0;
    PD_gfc_comp_B.uAmpGain[1] = 0.0;
    PD_gfc_comp_B.CurrentSenseBiasTuneforeachampc[0] = 0.0;
    PD_gfc_comp_B.CurrentSenseBiasTuneforeachampc[1] = 0.0;
    PD_gfc_comp_B.RateTransition[0] = 0.0;
    PD_gfc_comp_B.RateTransition[1] = 0.0;
    PD_gfc_comp_B.x[0] = 0.0;
    PD_gfc_comp_B.x[1] = 0.0;
    PD_gfc_comp_B.x_b[0] = 0.0;
    PD_gfc_comp_B.x_b[1] = 0.0;
  }

  /* parameters */
  PD_gfc_comp_M->defaultParam = ((real_T *)&PD_gfc_comp_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PD_gfc_comp_X;
    PD_gfc_comp_M->contStates = (x);
    (void) memset((void *)&PD_gfc_comp_X, 0,
                  sizeof(X_PD_gfc_comp_T));
  }

  /* states (dwork) */
  PD_gfc_comp_M->dwork = ((void *) &PD_gfc_comp_DW);
  (void) memset((void *)&PD_gfc_comp_DW, 0,
                sizeof(DW_PD_gfc_comp_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      PD_gfc_comp_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  PD_gfc_comp_DW.TimeStampA = 0.0;
  PD_gfc_comp_DW.LastUAtTimeA[0] = 0.0;
  PD_gfc_comp_DW.LastUAtTimeA[1] = 0.0;
  PD_gfc_comp_DW.TimeStampB = 0.0;
  PD_gfc_comp_DW.LastUAtTimeB[0] = 0.0;
  PD_gfc_comp_DW.LastUAtTimeB[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      PD_gfc_comp_DW.XYSuperimposed_XBuffer[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20000; i++) {
      PD_gfc_comp_DW.XYSuperimposed_YBuffer[i] = 0.0;
    }
  }

  PD_gfc_comp_DW.RateTransition_Buffer[0] = 0.0;
  PD_gfc_comp_DW.RateTransition_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PD_gfc_comp_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PD_gfc_comp_M->Sizes.numContStates = (2);/* Number of continuous states */
  PD_gfc_comp_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PD_gfc_comp_M->Sizes.numY = (0);     /* Number of model outputs */
  PD_gfc_comp_M->Sizes.numU = (0);     /* Number of model inputs */
  PD_gfc_comp_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PD_gfc_comp_M->Sizes.numSampTimes = (3);/* Number of sample times */
  PD_gfc_comp_M->Sizes.numBlocks = (40);/* Number of blocks */
  PD_gfc_comp_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  PD_gfc_comp_M->Sizes.numBlockPrms = (126);/* Sum of parameter "widths" */
  return PD_gfc_comp_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
