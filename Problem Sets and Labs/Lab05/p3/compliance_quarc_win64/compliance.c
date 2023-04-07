/*
 * compliance.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "compliance".
 *
 * Model version              : 8.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Apr  6 13:54:48 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "compliance.h"
#include "compliance_private.h"
#include "compliance_dt.h"

/* Block signals (default storage) */
B_compliance_T compliance_B;

/* Continuous states */
X_compliance_T compliance_X;

/* Block states (default storage) */
DW_compliance_T compliance_DW;

/* Real-time model */
static RT_MODEL_compliance_T compliance_M_;
RT_MODEL_compliance_T *const compliance_M = &compliance_M_;

/* Forward declaration for local functions */
static void compliance_inv(const real_T x[4], real_T y[4]);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(compliance_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(compliance_M, 2);
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
  if (compliance_M->Timing.TaskCounters.TID[1] == 0) {
    compliance_M->Timing.RateInteraction.TID1_2 =
      (compliance_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    compliance_M->Timing.perTaskSampleHits[5] =
      compliance_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (compliance_M->Timing.TaskCounters.TID[2])++;
  if ((compliance_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.02s, 0.0s] */
    compliance_M->Timing.TaskCounters.TID[2] = 0;
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
  compliance_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for atomic system:
 *    '<S57>/Bias Removal'
 *    '<S57>/Bias Removal1'
 */
void compliance_BiasRemoval_Init(B_BiasRemoval_compliance_T *localB,
  DW_BiasRemoval_compliance_T *localDW, P_BiasRemoval_compliance_T *localP)
{
  /* SystemInitialize for Enabled SubSystem: '<S61>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S65>/Sum( k=1,n-1, x(k) )' */
  localDW->Sumk1n1xk_DSTATE = localP->Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Product: '<S65>/div' incorporates:
   *  Outport: '<S65>/x_avg_n'
   */
  localB->div = localP->x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S61>/Enabled Moving Average' */

  /* SystemInitialize for IfAction SubSystem: '<S61>/Switch Case Action Subsystem' */
  /* SystemInitialize for Outport: '<S66>/zero' incorporates:
   *  Constant: '<S66>/Constant'
   */
  localB->Constant = localP->zero_Y0;

  /* End of SystemInitialize for SubSystem: '<S61>/Switch Case Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S61>/Switch Case Action Subsystem1' */
  /* SystemInitialize for Outport: '<S67>/Vbiased' incorporates:
   *  Inport: '<S67>/Vin'
   */
  localB->Vin = localP->Vbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S61>/Switch Case Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S61>/Switch Case Action Subsystem2' */
  /* SystemInitialize for Outport: '<S68>/Vunbiased' incorporates:
   *  Inport: '<S68>/V-Vavg'
   */
  localB->VVavg = localP->Vunbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S61>/Switch Case Action Subsystem2' */
}

/*
 * Start for atomic system:
 *    '<S57>/Bias Removal'
 *    '<S57>/Bias Removal1'
 */
void complianc_BiasRemoval_Start(DW_BiasRemoval_compliance_T *localDW)
{
  /* Start for Enabled SubSystem: '<S61>/Enabled Moving Average' */
  localDW->EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S61>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S61>/Switch Case' */
  localDW->SwitchCase_ActiveSubsystem = -1;
}

/*
 * Outputs for atomic system:
 *    '<S57>/Bias Removal'
 *    '<S57>/Bias Removal1'
 */
void compliance_BiasRemoval(RT_MODEL_compliance_T * const compliance_M, real_T
  rtu_V, real_T rtp_switch_id, real_T rtp_start_time, real_T rtp_end_time,
  B_BiasRemoval_compliance_T *localB, DW_BiasRemoval_compliance_T *localDW,
  P_BiasRemoval_compliance_T *localP)
{
  real_T rtb_Stepend_time;
  real_T rtb_Sum_c;
  real_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Step: '<S61>/Step: end_time' incorporates:
   *  Step: '<S61>/Step: start_time'
   */
  tmp = compliance_M->Timing.t[1];
  if (tmp < rtp_end_time) {
    rtb_Stepend_time = localP->Stepend_time_Y0;
  } else {
    rtb_Stepend_time = localP->Stepend_time_YFinal;
  }

  /* End of Step: '<S61>/Step: end_time' */

  /* Step: '<S61>/Step: start_time' */
  if (tmp < rtp_start_time) {
    tmp = localP->Stepstart_time_Y0;
  } else {
    tmp = localP->Stepstart_time_YFinal;
  }

  /* Outputs for Enabled SubSystem: '<S61>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  /* Logic: '<S61>/Logical Operator' incorporates:
   *  Logic: '<S61>/Logical Operator1'
   */
  if ((tmp != 0.0) && (!(rtb_Stepend_time != 0.0))) {
    if (!localDW->EnabledMovingAverage_MODE) {
      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
      localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S65>/Sum( k=1,n-1, x(k) )' */
      localDW->Sumk1n1xk_DSTATE = localP->Sumk1n1xk_InitialCondition;
      localDW->EnabledMovingAverage_MODE = true;
    }

    /* Sum: '<S69>/Count' incorporates:
     *  Constant: '<S69>/unity'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    localB->Count = localP->unity_Value + localDW->UnitDelay_DSTATE;

    /* Sum: '<S65>/Sum' incorporates:
     *  UnitDelay: '<S65>/Sum( k=1,n-1, x(k) )'
     */
    localB->Sum = rtu_V + localDW->Sumk1n1xk_DSTATE;

    /* Product: '<S65>/div' */
    localB->div = localB->Sum / localB->Count;
    srUpdateBC(localDW->EnabledMovingAverage_SubsysRanB);
  } else {
    localDW->EnabledMovingAverage_MODE = false;
  }

  /* End of Logic: '<S61>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S61>/Enabled Moving Average' */

  /* Sum: '<S61>/Sum' */
  rtb_Sum_c = rtu_V - localB->div;

  /* SwitchCase: '<S61>/Switch Case' incorporates:
   *  Constant: '<S61>/Constant'
   *  Constant: '<S66>/Constant'
   *  Inport: '<S67>/Vin'
   *  Inport: '<S68>/V-Vavg'
   */
  rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
  rtAction = -1;
  if (rtp_switch_id < 0.0) {
    tmp = ceil(rtp_switch_id);
  } else {
    tmp = floor(rtp_switch_id);
  }

  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 1:
    rtAction = 0;
    break;

   case 2:
    rtAction = 1;
    break;

   case 3:
    rtAction = 2;
    break;
  }

  localDW->SwitchCase_ActiveSubsystem = rtAction;
  if (rtPrevAction != rtAction) {
    switch (rtPrevAction) {
     case 0:
      /* Disable for Outport: '<S66>/zero' incorporates:
       *  Constant: '<S66>/Constant'
       * */
      localB->Constant = localP->zero_Y0;
      break;

     case 1:
      /* Disable for Outport: '<S67>/Vbiased' incorporates:
       *  Inport: '<S67>/Vin'
       * */
      localB->Vin = localP->Vbiased_Y0;
      break;

     case 2:
      /* Disable for Outport: '<S68>/Vunbiased' incorporates:
       *  Inport: '<S68>/V-Vavg'
       * */
      localB->VVavg = localP->Vunbiased_Y0;
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S61>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    localB->Constant = localP->Constant_Value;
    srUpdateBC(localDW->SwitchCaseActionSubsystem_Subsy);

    /* End of Outputs for SubSystem: '<S61>/Switch Case Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S61>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    localB->Vin = rtu_V;
    srUpdateBC(localDW->SwitchCaseActionSubsystem1_Subs);

    /* End of Outputs for SubSystem: '<S61>/Switch Case Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S61>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    localB->VVavg = rtb_Sum_c;
    srUpdateBC(localDW->SwitchCaseActionSubsystem2_Subs);

    /* End of Outputs for SubSystem: '<S61>/Switch Case Action Subsystem2' */
    break;
  }

  /* End of SwitchCase: '<S61>/Switch Case' */

  /* Switch: '<S61>/Switch' incorporates:
   *  Logic: '<S61>/Logical Operator2'
   */
  if (!(rtb_Stepend_time != 0.0)) {
    /* Switch: '<S61>/Switch' incorporates:
     *  Sum: '<S61>/Sum1'
     */
    localB->Switch = (localB->Constant + localB->Vin) + localB->VVavg;
  } else {
    /* Switch: '<S61>/Switch' */
    localB->Switch = rtb_Sum_c;
  }

  /* End of Switch: '<S61>/Switch' */
}

/*
 * Update for atomic system:
 *    '<S57>/Bias Removal'
 *    '<S57>/Bias Removal1'
 */
void complian_BiasRemoval_Update(B_BiasRemoval_compliance_T *localB,
  DW_BiasRemoval_compliance_T *localDW)
{
  /* Update for Enabled SubSystem: '<S61>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  if (localDW->EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S69>/Unit Delay' */
    localDW->UnitDelay_DSTATE = localB->Count;

    /* Update for UnitDelay: '<S65>/Sum( k=1,n-1, x(k) )' */
    localDW->Sumk1n1xk_DSTATE = localB->Sum;
  }

  /* End of Update for SubSystem: '<S61>/Enabled Moving Average' */
}

/* Function for MATLAB Function: '<Root>/Hx Matrix' */
static void compliance_inv(const real_T x[4], real_T y[4])
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
void compliance_output0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog_o1;
  real_T rtb_HILReadAnalog_o2;
  real_T rtb_HILReadAnalog[2];
  __m128d tmp_4;
  __m128d tmp_5;
  __m128d tmp_6;
  __m128d tmp_7;
  __m128d tmp_a;
  real_T J[4];
  real_T J_0[4];
  real_T tmp[4];
  real_T tmp_0[4];
  real_T tmp_1[4];
  real_T rtb_Derivative1[2];
  real_T rtb_Derivative1_0[2];
  real_T (*lastU)[2];
  real_T J_tmp;
  real_T h;
  real_T rtb_Clock_0;
  real_T rtb_Derivative_idx_0;
  real_T rtb_Derivative_idx_0_0;
  real_T rtb_Derivative_idx_1;
  real_T rtb_xAdmittance;
  real_T rtb_yAdmittance1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_8;
  real_T tmp_9;
  int32_T J_tmp_0;
  int32_T i;
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* set solver stop time */
    if (!(compliance_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&compliance_M->solverInfo,
                            ((compliance_M->Timing.clockTickH0 + 1) *
        compliance_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&compliance_M->solverInfo,
                            ((compliance_M->Timing.clockTick0 + 1) *
        compliance_M->Timing.stepSize0 + compliance_M->Timing.clockTickH0 *
        compliance_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(compliance_M)) {
    compliance_M->Timing.t[0] = rtsiGetT(&compliance_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(compliance_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(compliance_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(compliance_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(compliance_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* S-Function (hil_read_analog_block): '<S57>/HIL Read Analog' */

    /* S-Function Block: compliance/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(compliance_DW.HILInitialize_Card,
        compliance_P.HILReadAnalog_channels, 2,
        &compliance_DW.HILReadAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
      }

      rtb_HILReadAnalog_o1 = compliance_DW.HILReadAnalog_Buffer[0];
      rtb_HILReadAnalog_o2 = compliance_DW.HILReadAnalog_Buffer[1];
    }

    /* Gain: '<S57>/X Gain (N//V)' */
    compliance_B.XGainNV = compliance_P.XGainNV_Gain * rtb_HILReadAnalog_o1;

    /* Outputs for Atomic SubSystem: '<S57>/Bias Removal' */
    /* Outputs for Atomic SubSystem: '<S57>/Bias Removal' */
    compliance_BiasRemoval(compliance_M, compliance_B.XGainNV,
      compliance_P.BiasRemoval_switch_id, compliance_P.BiasRemoval_start_time,
      compliance_P.BiasRemoval_end_time, &compliance_B.BiasRemoval,
      &compliance_DW.BiasRemoval, &compliance_P.BiasRemoval);

    /* End of Outputs for SubSystem: '<S57>/Bias Removal' */
    /* End of Outputs for SubSystem: '<S57>/Bias Removal' */

    /* Gain: '<S57>/Y Gain (N//V)' */
    compliance_B.YGainNV = compliance_P.YGainNV_Gain * rtb_HILReadAnalog_o2;

    /* Outputs for Atomic SubSystem: '<S57>/Bias Removal1' */
    /* Outputs for Atomic SubSystem: '<S57>/Bias Removal1' */
    compliance_BiasRemoval(compliance_M, compliance_B.YGainNV,
      compliance_P.BiasRemoval1_switch_id, compliance_P.BiasRemoval1_start_time,
      compliance_P.BiasRemoval1_end_time, &compliance_B.BiasRemoval1,
      &compliance_DW.BiasRemoval1, &compliance_P.BiasRemoval1);

    /* End of Outputs for SubSystem: '<S57>/Bias Removal1' */
    /* End of Outputs for SubSystem: '<S57>/Bias Removal1' */

    /* Constant: '<S63>/x0' */
    compliance_B.x0 = compliance_P.x0_Value;
  }

  /* Integrator: '<S63>/Integrator1' */
  if (compliance_DW.Integrator1_IWORK != 0) {
    compliance_X.Integrator1_CSTATE = compliance_B.x0;
  }

  /* Integrator: '<S63>/Integrator1' */
  compliance_B.Integrator1 = compliance_X.Integrator1_CSTATE;

  /* Product: '<S63>/Product' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S63>/wn'
   *  Constant: '<S63>/zt'
   *  Integrator: '<S63>/Integrator2'
   *  Product: '<S63>/Product2'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S63>/Sum1'
   */
  compliance_B.Product = ((compliance_B.BiasRemoval.Switch -
    compliance_B.Integrator1) - compliance_X.Integrator2_CSTATE *
    compliance_P.Constant_Value * compliance_P.SecondOrderLowPassFilter_inpu_o) *
    compliance_P.SecondOrderLowPassFilter_input_;

  /* Product: '<S63>/Product1' incorporates:
   *  Constant: '<S63>/wn'
   *  Integrator: '<S63>/Integrator2'
   */
  compliance_B.Product1 = compliance_P.SecondOrderLowPassFilter_input_ *
    compliance_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* Constant: '<S64>/x0' */
    compliance_B.x0_i = compliance_P.x0_Value_a;
  }

  /* Integrator: '<S64>/Integrator1' */
  if (compliance_DW.Integrator1_IWORK_f != 0) {
    compliance_X.Integrator1_CSTATE_d = compliance_B.x0_i;
  }

  /* Integrator: '<S64>/Integrator1' */
  compliance_B.Integrator1_f = compliance_X.Integrator1_CSTATE_d;

  /* Product: '<S64>/Product' incorporates:
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/wn'
   *  Constant: '<S64>/zt'
   *  Integrator: '<S64>/Integrator2'
   *  Product: '<S64>/Product2'
   *  Sum: '<S64>/Sum'
   *  Sum: '<S64>/Sum1'
   */
  compliance_B.Product_e = ((compliance_B.BiasRemoval1.Switch -
    compliance_B.Integrator1_f) - compliance_X.Integrator2_CSTATE_m *
    compliance_P.Constant_Value_m * compliance_P.SecondOrderLowPassFilter1_inp_b)
    * compliance_P.SecondOrderLowPassFilter1_input;

  /* Product: '<S64>/Product1' incorporates:
   *  Constant: '<S64>/wn'
   *  Integrator: '<S64>/Integrator2'
   */
  compliance_B.Product1_p = compliance_P.SecondOrderLowPassFilter1_input *
    compliance_X.Integrator2_CSTATE_m;
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* S-Function (hil_read_encoder_block): '<S59>/HIL Read Encoder' */

    /* S-Function Block: compliance/Robot and Environment Subsystem/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILReadEncoder_channels, 2,
        &compliance_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = compliance_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = compliance_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S59>/Encoder Gain' incorporates:
     *  Constant: '<S59>/Home Position'
     *  Sum: '<S59>/Sum1'
     */
    compliance_B.EncoderGain[0] = (compliance_P.HomePosition_Value[0] +
      rtb_HILReadAnalog[0]) * compliance_P.EncoderGain_Gain[0];
    compliance_B.EncoderGain[1] = (compliance_P.HomePosition_Value[1] +
      rtb_HILReadAnalog[1]) * compliance_P.EncoderGain_Gain[1];
  }

  /* Derivative: '<S59>/Derivative' incorporates:
   *  Clock: '<Root>/Clock'
   *  Derivative: '<Root>/Derivative'
   *  Derivative: '<Root>/Derivative1'
   *  Gain: '<S59>/Encoder Gain'
   */
  rtb_Clock_0 = compliance_M->Timing.t[0];
  if ((compliance_DW.TimeStampA >= rtb_Clock_0) && (compliance_DW.TimeStampB >=
       rtb_Clock_0)) {
    rtb_Derivative_idx_0 = 0.0;
    rtb_Derivative_idx_1 = 0.0;
  } else {
    h = compliance_DW.TimeStampA;
    lastU = &compliance_DW.LastUAtTimeA;
    if (compliance_DW.TimeStampA < compliance_DW.TimeStampB) {
      if (compliance_DW.TimeStampB < rtb_Clock_0) {
        h = compliance_DW.TimeStampB;
        lastU = &compliance_DW.LastUAtTimeB;
      }
    } else if (compliance_DW.TimeStampA >= rtb_Clock_0) {
      h = compliance_DW.TimeStampB;
      lastU = &compliance_DW.LastUAtTimeB;
    }

    h = rtb_Clock_0 - h;
    rtb_Derivative_idx_0 = (compliance_B.EncoderGain[0] - (*lastU)[0]) / h;
    rtb_Derivative_idx_1 = (compliance_B.EncoderGain[1] - (*lastU)[1]) / h;
  }

  /* End of Derivative: '<S59>/Derivative' */
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* MATLAB Function: '<S6>/Forward Kinematics' incorporates:
     *  Gain: '<S59>/Encoder Gain'
     */
    /* MATLAB Function 'Robot and Environment Subsystem/Forward Kinematics': '<S58>:1' */
    /* '<S58>:1:5' */
    /* '<S58>:1:6' */
    /* '<S58>:1:8' */
    compliance_B.x_i[0] = 0.15 * cos(compliance_B.EncoderGain[0]) + 0.22 * cos
      (compliance_B.EncoderGain[1]);

    /* '<S58>:1:9' */
    compliance_B.x_i[1] = 0.15 * sin(compliance_B.EncoderGain[0]) + 0.22 * sin
      (compliance_B.EncoderGain[1]);
  }

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Constant: '<Root>/Speed'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S7>:1' */
  /* '<S7>:1:6' */
  /* '<S7>:1:7' */
  if (rtb_Clock_0 < 2.0) {
    /* '<S7>:1:9' */
    /* '<S7>:1:10' */
    h = 1.0 - cos(3.1415926535897931 * rtb_Clock_0 / 2.0);
    compliance_B.x[0] = h * 0.0375 + 0.22;

    /* '<S7>:1:11' */
    compliance_B.x[1] = 0.15 - h * 0.105;
  } else if (rtb_Clock_0 < 2.5) {
    /* '<S7>:1:12' */
    /* '<S7>:1:13' */
    h = (rtb_Clock_0 - 2.0) * (rtb_Clock_0 - 2.0) * (6.2831853071795862 *
      compliance_P.Speed_Value);
    compliance_B.x[0] = (cos(h) * 0.075 + 0.15) + 0.07;

    /* '<S7>:1:14' */
    compliance_B.x[1] = sin(h) * 0.075 + -0.06;
  } else {
    /* '<S7>:1:16' */
    h = 6.2831853071795862 * compliance_P.Speed_Value * (rtb_Clock_0 - 2.25);
    compliance_B.x[0] = (cos(h) * 0.075 + 0.15) + 0.07;

    /* '<S7>:1:17' */
    compliance_B.x[1] = sin(h) * 0.075 + -0.06;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */

  /* Derivative: '<Root>/Derivative' */
  if ((compliance_DW.TimeStampA_c >= rtb_Clock_0) && (compliance_DW.TimeStampB_p
       >= rtb_Clock_0)) {
    /* Derivative: '<Root>/Derivative' */
    compliance_B.Derivative[0] = 0.0;
    compliance_B.Derivative[1] = 0.0;
  } else {
    h = compliance_DW.TimeStampA_c;
    lastU = &compliance_DW.LastUAtTimeA_b;
    if (compliance_DW.TimeStampA_c < compliance_DW.TimeStampB_p) {
      if (compliance_DW.TimeStampB_p < rtb_Clock_0) {
        h = compliance_DW.TimeStampB_p;
        lastU = &compliance_DW.LastUAtTimeB_p;
      }
    } else if (compliance_DW.TimeStampA_c >= rtb_Clock_0) {
      h = compliance_DW.TimeStampB_p;
      lastU = &compliance_DW.LastUAtTimeB_p;
    }

    h = rtb_Clock_0 - h;

    /* Derivative: '<Root>/Derivative' */
    compliance_B.Derivative[0] = (compliance_B.x[0] - (*lastU)[0]) / h;
    compliance_B.Derivative[1] = (compliance_B.x[1] - (*lastU)[1]) / h;
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((compliance_DW.TimeStampA_j >= rtb_Clock_0) &&
      (compliance_DW.TimeStampB_p5 >= rtb_Clock_0)) {
    rtb_Derivative1[0] = 0.0;
    rtb_Derivative1[1] = 0.0;
  } else {
    h = compliance_DW.TimeStampA_j;
    lastU = &compliance_DW.LastUAtTimeA_o;
    if (compliance_DW.TimeStampA_j < compliance_DW.TimeStampB_p5) {
      if (compliance_DW.TimeStampB_p5 < rtb_Clock_0) {
        h = compliance_DW.TimeStampB_p5;
        lastU = &compliance_DW.LastUAtTimeB_m;
      }
    } else if (compliance_DW.TimeStampA_j >= rtb_Clock_0) {
      h = compliance_DW.TimeStampB_p5;
      lastU = &compliance_DW.LastUAtTimeB_m;
    }

    h = rtb_Clock_0 - h;
    rtb_Derivative1[0] = (compliance_B.Derivative[0] - (*lastU)[0]) / h;
    rtb_Derivative1[1] = (compliance_B.Derivative[1] - (*lastU)[1]) / h;
  }

  /* MATLAB Function: '<S6>/Rotation to Base Frame' incorporates:
   *  Gain: '<S59>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Hx Matrix'
   *  MATLAB Function: '<Root>/Jacobiandot'
   *  SignalConversion generated from: '<S60>/ SFunction '
   */
  /* MATLAB Function 'Robot and Environment Subsystem/Rotation to Base Frame': '<S60>:1' */
  /* '<S60>:1:7' */
  /* '<S60>:1:11' */
  h = sin(compliance_B.EncoderGain[1]);
  rtb_Clock_0 = cos(compliance_B.EncoderGain[1]);
  compliance_B.F0[0] = 0.0;
  compliance_B.F0[0] += rtb_Clock_0 * compliance_B.Integrator1;
  compliance_B.F0[0] += -h * compliance_B.Integrator1_f;
  compliance_B.F0[1] = 0.0;
  compliance_B.F0[1] += h * compliance_B.Integrator1;
  compliance_B.F0[1] += rtb_Clock_0 * compliance_B.Integrator1_f;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<Root>/x Admittance'
   *  Sum: '<Root>/Sum5'
   *  TransferFcn: '<Root>/y Admittance1'
   */
  compliance_B.Sum2[0] = (compliance_B.x[0] - compliance_P.xAdmittance_Gain *
    compliance_B.F0[0]) - compliance_B.x_i[0];
  compliance_B.Sum2[1] = (compliance_B.x[1] - (compliance_P.yAdmittance1_C[0] *
    compliance_X.yAdmittance1_CSTATE[0] + compliance_P.yAdmittance1_C[1] *
    compliance_X.yAdmittance1_CSTATE[1])) - compliance_B.x_i[1];

  /* MATLAB Function: '<Root>/Hx Matrix' incorporates:
   *  Gain: '<S59>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  MATLAB Function: '<Root>/Jacobiandot'
   */
  /* MATLAB Function 'Jacobiandot': '<S4>:1' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:6' */
  /* '<S4>:1:10' */
  /* MATLAB Function 'Hx Matrix': '<S2>:1' */
  /* '<S2>:1:30' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:7' */
  /* '<S2>:1:9' */
  /* '<S2>:1:23' */
  rtb_xAdmittance = compliance_B.EncoderGain[1] - compliance_B.EncoderGain[0];
  rtb_yAdmittance1 = cos(rtb_xAdmittance) * 0.00041579999999999997;

  /* '<S2>:1:27' */
  /* '<S2>:1:30' */
  tmp_8 = -0.15 * sin(compliance_B.EncoderGain[0]);
  tmp[0] = tmp_8 - 0.15 * h;
  tmp[2] = -0.15 * h;
  tmp_9 = 0.15 * cos(compliance_B.EncoderGain[0]);
  tmp[1] = 0.15 * rtb_Clock_0 + tmp_9;
  tmp[3] = 0.15 * cos(compliance_B.EncoderGain[1]);

  /* MATLAB Function: '<Root>/Feedback Comp' */
  /* '<S2>:1:32' */
  /* '<S2>:1:33' */
  /* '<S2>:1:37' */
  /* MATLAB Function 'Jacobian Transpose': '<S3>:1' */
  /* '<S3>:1:4' */
  /* '<S3>:1:5' */
  /* '<S3>:1:7' */
  /* '<S3>:1:8' */
  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  /* '<S3>:1:12' */
  /* '<S3>:1:14' */
  /* MATLAB Function 'Feedback Comp': '<S1>:1' */
  /* '<S1>:1:6' */
  /* '<S1>:1:8' */
  /* '<S1>:1:9' */
  /* '<S1>:1:10' */
  /* '<S1>:1:11' */
  /* '<S1>:1:16' */
  /* '<S1>:1:17' */
  /* '<S1>:1:18' */
  /* '<S1>:1:19' */
  /* '<S1>:1:20' */
  /* '<S1>:1:21' */
  /* '<S1>:1:22' */
  /* '<S1>:1:24' */
  h = sin(rtb_xAdmittance) * 0.00041579999999999997;

  /* MATLAB Function: '<Root>/Jacobiandot' incorporates:
   *  Gain: '<S59>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   */
  /* '<S1>:1:25' */
  /* '<S1>:1:26' */
  /* '<S1>:1:27' */
  /* '<S1>:1:28' */
  /* '<S1>:1:30' */
  /* '<S1>:1:31' */
  /* '<S1>:1:32' */
  /* '<S1>:1:34' */
  rtb_xAdmittance = cos(compliance_B.EncoderGain[0]);
  for (i = 0; i < 2; i++) {
    /* Gain: '<S43>/Filter Coefficient' incorporates:
     *  Gain: '<S34>/Derivative Gain'
     *  Integrator: '<S35>/Filter'
     *  Sum: '<S35>/SumD'
     */
    compliance_B.FilterCoefficient[i] = (compliance_P.PDController_D[i] *
      compliance_B.Sum2[i] - compliance_X.Filter_CSTATE[i]) *
      compliance_P.PDController_N;

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
  compliance_inv(J_0, tmp);
  compliance_inv(J, J_0);

  /* MATLAB Function: '<Root>/Jacobiandot' incorporates:
   *  Gain: '<S59>/Encoder Gain'
   */
  tmp_0[0] = -0.15 * rtb_xAdmittance;
  tmp_0[2] = -0.15 * rtb_Clock_0;
  tmp_0[1] = tmp_8;
  tmp_0[3] = -0.15 * sin(compliance_B.EncoderGain[1]);
  for (i = 0; i <= 0; i += 2) {
    /* MATLAB Function: '<Root>/Hx Matrix' */
    tmp_a = _mm_set1_pd(0.0);
    _mm_storeu_pd(&J[i], tmp_a);
    tmp_4 = _mm_loadu_pd(&tmp[i]);
    tmp_5 = _mm_loadu_pd(&J[i]);
    _mm_storeu_pd(&J[i], _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd(0.0055575)),
      tmp_5));
    tmp_4 = _mm_loadu_pd(&tmp[i + 2]);
    tmp_5 = _mm_set1_pd(rtb_yAdmittance1);
    tmp_6 = _mm_loadu_pd(&J[i]);
    _mm_storeu_pd(&J[i], _mm_add_pd(_mm_mul_pd(tmp_4, tmp_5), tmp_6));
    _mm_storeu_pd(&J[i + 2], tmp_a);
    tmp_4 = _mm_loadu_pd(&tmp[i]);
    tmp_6 = _mm_loadu_pd(&J[i + 2]);
    _mm_storeu_pd(&J[i + 2], _mm_add_pd(tmp_6, _mm_mul_pd(tmp_4, tmp_5)));
    tmp_4 = _mm_loadu_pd(&tmp[i + 2]);
    tmp_5 = _mm_loadu_pd(&J[i + 2]);
    _mm_storeu_pd(&J[i + 2], _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd
      (0.0034850000000000003)), tmp_5));
    _mm_storeu_pd(&tmp_1[i], tmp_a);
    tmp_4 = _mm_loadu_pd(&J[i]);
    tmp_5 = _mm_loadu_pd(&tmp_1[i]);
    _mm_storeu_pd(&tmp_1[i], _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd(J_0[0])),
      tmp_5));
    tmp_4 = _mm_loadu_pd(&J[i + 2]);
    tmp_5 = _mm_loadu_pd(&tmp_1[i]);
    _mm_storeu_pd(&tmp_1[i], _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd(J_0[1])),
      tmp_5));
    _mm_storeu_pd(&tmp_1[i + 2], tmp_a);
    tmp_a = _mm_loadu_pd(&J[i]);
    tmp_4 = _mm_loadu_pd(&tmp_1[i + 2]);
    _mm_storeu_pd(&tmp_1[i + 2], _mm_add_pd(tmp_4, _mm_mul_pd(tmp_a, _mm_set1_pd
      (J_0[2]))));
    tmp_a = _mm_loadu_pd(&J[i + 2]);
    tmp_4 = _mm_loadu_pd(&tmp_1[i + 2]);
    _mm_storeu_pd(&tmp_1[i + 2], _mm_add_pd(_mm_mul_pd(tmp_a, _mm_set1_pd(J_0[3])),
      tmp_4));

    /* Gain: '<S45>/Proportional Gain' incorporates:
     *  MATLAB Function: '<Root>/Hx Matrix'
     */
    tmp_a = _mm_loadu_pd(&compliance_B.Sum2[i]);

    /* Sum: '<S49>/Sum' incorporates:
     *  MATLAB Function: '<Root>/Hx Matrix'
     */
    tmp_4 = _mm_loadu_pd(&compliance_B.FilterCoefficient[i]);

    /* Sum: '<Root>/Sum4' incorporates:
     *  MATLAB Function: '<Root>/Hx Matrix'
     */
    tmp_5 = _mm_loadu_pd(&rtb_Derivative1[i]);

    /* MATLAB Function: '<Root>/Jacobiandot' incorporates:
     *  MATLAB Function: '<Root>/Hx Matrix'
     */
    tmp_6 = _mm_loadu_pd(&tmp_0[i + 2]);
    tmp_7 = _mm_loadu_pd(&tmp_0[i]);

    /* Sum: '<Root>/Sum4' incorporates:
     *  Derivative: '<S59>/Derivative'
     *  Gain: '<S45>/Proportional Gain'
     *  MATLAB Function: '<Root>/Hx Matrix'
     *  MATLAB Function: '<Root>/Jacobiandot'
     */
    _mm_storeu_pd(&rtb_Derivative1_0[i], _mm_sub_pd(_mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&compliance_P.PDController_P[i]), tmp_a), tmp_4),
      tmp_5), _mm_add_pd(_mm_mul_pd(tmp_6, _mm_set1_pd(rtb_Derivative_idx_1)),
                         _mm_mul_pd(tmp_7, _mm_set1_pd(rtb_Derivative_idx_0)))));
  }

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S59>/Derivative'
   */
  rtb_yAdmittance1 = rtb_Derivative_idx_0 * rtb_Derivative_idx_0;
  J_tmp = rtb_Derivative_idx_1 * rtb_Derivative_idx_1;

  /* Sum: '<Root>/Sum1' incorporates:
   *  MATLAB Function: '<Root>/Hx Matrix'
   */
  tmp_2 = (tmp_1[0] * rtb_Derivative1_0[0] + rtb_Derivative1_0[1] * tmp_1[2]) +
    compliance_B.x_i[0];
  tmp_3 = (rtb_Derivative1_0[0] * tmp_1[1] + rtb_Derivative1_0[1] * tmp_1[3]) +
    compliance_B.x_i[1];

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S59>/Derivative'
   */
  if (rtb_Derivative_idx_0 < 0.0) {
    rtb_Derivative_idx_0_0 = -1.0;
  } else if (rtb_Derivative_idx_0 > 0.0) {
    rtb_Derivative_idx_0_0 = 1.0;
  } else if (rtb_Derivative_idx_0 == 0.0) {
    rtb_Derivative_idx_0_0 = 0.0;
  } else {
    rtb_Derivative_idx_0_0 = (rtNaN);
  }

  /* Gain: '<S6>/inv motor gain' incorporates:
   *  Derivative: '<S59>/Derivative'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  compliance_B.current[0] = ((((0.0 * rtb_yAdmittance1 + -h * J_tmp) + 0.1690892
    * rtb_xAdmittance) + (0.01519 * rtb_Derivative_idx_0 + 0.007 *
    rtb_Derivative_idx_0_0)) + (tmp_8 * tmp_2 + tmp_9 * tmp_3)) *
    compliance_P.invmotorgain_Gain;

  /* Gain: '<S59>/1//AmpGain' incorporates:
   *  Bias: '<S59>/Amp Bias Tune for each amp if needed'
   */
  compliance_B.uAmpGain[0] = (compliance_B.current[0] +
    compliance_P.AmpBiasTuneforeachampifneeded_B[0]) *
    compliance_P.uAmpGain_Gain[0];

  /* MATLAB Function: '<Root>/Feedback Comp' incorporates:
   *  Derivative: '<S59>/Derivative'
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

  /* Gain: '<S6>/inv motor gain' incorporates:
   *  Derivative: '<S59>/Derivative'
   *  Gain: '<S59>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  compliance_B.current[1] = ((((h * rtb_yAdmittance1 + 0.0 * J_tmp) +
    0.027165599999999998 * rtb_Clock_0) + (0.01519 * rtb_Derivative_idx_1 +
    0.007 * rtb_Derivative_idx_0)) + (-0.15 * sin(compliance_B.EncoderGain[1]) *
    tmp_2 + 0.15 * cos(compliance_B.EncoderGain[1]) * tmp_3)) *
    compliance_P.invmotorgain_Gain;

  /* Gain: '<S59>/1//AmpGain' incorporates:
   *  Bias: '<S59>/Amp Bias Tune for each amp if needed'
   */
  compliance_B.uAmpGain[1] = (compliance_B.current[1] +
    compliance_P.AmpBiasTuneforeachampifneeded_B[1]) *
    compliance_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* S-Function (hil_write_analog_block): '<S59>/HIL Write Analog' */

    /* S-Function Block: compliance/Robot and Environment Subsystem/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILWriteAnalog_channels, 2, &compliance_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S59>/HIL Read Analog' */

    /* S-Function Block: compliance/Robot and Environment Subsystem/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILReadAnalog_channels_c, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
      }
    }

    /* Gain: '<S59>/1//Sense Gain' */
    compliance_B.uSenseGain[0] = compliance_P.uSenseGain_Gain *
      rtb_HILReadAnalog[0];
    compliance_B.uSenseGain[1] = compliance_P.uSenseGain_Gain *
      rtb_HILReadAnalog[1];

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S59>/Encoder Gain'
     */
    if (compliance_M->Timing.RateInteraction.TID1_2) {
      compliance_DW.RateTransition_Buffer[0] = compliance_B.EncoderGain[0];
      compliance_DW.RateTransition_Buffer[1] = compliance_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void compliance_update0(void)          /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];
  if (rtmIsMajorTimeStep(compliance_M)) {
    /* Update for Atomic SubSystem: '<S57>/Bias Removal' */
    complian_BiasRemoval_Update(&compliance_B.BiasRemoval,
      &compliance_DW.BiasRemoval);

    /* End of Update for SubSystem: '<S57>/Bias Removal' */

    /* Update for Atomic SubSystem: '<S57>/Bias Removal1' */
    complian_BiasRemoval_Update(&compliance_B.BiasRemoval1,
      &compliance_DW.BiasRemoval1);

    /* End of Update for SubSystem: '<S57>/Bias Removal1' */
  }

  /* Update for Integrator: '<S63>/Integrator1' */
  compliance_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S64>/Integrator1' */
  compliance_DW.Integrator1_IWORK_f = 0;

  /* Update for Derivative: '<S59>/Derivative' incorporates:
   *  Gain: '<S59>/Encoder Gain'
   */
  if (compliance_DW.TimeStampA == (rtInf)) {
    compliance_DW.TimeStampA = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeA;
  } else if (compliance_DW.TimeStampB == (rtInf)) {
    compliance_DW.TimeStampB = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeB;
  } else if (compliance_DW.TimeStampA < compliance_DW.TimeStampB) {
    compliance_DW.TimeStampA = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeA;
  } else {
    compliance_DW.TimeStampB = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeB;
  }

  (*lastU)[0] = compliance_B.EncoderGain[0];
  (*lastU)[1] = compliance_B.EncoderGain[1];

  /* End of Update for Derivative: '<S59>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (compliance_DW.TimeStampA_c == (rtInf)) {
    compliance_DW.TimeStampA_c = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeA_b;
  } else if (compliance_DW.TimeStampB_p == (rtInf)) {
    compliance_DW.TimeStampB_p = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeB_p;
  } else if (compliance_DW.TimeStampA_c < compliance_DW.TimeStampB_p) {
    compliance_DW.TimeStampA_c = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeA_b;
  } else {
    compliance_DW.TimeStampB_p = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeB_p;
  }

  (*lastU)[0] = compliance_B.x[0];
  (*lastU)[1] = compliance_B.x[1];

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (compliance_DW.TimeStampA_j == (rtInf)) {
    compliance_DW.TimeStampA_j = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeA_o;
  } else if (compliance_DW.TimeStampB_p5 == (rtInf)) {
    compliance_DW.TimeStampB_p5 = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeB_m;
  } else if (compliance_DW.TimeStampA_j < compliance_DW.TimeStampB_p5) {
    compliance_DW.TimeStampA_j = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeA_o;
  } else {
    compliance_DW.TimeStampB_p5 = compliance_M->Timing.t[0];
    lastU = &compliance_DW.LastUAtTimeB_m;
  }

  (*lastU)[0] = compliance_B.Derivative[0];
  (*lastU)[1] = compliance_B.Derivative[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */
  if (rtmIsMajorTimeStep(compliance_M)) {
    rt_ertODEUpdateContinuousStates(&compliance_M->solverInfo);
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
  if (!(++compliance_M->Timing.clockTick0)) {
    ++compliance_M->Timing.clockTickH0;
  }

  compliance_M->Timing.t[0] = rtsiGetSolverStopTime(&compliance_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++compliance_M->Timing.clockTick1)) {
    ++compliance_M->Timing.clockTickH1;
  }

  compliance_M->Timing.t[1] = compliance_M->Timing.clockTick1 *
    compliance_M->Timing.stepSize1 + compliance_M->Timing.clockTickH1 *
    compliance_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void compliance_derivatives(void)
{
  XDot_compliance_T *_rtXdot;
  _rtXdot = ((XDot_compliance_T *) compliance_M->derivs);

  /* Derivatives for Integrator: '<S63>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = compliance_B.Product1;

  /* Derivatives for Integrator: '<S63>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = compliance_B.Product;

  /* Derivatives for Integrator: '<S64>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_d = compliance_B.Product1_p;

  /* Derivatives for Integrator: '<S64>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_m = compliance_B.Product_e;

  /* Derivatives for TransferFcn: '<Root>/y Admittance1' */
  _rtXdot->yAdmittance1_CSTATE[0] = 0.0;
  _rtXdot->yAdmittance1_CSTATE[0] += compliance_P.yAdmittance1_A[0] *
    compliance_X.yAdmittance1_CSTATE[0];

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE[0] = compliance_B.FilterCoefficient[0];

  /* Derivatives for TransferFcn: '<Root>/y Admittance1' */
  _rtXdot->yAdmittance1_CSTATE[1] = 0.0;
  _rtXdot->yAdmittance1_CSTATE[0] += compliance_P.yAdmittance1_A[1] *
    compliance_X.yAdmittance1_CSTATE[1];

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE[1] = compliance_B.FilterCoefficient[1];

  /* Derivatives for TransferFcn: '<Root>/y Admittance1' */
  _rtXdot->yAdmittance1_CSTATE[1] += compliance_X.yAdmittance1_CSTATE[0];
  _rtXdot->yAdmittance1_CSTATE[0] += compliance_B.F0[1];
}

