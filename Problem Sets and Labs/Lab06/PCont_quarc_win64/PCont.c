/*
 * PCont.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PCont".
 *
 * Model version              : 8.3
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Apr 14 12:51:02 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PCont.h"
#include "PCont_private.h"
#include "PCont_dt.h"

/* Block signals (default storage) */
B_PCont_T PCont_B;

/* Continuous states */
X_PCont_T PCont_X;

/* Block states (default storage) */
DW_PCont_T PCont_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PCont_T PCont_PrevZCX;

/* Real-time model */
static RT_MODEL_PCont_T PCont_M_;
RT_MODEL_PCont_T *const PCont_M = &PCont_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(PCont_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(PCont_M, 2);
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
  if (PCont_M->Timing.TaskCounters.TID[1] == 0) {
    PCont_M->Timing.RateInteraction.TID1_2 = (PCont_M->Timing.TaskCounters.TID[2]
      == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    PCont_M->Timing.perTaskSampleHits[5] =
      PCont_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PCont_M->Timing.TaskCounters.TID[2])++;
  if ((PCont_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.02s, 0.0s] */
    PCont_M->Timing.TaskCounters.TID[2] = 0;
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
  PCont_derivatives();
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
void PCont_BiasRemoval_Init(B_BiasRemoval_PCont_T *localB,
  DW_BiasRemoval_PCont_T *localDW, P_BiasRemoval_PCont_T *localP)
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
void PCont_BiasRemoval_Start(DW_BiasRemoval_PCont_T *localDW)
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
void PCont_BiasRemoval(RT_MODEL_PCont_T * const PCont_M, real_T rtu_V, real_T
  rtp_switch_id, real_T rtp_start_time, real_T rtp_end_time,
  B_BiasRemoval_PCont_T *localB, DW_BiasRemoval_PCont_T *localDW,
  P_BiasRemoval_PCont_T *localP)
{
  real_T rtb_Stepend_time;
  real_T rtb_Sum_p;
  real_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Step: '<S60>/Step: end_time' incorporates:
   *  Step: '<S60>/Step: start_time'
   */
  tmp = PCont_M->Timing.t[1];
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
void PCont_BiasRemoval_Update(B_BiasRemoval_PCont_T *localB,
  DW_BiasRemoval_PCont_T *localDW)
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
void PCont_output0(void)               /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog_o1;
  real_T rtb_HILReadAnalog_o2;
  real_T rtb_HILReadAnalog[2];
  real_T (*lastU)[2];
  real_T F0_tmp;
  real_T F0_tmp_0;
  real_T lastTime;
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
  if (rtmIsMajorTimeStep(PCont_M)) {
    /* set solver stop time */
    if (!(PCont_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PCont_M->solverInfo, ((PCont_M->Timing.clockTickH0
        + 1) * PCont_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PCont_M->solverInfo, ((PCont_M->Timing.clockTick0 +
        1) * PCont_M->Timing.stepSize0 + PCont_M->Timing.clockTickH0 *
        PCont_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PCont_M)) {
    PCont_M->Timing.t[0] = rtsiGetT(&PCont_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PCont_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PCont_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PCont_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PCont_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(PCont_M)) {
    /* S-Function (hil_read_analog_block): '<S56>/HIL Read Analog' */

    /* S-Function Block: PCont/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(PCont_DW.HILInitialize_Card,
        PCont_P.HILReadAnalog_channels, 2, &PCont_DW.HILReadAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
      }

      rtb_HILReadAnalog_o1 = PCont_DW.HILReadAnalog_Buffer[0];
      rtb_HILReadAnalog_o2 = PCont_DW.HILReadAnalog_Buffer[1];
    }

    /* Gain: '<S56>/X Gain (N//V)' */
    PCont_B.XGainNV = PCont_P.XGainNV_Gain * rtb_HILReadAnalog_o1;

    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal' */
    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal' */
    PCont_BiasRemoval(PCont_M, PCont_B.XGainNV, PCont_P.BiasRemoval_switch_id,
                      PCont_P.BiasRemoval_start_time,
                      PCont_P.BiasRemoval_end_time, &PCont_B.BiasRemoval,
                      &PCont_DW.BiasRemoval, &PCont_P.BiasRemoval);

    /* End of Outputs for SubSystem: '<S56>/Bias Removal' */
    /* End of Outputs for SubSystem: '<S56>/Bias Removal' */

    /* Gain: '<S56>/Y Gain (N//V)' */
    PCont_B.YGainNV = PCont_P.YGainNV_Gain * rtb_HILReadAnalog_o2;

    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal1' */
    /* Outputs for Atomic SubSystem: '<S56>/Bias Removal1' */
    PCont_BiasRemoval(PCont_M, PCont_B.YGainNV, PCont_P.BiasRemoval1_switch_id,
                      PCont_P.BiasRemoval1_start_time,
                      PCont_P.BiasRemoval1_end_time, &PCont_B.BiasRemoval1,
                      &PCont_DW.BiasRemoval1, &PCont_P.BiasRemoval1);

    /* End of Outputs for SubSystem: '<S56>/Bias Removal1' */
    /* End of Outputs for SubSystem: '<S56>/Bias Removal1' */

    /* Constant: '<S62>/x0' */
    PCont_B.x0 = PCont_P.x0_Value;
  }

  /* Integrator: '<S62>/Integrator1' */
  if (PCont_DW.Integrator1_IWORK != 0) {
    PCont_X.Integrator1_CSTATE = PCont_B.x0;
  }

  /* Integrator: '<S62>/Integrator1' */
  PCont_B.Integrator1 = PCont_X.Integrator1_CSTATE;

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S62>/wn'
   *  Constant: '<S62>/zt'
   *  Integrator: '<S62>/Integrator2'
   *  Product: '<S62>/Product2'
   *  Sum: '<S62>/Sum'
   *  Sum: '<S62>/Sum1'
   */
  PCont_B.Product = ((PCont_B.BiasRemoval.Switch - PCont_B.Integrator1) -
                     PCont_X.Integrator2_CSTATE * PCont_P.Constant_Value *
                     PCont_P.SecondOrderLowPassFilter_inpu_h) *
    PCont_P.SecondOrderLowPassFilter_input_;

  /* Product: '<S62>/Product1' incorporates:
   *  Constant: '<S62>/wn'
   *  Integrator: '<S62>/Integrator2'
   */
  PCont_B.Product1 = PCont_P.SecondOrderLowPassFilter_input_ *
    PCont_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(PCont_M)) {
    /* Constant: '<S63>/x0' */
    PCont_B.x0_h = PCont_P.x0_Value_d;
  }

  /* Integrator: '<S63>/Integrator1' */
  if (PCont_DW.Integrator1_IWORK_b != 0) {
    PCont_X.Integrator1_CSTATE_l = PCont_B.x0_h;
  }

  /* Integrator: '<S63>/Integrator1' */
  PCont_B.Integrator1_c = PCont_X.Integrator1_CSTATE_l;

  /* Product: '<S63>/Product' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S63>/wn'
   *  Constant: '<S63>/zt'
   *  Integrator: '<S63>/Integrator2'
   *  Product: '<S63>/Product2'
   *  Sum: '<S63>/Sum'
   *  Sum: '<S63>/Sum1'
   */
  PCont_B.Product_i = ((PCont_B.BiasRemoval1.Switch - PCont_B.Integrator1_c) -
                       PCont_X.Integrator2_CSTATE_j * PCont_P.Constant_Value_j *
                       PCont_P.SecondOrderLowPassFilter1_inp_n) *
    PCont_P.SecondOrderLowPassFilter1_input;

  /* Product: '<S63>/Product1' incorporates:
   *  Constant: '<S63>/wn'
   *  Integrator: '<S63>/Integrator2'
   */
  PCont_B.Product1_k = PCont_P.SecondOrderLowPassFilter1_input *
    PCont_X.Integrator2_CSTATE_j;
  if (rtmIsMajorTimeStep(PCont_M)) {
    /* S-Function (hil_read_encoder_block): '<S58>/HIL Read Encoder' */

    /* S-Function Block: PCont/Robot and Environment Subsystem/Robot Subsystem/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILReadEncoder_channels, 2, &PCont_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
      } else {
        rtb_HILReadAnalog[0] = PCont_DW.HILReadEncoder_Buffer[0];
        rtb_HILReadAnalog[1] = PCont_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S58>/Encoder Gain' incorporates:
     *  Constant: '<S58>/Home Position'
     *  Sum: '<S58>/Sum1'
     */
    PCont_B.EncoderGain[0] = (PCont_P.HomePosition_Value[0] + rtb_HILReadAnalog
      [0]) * PCont_P.EncoderGain_Gain[0];
    PCont_B.EncoderGain[1] = (PCont_P.HomePosition_Value[1] + rtb_HILReadAnalog
      [1]) * PCont_P.EncoderGain_Gain[1];

    /* Constant: '<Root>/Speed' */
    PCont_B.Speed = PCont_P.Speed_Value;
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Derivative: '<S5>/Derivative'
   *  Derivative: '<S5>/Derivative1'
   *  Derivative: '<S5>/Derivative2'
   */
  rtb_Clock_tmp = PCont_M->Timing.t[0];

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
    PCont_B.x_f[0] = x_f_tmp * 0.0375 + 0.22;

    /* '<S1>:1:11' */
    PCont_B.x_f[1] = 0.15 - x_f_tmp * 0.105;
  } else if (rtb_Clock_tmp < 2.5) {
    /* '<S1>:1:12' */
    /* '<S1>:1:13' */
    PCont_B.x_f[0] = (cos((rtb_Clock_tmp - 2.0) * (rtb_Clock_tmp - 2.0) *
                          (6.2831853071795862 * PCont_B.Speed)) * 0.075 + 0.15)
      + 0.07;

    /* '<S1>:1:14' */
    PCont_B.x_f[1] = -0.06;
  } else {
    /* '<S1>:1:16' */
    PCont_B.x_f[0] = (cos(6.2831853071795862 * PCont_B.Speed * (rtb_Clock_tmp -
      2.25)) * 0.075 + 0.15) + 0.07;

    /* '<S1>:1:17' */
    PCont_B.x_f[1] = -0.06;
  }

  /* End of MATLAB Function: '<Root>/Desired Position' */

  /* Derivative: '<S5>/Derivative' */
  if ((PCont_DW.TimeStampA_b >= rtb_Clock_tmp) && (PCont_DW.TimeStampB_g >=
       rtb_Clock_tmp)) {
    /* Derivative: '<S5>/Derivative' */
    PCont_B.Derivative[0] = 0.0;
    PCont_B.Derivative[1] = 0.0;
  } else {
    lastTime = PCont_DW.TimeStampA_b;
    lastU = &PCont_DW.LastUAtTimeA_e;
    if (PCont_DW.TimeStampA_b < PCont_DW.TimeStampB_g) {
      if (PCont_DW.TimeStampB_g < rtb_Clock_tmp) {
        lastTime = PCont_DW.TimeStampB_g;
        lastU = &PCont_DW.LastUAtTimeB_a;
      }
    } else if (PCont_DW.TimeStampA_b >= rtb_Clock_tmp) {
      lastTime = PCont_DW.TimeStampB_g;
      lastU = &PCont_DW.LastUAtTimeB_a;
    }

    lastTime = rtb_Clock_tmp - lastTime;

    /* Derivative: '<S5>/Derivative' */
    PCont_B.Derivative[0] = (PCont_B.x_f[0] - (*lastU)[0]) / lastTime;
    PCont_B.Derivative[1] = (PCont_B.x_f[1] - (*lastU)[1]) / lastTime;
  }

  /* Derivative: '<S5>/Derivative1' */
  if ((PCont_DW.TimeStampA_n >= rtb_Clock_tmp) && (PCont_DW.TimeStampB_k >=
       rtb_Clock_tmp)) {
    rtb_Derivative1_idx_0 = 0.0;
    rtb_Derivative1_idx_1 = 0.0;
  } else {
    lastTime = PCont_DW.TimeStampA_n;
    lastU = &PCont_DW.LastUAtTimeA_k;
    if (PCont_DW.TimeStampA_n < PCont_DW.TimeStampB_k) {
      if (PCont_DW.TimeStampB_k < rtb_Clock_tmp) {
        lastTime = PCont_DW.TimeStampB_k;
        lastU = &PCont_DW.LastUAtTimeB_l;
      }
    } else if (PCont_DW.TimeStampA_n >= rtb_Clock_tmp) {
      lastTime = PCont_DW.TimeStampB_k;
      lastU = &PCont_DW.LastUAtTimeB_l;
    }

    lastTime = rtb_Clock_tmp - lastTime;
    rtb_Derivative1_idx_0 = (PCont_B.Derivative[0] - (*lastU)[0]) / lastTime;
    rtb_Derivative1_idx_1 = (PCont_B.Derivative[1] - (*lastU)[1]) / lastTime;
  }

  if (rtmIsMajorTimeStep(PCont_M)) {
    /* MATLAB Function: '<S6>/Forward Kinematics' incorporates:
     *  Gain: '<S58>/Encoder Gain'
     */
    /* MATLAB Function 'Robot and Environment Subsystem/Forward Kinematics': '<S57>:1' */
    /* '<S57>:1:5' */
    /* '<S57>:1:6' */
    /* '<S57>:1:8' */
    PCont_B.x[0] = 0.15 * cos(PCont_B.EncoderGain[0]) + 0.22 * cos
      (PCont_B.EncoderGain[1]);

    /* '<S57>:1:9' */
    PCont_B.x[1] = 0.15 * sin(PCont_B.EncoderGain[0]) + 0.22 * sin
      (PCont_B.EncoderGain[1]);
  }

  /* Sum: '<S5>/Sum2' */
  PCont_B.Sum2[0] = PCont_B.x_f[0] - PCont_B.x[0];
  PCont_B.Sum2[1] = PCont_B.x_f[1] - PCont_B.x[1];

  /* Derivative: '<S5>/Derivative2' */
  if ((PCont_DW.TimeStampA_k >= rtb_Clock_tmp) && (PCont_DW.TimeStampB_j >=
       rtb_Clock_tmp)) {
    rtb_Derivative2_idx_0 = 0.0;
    rtb_Derivative2_idx_1 = 0.0;
  } else {
    lastTime = PCont_DW.TimeStampA_k;
    lastU = &PCont_DW.LastUAtTimeA_p;
    if (PCont_DW.TimeStampA_k < PCont_DW.TimeStampB_j) {
      if (PCont_DW.TimeStampB_j < rtb_Clock_tmp) {
        lastTime = PCont_DW.TimeStampB_j;
        lastU = &PCont_DW.LastUAtTimeB_m;
      }
    } else if (PCont_DW.TimeStampA_k >= rtb_Clock_tmp) {
      lastTime = PCont_DW.TimeStampB_j;
      lastU = &PCont_DW.LastUAtTimeB_m;
    }

    lastTime = rtb_Clock_tmp - lastTime;
    rtb_Derivative2_idx_0 = (PCont_B.x[0] - (*lastU)[0]) / lastTime;
    rtb_Derivative2_idx_1 = (PCont_B.x[1] - (*lastU)[1]) / lastTime;
  }

  /* Step: '<S5>/Desired Force' incorporates:
   *  Step: '<S5>/Reset Integrator'
   */
  x_f_tmp = PCont_M->Timing.t[0];

  /* MATLAB Function: '<S6>/Rotation to Base Frame' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  SignalConversion generated from: '<S59>/ SFunction '
   */
  /* MATLAB Function 'Robot and Environment Subsystem/Rotation to Base Frame': '<S59>:1' */
  /* '<S59>:1:7' */
  /* '<S59>:1:11' */
  F0_tmp = sin(PCont_B.EncoderGain[1]);
  F0_tmp_0 = cos(PCont_B.EncoderGain[1]);
  PCont_B.F0[0] = 0.0;
  PCont_B.F0[0] += F0_tmp_0 * PCont_B.Integrator1;
  PCont_B.F0[0] += -F0_tmp * PCont_B.Integrator1_c;

  /* Step: '<S5>/Desired Force' */
  if (x_f_tmp < PCont_P.DesiredForce_Time) {
    lastTime = PCont_P.DesiredForce_Y0;
  } else {
    lastTime = PCont_P.DesiredForce_YFinal[0];
  }

  /* Sum: '<S5>/Sum1' */
  PCont_B.Sum1[0] = lastTime - PCont_B.F0[0];

  /* Sum: '<S4>/Sum2' */
  lastTime = PCont_B.x_f[0] - PCont_B.x[0];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<S34>/SumD'
   */
  PCont_B.FilterCoefficient[0] = (PCont_P.PDController_D[0] * lastTime -
    PCont_X.Filter_CSTATE[0]) * PCont_P.PDController_N;

  /* Sum: '<S4>/Sum2' */
  rtb_Filter_idx_0 = lastTime;

  /* MATLAB Function: '<S6>/Rotation to Base Frame' incorporates:
   *  SignalConversion generated from: '<S59>/ SFunction '
   */
  PCont_B.F0[1] = 0.0;
  PCont_B.F0[1] += F0_tmp * PCont_B.Integrator1;
  PCont_B.F0[1] += F0_tmp_0 * PCont_B.Integrator1_c;

  /* Step: '<S5>/Desired Force' */
  if (x_f_tmp < PCont_P.DesiredForce_Time) {
    lastTime = PCont_P.DesiredForce_Y0;
  } else {
    lastTime = PCont_P.DesiredForce_YFinal[1];
  }

  /* Sum: '<S5>/Sum1' */
  PCont_B.Sum1[1] = lastTime - PCont_B.F0[1];

  /* Sum: '<S4>/Sum2' */
  lastTime = PCont_B.x_f[1] - PCont_B.x[1];

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   *  Integrator: '<S34>/Filter'
   *  Sum: '<S34>/SumD'
   */
  PCont_B.FilterCoefficient[1] = (PCont_P.PDController_D[1] * lastTime -
    PCont_X.Filter_CSTATE[1]) * PCont_P.PDController_N;

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
  if (rtb_Clock_tmp > PCont_P.Switch_Threshold) {
    /* Sum: '<S5>/Sum3' incorporates:
     *  Gain: '<S5>/Kf Gain'
     */
    rtb_Clock_tmp = PCont_P.KfGain_Gain * PCont_B.Sum1[0];
    lastTime = PCont_P.KfGain_Gain * PCont_B.Sum1[1];

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/ P Gain'
     *  Gain: '<S5>/S'
     */
    rtb_Filter_idx_0_tmp = PCont_P.PGain_Gain * PCont_B.Sum2[0];
    rtb_Filter_idx_0_tmp_0 = PCont_P.PGain_Gain * PCont_B.Sum2[1];
    rtb_Filter_idx_0 = (((rtb_Filter_idx_0_tmp * PCont_P.S_Gain[0] +
                          rtb_Filter_idx_0_tmp_0 * PCont_P.S_Gain[2]) +
                         rtb_Derivative1_idx_0) - PCont_P.DGain_Gain[0] *
                        rtb_Derivative2_idx_0) + (PCont_P.IS_Gain[0] *
      rtb_Clock_tmp + PCont_P.IS_Gain[2] * lastTime);
    rtb_Derivative1_idx_0 = (((rtb_Filter_idx_0_tmp * PCont_P.S_Gain[1] +
      rtb_Filter_idx_0_tmp_0 * PCont_P.S_Gain[3]) + rtb_Derivative1_idx_1) -
      PCont_P.DGain_Gain[1] * rtb_Derivative2_idx_1) + (PCont_P.IS_Gain[1] *
      rtb_Clock_tmp + PCont_P.IS_Gain[3] * lastTime);
  } else {
    rtb_Filter_idx_0 = PCont_P.PDController_P[0] * rtb_Filter_idx_0 +
      PCont_B.FilterCoefficient[0];
    rtb_Derivative1_idx_0 = PCont_P.PDController_P[1] * lastTime +
      PCont_B.FilterCoefficient[1];
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
  PCont_B.current[0] = ((-0.15 * sin(PCont_B.EncoderGain[0]) * rtb_Filter_idx_0
    + 0.15 * cos(PCont_B.EncoderGain[0]) * rtb_Derivative1_idx_0) + 0.2131892 *
                        cos(PCont_B.EncoderGain[0])) * PCont_P.invmotorgain_Gain;

  /* Gain: '<S58>/1//AmpGain' incorporates:
   *  Bias: '<S58>/Amp Bias Tune for each amp if needed'
   */
  PCont_B.uAmpGain[0] = (PCont_B.current[0] +
    PCont_P.AmpBiasTuneforeachampifneeded_B[0]) * PCont_P.uAmpGain_Gain[0];

  /* Gain: '<S6>/inv motor gain' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   *  MATLAB Function: '<Root>/Feedback Comp'
   *  MATLAB Function: '<Root>/Jacobian Transpose'
   *  Sum: '<Root>/Sum3'
   */
  PCont_B.current[1] = ((-0.22 * F0_tmp * rtb_Filter_idx_0 + 0.22 * cos
    (PCont_B.EncoderGain[1]) * rtb_Derivative1_idx_0) + 0.0796936 * F0_tmp_0) *
    PCont_P.invmotorgain_Gain;

  /* Gain: '<S58>/1//AmpGain' incorporates:
   *  Bias: '<S58>/Amp Bias Tune for each amp if needed'
   */
  PCont_B.uAmpGain[1] = (PCont_B.current[1] +
    PCont_P.AmpBiasTuneforeachampifneeded_B[1]) * PCont_P.uAmpGain_Gain[1];
  if (rtmIsMajorTimeStep(PCont_M)) {
    /* S-Function (hil_write_analog_block): '<S58>/HIL Write Analog' */

    /* S-Function Block: PCont/Robot and Environment Subsystem/Robot Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILWriteAnalog_channels, 2, &PCont_B.uAmpGain[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<S58>/HIL Read Analog' */

    /* S-Function Block: PCont/Robot and Environment Subsystem/Robot Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILReadAnalog_channels_c, 2, &rtb_HILReadAnalog[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
      }
    }

    /* Gain: '<S58>/1//Sense Gain' */
    PCont_B.uSenseGain[0] = PCont_P.uSenseGain_Gain * rtb_HILReadAnalog[0];
    PCont_B.uSenseGain[1] = PCont_P.uSenseGain_Gain * rtb_HILReadAnalog[1];
  }

  /* Step: '<S5>/Reset Integrator' */
  if (x_f_tmp < PCont_P.ResetIntegrator_Time) {
    /* Step: '<S5>/Reset Integrator' */
    PCont_B.ResetIntegrator = PCont_P.ResetIntegrator_Y0;
  } else {
    /* Step: '<S5>/Reset Integrator' */
    PCont_B.ResetIntegrator = PCont_P.ResetIntegrator_YFinal;
  }

  /* Integrator: '<S5>/Integrator' */
  if (rtmIsMajorTimeStep(PCont_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&PCont_PrevZCX.Integrator_Reset_ZCE,
                       (PCont_B.ResetIntegrator));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      PCont_X.Integrator_CSTATE[0] = PCont_P.Integrator_IC;
      PCont_X.Integrator_CSTATE[1] = PCont_P.Integrator_IC;
    }
  }

  /* End of Integrator: '<S5>/Integrator' */

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   */
  if (rtmIsMajorTimeStep(PCont_M) && PCont_M->Timing.RateInteraction.TID1_2) {
    PCont_DW.RateTransition_Buffer[0] = PCont_B.EncoderGain[0];
    PCont_DW.RateTransition_Buffer[1] = PCont_B.EncoderGain[1];
  }

  /* End of RateTransition: '<Root>/Rate Transition' */
}

/* Model update function for TID0 */
void PCont_update0(void)               /* Sample time: [0.0s, 0.0s] */
{
  real_T (*lastU)[2];
  if (rtmIsMajorTimeStep(PCont_M)) {
    /* Update for Atomic SubSystem: '<S56>/Bias Removal' */
    PCont_BiasRemoval_Update(&PCont_B.BiasRemoval, &PCont_DW.BiasRemoval);

    /* End of Update for SubSystem: '<S56>/Bias Removal' */

    /* Update for Atomic SubSystem: '<S56>/Bias Removal1' */
    PCont_BiasRemoval_Update(&PCont_B.BiasRemoval1, &PCont_DW.BiasRemoval1);

    /* End of Update for SubSystem: '<S56>/Bias Removal1' */
  }

  /* Update for Integrator: '<S62>/Integrator1' */
  PCont_DW.Integrator1_IWORK = 0;

  /* Update for Integrator: '<S63>/Integrator1' */
  PCont_DW.Integrator1_IWORK_b = 0;

  /* Update for Derivative: '<S58>/Derivative' incorporates:
   *  Gain: '<S58>/Encoder Gain'
   */
  if (PCont_DW.TimeStampA == (rtInf)) {
    PCont_DW.TimeStampA = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA;
  } else if (PCont_DW.TimeStampB == (rtInf)) {
    PCont_DW.TimeStampB = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB;
  } else if (PCont_DW.TimeStampA < PCont_DW.TimeStampB) {
    PCont_DW.TimeStampA = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA;
  } else {
    PCont_DW.TimeStampB = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB;
  }

  (*lastU)[0] = PCont_B.EncoderGain[0];
  (*lastU)[1] = PCont_B.EncoderGain[1];

  /* End of Update for Derivative: '<S58>/Derivative' */

  /* Update for Derivative: '<S5>/Derivative' */
  if (PCont_DW.TimeStampA_b == (rtInf)) {
    PCont_DW.TimeStampA_b = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA_e;
  } else if (PCont_DW.TimeStampB_g == (rtInf)) {
    PCont_DW.TimeStampB_g = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB_a;
  } else if (PCont_DW.TimeStampA_b < PCont_DW.TimeStampB_g) {
    PCont_DW.TimeStampA_b = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA_e;
  } else {
    PCont_DW.TimeStampB_g = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB_a;
  }

  (*lastU)[0] = PCont_B.x_f[0];
  (*lastU)[1] = PCont_B.x_f[1];

  /* End of Update for Derivative: '<S5>/Derivative' */

  /* Update for Derivative: '<S5>/Derivative1' */
  if (PCont_DW.TimeStampA_n == (rtInf)) {
    PCont_DW.TimeStampA_n = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA_k;
  } else if (PCont_DW.TimeStampB_k == (rtInf)) {
    PCont_DW.TimeStampB_k = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB_l;
  } else if (PCont_DW.TimeStampA_n < PCont_DW.TimeStampB_k) {
    PCont_DW.TimeStampA_n = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA_k;
  } else {
    PCont_DW.TimeStampB_k = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB_l;
  }

  (*lastU)[0] = PCont_B.Derivative[0];
  (*lastU)[1] = PCont_B.Derivative[1];

  /* End of Update for Derivative: '<S5>/Derivative1' */

  /* Update for Derivative: '<S5>/Derivative2' */
  if (PCont_DW.TimeStampA_k == (rtInf)) {
    PCont_DW.TimeStampA_k = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA_p;
  } else if (PCont_DW.TimeStampB_j == (rtInf)) {
    PCont_DW.TimeStampB_j = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB_m;
  } else if (PCont_DW.TimeStampA_k < PCont_DW.TimeStampB_j) {
    PCont_DW.TimeStampA_k = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeA_p;
  } else {
    PCont_DW.TimeStampB_j = PCont_M->Timing.t[0];
    lastU = &PCont_DW.LastUAtTimeB_m;
  }

  (*lastU)[0] = PCont_B.x[0];
  (*lastU)[1] = PCont_B.x[1];

  /* End of Update for Derivative: '<S5>/Derivative2' */
  if (rtmIsMajorTimeStep(PCont_M)) {
    rt_ertODEUpdateContinuousStates(&PCont_M->solverInfo);
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
  if (!(++PCont_M->Timing.clockTick0)) {
    ++PCont_M->Timing.clockTickH0;
  }

  PCont_M->Timing.t[0] = rtsiGetSolverStopTime(&PCont_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PCont_M->Timing.clockTick1)) {
    ++PCont_M->Timing.clockTickH1;
  }

  PCont_M->Timing.t[1] = PCont_M->Timing.clockTick1 * PCont_M->Timing.stepSize1
    + PCont_M->Timing.clockTickH1 * PCont_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void PCont_derivatives(void)
{
  XDot_PCont_T *_rtXdot;
  _rtXdot = ((XDot_PCont_T *) PCont_M->derivs);

  /* Derivatives for Integrator: '<S62>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = PCont_B.Product1;

  /* Derivatives for Integrator: '<S62>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = PCont_B.Product;

  /* Derivatives for Integrator: '<S63>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_l = PCont_B.Product1_k;

  /* Derivatives for Integrator: '<S63>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j = PCont_B.Product_i;

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE[0] = PCont_B.FilterCoefficient[0];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = PCont_B.Sum1[0];

  /* Derivatives for Integrator: '<S34>/Filter' */
  _rtXdot->Filter_CSTATE[1] = PCont_B.FilterCoefficient[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = PCont_B.Sum1[1];
}

/* Model output function for TID2 */
void PCont_output2(void)               /* Sample time: [0.02s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition' */
  PCont_B.RateTransition[0] = PCont_DW.RateTransition_Buffer[0];
  PCont_B.RateTransition[1] = PCont_DW.RateTransition_Buffer[1];
}

/* Model update function for TID2 */
void PCont_update2(void)               /* Sample time: [0.02s, 0.0s] */
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
  if (!(++PCont_M->Timing.clockTick2)) {
    ++PCont_M->Timing.clockTickH2;
  }

  PCont_M->Timing.t[2] = PCont_M->Timing.clockTick2 * PCont_M->Timing.stepSize2
    + PCont_M->Timing.clockTickH2 * PCont_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PCont_output(int_T tid)
{
  switch (tid) {
   case 0 :
    PCont_output0();
    break;

   case 2 :
    PCont_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void PCont_update(int_T tid)
{
  switch (tid) {
   case 0 :
    PCont_update0();
    break;

   case 2 :
    PCont_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void PCont_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S56>/HIL Initialize' */

  /* S-Function Block: PCont/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6014", "0", &PCont_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PCont_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(PCont_DW.HILInitialize_Card,
      "terminal_board=e_series", 24);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PCont_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(PCont_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PCont_M, _rt_error_message);
      return;
    }

    if ((PCont_P.HILInitialize_AOPStart && !is_switching) ||
        (PCont_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(PCont_DW.HILInitialize_Card,
        &PCont_P.HILInitialize_AOChannels, 1U,
        &PCont_P.HILInitialize_AOLow, &PCont_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_AOStart && !is_switching) ||
        (PCont_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(PCont_DW.HILInitialize_Card,
        &PCont_P.HILInitialize_AOChannels, 1U, &PCont_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_initialize_block): '<S58>/HIL Initialize' */

  /* S-Function Block: PCont/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &PCont_DW.HILInitialize_Card_k);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PCont_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(PCont_DW.HILInitialize_Card_k,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PCont_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(PCont_DW.HILInitialize_Card_k);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(PCont_M, _rt_error_message);
      return;
    }

    if ((PCont_P.HILInitialize_AIPStart_j && !is_switching) ||
        (PCont_P.HILInitialize_AIPEnter_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &PCont_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (PCont_P.HILInitialize_AILow_m);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &PCont_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = PCont_P.HILInitialize_AIHigh_p;
        }
      }

      result = hil_set_analog_input_ranges(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_AIChannels, 8U,
        &PCont_DW.HILInitialize_AIMinimums[0],
        &PCont_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_AOPStart_b && !is_switching) ||
        (PCont_P.HILInitialize_AOPEnter_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &PCont_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (PCont_P.HILInitialize_AOLow_n);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &PCont_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = PCont_P.HILInitialize_AOHigh_n;
        }
      }

      result = hil_set_analog_output_ranges(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_AOChannels_p, 8U,
        &PCont_DW.HILInitialize_AOMinimums[0],
        &PCont_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_AOStart_k && !is_switching) ||
        (PCont_P.HILInitialize_AOEnter_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PCont_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PCont_P.HILInitialize_AOInitial_b;
        }
      }

      result = hil_write_analog(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_AOChannels_p, 8U,
        &PCont_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if (PCont_P.HILInitialize_AOReset_b) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PCont_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PCont_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (PCont_DW.HILInitialize_Card_k, PCont_P.HILInitialize_AOChannels_p, 8U,
         &PCont_DW.HILInitialize_AOVoltages_a[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_EIPStart_j && !is_switching) ||
        (PCont_P.HILInitialize_EIPEnter_i && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &PCont_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = PCont_P.HILInitialize_EIQuadrature_e;
        }
      }

      result = hil_set_encoder_quadrature_mode(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &PCont_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_EIStart_a && !is_switching) ||
        (PCont_P.HILInitialize_EIEnter_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &PCont_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = PCont_P.HILInitialize_EIInitial_d;
        }
      }

      result = hil_set_encoder_counts(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_EIChannels, 8U,
        &PCont_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_POPStart_a && !is_switching) ||
        (PCont_P.HILInitialize_POPEnter_b && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &PCont_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PCont_P.HILInitialize_POModes_k;
        }
      }

      result = hil_set_pwm_mode(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &PCont_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          PCont_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &PCont_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            PCont_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            PCont_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              PCont_P.HILInitialize_POFrequency_c;
            num_duty_cycle_modes++;
          } else {
            PCont_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            PCont_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              PCont_P.HILInitialize_POFrequency_c;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(PCont_DW.HILInitialize_Card_k,
          &PCont_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &PCont_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PCont_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(PCont_DW.HILInitialize_Card_k,
          &PCont_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &PCont_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PCont_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &PCont_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = PCont_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &PCont_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = PCont_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &PCont_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = PCont_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &PCont_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &PCont_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &PCont_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &PCont_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = PCont_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &PCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PCont_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_POChannels, 8U,
        &PCont_DW.HILInitialize_POSortedFreqs[0],
        &PCont_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if ((PCont_P.HILInitialize_POStart_n && !is_switching) ||
        (PCont_P.HILInitialize_POEnter_n && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PCont_P.HILInitialize_POInitial_g;
        }
      }

      result = hil_write_pwm(PCont_DW.HILInitialize_Card_k,
        PCont_P.HILInitialize_POChannels, 8U, &PCont_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }

    if (PCont_P.HILInitialize_POReset_d) {
      {
        int_T i1;
        real_T *dw_POValues = &PCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PCont_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (PCont_DW.HILInitialize_Card_k, PCont_P.HILInitialize_POChannels, 8U,
         &PCont_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Atomic SubSystem: '<S56>/Bias Removal' */
  PCont_BiasRemoval_Start(&PCont_DW.BiasRemoval);

  /* End of Start for SubSystem: '<S56>/Bias Removal' */

  /* Start for Atomic SubSystem: '<S56>/Bias Removal1' */
  PCont_BiasRemoval_Start(&PCont_DW.BiasRemoval1);

  /* End of Start for SubSystem: '<S56>/Bias Removal1' */

  /* Start for Constant: '<S62>/x0' */
  PCont_B.x0 = PCont_P.x0_Value;

  /* Start for Constant: '<S63>/x0' */
  PCont_B.x0_h = PCont_P.x0_Value_d;

  /* Start for Constant: '<Root>/Speed' */
  PCont_B.Speed = PCont_P.Speed_Value;
  PCont_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S62>/Integrator1' incorporates:
   *  Integrator: '<S63>/Integrator1'
   */
  if (rtmIsFirstInitCond(PCont_M)) {
    PCont_X.Integrator1_CSTATE = 0.0;
    PCont_X.Integrator1_CSTATE_l = 0.0;
  }

  PCont_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S62>/Integrator1' */

  /* InitializeConditions for Integrator: '<S62>/Integrator2' */
  PCont_X.Integrator2_CSTATE = PCont_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S63>/Integrator1' */
  PCont_DW.Integrator1_IWORK_b = 1;

  /* InitializeConditions for Integrator: '<S63>/Integrator2' */
  PCont_X.Integrator2_CSTATE_j = PCont_P.Integrator2_IC_h;

  /* InitializeConditions for Derivative: '<S58>/Derivative' */
  PCont_DW.TimeStampA = (rtInf);
  PCont_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  PCont_DW.TimeStampA_b = (rtInf);
  PCont_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative1' */
  PCont_DW.TimeStampA_n = (rtInf);
  PCont_DW.TimeStampB_k = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative2' */
  PCont_DW.TimeStampA_k = (rtInf);
  PCont_DW.TimeStampB_j = (rtInf);

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  PCont_X.Filter_CSTATE[0] = PCont_P.PDController_InitialConditionFo;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  PCont_X.Integrator_CSTATE[0] = PCont_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S34>/Filter' */
  PCont_X.Filter_CSTATE[1] = PCont_P.PDController_InitialConditionFo;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  PCont_X.Integrator_CSTATE[1] = PCont_P.Integrator_IC;

  /* SystemInitialize for Atomic SubSystem: '<S56>/Bias Removal' */
  PCont_BiasRemoval_Init(&PCont_B.BiasRemoval, &PCont_DW.BiasRemoval,
    &PCont_P.BiasRemoval);

  /* End of SystemInitialize for SubSystem: '<S56>/Bias Removal' */

  /* SystemInitialize for Atomic SubSystem: '<S56>/Bias Removal1' */
  PCont_BiasRemoval_Init(&PCont_B.BiasRemoval1, &PCont_DW.BiasRemoval1,
    &PCont_P.BiasRemoval1);

  /* End of SystemInitialize for SubSystem: '<S56>/Bias Removal1' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(PCont_M)) {
    rtmSetFirstInitCond(PCont_M, 0);
  }
}

/* Model terminate function */
void PCont_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S56>/HIL Initialize' */

  /* S-Function Block: PCont/Robot and Environment Subsystem/Force Sensor Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(PCont_DW.HILInitialize_Card);
    hil_monitor_stop_all(PCont_DW.HILInitialize_Card);
    is_switching = false;
    if ((PCont_P.HILInitialize_AOTerminate && !is_switching) ||
        (PCont_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(PCont_DW.HILInitialize_Card,
        &PCont_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &PCont_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(PCont_M, _rt_error_message);
      }
    }

    hil_task_delete_all(PCont_DW.HILInitialize_Card);
    hil_monitor_delete_all(PCont_DW.HILInitialize_Card);
    hil_close(PCont_DW.HILInitialize_Card);
    PCont_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (hil_initialize_block): '<S58>/HIL Initialize' */

  /* S-Function Block: PCont/Robot and Environment Subsystem/Robot Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(PCont_DW.HILInitialize_Card_k);
    hil_monitor_stop_all(PCont_DW.HILInitialize_Card_k);
    is_switching = false;
    if ((PCont_P.HILInitialize_AOTerminate_g && !is_switching) ||
        (PCont_P.HILInitialize_AOExit_e && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &PCont_DW.HILInitialize_AOVoltages_a[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = PCont_P.HILInitialize_AOFinal_m;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((PCont_P.HILInitialize_POTerminate_a && !is_switching) ||
        (PCont_P.HILInitialize_POExit_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &PCont_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = PCont_P.HILInitialize_POFinal_c;
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
      result = hil_write(PCont_DW.HILInitialize_Card_k
                         , PCont_P.HILInitialize_AOChannels_p,
                         num_final_analog_outputs
                         , PCont_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &PCont_DW.HILInitialize_AOVoltages_a[0]
                         , &PCont_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(PCont_DW.HILInitialize_Card_k,
            PCont_P.HILInitialize_AOChannels_p, num_final_analog_outputs,
            &PCont_DW.HILInitialize_AOVoltages_a[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(PCont_DW.HILInitialize_Card_k,
            PCont_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &PCont_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(PCont_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(PCont_DW.HILInitialize_Card_k);
    hil_monitor_delete_all(PCont_DW.HILInitialize_Card_k);
    hil_close(PCont_DW.HILInitialize_Card_k);
    PCont_DW.HILInitialize_Card_k = NULL;
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
  PCont_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  PCont_update(tid);
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
  PCont_initialize();
}

void MdlTerminate(void)
{
  PCont_terminate();
}

/* Registration function */
RT_MODEL_PCont_T *PCont(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PCont_M, 0,
                sizeof(RT_MODEL_PCont_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PCont_M->solverInfo, &PCont_M->Timing.simTimeStep);
    rtsiSetTPtr(&PCont_M->solverInfo, &rtmGetTPtr(PCont_M));
    rtsiSetStepSizePtr(&PCont_M->solverInfo, &PCont_M->Timing.stepSize0);
    rtsiSetdXPtr(&PCont_M->solverInfo, &PCont_M->derivs);
    rtsiSetContStatesPtr(&PCont_M->solverInfo, (real_T **) &PCont_M->contStates);
    rtsiSetNumContStatesPtr(&PCont_M->solverInfo, &PCont_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PCont_M->solverInfo,
      &PCont_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PCont_M->solverInfo,
      &PCont_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PCont_M->solverInfo,
      &PCont_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PCont_M->solverInfo, (&rtmGetErrorStatus(PCont_M)));
    rtsiSetRTModelPtr(&PCont_M->solverInfo, PCont_M);
  }

  rtsiSetSimTimeStep(&PCont_M->solverInfo, MAJOR_TIME_STEP);
  PCont_M->intgData.f[0] = PCont_M->odeF[0];
  PCont_M->contStates = ((real_T *) &PCont_X);
  rtsiSetSolverData(&PCont_M->solverInfo, (void *)&PCont_M->intgData);
  rtsiSetSolverName(&PCont_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PCont_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "PCont_M points to
       static memory which is guaranteed to be non-NULL" */
    PCont_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PCont_M->Timing.sampleTimes = (&PCont_M->Timing.sampleTimesArray[0]);
    PCont_M->Timing.offsetTimes = (&PCont_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PCont_M->Timing.sampleTimes[0] = (0.0);
    PCont_M->Timing.sampleTimes[1] = (0.002);
    PCont_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    PCont_M->Timing.offsetTimes[0] = (0.0);
    PCont_M->Timing.offsetTimes[1] = (0.0);
    PCont_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(PCont_M, &PCont_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PCont_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = PCont_M->Timing.perTaskSampleHitsArray;
    PCont_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    PCont_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PCont_M, 10.0);
  PCont_M->Timing.stepSize0 = 0.002;
  PCont_M->Timing.stepSize1 = 0.002;
  PCont_M->Timing.stepSize2 = 0.02;
  rtmSetFirstInitCond(PCont_M, 1);

  /* External mode info */
  PCont_M->Sizes.checksums[0] = (1343646904U);
  PCont_M->Sizes.checksums[1] = (976197579U);
  PCont_M->Sizes.checksums[2] = (2860448173U);
  PCont_M->Sizes.checksums[3] = (3140888897U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    PCont_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &PCont_DW.BiasRemoval.EnabledMovingAverage_SubsysRanB;
    systemRan[5] = (sysRanDType *)
      &PCont_DW.BiasRemoval.SwitchCaseActionSubsystem_Subsy;
    systemRan[6] = (sysRanDType *)
      &PCont_DW.BiasRemoval.SwitchCaseActionSubsystem1_Subs;
    systemRan[7] = (sysRanDType *)
      &PCont_DW.BiasRemoval.SwitchCaseActionSubsystem2_Subs;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &PCont_DW.BiasRemoval1.EnabledMovingAverage_SubsysRanB;
    systemRan[10] = (sysRanDType *)
      &PCont_DW.BiasRemoval1.SwitchCaseActionSubsystem_Subsy;
    systemRan[11] = (sysRanDType *)
      &PCont_DW.BiasRemoval1.SwitchCaseActionSubsystem1_Subs;
    systemRan[12] = (sysRanDType *)
      &PCont_DW.BiasRemoval1.SwitchCaseActionSubsystem2_Subs;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PCont_M->extModeInfo,
      &PCont_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PCont_M->extModeInfo, PCont_M->Sizes.checksums);
    rteiSetTPtr(PCont_M->extModeInfo, rtmGetTPtr(PCont_M));
  }

  PCont_M->solverInfoPtr = (&PCont_M->solverInfo);
  PCont_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&PCont_M->solverInfo, 0.002);
  rtsiSetSolverMode(&PCont_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  PCont_M->blockIO = ((void *) &PCont_B);
  (void) memset(((void *) &PCont_B), 0,
                sizeof(B_PCont_T));

  /* parameters */
  PCont_M->defaultParam = ((real_T *)&PCont_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PCont_X;
    PCont_M->contStates = (x);
    (void) memset((void *)&PCont_X, 0,
                  sizeof(X_PCont_T));
  }

  /* states (dwork) */
  PCont_M->dwork = ((void *) &PCont_DW);
  (void) memset((void *)&PCont_DW, 0,
                sizeof(DW_PCont_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PCont_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PCont_M->Sizes.numContStates = (8);  /* Number of continuous states */
  PCont_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PCont_M->Sizes.numY = (0);           /* Number of model outputs */
  PCont_M->Sizes.numU = (0);           /* Number of model inputs */
  PCont_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  PCont_M->Sizes.numSampTimes = (3);   /* Number of sample times */
  PCont_M->Sizes.numBlocks = (114);    /* Number of blocks */
  PCont_M->Sizes.numBlockIO = (40);    /* Number of block outputs */
  PCont_M->Sizes.numBlockPrms = (244); /* Sum of parameter "widths" */
  return PCont_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
