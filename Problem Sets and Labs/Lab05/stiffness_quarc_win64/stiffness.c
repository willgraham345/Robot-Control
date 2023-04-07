/*
 * stiffness.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "stiffness".
 *
 * Model version              : 8.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Apr  6 12:55:59 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stiffness.h"
#include "stiffness_private.h"
#include "stiffness_dt.h"

/* Block signals (default storage) */
B_stiffness_T stiffness_B;

/* Continuous states */
X_stiffness_T stiffness_X;

/* Block states (default storage) */
DW_stiffness_T stiffness_DW;

/* Real-time model */
static RT_MODEL_stiffness_T stiffness_M_;
RT_MODEL_stiffness_T *const stiffness_M = &stiffness_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(stiffness_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(stiffness_M, 2);
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
  if (stiffness_M->Timing.TaskCounters.TID[1] == 0) {
    stiffness_M->Timing.RateInteraction.TID1_2 =
      (stiffness_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    stiffness_M->Timing.perTaskSampleHits[5] =
      stiffness_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (stiffness_M->Timing.TaskCounters.TID[2])++;
  if ((stiffness_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.02s, 0.0s] */
    stiffness_M->Timing.TaskCounters.TID[2] = 0;
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
  stiffness_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for atomic system:
 *    '<S55>/Bias Removal'
 *    '<S55>/Bias Removal1'
 */
void stiffness_BiasRemoval_Init(B_BiasRemoval_stiffness_T *localB,
  DW_BiasRemoval_stiffness_T *localDW, P_BiasRemoval_stiffness_T *localP)
{
  /* SystemInitialize for Enabled SubSystem: '<S59>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S67>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S63>/Sum( k=1,n-1, x(k) )' */
  localDW->Sumk1n1xk_DSTATE = localP->Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Product: '<S63>/div' incorporates:
   *  Outport: '<S63>/x_avg_n'
   */
  localB->div = localP->x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S59>/Enabled Moving Average' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Switch Case Action Subsystem' */
  /* SystemInitialize for Outport: '<S64>/zero' incorporates:
   *  Constant: '<S64>/Constant'
   */
  localB->Constant = localP->zero_Y0;

  /* End of SystemInitialize for SubSystem: '<S59>/Switch Case Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Switch Case Action Subsystem1' */
  /* SystemInitialize for Outport: '<S65>/Vbiased' incorporates:
   *  Inport: '<S65>/Vin'
   */
  localB->Vin = localP->Vbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S59>/Switch Case Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Switch Case Action Subsystem2' */
  /* SystemInitialize for Outport: '<S66>/Vunbiased' incorporates:
   *  Inport: '<S66>/V-Vavg'
   */
  localB->VVavg = localP->Vunbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S59>/Switch Case Action Subsystem2' */
}

/*
 * Start for atomic system:
 *    '<S55>/Bias Removal'
 *    '<S55>/Bias Removal1'
 */
void stiffness_BiasRemoval_Start(DW_BiasRemoval_stiffness_T *localDW)
{
  /* Start for Enabled SubSystem: '<S59>/Enabled Moving Average' */
  localDW->EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S59>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S59>/Switch Case' */
  localDW->SwitchCase_ActiveSubsystem = -1;
}

/*
 * Outputs for atomic system:
 *    '<S55>/Bias Removal'
 *    '<S55>/Bias Removal1'
 */
void stiffness_BiasRemoval(RT_MODEL_stiffness_T * const stiffness_M, real_T
  rtu_V, real_T rtp_switch_id, real_T rtp_start_time, real_T rtp_end_time,
  B_BiasRemoval_stiffness_T *localB, DW_BiasRemoval_stiffness_T *localDW,
  P_BiasRemoval_stiffness_T *localP)
{
  real_T rtb_Stepend_time;
  real_T rtb_Sum_c;
  real_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Step: '<S59>/Step: end_time' incorporates:
   *  Step: '<S59>/Step: start_time'
   */
  tmp = stiffness_M->Timing.t[1];
  if (tmp < rtp_end_time) {
    rtb_Stepend_time = localP->Stepend_time_Y0;
  } else {
    rtb_Stepend_time = localP->Stepend_time_YFinal;
  }

  /* End of Step: '<S59>/Step: end_time' */

  /* Step: '<S59>/Step: start_time' */
  if (tmp < rtp_start_time) {
    tmp = localP->Stepstart_time_Y0;
  } else {
    tmp = localP->Stepstart_time_YFinal;
  }

  /* Outputs for Enabled SubSystem: '<S59>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S63>/Enable'
   */
  /* Logic: '<S59>/Logical Operator' incorporates:
   *  Logic: '<S59>/Logical Operator1'
   */
  if ((tmp != 0.0) && (!(rtb_Stepend_time != 0.0))) {
    if (!localDW->EnabledMovingAverage_MODE) {
      /* InitializeConditions for UnitDelay: '<S67>/Unit Delay' */
      localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S63>/Sum( k=1,n-1, x(k) )' */
      localDW->Sumk1n1xk_DSTATE = localP->Sumk1n1xk_InitialCondition;
      localDW->EnabledMovingAverage_MODE = true;
    }

    /* Sum: '<S67>/Count' incorporates:
     *  Constant: '<S67>/unity'
     *  UnitDelay: '<S67>/Unit Delay'
     */
    localB->Count = localP->unity_Value + localDW->UnitDelay_DSTATE;

    /* Sum: '<S63>/Sum' incorporates:
     *  UnitDelay: '<S63>/Sum( k=1,n-1, x(k) )'
     */
    localB->Sum = rtu_V + localDW->Sumk1n1xk_DSTATE;

    /* Product: '<S63>/div' */
    localB->div = localB->Sum / localB->Count;
    srUpdateBC(localDW->EnabledMovingAverage_SubsysRanB);
  } else {
    localDW->EnabledMovingAverage_MODE = false;
  }

  /* End of Logic: '<S59>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S59>/Enabled Moving Average' */

  /* Sum: '<S59>/Sum' */
  rtb_Sum_c = rtu_V - localB->div;

  /* SwitchCase: '<S59>/Switch Case' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S64>/Constant'
   *  Inport: '<S65>/Vin'
   *  Inport: '<S66>/V-Vavg'
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
      /* Disable for Outport: '<S64>/zero' incorporates:
       *  Constant: '<S64>/Constant'
       * */
      localB->Constant = localP->zero_Y0;
      break;

     case 1:
      /* Disable for Outport: '<S65>/Vbiased' incorporates:
       *  Inport: '<S65>/Vin'
       * */
      localB->Vin = localP->Vbiased_Y0;
      break;

     case 2:
      /* Disable for Outport: '<S66>/Vunbiased' incorporates:
       *  Inport: '<S66>/V-Vavg'
       * */
      localB->VVavg = localP->Vunbiased_Y0;
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S59>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S64>/Action Port'
     */
    localB->Constant = localP->Constant_Value;
    srUpdateBC(localDW->SwitchCaseActionSubsystem_Subsy);

    /* End of Outputs for SubSystem: '<S59>/Switch Case Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S59>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    localB->Vin = rtu_V;
    srUpdateBC(localDW->SwitchCaseActionSubsystem1_Subs);

    /* End of Outputs for SubSystem: '<S59>/Switch Case Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S59>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    localB->VVavg = rtb_Sum_c;
    srUpdateBC(localDW->SwitchCaseActionSubsystem2_Subs);

    /* End of Outputs for SubSystem: '<S59>/Switch Case Action Subsystem2' */
    break;
  }

  /* End of SwitchCase: '<S59>/Switch Case' */

  /* Switch: '<S59>/Switch' incorporates:
   *  Logic: '<S59>/Logical Operator2'
   */
  if (!(rtb_Stepend_time != 0.0)) {
    /* Switch: '<S59>/Switch' incorporates:
     *  Sum: '<S59>/Sum1'
     */
    localB->Switch = (localB->Constant + localB->Vin) + localB->VVavg;
  } else {
    /* Switch: '<S59>/Switch' */
    localB->Switch = rtb_Sum_c;
  }

  /* End of Switch: '<S59>/Switch' */
}

/*
 * Update for atomic system:
 *    '<S55>/Bias Removal'
 *    '<S55>/Bias Removal1'
 */
void stiffnes_BiasRemoval_Update(B_BiasRemoval_stiffness_T *localB,
  DW_BiasRemoval_stiffness_T *localDW)
{
  /* Update for Enabled SubSystem: '<S59>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S63>/Enable'
   */
  if (localDW->EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S67>/Unit Delay' */
    localDW->UnitDelay_DSTATE = localB->Count;

    /* Update for UnitDelay: '<S63>/Sum( k=1,n-1, x(k) )' */
    localDW->Sumk1n1xk_DSTATE = localB->Sum;
  }

  /* End of Update for SubSystem: '<S59>/Enabled Moving Average' */
}

/* Model output function for TID0 */
void stiffness_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog_o1;
  real_T rtb_HILReadAnalog_o2;
  real_T rtb_HILReadAnalog[2];
  real_T current_tmp;
  real_T rtb_Clock;
  real_T tmp;
  real_T tmp_0;
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* set solver stop time */
    if (!(stiffness_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&stiffness_M->solverInfo,
                            ((stiffness_M->Timing.clockTickH0 + 1) *
        stiffness_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&stiffness_M->solverInfo,
                            ((stiffness_M->Timing.clockTick0 + 1) *
        stiffness_M->Timing.stepSize0 + stiffness_M->Timing.clockTickH0 *
        stiffness_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(stiffness_M)) {
    stiffness_M->Timing.t[0] = rtsiGetT(&stiffness_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(stiffness_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(stiffness_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(stiffness_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(stiffness_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* S-Function (hil_read_analog_block): '<S55>/HIL Read Analog' */

    /* S-Function Block: stiffness/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(stiffness_DW.HILInitialize_Card,
        stiffness_P.HILReadAnalog_channels, 2,
        &stiffness_DW.HILReadAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
      }

      rtb_HILReadAnalog_o1 = stiffness_DW.HILReadAnalog_Buffer[0];
      rtb_HILReadAnalog_o2 = stiffness_DW.HILReadAnalog_Buffer[1];
    }

    /* Gain: '<S55>/X Gain (N//V)' */
    stiffness_B.XGainNV = stiffness_P.XGainNV_Gain * rtb_HILReadAnalog_o1;

    /* Outputs for Atomic SubSystem: '<S55>/Bias Removal' */
    /* Outputs for Atomic SubSystem: '<S55>/Bias Removal' */
    stiffness_BiasRemoval(stiffness_M, stiffness_B.XGainNV,
                          stiffness_P.BiasRemoval_switch_id,
                          stiffness_P.BiasRemoval_start_time,
                          stiffness_P.BiasRemoval_end_time,
                          &stiffness_B.BiasRemoval, &stiffness_DW.BiasRemoval,
                          &stiffness_P.BiasRemoval);

    /* End of Outputs for SubSystem: '<S55>/Bias Removal' */
    /* End of Outputs for SubSystem: '<S55>/Bias Removal' */

    /* Gain: '<S55>/Y Gain (N//V)' */
    stiffness_B.YGainNV = stiffness_P.YGainNV_Gain * rtb_HILReadAnalog_o2;

    /* Outputs for Atomic SubSystem: '<S55>/Bias Removal1' */
    /* Outputs for Atomic SubSystem: '<S55>/Bias Removal1' */
    stiffness_BiasRemoval(stiffness_M, stiffness_B.YGainNV,
                          stiffness_P.BiasRemoval1_switch_id,
                          stiffness_P.BiasRemoval1_start_time,
                          stiffness_P.BiasRemoval1_end_time,
                          &stiffness_B.BiasRemoval1, &stiffness_DW.BiasRemoval1,
                          &stiffness_P.BiasRemoval1);

    /* End of Outputs for SubSystem: '<S55>/Bias Removal1' */
    /* End of Outputs for SubSystem: '<S55>/Bias Removal1' */

    /* Constant: '<S61>/x0' */
    stiffness_B.x0 = stiffness_P.x0_Value;
  }

  /* Integrator: '<S61>/Integrator1' */
  if (stiffness_DW.Integrator1_IWORK != 0) {
    stiffness_X.Integrator1_CSTATE = stiffness_B.x0;
  }

  /* Integrator: '<S61>/Integrator1' */
  stiffness_B.Integrator1 = stiffness_X.Integrator1_CSTATE;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant'
   *  Constant: '<S61>/wn'
   *  Constant: '<S61>/zt'
   *  Integrator: '<S61>/Integrator2'
   *  Product: '<S61>/Product2'
   *  Sum: '<S61>/Sum'
   *  Sum: '<S61>/Sum1'
   */
  stiffness_B.Product = ((stiffness_B.BiasRemoval.Switch -
    stiffness_B.Integrator1) - stiffness_X.Integrator2_CSTATE *
    stiffness_P.Constant_Value * stiffness_P.SecondOrderLowPassFilter_inpu_o) *
    stiffness_P.SecondOrderLowPassFilter_input_;

  /* Product: '<S61>/Product1' incorporates:
   *  Constant: '<S61>/wn'
   *  Integrator: '<S61>/Integrator2'
   */
  stiffness_B.Product1 = stiffness_P.SecondOrderLowPassFilter_input_ *
    stiffness_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* Constant: '<S62>/x0' */
    stiffness_B.x0_i = stiffness_P.x0_Value_a;
  }

  /* Integrator: '<S62>/Integrator1' */
  if (stiffness_DW.Integrator1_IWORK_f != 0) {
    stiffness_X.Integrator1_CSTATE_d = stiffness_B.x0_i;
  }

  /* Integrator: '<S62>/Integrator1' */
  stiffness_B.Integrator1_f = stiffness_X.Integrator1_CSTATE_d;

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S62>/wn'
   *  Constant: '<S62>/zt'
   *  Integrator: '<S62>/Integrator2'
   *  Product: '<S62>/Product2'
   *  Sum: '<S62>/Sum'
   *  Sum: '<S62>/Sum1'
   */
  stiffness_B.Product_e = ((stiffness_B.BiasRemoval1.Switch -
    stiffness_B.Integrator1_f) - stiffness_X.Integrator2_CSTATE_m *
    stiffness_P.Constant_Value_m * stiffness_P.SecondOrderLowPassFilter1_inp_b) *
    stiffness_P.SecondOrderLowPassFilter1_input;

  /* Product: '<S62>/Product1' incorporates:
   *  Constant: '<S62>/wn'
   *  Integrator: '<S62>/Integrator2'
   */
  stiffness_B.Product1_p = stiffness_P.SecondOrderLowPassFilter1_input *
    stiffness_X.Integrator2_CSTATE_m;
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* S-Function (hil_read_encoder_block): '<S57>/HIL Read Encoder' */

    /* S-Function Block: stiffness/Robot and Environment Subsystem/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILReadEncoder_channels, 2,
        &stiffness_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = stiffness_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = stiffness_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S57>/Encoder Gain' incorporates:
     *  Constant: '<S57>/Home Position'
     *  Sum: '<S57>/Sum1'
     */
    stiffness_B.EncoderGain[0] = (stiffness_P.HomePosition_Value[0] +
      rtb_HILReadAnalog[0]) * stiffness_P.EncoderGain_Gain[0];
    stiffness_B.EncoderGain[1] = (stiffness_P.HomePosition_Value[1] +
      rtb_HILReadAnalog[1]) * stiffness_P.EncoderGain_Gain[1];
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = stiffness_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Trajectory  Generator' incorporates:
   *  Constant: '<Root>/Speed'
   */
  /* MATLAB Function 'Trajectory  Generator': '<S5>:1' */
  /* '<S5>:1:6' */
  /* '<S5>:1:7' */
  if (rtb_Clock < 2.0) {
    /* '<S5>:1:9' */
    /* '<S5>:1:10' */
    rtb_Clock = 1.0 - cos(3.1415926535897931 * rtb_Clock / 2.0);
    stiffness_B.x[0] = rtb_Clock * 0.0375 + 0.22;

    /* '<S5>:1:11' */
    stiffness_B.x[1] = 0.15 - rtb_Clock * 0.105;
  } else if (rtb_Clock < 2.5) {
    /* '<S5>:1:12' */
    /* '<S5>:1:13' */
    rtb_Clock = (rtb_Clock - 2.0) * (rtb_Clock - 2.0) * (6.2831853071795862 *
      stiffness_P.Speed_Value);
    stiffness_B.x[0] = (cos(rtb_Clock) * 0.075 + 0.15) + 0.07;

    /* '<S5>:1:14' */
    stiffness_B.x[1] = sin(rtb_Clock) * 0.075 + -0.06;
  } else {
    /* '<S5>:1:16' */
    rtb_Clock = 6.2831853071795862 * stiffness_P.Speed_Value * (rtb_Clock - 2.25);
    stiffness_B.x[0] = (cos(rtb_Clock) * 0.075 + 0.15) + 0.07;

    /* '<S5>:1:17' */
    stiffness_B.x[1] = sin(rtb_Clock) * 0.075 + -0.06;
  }

  /* End of MATLAB Function: '<Root>/Trajectory  Generator' */
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* MATLAB Function: '<S4>/Forward Kinematics' incorporates:
     *  Gain: '<S57>/Encoder Gain'
     */
    /* MATLAB Function 'Robot and Environment Subsystem/Forward Kinematics': '<S56>:1' */
    /* '<S56>:1:5' */
    /* '<S56>:1:6' */
    /* '<S56>:1:8' */
    stiffness_B.x_i[0] = 0.15 * cos(stiffness_B.EncoderGain[0]) + 0.22 * cos
      (stiffness_B.EncoderGain[1]);

    /* '<S56>:1:9' */
    stiffness_B.x_i[1] = 0.15 * sin(stiffness_B.EncoderGain[0]) + 0.22 * sin
      (stiffness_B.EncoderGain[1]);
  }

  /* MATLAB Function: '<Root>/Jacobian Transpose' incorporates:
   *  Gain: '<S57>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<S4>/Rotation to Base Frame'
   */
  /* MATLAB Function 'Jacobian Transpose': '<S2>:1' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:7' */
  /* '<S2>:1:8' */
  /* '<S2>:1:9' */
  /* '<S2>:1:10' */
  /* '<S2>:1:12' */
  /* '<S2>:1:14' */
  /* MATLAB Function 'Feedback Comp': '<S1>:1' */
  /* '<S1>:1:5' */
  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /* '<S1>:1:9' */
  /* '<S1>:1:10' */
  /* '<S1>:1:12' */
  /* '<S1>:1:14' */
  /* '<S1>:1:15' */
  /* '<S1>:1:17' */
  rtb_Clock = cos(stiffness_B.EncoderGain[1]);
  current_tmp = sin(stiffness_B.EncoderGain[1]);

  /* Sum: '<Root>/Sum2' */
  stiffness_B.Sum2[0] = stiffness_B.x[0] - stiffness_B.x_i[0];

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  stiffness_B.FilterCoefficient[0] = (stiffness_P.PDController_D[0] *
    stiffness_B.Sum2[0] - stiffness_X.Filter_CSTATE[0]) *
    stiffness_P.PDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   */
  tmp = stiffness_P.PDController_P[0] * stiffness_B.Sum2[0] +
    stiffness_B.FilterCoefficient[0];

  /* Sum: '<Root>/Sum2' */
  stiffness_B.Sum2[1] = stiffness_B.x[1] - stiffness_B.x_i[1];

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  stiffness_B.FilterCoefficient[1] = (stiffness_P.PDController_D[1] *
    stiffness_B.Sum2[1] - stiffness_X.Filter_CSTATE[1]) *
    stiffness_P.PDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   */
  tmp_0 = stiffness_P.PDController_P[1] * stiffness_B.Sum2[1] +
    stiffness_B.FilterCoefficient[1];

  /* Gain: '<S4>/inv motor gain' incorporates:
   *  Gain: '<S57>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  stiffness_B.current[0] = ((-0.15 * sin(stiffness_B.EncoderGain[0]) * tmp +
    0.15 * cos(stiffness_B.EncoderGain[0]) * tmp_0) + 0.2131892 * cos
    (stiffness_B.EncoderGain[0])) * stiffness_P.invmotorgain_Gain;

  /* Gain: '<S57>/1//AmpGain' incorporates:
   *  Bias: '<S57>/Amp Bias Tune for each amp if needed'
   */
  stiffness_B.uAmpGain[0] = (stiffness_B.current[0] +
    stiffness_P.AmpBiasTuneforeachampifneeded_B[0]) * stiffness_P.uAmpGain_Gain
    [0];

  /* Gain: '<S4>/inv motor gain' incorporates:
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  stiffness_B.current[1] = ((-0.15 * current_tmp * tmp + 0.15 * rtb_Clock *
    tmp_0) + 0.0796936 * rtb_Clock) * stiffness_P.invmotorgain_Gain;

  /* Gain: '<S57>/1//AmpGain' incorporates:
   *  Bias: '<S57>/Amp Bias Tune for each amp if needed'
   */
  stiffness_B.uAmpGain[1] = (stiffness_B.current[1] +
    stiffness_P.AmpBiasTuneforeachampifneeded_B[1]) * stiffness_P.uAmpGain_Gain
    [1];
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* S-Function (hil_write_analog_block): '<S57>/HIL Write Analog' */

    /* S-Function Block: stiffness/Robot and Environment Subsystem/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILWriteAnalog_channels, 2, &stiffness_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S57>/HIL Read Analog' */

    /* S-Function Block: stiffness/Robot and Environment Subsystem/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILReadAnalog_channels_c, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
      }
    }

    /* Gain: '<S57>/1//Sense Gain' */
    stiffness_B.uSenseGain[0] = stiffness_P.uSenseGain_Gain * rtb_HILReadAnalog
      [0];
    stiffness_B.uSenseGain[1] = stiffness_P.uSenseGain_Gain * rtb_HILReadAnalog
      [1];
  }

  /* MATLAB Function: '<S4>/Rotation to Base Frame' incorporates:
   *  SignalConversion generated from: '<S58>/ SFunction '
   */
  /* MATLAB Function 'Robot and Environment Subsystem/Rotation to Base Frame': '<S58>:1' */
  /* '<S58>:1:7' */
  /* '<S58>:1:11' */
  stiffness_B.F0[0] = 0.0;
  stiffness_B.F0[0] += rtb_Clock * stiffness_B.Integrator1;
  stiffness_B.F0[0] += -current_tmp * stiffness_B.Integrator1_f;
  stiffness_B.F0[1] = 0.0;
  stiffness_B.F0[1] += current_tmp * stiffness_B.Integrator1;
  stiffness_B.F0[1] += rtb_Clock * stiffness_B.Integrator1_f;
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S57>/Encoder Gain'
     */
    if (stiffness_M->Timing.RateInteraction.TID1_2) {
      stiffness_DW.RateTransition_Buffer[0] = stiffness_B.EncoderGain[0];
      stiffness_DW.RateTransition_Buffer[1] = stiffness_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void stiffness_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];
  if (rtmIsMajorTimeStep(stiffness_M)) {
    /* Update for Atomic SubSystem: '<S55>/Bias Removal' */
    stiffnes_BiasRemoval_Update(&stiffness_B.BiasRemoval,
      &stiffness_DW.BiasRemoval);

    /* End of Update for SubSystem: '<S55>/Bias Removal' */

    /* Update for Atomic SubSystem: '<S55>/Bias Removal1' */
    stiffnes_BiasRemoval_Update(&stiffness_B.BiasRemoval1,
      &stiffness_DW.BiasRemoval1);

    /* End of Update for SubSystem: '<S55>/Bias Removal1' */
  }

  /* Update for Integrator: '<S61>/Integrator1' */
  stiffness_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S62>/Integrator1' */
  stiffness_DW.Integrator1_IWORK_f = 0;

  /* Update for Derivative: '<S57>/Derivative' incorporates:
   *  Gain: '<S57>/Encoder Gain'
   */
  if (stiffness_DW.TimeStampA == (rtInf)) {
    stiffness_DW.TimeStampA = stiffness_M->Timing.t[0];
    lastU = &stiffness_DW.LastUAtTimeA;
  } else if (stiffness_DW.TimeStampB == (rtInf)) {
    stiffness_DW.TimeStampB = stiffness_M->Timing.t[0];
    lastU = &stiffness_DW.LastUAtTimeB;
  } else if (stiffness_DW.TimeStampA < stiffness_DW.TimeStampB) {
    stiffness_DW.TimeStampA = stiffness_M->Timing.t[0];
    lastU = &stiffness_DW.LastUAtTimeA;
  } else {
    stiffness_DW.TimeStampB = stiffness_M->Timing.t[0];
    lastU = &stiffness_DW.LastUAtTimeB;
  }

  (*lastU)[0] = stiffness_B.EncoderGain[0];
  (*lastU)[1] = stiffness_B.EncoderGain[1];

  /* End of Update for Derivative: '<S57>/Derivative' */
  if (rtmIsMajorTimeStep(stiffness_M)) {
    rt_ertODEUpdateContinuousStates(&stiffness_M->solverInfo);
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
  if (!(++stiffness_M->Timing.clockTick0)) {
    ++stiffness_M->Timing.clockTickH0;
  }

  stiffness_M->Timing.t[0] = rtsiGetSolverStopTime(&stiffness_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++stiffness_M->Timing.clockTick1)) {
    ++stiffness_M->Timing.clockTickH1;
  }

  stiffness_M->Timing.t[1] = stiffness_M->Timing.clockTick1 *
    stiffness_M->Timing.stepSize1 + stiffness_M->Timing.clockTickH1 *
    stiffness_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void stiffness_derivatives(void)
{
  XDot_stiffness_T *_rtXdot;
  _rtXdot = ((XDot_stiffness_T *) stiffness_M->derivs);

  /* Derivatives for Integrator: '<S61>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = stiffness_B.Product1;

  /* Derivatives for Integrator: '<S61>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = stiffness_B.Product;

  /* Derivatives for Integrator: '<S62>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_d = stiffness_B.Product1_p;

  /* Derivatives for Integrator: '<S62>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_m = stiffness_B.Product_e;

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE[0] = stiffness_B.FilterCoefficient[0];
  _rtXdot->Filter_CSTATE[1] = stiffness_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void stiffness_output2(void)           /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  stiffness_B.RateTransition[0] = stiffness_DW.RateTransition_Buffer[0];
  stiffness_B.RateTransition[1] = stiffness_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void stiffness_update2(void)           /* Sample time: [0.02s, 0.0s] */
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
  if (!(++stiffness_M->Timing.clockTick2)) {
    ++stiffness_M->Timing.clockTickH2;
  }

  stiffness_M->Timing.t[2] = stiffness_M->Timing.clockTick2 *
    stiffness_M->Timing.stepSize2 + stiffness_M->Timing.clockTickH2 *
    stiffness_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void stiffness_output(int_T tid)
{
  switch (tid) {
   case 0 :
    stiffness_output0();
    break;

   case 2 :
    stiffness_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void stiffness_update(int_T tid)
{
  switch (tid) {
   case 0 :
    stiffness_update0();
    break;

   case 2 :
    stiffness_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void stiffness_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S55>/HIL Initialize' */

  /* S-Function Block: stiffness/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6014", "0", &stiffness_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stiffness_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(stiffness_DW.HILInitialize_Card,
      "terminal_board=e_series", 24);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stiffness_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(stiffness_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stiffness_M, _rt_error_message);
      return;
    }

    if ((stiffness_P.HILInitialize_AOPStart && !is_switching) ||
        (stiffness_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(stiffness_DW.HILInitialize_Card,
        &stiffness_P.HILInitialize_AOChannels, 1U,
        &stiffness_P.HILInitialize_AOLow, &stiffness_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_AOStart && !is_switching) ||
        (stiffness_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(stiffness_DW.HILInitialize_Card,
        &stiffness_P.HILInitialize_AOChannels, 1U,
        &stiffness_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_initialize_block): '<S57>/HIL Initialize' */

  /* S-Function Block: stiffness/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &stiffness_DW.HILInitialize_Card_k);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stiffness_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(stiffness_DW.HILInitialize_Card_k,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stiffness_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(stiffness_DW.HILInitialize_Card_k);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stiffness_M, _rt_error_message);
      return;
    }

    if ((stiffness_P.HILInitialize_AIPStart_j && !is_switching) ||
        (stiffness_P.HILInitialize_AIPEnter_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &stiffness_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (stiffness_P.HILInitialize_AILow_m);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &stiffness_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = stiffness_P.HILInitialize_AIHigh_p;
        }
      }

      result = hil_set_analog_input_ranges(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_AIChannels, 8U,
        &stiffness_DW.HILInitialize_AIMinimums[0],
        &stiffness_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_AOPStart_b && !is_switching) ||
        (stiffness_P.HILInitialize_AOPEnter_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &stiffness_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (stiffness_P.HILInitialize_AOLow_n);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &stiffness_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = stiffness_P.HILInitialize_AOHigh_n;
        }
      }

      result = hil_set_analog_output_ranges(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_AOChannels_p, 8U,
        &stiffness_DW.HILInitialize_AOMinimums[0],
        &stiffness_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_AOStart_k && !is_switching) ||
        (stiffness_P.HILInitialize_AOEnter_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &stiffness_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = stiffness_P.HILInitialize_AOInitial_b;
        }
      }

      result = hil_write_analog(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_AOChannels_p, 8U,
        &stiffness_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if (stiffness_P.HILInitialize_AOReset_b) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &stiffness_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = stiffness_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (stiffness_DW.HILInitialize_Card_k,
         stiffness_P.HILInitialize_AOChannels_p, 8U,
         &stiffness_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_EIPStart_j && !is_switching) ||
        (stiffness_P.HILInitialize_EIPEnter_i && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &stiffness_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = stiffness_P.HILInitialize_EIQuadrature_e;
        }
      }

      result = hil_set_encoder_quadrature_mode(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &stiffness_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_EIStart_a && !is_switching) ||
        (stiffness_P.HILInitialize_EIEnter_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &stiffness_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = stiffness_P.HILInitialize_EIInitial_d;
        }
      }

      result = hil_set_encoder_counts(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_EIChannels, 8U,
        &stiffness_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_POPStart_a && !is_switching) ||
        (stiffness_P.HILInitialize_POPEnter_b && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &stiffness_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = stiffness_P.HILInitialize_POModes_k;
        }
      }

      result = hil_set_pwm_mode(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &stiffness_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          stiffness_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &stiffness_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            stiffness_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            stiffness_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              stiffness_P.HILInitialize_POFrequency_c;
            num_duty_cycle_modes++;
          } else {
            stiffness_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            stiffness_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              stiffness_P.HILInitialize_POFrequency_c;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(stiffness_DW.HILInitialize_Card_k,
          &stiffness_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &stiffness_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(stiffness_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(stiffness_DW.HILInitialize_Card_k,
          &stiffness_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &stiffness_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(stiffness_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &stiffness_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = stiffness_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &stiffness_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = stiffness_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &stiffness_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = stiffness_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &stiffness_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &stiffness_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &stiffness_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &stiffness_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = stiffness_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &stiffness_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = stiffness_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_POChannels, 8U,
        &stiffness_DW.HILInitialize_POSortedFreqs[0],
        &stiffness_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if ((stiffness_P.HILInitialize_POStart_n && !is_switching) ||
        (stiffness_P.HILInitialize_POEnter_n && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &stiffness_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = stiffness_P.HILInitialize_POInitial_g;
        }
      }

      result = hil_write_pwm(stiffness_DW.HILInitialize_Card_k,
        stiffness_P.HILInitialize_POChannels, 8U,
        &stiffness_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }

    if (stiffness_P.HILInitialize_POReset_d) {
      {
        int_T i1;
        real_T *dw_POValues = &stiffness_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = stiffness_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (stiffness_DW.HILInitialize_Card_k, stiffness_P.HILInitialize_POChannels,
         8U, &stiffness_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Atomic SubSystem: '<S55>/Bias Removal' */
  stiffness_BiasRemoval_Start(&stiffness_DW.BiasRemoval);

  /* End of Start for SubSystem: '<S55>/Bias Removal' */

  /* Start for Atomic SubSystem: '<S55>/Bias Removal1' */
  stiffness_BiasRemoval_Start(&stiffness_DW.BiasRemoval1);

  /* End of Start for SubSystem: '<S55>/Bias Removal1' */

  /* Start for Constant: '<S61>/x0' */
  stiffness_B.x0 = stiffness_P.x0_Value;

  /* Start for Constant: '<S62>/x0' */
  stiffness_B.x0_i = stiffness_P.x0_Value_a;

  /* InitializeConditions for Integrator: '<S61>/Integrator1' incorporates:
   *  Integrator: '<S62>/Integrator1'
   */
  if (rtmIsFirstInitCond(stiffness_M)) {
    stiffness_X.Integrator1_CSTATE = 0.0;
    stiffness_X.Integrator1_CSTATE_d = 0.0;
  }

  stiffness_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S61>/Integrator1' */

  /* InitializeConditions for Integrator: '<S61>/Integrator2' */
  stiffness_X.Integrator2_CSTATE = stiffness_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S62>/Integrator1' */
  stiffness_DW.Integrator1_IWORK_f = 1;

  /* InitializeConditions for Integrator: '<S62>/Integrator2' */
  stiffness_X.Integrator2_CSTATE_m = stiffness_P.Integrator2_IC_p;

  /* InitializeConditions for Derivative: '<S57>/Derivative' */
  stiffness_DW.TimeStampA = (rtInf);
  stiffness_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  stiffness_X.Filter_CSTATE[0] = stiffness_P.PDController_InitialConditionFo;
  stiffness_X.Filter_CSTATE[1] = stiffness_P.PDController_InitialConditionFo;

  /* SystemInitialize for Atomic SubSystem: '<S55>/Bias Removal' */
  stiffness_BiasRemoval_Init(&stiffness_B.BiasRemoval, &stiffness_DW.BiasRemoval,
    &stiffness_P.BiasRemoval);

  /* End of SystemInitialize for SubSystem: '<S55>/Bias Removal' */

  /* SystemInitialize for Atomic SubSystem: '<S55>/Bias Removal1' */
  stiffness_BiasRemoval_Init(&stiffness_B.BiasRemoval1,
    &stiffness_DW.BiasRemoval1, &stiffness_P.BiasRemoval1);

  /* End of SystemInitialize for SubSystem: '<S55>/Bias Removal1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(stiffness_M)) {
    rtmSetFirstInitCond(stiffness_M, 0);
  }
}

/* Model terminate function */
void stiffness_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S55>/HIL Initialize' */

  /* S-Function Block: stiffness/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(stiffness_DW.HILInitialize_Card);
    hil_monitor_stop_all(stiffness_DW.HILInitialize_Card);
    is_switching = false;
    if ((stiffness_P.HILInitialize_AOTerminate && !is_switching) ||
        (stiffness_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(stiffness_DW.HILInitialize_Card,
        &stiffness_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &stiffness_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stiffness_M, _rt_error_message);
      }
    }

    hil_task_delete_all(stiffness_DW.HILInitialize_Card);
    hil_monitor_delete_all(stiffness_DW.HILInitialize_Card);
    hil_close(stiffness_DW.HILInitialize_Card);
    stiffness_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (hil_initialize_block): '<S57>/HIL Initialize' */

  /* S-Function Block: stiffness/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(stiffness_DW.HILInitialize_Card_k);
    hil_monitor_stop_all(stiffness_DW.HILInitialize_Card_k);
    is_switching = false;
    if ((stiffness_P.HILInitialize_AOTerminate_g && !is_switching) ||
        (stiffness_P.HILInitialize_AOExit_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &stiffness_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = stiffness_P.HILInitialize_AOFinal_m;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((stiffness_P.HILInitialize_POTerminate_a && !is_switching) ||
        (stiffness_P.HILInitialize_POExit_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &stiffness_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = stiffness_P.HILInitialize_POFinal_c;
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
      result = hil_write(stiffness_DW.HILInitialize_Card_k
                         , stiffness_P.HILInitialize_AOChannels_p,
                         num_final_analog_outputs
                         , stiffness_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &stiffness_DW.HILInitialize_AOVoltages_a[0]
                         , &stiffness_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(stiffness_DW.HILInitialize_Card_k,
            stiffness_P.HILInitialize_AOChannels_p, num_final_analog_outputs,
            &stiffness_DW.HILInitialize_AOVoltages_a[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(stiffness_DW.HILInitialize_Card_k,
            stiffness_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &stiffness_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(stiffness_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(stiffness_DW.HILInitialize_Card_k);
    hil_monitor_delete_all(stiffness_DW.HILInitialize_Card_k);
    hil_close(stiffness_DW.HILInitialize_Card_k);
    stiffness_DW.HILInitialize_Card_k = NULL;
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
  stiffness_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  stiffness_update(tid);
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
  stiffness_initialize();
}

void MdlTerminate(void)
{
  stiffness_terminate();
}

/* Registration function */
RT_MODEL_stiffness_T *stiffness(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)stiffness_M, 0,
                sizeof(RT_MODEL_stiffness_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&stiffness_M->solverInfo,
                          &stiffness_M->Timing.simTimeStep);
    rtsiSetTPtr(&stiffness_M->solverInfo, &rtmGetTPtr(stiffness_M));
    rtsiSetStepSizePtr(&stiffness_M->solverInfo, &stiffness_M->Timing.stepSize0);
    rtsiSetdXPtr(&stiffness_M->solverInfo, &stiffness_M->derivs);
    rtsiSetContStatesPtr(&stiffness_M->solverInfo, (real_T **)
                         &stiffness_M->contStates);
    rtsiSetNumContStatesPtr(&stiffness_M->solverInfo,
      &stiffness_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&stiffness_M->solverInfo,
      &stiffness_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&stiffness_M->solverInfo,
      &stiffness_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&stiffness_M->solverInfo,
      &stiffness_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&stiffness_M->solverInfo, (&rtmGetErrorStatus
      (stiffness_M)));
    rtsiSetRTModelPtr(&stiffness_M->solverInfo, stiffness_M);
  }

  rtsiSetSimTimeStep(&stiffness_M->solverInfo, MAJOR_TIME_STEP);
  stiffness_M->intgData.f[0] = stiffness_M->odeF[0];
  stiffness_M->contStates = ((real_T *) &stiffness_X);
  rtsiSetSolverData(&stiffness_M->solverInfo, (void *)&stiffness_M->intgData);
  rtsiSetSolverName(&stiffness_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = stiffness_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "stiffness_M points to
       static memory which is guaranteed to be non-NULL" */
    stiffness_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    stiffness_M->Timing.sampleTimes = (&stiffness_M->Timing.sampleTimesArray[0]);
    stiffness_M->Timing.offsetTimes = (&stiffness_M->Timing.offsetTimesArray[0]);

    /* task periods */
    stiffness_M->Timing.sampleTimes[0] = (0.0);
    stiffness_M->Timing.sampleTimes[1] = (0.002);
    stiffness_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    stiffness_M->Timing.offsetTimes[0] = (0.0);
    stiffness_M->Timing.offsetTimes[1] = (0.0);
    stiffness_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(stiffness_M, &stiffness_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = stiffness_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = stiffness_M->Timing.perTaskSampleHitsArray;
    stiffness_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    stiffness_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(stiffness_M, 10.0);
  stiffness_M->Timing.stepSize0 = 0.002;
  stiffness_M->Timing.stepSize1 = 0.002;
  stiffness_M->Timing.stepSize2 = 0.02;
  rtmSetFirstInitCond(stiffness_M, 1);

  /* External mode info */
  stiffness_M->Sizes.checksums[0] = (2849769843U);
  stiffness_M->Sizes.checksums[1] = (1309040723U);
  stiffness_M->Sizes.checksums[2] = (3385562158U);
  stiffness_M->Sizes.checksums[3] = (764540372U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    stiffness_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &stiffness_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB;
    systemRan[4] = (sysRanDType *)
      &stiffness_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy;
    systemRan[5] = (sysRanDType *)
      &stiffness_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs;
    systemRan[6] = (sysRanDType *)
      &stiffness_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &stiffness_DW.BiasRemoval1.EnabledMovingAverage_SubsysRanB;
    systemRan[9] = (sysRanDType *)
      &stiffness_DW.BiasRemoval1.SwitchCaseActionSubsystem_Subsy;
    systemRan[10] = (sysRanDType *)
      &stiffness_DW.BiasRemoval1.SwitchCaseActionSubsystem1_Subs;
    systemRan[11] = (sysRanDType *)
      &stiffness_DW.BiasRemoval1.SwitchCaseActionSubsystem2_Subs;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(stiffness_M->extModeInfo,
      &stiffness_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(stiffness_M->extModeInfo, stiffness_M->Sizes.checksums);
    rteiSetTPtr(stiffness_M->extModeInfo, rtmGetTPtr(stiffness_M));
  }

  stiffness_M->solverInfoPtr = (&stiffness_M->solverInfo);
  stiffness_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&stiffness_M->solverInfo, 0.002);
  rtsiSetSolverMode(&stiffness_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  stiffness_M->blockIO = ((void *) &stiffness_B);
  (void) memset(((void *) &stiffness_B), 0,
                sizeof(B_stiffness_T));

  /* parameters */
  stiffness_M->defaultParam = ((real_T *)&stiffness_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &stiffness_X;
    stiffness_M->contStates = (x);
    (void) memset((void *)&stiffness_X, 0,
                  sizeof(X_stiffness_T));
  }

  /* states (dwork) */
  stiffness_M->dwork = ((void *) &stiffness_DW);
  (void) memset((void *)&stiffness_DW, 0,
                sizeof(DW_stiffness_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    stiffness_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  stiffness_M->Sizes.numContStates = (6);/* Number of continuous states */
  stiffness_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  stiffness_M->Sizes.numY = (0);       /* Number of model outputs */
  stiffness_M->Sizes.numU = (0);       /* Number of model inputs */
  stiffness_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  stiffness_M->Sizes.numSampTimes = (3);/* Number of sample times */
  stiffness_M->Sizes.numBlocks = (94); /* Number of blocks */
  stiffness_M->Sizes.numBlockIO = (36);/* Number of block outputs */
  stiffness_M->Sizes.numBlockPrms = (223);/* Sum of parameter "widths" */
  return stiffness_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