/* Model output function for TID2 */
void compliance_output2(void)          /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  compliance_B.RateTransition[0] = compliance_DW.RateTransition_Buffer[0];
  compliance_B.RateTransition[1] = compliance_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void compliance_update2(void)          /* Sample time: [0.02s, 0.0s] */
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
  if (!(++compliance_M->Timing.clockTick2)) {
    ++compliance_M->Timing.clockTickH2;
  }

  compliance_M->Timing.t[2] = compliance_M->Timing.clockTick2 *
    compliance_M->Timing.stepSize2 + compliance_M->Timing.clockTickH2 *
    compliance_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void compliance_output(int_T tid)
{
  switch (tid) {
   case 0 :
    compliance_output0();
    break;

   case 2 :
    compliance_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void compliance_update(int_T tid)
{
  switch (tid) {
   case 0 :
    compliance_update0();
    break;

   case 2 :
    compliance_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void compliance_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S57>/HIL Initialize' */

  /* S-Function Block: compliance/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6014", "0", &compliance_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(compliance_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(compliance_DW.HILInitialize_Card,
      "terminal_board=e_series", 24);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(compliance_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(compliance_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(compliance_M, _rt_error_message);
      return;
    }

    if ((compliance_P.HILInitialize_AOPStart && !is_switching) ||
        (compliance_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(compliance_DW.HILInitialize_Card,
        &compliance_P.HILInitialize_AOChannels, 1U,
        &compliance_P.HILInitialize_AOLow, &compliance_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_AOStart && !is_switching) ||
        (compliance_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(compliance_DW.HILInitialize_Card,
        &compliance_P.HILInitialize_AOChannels, 1U,
        &compliance_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_initialize_block): '<S59>/HIL Initialize' */

  /* S-Function Block: compliance/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &compliance_DW.HILInitialize_Card_k);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(compliance_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(compliance_DW.HILInitialize_Card_k,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(compliance_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(compliance_DW.HILInitialize_Card_k);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(compliance_M, _rt_error_message);
      return;
    }

    if ((compliance_P.HILInitialize_AIPStart_j && !is_switching) ||
        (compliance_P.HILInitialize_AIPEnter_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &compliance_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (compliance_P.HILInitialize_AILow_m);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &compliance_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = compliance_P.HILInitialize_AIHigh_p;
        }
      }

      result = hil_set_analog_input_ranges(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_AIChannels, 8U,
        &compliance_DW.HILInitialize_AIMinimums[0],
        &compliance_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_AOPStart_b && !is_switching) ||
        (compliance_P.HILInitialize_AOPEnter_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &compliance_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (compliance_P.HILInitialize_AOLow_n);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &compliance_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = compliance_P.HILInitialize_AOHigh_n;
        }
      }

      result = hil_set_analog_output_ranges(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_AOChannels_p, 8U,
        &compliance_DW.HILInitialize_AOMinimums[0],
        &compliance_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_AOStart_k && !is_switching) ||
        (compliance_P.HILInitialize_AOEnter_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &compliance_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = compliance_P.HILInitialize_AOInitial_b;
        }
      }

      result = hil_write_analog(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_AOChannels_p, 8U,
        &compliance_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if (compliance_P.HILInitialize_AOReset_b) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &compliance_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = compliance_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (compliance_DW.HILInitialize_Card_k,
         compliance_P.HILInitialize_AOChannels_p, 8U,
         &compliance_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_EIPStart_j && !is_switching) ||
        (compliance_P.HILInitialize_EIPEnter_i && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &compliance_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = compliance_P.HILInitialize_EIQuadrature_e;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (compliance_DW.HILInitialize_Card_k,
         compliance_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
         &compliance_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_EIStart_a && !is_switching) ||
        (compliance_P.HILInitialize_EIEnter_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &compliance_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = compliance_P.HILInitialize_EIInitial_d;
        }
      }

      result = hil_set_encoder_counts(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_EIChannels, 8U,
        &compliance_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_POPStart_a && !is_switching) ||
        (compliance_P.HILInitialize_POPEnter_b && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &compliance_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = compliance_P.HILInitialize_POModes_k;
        }
      }

      result = hil_set_pwm_mode(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &compliance_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          compliance_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &compliance_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            compliance_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            compliance_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              compliance_P.HILInitialize_POFrequency_c;
            num_duty_cycle_modes++;
          } else {
            compliance_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            compliance_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              compliance_P.HILInitialize_POFrequency_c;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(compliance_DW.HILInitialize_Card_k,
          &compliance_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &compliance_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(compliance_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(compliance_DW.HILInitialize_Card_k,
          &compliance_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &compliance_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(compliance_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &compliance_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = compliance_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &compliance_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = compliance_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &compliance_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = compliance_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &compliance_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &compliance_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &compliance_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &compliance_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = compliance_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &compliance_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = compliance_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_POChannels, 8U,
        &compliance_DW.HILInitialize_POSortedFreqs[0],
        &compliance_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if ((compliance_P.HILInitialize_POStart_n && !is_switching) ||
        (compliance_P.HILInitialize_POEnter_n && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &compliance_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = compliance_P.HILInitialize_POInitial_g;
        }
      }

      result = hil_write_pwm(compliance_DW.HILInitialize_Card_k,
        compliance_P.HILInitialize_POChannels, 8U,
        &compliance_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }

    if (compliance_P.HILInitialize_POReset_d) {
      {
        int_T i1;
        real_T *dw_POValues = &compliance_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = compliance_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (compliance_DW.HILInitialize_Card_k,
         compliance_P.HILInitialize_POChannels, 8U,
         &compliance_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Atomic SubSystem: '<S57>/Bias Removal' */
  complianc_BiasRemoval_Start(&compliance_DW.BiasRemoval);

  /* End of Start for SubSystem: '<S57>/Bias Removal' */

  /* Start for Atomic SubSystem: '<S57>/Bias Removal1' */
  complianc_BiasRemoval_Start(&compliance_DW.BiasRemoval1);

  /* End of Start for SubSystem: '<S57>/Bias Removal1' */

  /* Start for Constant: '<S63>/x0' */
  compliance_B.x0 = compliance_P.x0_Value;

  /* Start for Constant: '<S64>/x0' */
  compliance_B.x0_i = compliance_P.x0_Value_a;

  /* InitializeConditions for Integrator: '<S63>/Integrator1' incorporates:
   *  Integrator: '<S64>/Integrator1'
   */
  if (rtmIsFirstInitCond(compliance_M)) {
    compliance_X.Integrator1_CSTATE = 0.0;
    compliance_X.Integrator1_CSTATE_d = 0.0;
  }

  compliance_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S63>/Integrator1' */

  /* InitializeConditions for Integrator: '<S63>/Integrator2' */
  compliance_X.Integrator2_CSTATE = compliance_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S64>/Integrator1' */
  compliance_DW.Integrator1_IWORK_f = 1;

  /* InitializeConditions for Integrator: '<S64>/Integrator2' */
  compliance_X.Integrator2_CSTATE_m = compliance_P.Integrator2_IC_p;

  /* InitializeConditions for Derivative: '<S59>/Derivative' */
  compliance_DW.TimeStampA = (rtInf);
  compliance_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  compliance_DW.TimeStampA_c = (rtInf);
  compliance_DW.TimeStampB_p = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  compliance_DW.TimeStampA_j = (rtInf);
  compliance_DW.TimeStampB_p5 = (rtInf);

  /* InitializeConditions for TransferFcn: '<Root>/y Admittance1' */
  compliance_X.yAdmittance1_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  compliance_X.Filter_CSTATE[0] = compliance_P.PDController_InitialConditionFo;

  /* InitializeConditions for TransferFcn: '<Root>/y Admittance1' */
  compliance_X.yAdmittance1_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  compliance_X.Filter_CSTATE[1] = compliance_P.PDController_InitialConditionFo;

  /* SystemInitialize for Atomic SubSystem: '<S57>/Bias Removal' */
  compliance_BiasRemoval_Init(&compliance_B.BiasRemoval,
    &compliance_DW.BiasRemoval, &compliance_P.BiasRemoval);

  /* End of SystemInitialize for SubSystem: '<S57>/Bias Removal' */

  /* SystemInitialize for Atomic SubSystem: '<S57>/Bias Removal1' */
  compliance_BiasRemoval_Init(&compliance_B.BiasRemoval1,
    &compliance_DW.BiasRemoval1, &compliance_P.BiasRemoval1);

  /* End of SystemInitialize for SubSystem: '<S57>/Bias Removal1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(compliance_M)) {
    rtmSetFirstInitCond(compliance_M, 0);
  }
}

/* Model terminate function */
void compliance_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S57>/HIL Initialize' */

  /* S-Function Block: compliance/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(compliance_DW.HILInitialize_Card);
    hil_monitor_stop_all(compliance_DW.HILInitialize_Card);
    is_switching = false;
    if ((compliance_P.HILInitialize_AOTerminate && !is_switching) ||
        (compliance_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(compliance_DW.HILInitialize_Card,
        &compliance_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &compliance_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(compliance_M, _rt_error_message);
      }
    }

    hil_task_delete_all(compliance_DW.HILInitialize_Card);
    hil_monitor_delete_all(compliance_DW.HILInitialize_Card);
    hil_close(compliance_DW.HILInitialize_Card);
    compliance_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (hil_initialize_block): '<S59>/HIL Initialize' */

  /* S-Function Block: compliance/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(compliance_DW.HILInitialize_Card_k);
    hil_monitor_stop_all(compliance_DW.HILInitialize_Card_k);
    is_switching = false;
    if ((compliance_P.HILInitialize_AOTerminate_g && !is_switching) ||
        (compliance_P.HILInitialize_AOExit_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &compliance_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = compliance_P.HILInitialize_AOFinal_m;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((compliance_P.HILInitialize_POTerminate_a && !is_switching) ||
        (compliance_P.HILInitialize_POExit_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &compliance_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = compliance_P.HILInitialize_POFinal_c;
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
      result = hil_write(compliance_DW.HILInitialize_Card_k
                         , compliance_P.HILInitialize_AOChannels_p,
                         num_final_analog_outputs
                         , compliance_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &compliance_DW.HILInitialize_AOVoltages_a[0]
                         , &compliance_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(compliance_DW.HILInitialize_Card_k,
            compliance_P.HILInitialize_AOChannels_p, num_final_analog_outputs,
            &compliance_DW.HILInitialize_AOVoltages_a[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(compliance_DW.HILInitialize_Card_k,
            compliance_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &compliance_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(compliance_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(compliance_DW.HILInitialize_Card_k);
    hil_monitor_delete_all(compliance_DW.HILInitialize_Card_k);
    hil_close(compliance_DW.HILInitialize_Card_k);
    compliance_DW.HILInitialize_Card_k = NULL;
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
  compliance_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  compliance_update(tid);
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
  compliance_initialize();
}

void MdlTerminate(void)
{
  compliance_terminate();
}

/* Registration function */
RT_MODEL_compliance_T *compliance(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)compliance_M, 0,
                sizeof(RT_MODEL_compliance_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&compliance_M->solverInfo,
                          &compliance_M->Timing.simTimeStep);
    rtsiSetTPtr(&compliance_M->solverInfo, &rtmGetTPtr(compliance_M));
    rtsiSetStepSizePtr(&compliance_M->solverInfo,
                       &compliance_M->Timing.stepSize0);
    rtsiSetdXPtr(&compliance_M->solverInfo, &compliance_M->derivs);
    rtsiSetContStatesPtr(&compliance_M->solverInfo, (real_T **)
                         &compliance_M->contStates);
    rtsiSetNumContStatesPtr(&compliance_M->solverInfo,
      &compliance_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&compliance_M->solverInfo,
      &compliance_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&compliance_M->solverInfo,
      &compliance_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&compliance_M->solverInfo,
      &compliance_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&compliance_M->solverInfo, (&rtmGetErrorStatus
      (compliance_M)));
    rtsiSetRTModelPtr(&compliance_M->solverInfo, compliance_M);
  }

  rtsiSetSimTimeStep(&compliance_M->solverInfo, MAJOR_TIME_STEP);
  compliance_M->intgData.f[0] = compliance_M->odeF[0];
  compliance_M->contStates = ((real_T *) &compliance_X);
  rtsiSetSolverData(&compliance_M->solverInfo, (void *)&compliance_M->intgData);
  rtsiSetSolverName(&compliance_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = compliance_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "compliance_M points to
       static memory which is guaranteed to be non-NULL" */
    compliance_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    compliance_M->Timing.sampleTimes = (&compliance_M->Timing.sampleTimesArray[0]);
    compliance_M->Timing.offsetTimes = (&compliance_M->Timing.offsetTimesArray[0]);

    /* task periods */
    compliance_M->Timing.sampleTimes[0] = (0.0);
    compliance_M->Timing.sampleTimes[1] = (0.002);
    compliance_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    compliance_M->Timing.offsetTimes[0] = (0.0);
    compliance_M->Timing.offsetTimes[1] = (0.0);
    compliance_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(compliance_M, &compliance_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = compliance_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = compliance_M->Timing.perTaskSampleHitsArray;
    compliance_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    compliance_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(compliance_M, 10.0);
  compliance_M->Timing.stepSize0 = 0.002;
  compliance_M->Timing.stepSize1 = 0.002;
  compliance_M->Timing.stepSize2 = 0.02;
  rtmSetFirstInitCond(compliance_M, 1);

  /* External mode info */
  compliance_M->Sizes.checksums[0] = (3071022042U);
  compliance_M->Sizes.checksums[1] = (2531133447U);
  compliance_M->Sizes.checksums[2] = (1505607290U);
  compliance_M->Sizes.checksums[3] = (2057181967U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    compliance_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &compliance_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB;
    systemRan[6] = (sysRanDType *)
      &compliance_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy;
    systemRan[7] = (sysRanDType *)
      &compliance_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs;
    systemRan[8] = (sysRanDType *)
      &compliance_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &compliance_DW.BiasRemoval1.EnabledMovingAverage_SubsysRanB;
    systemRan[11] = (sysRanDType *)
      &compliance_DW.BiasRemoval1.SwitchCaseActionSubsystem_Subsy;
    systemRan[12] = (sysRanDType *)
      &compliance_DW.BiasRemoval1.SwitchCaseActionSubsystem1_Subs;
    systemRan[13] = (sysRanDType *)
      &compliance_DW.BiasRemoval1.SwitchCaseActionSubsystem2_Subs;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(compliance_M->extModeInfo,
      &compliance_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(compliance_M->extModeInfo, compliance_M->Sizes.checksums);
    rteiSetTPtr(compliance_M->extModeInfo, rtmGetTPtr(compliance_M));
  }

  compliance_M->solverInfoPtr = (&compliance_M->solverInfo);
  compliance_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&compliance_M->solverInfo, 0.002);
  rtsiSetSolverMode(&compliance_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  compliance_M->blockIO = ((void *) &compliance_B);
  (void) memset(((void *) &compliance_B), 0,
                sizeof(B_compliance_T));

  /* parameters */
  compliance_M->defaultParam = ((real_T *)&compliance_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &compliance_X;
    compliance_M->contStates = (x);
    (void) memset((void *)&compliance_X, 0,
                  sizeof(X_compliance_T));
  }

  /* states (dwork) */
  compliance_M->dwork = ((void *) &compliance_DW);
  (void) memset((void *)&compliance_DW, 0,
                sizeof(DW_compliance_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    compliance_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  compliance_M->Sizes.numContStates = (8);/* Number of continuous states */
  compliance_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  compliance_M->Sizes.numY = (0);      /* Number of model outputs */
  compliance_M->Sizes.numU = (0);      /* Number of model inputs */
  compliance_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  compliance_M->Sizes.numSampTimes = (3);/* Number of sample times */
  compliance_M->Sizes.numBlocks = (105);/* Number of blocks */
  compliance_M->Sizes.numBlockIO = (37);/* Number of block outputs */
  compliance_M->Sizes.numBlockPrms = (228);/* Sum of parameter "widths" */
  return compliance_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
