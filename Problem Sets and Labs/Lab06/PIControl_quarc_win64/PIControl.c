/*
 * PIControl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PIControl".
 *
 * Model version              : 8.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Apr 14 13:17:51 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIControl.h"
#include "PIControl_private.h"
#include "PIControl_dt.h"

/* Block signals (default storage) */
B_PIControl_T PIControl_B;

/* Continuous states */
X_PIControl_T PIControl_X;

/* Block states (default storage) */
DW_PIControl_T PIControl_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PIControl_T PIControl_PrevZCX;

/* Real-time model */
static RT_MODEL_PIControl_T PIControl_M_;
RT_MODEL_PIControl_T *const PIControl_M = &PIControl_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(PIControl_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(PIControl_M, 2);
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
  if (PIControl_M->Timing.TaskCounters.TID[1] == 0) {
    PIControl_M->Timing.RateInteraction.TID1_2 =
      (PIControl_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    PIControl_M->Timing.perTaskSampleHits[5] =
      PIControl_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PIControl_M->Timing.TaskCounters.TID[2])++;
  if ((PIControl_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.02s, 0.0s] */
    PIControl_M->Timing.TaskCounters.TID[2] = 0;
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
  PIControl_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for atomic system:
 *    '<S56>/Bias Removal'
 *    '<S56>/Bias Removal1'
 */
void PIControl_BiasRemoval_Init(B_BiasRemoval_PIControl_T *localB,
  DW_BiasRemoval_PIControl_T *localDW, P_BiasRemoval_PIControl_T *localP)
{
  /* SystemInitialize for Enabled SubSystem: '<S60>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )' */
  localDW->Sumk1n1xk_DSTATE = localP->Sumk1n1xk_InitialCondition;

  /* SystemInitialize for Product: '<S64>/div' incorporates:
   *  Outport: '<S64>/x_avg_n'
   */
  localB->div = localP->x_avg_n_Y0;

  /* End of SystemInitialize for SubSystem: '<S60>/Enabled Moving Average' */

  /* SystemInitialize for IfAction SubSystem: '<S60>/Switch Case Action Subsystem' */
  /* SystemInitialize for Outport: '<S65>/zero' incorporates:
   *  Constant: '<S65>/Constant'
   */
  localB->Constant = localP->zero_Y0;

  /* End of SystemInitialize for SubSystem: '<S60>/Switch Case Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S60>/Switch Case Action Subsystem1' */
  /* SystemInitialize for Outport: '<S66>/Vbiased' incorporates:
   *  Inport: '<S66>/Vin'
   */
  localB->Vin = localP->Vbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S60>/Switch Case Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S60>/Switch Case Action Subsystem2' */
  /* SystemInitialize for Outport: '<S67>/Vunbiased' incorporates:
   *  Inport: '<S67>/V-Vavg'
   */
  localB->VVavg = localP->Vunbiased_Y0;

  /* End of SystemInitialize for SubSystem: '<S60>/Switch Case Action Subsystem2' */
}

/*
 * Start for atomic system:
 *    '<S56>/Bias Removal'
 *    '<S56>/Bias Removal1'
 */
void PIControl_BiasRemoval_Start(DW_BiasRemoval_PIControl_T *localDW)
{
  /* Start for Enabled SubSystem: '<S60>/Enabled Moving Average' */
  localDW->EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S60>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S60>/Switch Case' */
  localDW->SwitchCase_ActiveSubsystem = -1;
}

/*
 * Outputs for atomic system:
 *    '<S56>/Bias Removal'
 *    '<S56>/Bias Removal1'
 */
void PIControl_BiasRemoval(RT_MODEL_PIControl_T * const PIControl_M, real_T
  rtu_V, real_T rtp_switch_id, real_T rtp_start_time, real_T rtp_end_time,
  B_BiasRemoval_PIControl_T *localB, DW_BiasRemoval_PIControl_T *localDW,
  P_BiasRemoval_PIControl_T *localP)
{
  real_T rtb_Stepend_time;
  real_T rtb_Sum_p;
  real_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Step: '<S60>/Step: end_time' incorporates:
   *  Step: '<S60>/Step: start_time'
   */
  tmp = PIControl_M->Timing.t[1];
  if (tmp < rtp_end_time) {
    rtb_Stepend_time = localP->Stepend_time_Y0;
  } else {
    rtb_Stepend_time = localP->Stepend_time_YFinal;
  }

  /* End of Step: '<S60>/Step: end_time' */

  /* Step: '<S60>/Step: start_time' */
  if (tmp < rtp_start_time) {
    tmp = localP->Stepstart_time_Y0;
  } else {
    tmp = localP->Stepstart_time_YFinal;
  }

  /* Outputs for Enabled SubSystem: '<S60>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  /* Logic: '<S60>/Logical Operator' incorporates:
   *  Logic: '<S60>/Logical Operator1'
   */
  if ((tmp != 0.0) && (!(rtb_Stepend_time != 0.0))) {
    if (!localDW->EnabledMovingAverage_MODE) {
      /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
      localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )' */
      localDW->Sumk1n1xk_DSTATE = localP->Sumk1n1xk_InitialCondition;
      localDW->EnabledMovingAverage_MODE = true;
    }

    /* Sum: '<S68>/Count' incorporates:
     *  Constant: '<S68>/unity'
     *  UnitDelay: '<S68>/Unit Delay'
     */
    localB->Count = localP->unity_Value + localDW->UnitDelay_DSTATE;

    /* Sum: '<S64>/Sum' incorporates:
     *  UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )'
     */
    localB->Sum = rtu_V + localDW->Sumk1n1xk_DSTATE;

    /* Product: '<S64>/div' */
    localB->div = localB->Sum / localB->Count;
    srUpdateBC(localDW->EnabledMovingAverage_SubsysRanB);
  } else {
    localDW->EnabledMovingAverage_MODE = false;
  }

  /* End of Logic: '<S60>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S60>/Enabled Moving Average' */

  /* Sum: '<S60>/Sum' */
  rtb_Sum_p = rtu_V - localB->div;

  /* SwitchCase: '<S60>/Switch Case' incorporates:
   *  Constant: '<S60>/Constant'
   *  Constant: '<S65>/Constant'
   *  Inport: '<S66>/Vin'
   *  Inport: '<S67>/V-Vavg'
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
      /* Disable for Outport: '<S65>/zero' incorporates:
       *  Constant: '<S65>/Constant'
       * */
      localB->Constant = localP->zero_Y0;
      break;

     case 1:
      /* Disable for Outport: '<S66>/Vbiased' incorporates:
       *  Inport: '<S66>/Vin'
       * */
      localB->Vin = localP->Vbiased_Y0;
      break;

     case 2:
      /* Disable for Outport: '<S67>/Vunbiased' incorporates:
       *  Inport: '<S67>/V-Vavg'
       * */
      localB->VVavg = localP->Vunbiased_Y0;
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S60>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S65>/Action Port'
     */
    localB->Constant = localP->Constant_Value;
    srUpdateBC(localDW->SwitchCaseActionSubsystem_Subsy);

    /* End of Outputs for SubSystem: '<S60>/Switch Case Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S60>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    localB->Vin = rtu_V;
    srUpdateBC(localDW->SwitchCaseActionSubsystem1_Subs);

    /* End of Outputs for SubSystem: '<S60>/Switch Case Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S60>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    localB->VVavg = rtb_Sum_p;
    srUpdateBC(localDW->SwitchCaseActionSubsystem2_Subs);

    /* End of Outputs for SubSystem: '<S60>/Switch Case Action Subsystem2' */
    break;
  }

  /* End of SwitchCase: '<S60>/Switch Case' */

  /* Switch: '<S60>/Switch' incorporates:
   *  Logic: '<S60>/Logical Operator2'
   */
  if (!(rtb_Stepend_time != 0.0)) {
    /* Switch: '<S60>/Switch' incorporates:
     *  Sum: '<S60>/Sum1'
     */
    localB->Switch = (localB->Constant + localB->Vin) + localB->VVavg;
  } else {
    /* Switch: '<S60>/Switch' */
    localB->Switch = rtb_Sum_p;
  }

  /* End of Switch: '<S60>/Switch' */
}

/*
 * Update for atomic system:
 *    '<S56>/Bias Removal'
 *    '<S56>/Bias Removal1'
 */
void PIContro_BiasRemoval_Update(B_BiasRemoval_PIControl_T *localB,
  DW_BiasRemoval_PIControl_T *localDW)
{
  /* Update for Enabled SubSystem: '<S60>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  if (localDW->EnabledMovingAverage_MODE) {
    /* Update for UnitDelay: '<S68>/Unit Delay' */
    localDW->UnitDelay_DSTATE = localB->Count;

    /* Update for UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )' */
    localDW->Sumk1n1xk_DSTATE = localB->Sum;
  }

  /* End of Update for SubSystem: '<S60>/Enabled Moving Average' */
}

/* Model output function for TID0 */
void PIControl_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog_o1;
  real_T rtb_HILReadAnalog_o2;
  real_T rtb_HILReadAnalog[2];
  real_T (*lastU)[2];
  real_T F0_tmp;
  real_T lastTime_tmp;
  real_T rtb_Clock_tmp;
  real_T rtb_Derivative1_idx_0;
  real_T rtb_Derivative1_idx_1;
  real_T rtb_Derivative2_idx_0;
  real_T rtb_Derivative2_idx_1;
  real_T rtb_Filter_idx_0;
  real_T rtb_Filter_idx_0_tmp;
  real_T rtb_Filter_idx_0_tmp_0;
  real_T x_f_tmp;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* set solver stop time */
    if (!(PIControl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PIControl_M->solverInfo,
                            ((PIControl_M->Timing.clockTickH0 + 1) *
        PIControl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PIControl_M->solverInfo,
                            ((PIControl_M->Timing.clockTick0 + 1) *
        PIControl_M->Timing.stepSize0 + PIControl_M->Timing.clockTickH0 *
        PIControl_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PIControl_M)) {
    PIControl_M->Timing.t[0] = rtsiGetT(&PIControl_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PIControl_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PIControl_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PIControl_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PIControl_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* S-Function (hil_read_analog_block): '<S56>/HIL Read Analog' */

    /* S-Function Block: PIControl/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(PIControl_DW.HILInitialize_Card,
        PIControl_P.HILReadAnalog_channels, 2,
        &PIControl_DW.HILReadAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
      }

      rtb_HILReadAnalog_o1 = PIControl_DW.HILReadAnalog_Buffer[0];
      rtb_HILReadAnalog_o2 = PIControl_DW.HILReadAnalog_Buffer[1];
    }

    /* Gain: '<S56>/X Gain (N//V)' */
    PIControl_B.XGainNV = PIControl_P.XGainNV_Gain * rtb_HILReadAnalog_o1;

    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal' */
    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal' */
    PIControl_BiasRemoval(PIControl_M, PIControl_B.XGainNV,
                          PIControl_P.BiasRemoval_switch_id,
                          PIControl_P.BiasRemoval_start_time,
                          PIControl_P.BiasRemoval_end_time,
                          &PIControl_B.BiasRemoval, &PIControl_DW.BiasRemoval,
                          &PIControl_P.BiasRemoval);

    /* End of Outputs for SubSystem: '<S56>/Bias Removal' */
    /* End of Outputs for SubSystem: '<S56>/Bias Removal' */

    /* Gain: '<S56>/Y Gain (N//V)' */
    PIControl_B.YGainNV = PIControl_P.YGainNV_Gain * rtb_HILReadAnalog_o2;

    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal1' */
    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal1' */
    PIControl_BiasRemoval(PIControl_M, PIControl_B.YGainNV,
                          PIControl_P.BiasRemoval1_switch_id,
                          PIControl_P.BiasRemoval1_start_time,
                          PIControl_P.BiasRemoval1_end_time,
                          &PIControl_B.BiasRemoval1, &PIControl_DW.BiasRemoval1,
                          &PIControl_P.BiasRemoval1);

    /* End of Outputs for SubSystem: '<S56>/Bias Removal1' */
    /* End of Outputs for SubSystem: '<S56>/Bias Removal1' */

    /* Constant: '<S62>/x0' */
    PIControl_B.x0 = PIControl_P.x0_Value;
  }

  /* Integrator: '<S62>/Integrator1' */
  if (PIControl_DW.Integrator1_IWORK != 0) {
    PIControl_X.Integrator1_CSTATE = PIControl_B.x0;
  }

  /* Integrator: '<S62>/Integrator1' */
  PIControl_B.Integrator1 = PIControl_X.Integrator1_CSTATE;

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S62>/wn'
   *  Constant: '<S62>/zt'
   *  Integrator: '<S62>/Integrator2'
   *  Product: '<S62>/Product2'
   *  Sum: '<S62>/Sum'
   *  Sum: '<S62>/Sum1'
   */
  PIControl_B.Product = ((PIControl_B.BiasRemoval.Switch -
    PIControl_B.Integrator1) - PIControl_X.Integrator2_CSTATE *
    PIControl_P.Constant_Value * PIControl_P.SecondOrderLowPassFilter_inpu_h) *
    PIControl_P.SecondOrderLowPassFilter_input_;

  /* Product: '<S62>/Product1' incorporates:
   *  Constant: '<S62>/wn'
   *  Integrator: '<S62>/Integrator2'
   */
  PIControl_B.Product1 = PIControl_P.SecondOrderLowPassFilter_input_ *
    PIControl_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* Constant: '<S63>/x0' */
    PIControl_B.x0_h = PIControl_P.x0_Value_d;
  }

  /* Integrator: '<S63>/Integrator1' */
  if (PIControl_DW.Integrator1_IWORK_b != 0) {
    PIControl_X.Integrator1_CSTATE_l = PIControl_B.x0_h;
  }

  /* Integrator: '<S63>/Integrator1' */
  PIControl_B.Integrator1_c = PIControl_X.Integrator1_CSTATE_l;

  /* Product: '<S63>/Product' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S63>/wn'
   *  Constant: '<S63>/zt'
   *  Integrator: '<S63>/Integrator2'
   *  Product: '<S63>/Product2'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S63>/Sum1'
   */
  PIControl_B.Product_i = ((PIControl_B.BiasRemoval1.Switch -
    PIControl_B.Integrator1_c) - PIControl_X.Integrator2_CSTATE_j *
    PIControl_P.Constant_Value_j * PIControl_P.SecondOrderLowPassFilter1_inp_n) *
    PIControl_P.SecondOrderLowPassFilter1_input;

  /* Product: '<S63>/Product1' incorporates:
   *  Constant: '<S63>/wn'
   *  Integrator: '<S63>/Integrator2'
   */
  PIControl_B.Product1_k = PIControl_P.SecondOrderLowPassFilter1_input *
    PIControl_X.Integrator2_CSTATE_j;
  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* S-Function (hil_read_encoder_block): '<S58>/HIL Read Encoder' */

    /* S-Function Block: PIControl/Robot and Environment Subsystem/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILReadEncoder_channels, 2,
        &PIControl_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = PIControl_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = PIControl_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S58>/Encoder Gain' incorporates:
     *  Constant: '<S58>/Home Position'
     *  Sum: '<S58>/Sum1'
     */
    PIControl_B.EncoderGain[0] = (PIControl_P.HomePosition_Value[0] +
      rtb_HILReadAnalog[0]) * PIControl_P.EncoderGain_Gain[0];
    PIControl_B.EncoderGain[1] = (PIControl_P.HomePosition_Value[1] +
      rtb_HILReadAnalog[1]) * PIControl_P.EncoderGain_Gain[1];

    /* Constant: '<Root>/Speed' */
    PIControl_B.Speed = PIControl_P.Speed_Value;
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Derivative: '<S5>/Derivative'
   *  Derivative: '<S5>/Derivative1'
   *  Derivative: '<S5>/Derivative2'
   */
  rtb_Clock_tmp = PIControl_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Desired Position' incorporates:
   *  Clock: '<Root>/Clock'
   */
  /* MATLAB Function 'Desired Position': '<S1>:1' */
  /* '<S1>:1:6' */
  /* '<S1>:1:7' */
  if (rtb_Clock_tmp < 2.0) {
    /* '<S1>:1:9' */
    /* '<S1>:1:10' */
    x_f_tmp = 1.0 - cos(3.1415926535897931 * rtb_Clock_tmp / 2.0);
    PIControl_B.x_f[0] = x_f_tmp * 0.0375 + 0.22;

    /* '<S1>:1:11' */
    PIControl_B.x_f[1] = 0.15 - x_f_tmp * 0.105;
  } else if (rtb_Clock_tmp < 2.5) {
    /* '<S1>:1:12' */
    /* '<S1>:1:13' */
    PIControl_B.x_f[0] = (cos((rtb_Clock_tmp - 2.0) * (rtb_Clock_tmp - 2.0) *
      (6.2831853071795862 * PIControl_B.Speed)) * 0.075 + 0.15) + 0.07;

    /* '<S1>:1:14' */
    PIControl_B.x_f[1] = -0.06;
  } else {
    /* '<S1>:1:16' */
    PIControl_B.x_f[0] = (cos(6.2831853071795862 * PIControl_B.Speed *
      (rtb_Clock_tmp - 2.25)) * 0.075 + 0.15) + 0.07;

    /* '<S1>:1:17' */
    PIControl_B.x_f[1] = -0.06;
  }

  /* End of MATLAB Function: '<Root>/Desired Position' */

  /* Derivative: '<S5>/Derivative' */
  if ((PIControl_DW.TimeStampA_b >= rtb_Clock_tmp) && (PIControl_DW.TimeStampB_g
       >= rtb_Clock_tmp)) {
    /* Derivative: '<S5>/Derivative' */
    PIControl_B.Derivative[0] = 0.0;
    PIControl_B.Derivative[1] = 0.0;
  } else {
    rtb_Filter_idx_0 = PIControl_DW.TimeStampA_b;
    lastU = &PIControl_DW.LastUAtTimeA_e;
    if (PIControl_DW.TimeStampA_b < PIControl_DW.TimeStampB_g) {
      if (PIControl_DW.TimeStampB_g < rtb_Clock_tmp) {
        rtb_Filter_idx_0 = PIControl_DW.TimeStampB_g;
        lastU = &PIControl_DW.LastUAtTimeB_a;
      }
    } else if (PIControl_DW.TimeStampA_b >= rtb_Clock_tmp) {
      rtb_Filter_idx_0 = PIControl_DW.TimeStampB_g;
      lastU = &PIControl_DW.LastUAtTimeB_a;
    }

    rtb_Filter_idx_0 = rtb_Clock_tmp - rtb_Filter_idx_0;

    /* Derivative: '<S5>/Derivative' */
    PIControl_B.Derivative[0] = (PIControl_B.x_f[0] - (*lastU)[0]) /
      rtb_Filter_idx_0;
    PIControl_B.Derivative[1] = (PIControl_B.x_f[1] - (*lastU)[1]) /
      rtb_Filter_idx_0;
  }

  /* Derivative: '<S5>/Derivative1' */
  if ((PIControl_DW.TimeStampA_n >= rtb_Clock_tmp) && (PIControl_DW.TimeStampB_k
       >= rtb_Clock_tmp)) {
    rtb_Derivative1_idx_0 = 0.0;
    rtb_Derivative1_idx_1 = 0.0;
  } else {
    rtb_Filter_idx_0 = PIControl_DW.TimeStampA_n;
    lastU = &PIControl_DW.LastUAtTimeA_k;
    if (PIControl_DW.TimeStampA_n < PIControl_DW.TimeStampB_k) {
      if (PIControl_DW.TimeStampB_k < rtb_Clock_tmp) {
        rtb_Filter_idx_0 = PIControl_DW.TimeStampB_k;
        lastU = &PIControl_DW.LastUAtTimeB_l;
      }
    } else if (PIControl_DW.TimeStampA_n >= rtb_Clock_tmp) {
      rtb_Filter_idx_0 = PIControl_DW.TimeStampB_k;
      lastU = &PIControl_DW.LastUAtTimeB_l;
    }

    rtb_Filter_idx_0 = rtb_Clock_tmp - rtb_Filter_idx_0;
    rtb_Derivative1_idx_0 = (PIControl_B.Derivative[0] - (*lastU)[0]) /
      rtb_Filter_idx_0;
    rtb_Derivative1_idx_1 = (PIControl_B.Derivative[1] - (*lastU)[1]) /
      rtb_Filter_idx_0;
  }

  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* MATLAB Function: '<S6>/Forward Kinematics' incorporates:
     *  Gain: '<S58>/Encoder Gain'
     */
    /* MATLAB Function 'Robot and Environment Subsystem/Forward Kinematics': '<S57>:1' */
    /* '<S57>:1:5' */
    /* '<S57>:1:6' */
    /* '<S57>:1:8' */
    PIControl_B.x[0] = 0.15 * cos(PIControl_B.EncoderGain[0]) + 0.22 * cos
      (PIControl_B.EncoderGain[1]);

    /* '<S57>:1:9' */
    PIControl_B.x[1] = 0.15 * sin(PIControl_B.EncoderGain[0]) + 0.22 * sin
      (PIControl_B.EncoderGain[1]);
  }

  /* Sum: '<S5>/Sum2' */
  PIControl_B.Sum2[0] = PIControl_B.x_f[0] - PIControl_B.x[0];
  PIControl_B.Sum2[1] = PIControl_B.x_f[1] - PIControl_B.x[1];

  /* Derivative: '<S5>/Derivative2' */
  if ((PIControl_DW.TimeStampA_k >= rtb_Clock_tmp) && (PIControl_DW.TimeStampB_j
       >= rtb_Clock_tmp)) {
    rtb_Derivative2_idx_0 = 0.0;
    rtb_Derivative2_idx_1 = 0.0;
  } else {
    rtb_Filter_idx_0 = PIControl_DW.TimeStampA_k;
    lastU = &PIControl_DW.LastUAtTimeA_p;
    if (PIControl_DW.TimeStampA_k < PIControl_DW.TimeStampB_j) {
      if (PIControl_DW.TimeStampB_j < rtb_Clock_tmp) {
        rtb_Filter_idx_0 = PIControl_DW.TimeStampB_j;
        lastU = &PIControl_DW.LastUAtTimeB_m;
      }
    } else if (PIControl_DW.TimeStampA_k >= rtb_Clock_tmp) {
      rtb_Filter_idx_0 = PIControl_DW.TimeStampB_j;
      lastU = &PIControl_DW.LastUAtTimeB_m;
    }

    rtb_Filter_idx_0 = rtb_Clock_tmp - rtb_Filter_idx_0;
    rtb_Derivative2_idx_0 = (PIControl_B.x[0] - (*lastU)[0]) / rtb_Filter_idx_0;
    rtb_Derivative2_idx_1 = (PIControl_B.x[1] - (*lastU)[1]) / rtb_Filter_idx_0;
  }

  /* Step: '<S5>/Desired Force' incorporates:
   *  Step: '<S5>/Reset Integrator'
   */
  lastTime_tmp = PIControl_M->Timing.t[0];

  /* MATLAB Function: '<S6>/Rotation to Base Frame' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  SignalConversion generated from: '<S59>/ SFunction '
   */
  /* MATLAB Function 'Robot and Environment Subsystem/Rotation to Base Frame': '<S59>:1' */
  /* '<S59>:1:7' */
  /* '<S59>:1:11' */
  x_f_tmp = sin(PIControl_B.EncoderGain[1]);
  F0_tmp = cos(PIControl_B.EncoderGain[1]);
  PIControl_B.F0[0] = 0.0;
  PIControl_B.F0[0] += F0_tmp * PIControl_B.Integrator1;
  PIControl_B.F0[0] += -x_f_tmp * PIControl_B.Integrator1_c;

  /* Step: '<S5>/Desired Force' */
  if (lastTime_tmp < PIControl_P.DesiredForce_Time) {
    rtb_Filter_idx_0 = PIControl_P.DesiredForce_Y0;
  } else {
    rtb_Filter_idx_0 = PIControl_P.DesiredForce_YFinal[0];
  }

  /* Sum: '<S5>/Sum1' */
  PIControl_B.Sum1[0] = rtb_Filter_idx_0 - PIControl_B.F0[0];

  /* MATLAB Function: '<S6>/Rotation to Base Frame' incorporates:
   *  SignalConversion generated from: '<S59>/ SFunction '
   */
  PIControl_B.F0[1] = 0.0;
  PIControl_B.F0[1] += x_f_tmp * PIControl_B.Integrator1;
  PIControl_B.F0[1] += F0_tmp * PIControl_B.Integrator1_c;

  /* Step: '<S5>/Desired Force' */
  if (lastTime_tmp < PIControl_P.DesiredForce_Time) {
    rtb_Filter_idx_0 = PIControl_P.DesiredForce_Y0;
  } else {
    rtb_Filter_idx_0 = PIControl_P.DesiredForce_YFinal[1];
  }

  /* Sum: '<S5>/Sum1' */
  PIControl_B.Sum1[1] = rtb_Filter_idx_0 - PIControl_B.F0[1];

  /* Step: '<S5>/Reset Integrator' */
  if (lastTime_tmp < PIControl_P.ResetIntegrator_Time) {
    /* Step: '<S5>/Reset Integrator' */
    PIControl_B.ResetIntegrator = PIControl_P.ResetIntegrator_Y0;
  } else {
    /* Step: '<S5>/Reset Integrator' */
    PIControl_B.ResetIntegrator = PIControl_P.ResetIntegrator_YFinal;
  }

  /* Integrator: '<S5>/Integrator' */
  if (rtmIsMajorTimeStep(PIControl_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &PIControl_PrevZCX.Integrator_Reset_ZCE,
                       (PIControl_B.ResetIntegrator));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      PIControl_X.Integrator_CSTATE[0] = PIControl_P.Integrator_IC;
      PIControl_X.Integrator_CSTATE[1] = PIControl_P.Integrator_IC;
    }
  }

  /* Sum: '<S4>/Sum2' */
  lastTime_tmp = PIControl_B.x_f[0] - PIControl_B.x[0];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<S34>/SumD'
   */
  PIControl_B.FilterCoefficient[0] = (PIControl_P.PDController_D[0] *
    lastTime_tmp - PIControl_X.Filter_CSTATE[0]) * PIControl_P.PDController_N;

  /* Sum: '<S4>/Sum2' */
  rtb_Filter_idx_0 = lastTime_tmp;
  lastTime_tmp = PIControl_B.x_f[1] - PIControl_B.x[1];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<S34>/SumD'
   */
  PIControl_B.FilterCoefficient[1] = (PIControl_P.PDController_D[1] *
    lastTime_tmp - PIControl_X.Filter_CSTATE[1]) * PIControl_P.PDController_N;

  /* Switch: '<Root>/Switch' incorporates:
   *  Clock: '<Root>/Clock'
   *  Gain: '<S44>/Proportional Gain'
   *  Gain: '<S5>/ P Gain'
   *  Gain: '<S5>/D Gain'
   *  Gain: '<S5>/I-S'
   *  Gain: '<S5>/S'
   *  Sum: '<S48>/Sum'
   *  Sum: '<S5>/Sum'
   */
  if (rtb_Clock_tmp > PIControl_P.Switch_Threshold) {
    /* Sum: '<S5>/Sum3' incorporates:
     *  Gain: '<S5>/I Gain'
     *  Gain: '<S5>/Kf Gain'
     *  Integrator: '<S5>/Integrator'
     */
    rtb_Clock_tmp = PIControl_P.KfGain_Gain * PIControl_B.Sum1[0] +
      PIControl_P.IGain_Gain * PIControl_X.Integrator_CSTATE[0];
    lastTime_tmp = PIControl_P.KfGain_Gain * PIControl_B.Sum1[1] +
      PIControl_P.IGain_Gain * PIControl_X.Integrator_CSTATE[1];

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/ P Gain'
     *  Gain: '<S5>/S'
     */
    rtb_Filter_idx_0_tmp = PIControl_P.PGain_Gain * PIControl_B.Sum2[0];
    rtb_Filter_idx_0_tmp_0 = PIControl_P.PGain_Gain * PIControl_B.Sum2[1];
    rtb_Filter_idx_0 = (((rtb_Filter_idx_0_tmp * PIControl_P.S_Gain[0] +
                          rtb_Filter_idx_0_tmp_0 * PIControl_P.S_Gain[2]) +
                         rtb_Derivative1_idx_0) - PIControl_P.DGain_Gain[0] *
                        rtb_Derivative2_idx_0) + (PIControl_P.IS_Gain[0] *
      rtb_Clock_tmp + PIControl_P.IS_Gain[2] * lastTime_tmp);
    rtb_Derivative1_idx_0 = (((rtb_Filter_idx_0_tmp * PIControl_P.S_Gain[1] +
      rtb_Filter_idx_0_tmp_0 * PIControl_P.S_Gain[3]) + rtb_Derivative1_idx_1) -
      PIControl_P.DGain_Gain[1] * rtb_Derivative2_idx_1) + (PIControl_P.IS_Gain
      [1] * rtb_Clock_tmp + PIControl_P.IS_Gain[3] * lastTime_tmp);
  } else {
    rtb_Filter_idx_0 = PIControl_P.PDController_P[0] * rtb_Filter_idx_0 +
      PIControl_B.FilterCoefficient[0];
    rtb_Derivative1_idx_0 = PIControl_P.PDController_P[1] * lastTime_tmp +
      PIControl_B.FilterCoefficient[1];
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<S6>/inv motor gain' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  /* MATLAB Function 'Jacobian Transpose': '<S3>:1' */
  /* '<S3>:1:4' */
  /* '<S3>:1:5' */
  /* '<S3>:1:7' */
  /* '<S3>:1:8' */
  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  /* '<S3>:1:12' */
  /* '<S3>:1:14' */
  /* MATLAB Function 'Feedback Comp': '<S2>:1' */
  /* '<S2>:1:5' */
  /* '<S2>:1:7' */
  /* '<S2>:1:8' */
  /* '<S2>:1:9' */
  /* '<S2>:1:10' */
  /* '<S2>:1:12' */
  /* '<S2>:1:14' */
  /* '<S2>:1:15' */
  /* '<S2>:1:17' */
  PIControl_B.current[0] = ((-0.15 * sin(PIControl_B.EncoderGain[0]) *
    rtb_Filter_idx_0 + 0.15 * cos(PIControl_B.EncoderGain[0]) *
    rtb_Derivative1_idx_0) + 0.2131892 * cos(PIControl_B.EncoderGain[0])) *
    PIControl_P.invmotorgain_Gain;

  /* Gain: '<S58>/1//AmpGain' incorporates:
   *  Bias: '<S58>/Amp Bias Tune for each amp if needed'
   */
  PIControl_B.uAmpGain[0] = (PIControl_B.current[0] +
    PIControl_P.AmpBiasTuneforeachampifneeded_B[0]) * PIControl_P.uAmpGain_Gain
    [0];

  /* Gain: '<S6>/inv motor gain' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  PIControl_B.current[1] = ((-0.22 * x_f_tmp * rtb_Filter_idx_0 + 0.22 * cos
    (PIControl_B.EncoderGain[1]) * rtb_Derivative1_idx_0) + 0.0796936 * F0_tmp) *
    PIControl_P.invmotorgain_Gain;

  /* Gain: '<S58>/1//AmpGain' incorporates:
   *  Bias: '<S58>/Amp Bias Tune for each amp if needed'
   */
  PIControl_B.uAmpGain[1] = (PIControl_B.current[1] +
    PIControl_P.AmpBiasTuneforeachampifneeded_B[1]) * PIControl_P.uAmpGain_Gain
    [1];
  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* S-Function (hil_write_analog_block): '<S58>/HIL Write Analog' */

    /* S-Function Block: PIControl/Robot and Environment Subsystem/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILWriteAnalog_channels, 2, &PIControl_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S58>/HIL Read Analog' */

    /* S-Function Block: PIControl/Robot and Environment Subsystem/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILReadAnalog_channels_c, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
      }
    }

    /* Gain: '<S58>/1//Sense Gain' */
    PIControl_B.uSenseGain[0] = PIControl_P.uSenseGain_Gain * rtb_HILReadAnalog
      [0];
    PIControl_B.uSenseGain[1] = PIControl_P.uSenseGain_Gain * rtb_HILReadAnalog
      [1];

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  Gain: '<S58>/Encoder Gain'
     */
    if (PIControl_M->Timing.RateInteraction.TID1_2) {
      PIControl_DW.RateTransition_Buffer[0] = PIControl_B.EncoderGain[0];
      PIControl_DW.RateTransition_Buffer[1] = PIControl_B.EncoderGain[1];
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Model update function for TID0 */
void PIControl_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];
  if (rtmIsMajorTimeStep(PIControl_M)) {
    /* Update for Atomic SubSystem: '<S56>/Bias Removal' */
    PIContro_BiasRemoval_Update(&PIControl_B.BiasRemoval,
      &PIControl_DW.BiasRemoval);

    /* End of Update for SubSystem: '<S56>/Bias Removal' */

    /* Update for Atomic SubSystem: '<S56>/Bias Removal1' */
    PIContro_BiasRemoval_Update(&PIControl_B.BiasRemoval1,
      &PIControl_DW.BiasRemoval1);

    /* End of Update for SubSystem: '<S56>/Bias Removal1' */
  }

  /* Update for Integrator: '<S62>/Integrator1' */
  PIControl_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S63>/Integrator1' */
  PIControl_DW.Integrator1_IWORK_b = 0;

  /* Update for Derivative: '<S58>/Derivative' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   */
  if (PIControl_DW.TimeStampA == (rtInf)) {
    PIControl_DW.TimeStampA = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA;
  } else if (PIControl_DW.TimeStampB == (rtInf)) {
    PIControl_DW.TimeStampB = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB;
  } else if (PIControl_DW.TimeStampA < PIControl_DW.TimeStampB) {
    PIControl_DW.TimeStampA = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA;
  } else {
    PIControl_DW.TimeStampB = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB;
  }

  (*lastU)[0] = PIControl_B.EncoderGain[0];
  (*lastU)[1] = PIControl_B.EncoderGain[1];

  /* End of Update for Derivative: '<S58>/Derivative' */

  /* Update for Derivative: '<S5>/Derivative' */
  if (PIControl_DW.TimeStampA_b == (rtInf)) {
    PIControl_DW.TimeStampA_b = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA_e;
  } else if (PIControl_DW.TimeStampB_g == (rtInf)) {
    PIControl_DW.TimeStampB_g = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB_a;
  } else if (PIControl_DW.TimeStampA_b < PIControl_DW.TimeStampB_g) {
    PIControl_DW.TimeStampA_b = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA_e;
  } else {
    PIControl_DW.TimeStampB_g = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB_a;
  }

  (*lastU)[0] = PIControl_B.x_f[0];
  (*lastU)[1] = PIControl_B.x_f[1];

  /* End of Update for Derivative: '<S5>/Derivative' */

  /* Update for Derivative: '<S5>/Derivative1' */
  if (PIControl_DW.TimeStampA_n == (rtInf)) {
    PIControl_DW.TimeStampA_n = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA_k;
  } else if (PIControl_DW.TimeStampB_k == (rtInf)) {
    PIControl_DW.TimeStampB_k = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB_l;
  } else if (PIControl_DW.TimeStampA_n < PIControl_DW.TimeStampB_k) {
    PIControl_DW.TimeStampA_n = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA_k;
  } else {
    PIControl_DW.TimeStampB_k = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB_l;
  }

  (*lastU)[0] = PIControl_B.Derivative[0];
  (*lastU)[1] = PIControl_B.Derivative[1];

  /* End of Update for Derivative: '<S5>/Derivative1' */

  /* Update for Derivative: '<S5>/Derivative2' */
  if (PIControl_DW.TimeStampA_k == (rtInf)) {
    PIControl_DW.TimeStampA_k = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA_p;
  } else if (PIControl_DW.TimeStampB_j == (rtInf)) {
    PIControl_DW.TimeStampB_j = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB_m;
  } else if (PIControl_DW.TimeStampA_k < PIControl_DW.TimeStampB_j) {
    PIControl_DW.TimeStampA_k = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeA_p;
  } else {
    PIControl_DW.TimeStampB_j = PIControl_M->Timing.t[0];
    lastU = &PIControl_DW.LastUAtTimeB_m;
  }

  (*lastU)[0] = PIControl_B.x[0];
  (*lastU)[1] = PIControl_B.x[1];

  /* End of Update for Derivative: '<S5>/Derivative2' */
  if (rtmIsMajorTimeStep(PIControl_M)) {
    rt_ertODEUpdateContinuousStates(&PIControl_M->solverInfo);
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
  if (!(++PIControl_M->Timing.clockTick0)) {
    ++PIControl_M->Timing.clockTickH0;
  }

  PIControl_M->Timing.t[0] = rtsiGetSolverStopTime(&PIControl_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PIControl_M->Timing.clockTick1)) {
    ++PIControl_M->Timing.clockTickH1;
  }

  PIControl_M->Timing.t[1] = PIControl_M->Timing.clockTick1 *
    PIControl_M->Timing.stepSize1 + PIControl_M->Timing.clockTickH1 *
    PIControl_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void PIControl_derivatives(void)
{
  XDot_PIControl_T *_rtXdot;
  _rtXdot = ((XDot_PIControl_T *) PIControl_M->derivs);

  /* Derivatives for Integrator: '<S62>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = PIControl_B.Product1;

  /* Derivatives for Integrator: '<S62>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = PIControl_B.Product;

  /* Derivatives for Integrator: '<S63>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_l = PIControl_B.Product1_k;

  /* Derivatives for Integrator: '<S63>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j = PIControl_B.Product_i;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = PIControl_B.Sum1[0];

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE[0] = PIControl_B.FilterCoefficient[0];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = PIControl_B.Sum1[1];

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE[1] = PIControl_B.FilterCoefficient[1];
}

/* Model output function for TID2 */
void PIControl_output2(void)           /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  PIControl_B.RateTransition[0] = PIControl_DW.RateTransition_Buffer[0];
  PIControl_B.RateTransition[1] = PIControl_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void PIControl_update2(void)           /* Sample time: [0.02s, 0.0s] */
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
  if (!(++PIControl_M->Timing.clockTick2)) {
    ++PIControl_M->Timing.clockTickH2;
  }

  PIControl_M->Timing.t[2] = PIControl_M->Timing.clockTick2 *
    PIControl_M->Timing.stepSize2 + PIControl_M->Timing.clockTickH2 *
    PIControl_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PIControl_output(int_T tid)
{
  switch (tid) {
   case 0 :
    PIControl_output0();
    break;

   case 2 :
    PIControl_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PIControl_update(int_T tid)
{
  switch (tid) {
   case 0 :
    PIControl_update0();
    break;

   case 2 :
    PIControl_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void PIControl_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S56>/HIL Initialize' */

  /* S-Function Block: PIControl/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6014", "0", &PIControl_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PIControl_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(PIControl_DW.HILInitialize_Card,
      "terminal_board=e_series", 24);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PIControl_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(PIControl_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PIControl_M, _rt_error_message);
      return;
    }

    if ((PIControl_P.HILInitialize_AOPStart && !is_switching) ||
        (PIControl_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(PIControl_DW.HILInitialize_Card,
        &PIControl_P.HILInitialize_AOChannels, 1U,
        &PIControl_P.HILInitialize_AOLow, &PIControl_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_AOStart && !is_switching) ||
        (PIControl_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(PIControl_DW.HILInitialize_Card,
        &PIControl_P.HILInitialize_AOChannels, 1U,
        &PIControl_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_initialize_block): '<S58>/HIL Initialize' */

  /* S-Function Block: PIControl/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &PIControl_DW.HILInitialize_Card_k);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PIControl_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(PIControl_DW.HILInitialize_Card_k,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PIControl_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(PIControl_DW.HILInitialize_Card_k);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PIControl_M, _rt_error_message);
      return;
    }

    if ((PIControl_P.HILInitialize_AIPStart_j && !is_switching) ||
        (PIControl_P.HILInitialize_AIPEnter_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &PIControl_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (PIControl_P.HILInitialize_AILow_m);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &PIControl_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = PIControl_P.HILInitialize_AIHigh_p;
        }
      }

      result = hil_set_analog_input_ranges(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_AIChannels, 8U,
        &PIControl_DW.HILInitialize_AIMinimums[0],
        &PIControl_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_AOPStart_b && !is_switching) ||
        (PIControl_P.HILInitialize_AOPEnter_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &PIControl_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (PIControl_P.HILInitialize_AOLow_n);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &PIControl_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = PIControl_P.HILInitialize_AOHigh_n;
        }
      }

      result = hil_set_analog_output_ranges(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_AOChannels_p, 8U,
        &PIControl_DW.HILInitialize_AOMinimums[0],
        &PIControl_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_AOStart_k && !is_switching) ||
        (PIControl_P.HILInitialize_AOEnter_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PIControl_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PIControl_P.HILInitialize_AOInitial_b;
        }
      }

      result = hil_write_analog(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_AOChannels_p, 8U,
        &PIControl_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if (PIControl_P.HILInitialize_AOReset_b) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PIControl_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PIControl_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (PIControl_DW.HILInitialize_Card_k,
         PIControl_P.HILInitialize_AOChannels_p, 8U,
         &PIControl_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_EIPStart_j && !is_switching) ||
        (PIControl_P.HILInitialize_EIPEnter_i && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &PIControl_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = PIControl_P.HILInitialize_EIQuadrature_e;
        }
      }

      result = hil_set_encoder_quadrature_mode(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &PIControl_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_EIStart_a && !is_switching) ||
        (PIControl_P.HILInitialize_EIEnter_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &PIControl_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = PIControl_P.HILInitialize_EIInitial_d;
        }
      }

      result = hil_set_encoder_counts(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_EIChannels, 8U,
        &PIControl_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_POPStart_a && !is_switching) ||
        (PIControl_P.HILInitialize_POPEnter_b && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &PIControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PIControl_P.HILInitialize_POModes_k;
        }
      }

      result = hil_set_pwm_mode(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &PIControl_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          PIControl_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &PIControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            PIControl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            PIControl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              PIControl_P.HILInitialize_POFrequency_c;
            num_duty_cycle_modes++;
          } else {
            PIControl_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            PIControl_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              PIControl_P.HILInitialize_POFrequency_c;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(PIControl_DW.HILInitialize_Card_k,
          &PIControl_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &PIControl_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PIControl_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(PIControl_DW.HILInitialize_Card_k,
          &PIControl_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &PIControl_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PIControl_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &PIControl_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PIControl_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &PIControl_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = PIControl_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &PIControl_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = PIControl_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &PIControl_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &PIControl_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &PIControl_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &PIControl_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = PIControl_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &PIControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PIControl_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_POChannels, 8U,
        &PIControl_DW.HILInitialize_POSortedFreqs[0],
        &PIControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if ((PIControl_P.HILInitialize_POStart_n && !is_switching) ||
        (PIControl_P.HILInitialize_POEnter_n && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PIControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PIControl_P.HILInitialize_POInitial_g;
        }
      }

      result = hil_write_pwm(PIControl_DW.HILInitialize_Card_k,
        PIControl_P.HILInitialize_POChannels, 8U,
        &PIControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }

    if (PIControl_P.HILInitialize_POReset_d) {
      {
        int_T i1;
        real_T *dw_POValues = &PIControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PIControl_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (PIControl_DW.HILInitialize_Card_k, PIControl_P.HILInitialize_POChannels,
         8U, &PIControl_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Atomic SubSystem: '<S56>/Bias Removal' */
  PIControl_BiasRemoval_Start(&PIControl_DW.BiasRemoval);

  /* End of Start for SubSystem: '<S56>/Bias Removal' */

  /* Start for Atomic SubSystem: '<S56>/Bias Removal1' */
  PIControl_BiasRemoval_Start(&PIControl_DW.BiasRemoval1);

  /* End of Start for SubSystem: '<S56>/Bias Removal1' */

  /* Start for Constant: '<S62>/x0' */
  PIControl_B.x0 = PIControl_P.x0_Value;

  /* Start for Constant: '<S63>/x0' */
  PIControl_B.x0_h = PIControl_P.x0_Value_d;

  /* Start for Constant: '<Root>/Speed' */
  PIControl_B.Speed = PIControl_P.Speed_Value;
  PIControl_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S62>/Integrator1' incorporates:
   *  Integrator: '<S63>/Integrator1'
   */
  if (rtmIsFirstInitCond(PIControl_M)) {
    PIControl_X.Integrator1_CSTATE = 0.0;
    PIControl_X.Integrator1_CSTATE_l = 0.0;
  }

  PIControl_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S62>/Integrator1' */

  /* InitializeConditions for Integrator: '<S62>/Integrator2' */
  PIControl_X.Integrator2_CSTATE = PIControl_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S63>/Integrator1' */
  PIControl_DW.Integrator1_IWORK_b = 1;

  /* InitializeConditions for Integrator: '<S63>/Integrator2' */
  PIControl_X.Integrator2_CSTATE_j = PIControl_P.Integrator2_IC_h;

  /* InitializeConditions for Derivative: '<S58>/Derivative' */
  PIControl_DW.TimeStampA = (rtInf);
  PIControl_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  PIControl_DW.TimeStampA_b = (rtInf);
  PIControl_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative1' */
  PIControl_DW.TimeStampA_n = (rtInf);
  PIControl_DW.TimeStampB_k = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative2' */
  PIControl_DW.TimeStampA_k = (rtInf);
  PIControl_DW.TimeStampB_j = (rtInf);

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  PIControl_X.Integrator_CSTATE[0] = PIControl_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  PIControl_X.Filter_CSTATE[0] = PIControl_P.PDController_InitialConditionFo;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  PIControl_X.Integrator_CSTATE[1] = PIControl_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  PIControl_X.Filter_CSTATE[1] = PIControl_P.PDController_InitialConditionFo;

  /* SystemInitialize for Atomic SubSystem: '<S56>/Bias Removal' */
  PIControl_BiasRemoval_Init(&PIControl_B.BiasRemoval, &PIControl_DW.BiasRemoval,
    &PIControl_P.BiasRemoval);

  /* End of SystemInitialize for SubSystem: '<S56>/Bias Removal' */

  /* SystemInitialize for Atomic SubSystem: '<S56>/Bias Removal1' */
  PIControl_BiasRemoval_Init(&PIControl_B.BiasRemoval1,
    &PIControl_DW.BiasRemoval1, &PIControl_P.BiasRemoval1);

  /* End of SystemInitialize for SubSystem: '<S56>/Bias Removal1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(PIControl_M)) {
    rtmSetFirstInitCond(PIControl_M, 0);
  }
}

/* Model terminate function */
void PIControl_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S56>/HIL Initialize' */

  /* S-Function Block: PIControl/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(PIControl_DW.HILInitialize_Card);
    hil_monitor_stop_all(PIControl_DW.HILInitialize_Card);
    is_switching = false;
    if ((PIControl_P.HILInitialize_AOTerminate && !is_switching) ||
        (PIControl_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(PIControl_DW.HILInitialize_Card,
        &PIControl_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &PIControl_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PIControl_M, _rt_error_message);
      }
    }

    hil_task_delete_all(PIControl_DW.HILInitialize_Card);
    hil_monitor_delete_all(PIControl_DW.HILInitialize_Card);
    hil_close(PIControl_DW.HILInitialize_Card);
    PIControl_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (hil_initialize_block): '<S58>/HIL Initialize' */

  /* S-Function Block: PIControl/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(PIControl_DW.HILInitialize_Card_k);
    hil_monitor_stop_all(PIControl_DW.HILInitialize_Card_k);
    is_switching = false;
    if ((PIControl_P.HILInitialize_AOTerminate_g && !is_switching) ||
        (PIControl_P.HILInitialize_AOExit_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PIControl_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PIControl_P.HILInitialize_AOFinal_m;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((PIControl_P.HILInitialize_POTerminate_a && !is_switching) ||
        (PIControl_P.HILInitialize_POExit_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PIControl_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PIControl_P.HILInitialize_POFinal_c;
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
      result = hil_write(PIControl_DW.HILInitialize_Card_k
                         , PIControl_P.HILInitialize_AOChannels_p,
                         num_final_analog_outputs
                         , PIControl_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &PIControl_DW.HILInitialize_AOVoltages_a[0]
                         , &PIControl_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(PIControl_DW.HILInitialize_Card_k,
            PIControl_P.HILInitialize_AOChannels_p, num_final_analog_outputs,
            &PIControl_DW.HILInitialize_AOVoltages_a[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(PIControl_DW.HILInitialize_Card_k,
            PIControl_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &PIControl_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PIControl_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(PIControl_DW.HILInitialize_Card_k);
    hil_monitor_delete_all(PIControl_DW.HILInitialize_Card_k);
    hil_close(PIControl_DW.HILInitialize_Card_k);
    PIControl_DW.HILInitialize_Card_k = NULL;
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
  PIControl_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  PIControl_update(tid);
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
  PIControl_initialize();
}

void MdlTerminate(void)
{
  PIControl_terminate();
}

/* Registration function */
RT_MODEL_PIControl_T *PIControl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PIControl_M, 0,
                sizeof(RT_MODEL_PIControl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PIControl_M->solverInfo,
                          &PIControl_M->Timing.simTimeStep);
    rtsiSetTPtr(&PIControl_M->solverInfo, &rtmGetTPtr(PIControl_M));
    rtsiSetStepSizePtr(&PIControl_M->solverInfo, &PIControl_M->Timing.stepSize0);
    rtsiSetdXPtr(&PIControl_M->solverInfo, &PIControl_M->derivs);
    rtsiSetContStatesPtr(&PIControl_M->solverInfo, (real_T **)
                         &PIControl_M->contStates);
    rtsiSetNumContStatesPtr(&PIControl_M->solverInfo,
      &PIControl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PIControl_M->solverInfo,
      &PIControl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PIControl_M->solverInfo,
      &PIControl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PIControl_M->solverInfo,
      &PIControl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PIControl_M->solverInfo, (&rtmGetErrorStatus
      (PIControl_M)));
    rtsiSetRTModelPtr(&PIControl_M->solverInfo, PIControl_M);
  }

  rtsiSetSimTimeStep(&PIControl_M->solverInfo, MAJOR_TIME_STEP);
  PIControl_M->intgData.f[0] = PIControl_M->odeF[0];
  PIControl_M->contStates = ((real_T *) &PIControl_X);
  rtsiSetSolverData(&PIControl_M->solverInfo, (void *)&PIControl_M->intgData);
  rtsiSetSolverName(&PIControl_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PIControl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "PIControl_M points to
       static memory which is guaranteed to be non-NULL" */
    PIControl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PIControl_M->Timing.sampleTimes = (&PIControl_M->Timing.sampleTimesArray[0]);
    PIControl_M->Timing.offsetTimes = (&PIControl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PIControl_M->Timing.sampleTimes[0] = (0.0);
    PIControl_M->Timing.sampleTimes[1] = (0.002);
    PIControl_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    PIControl_M->Timing.offsetTimes[0] = (0.0);
    PIControl_M->Timing.offsetTimes[1] = (0.0);
    PIControl_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(PIControl_M, &PIControl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PIControl_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = PIControl_M->Timing.perTaskSampleHitsArray;
    PIControl_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    PIControl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PIControl_M, 10.0);
  PIControl_M->Timing.stepSize0 = 0.002;
  PIControl_M->Timing.stepSize1 = 0.002;
  PIControl_M->Timing.stepSize2 = 0.02;
  rtmSetFirstInitCond(PIControl_M, 1);

  /* External mode info */
  PIControl_M->Sizes.checksums[0] = (636859846U);
  PIControl_M->Sizes.checksums[1] = (287713515U);
  PIControl_M->Sizes.checksums[2] = (1148501425U);
  PIControl_M->Sizes.checksums[3] = (1222079358U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    PIControl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &PIControl_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB;
    systemRan[5] = (sysRanDType *)
      &PIControl_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy;
    systemRan[6] = (sysRanDType *)
      &PIControl_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs;
    systemRan[7] = (sysRanDType *)
      &PIControl_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &PIControl_DW.BiasRemoval1.EnabledMovingAverage_SubsysRanB;
    systemRan[10] = (sysRanDType *)
      &PIControl_DW.BiasRemoval1.SwitchCaseActionSubsystem_Subsy;
    systemRan[11] = (sysRanDType *)
      &PIControl_DW.BiasRemoval1.SwitchCaseActionSubsystem1_Subs;
    systemRan[12] = (sysRanDType *)
      &PIControl_DW.BiasRemoval1.SwitchCaseActionSubsystem2_Subs;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PIControl_M->extModeInfo,
      &PIControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PIControl_M->extModeInfo, PIControl_M->Sizes.checksums);
    rteiSetTPtr(PIControl_M->extModeInfo, rtmGetTPtr(PIControl_M));
  }

  PIControl_M->solverInfoPtr = (&PIControl_M->solverInfo);
  PIControl_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&PIControl_M->solverInfo, 0.002);
  rtsiSetSolverMode(&PIControl_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  PIControl_M->blockIO = ((void *) &PIControl_B);
  (void) memset(((void *) &PIControl_B), 0,
                sizeof(B_PIControl_T));

  /* parameters */
  PIControl_M->defaultParam = ((real_T *)&PIControl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PIControl_X;
    PIControl_M->contStates = (x);
    (void) memset((void *)&PIControl_X, 0,
                  sizeof(X_PIControl_T));
  }

  /* states (dwork) */
  PIControl_M->dwork = ((void *) &PIControl_DW);
  (void) memset((void *)&PIControl_DW, 0,
                sizeof(DW_PIControl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PIControl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PIControl_M->Sizes.numContStates = (8);/* Number of continuous states */
  PIControl_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PIControl_M->Sizes.numY = (0);       /* Number of model outputs */
  PIControl_M->Sizes.numU = (0);       /* Number of model inputs */
  PIControl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PIControl_M->Sizes.numSampTimes = (3);/* Number of sample times */
  PIControl_M->Sizes.numBlocks = (115);/* Number of blocks */
  PIControl_M->Sizes.numBlockIO = (40);/* Number of block outputs */
  PIControl_M->Sizes.numBlockPrms = (245);/* Sum of parameter "widths" */
  return PIControl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
