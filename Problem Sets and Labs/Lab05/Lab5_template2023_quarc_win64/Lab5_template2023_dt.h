/*
 * Lab5_template2023_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab5_template2023".
 *
 * Model version              : 1.46
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Apr  6 12:38:41 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Lab5_template2023_B.XGainNV), 0, 0, 30 },

  { (char_T *)(&Lab5_template2023_B.BiasRemoval1.Switch), 0, 0, 7 },

  { (char_T *)(&Lab5_template2023_B.BiasRemoval.Switch), 0, 0, 7 }
  ,

  { (char_T *)(&Lab5_template2023_DW.HILInitialize_AOVoltages), 0, 0, 40075 },

  { (char_T *)(&Lab5_template2023_DW.HILInitialize_Card), 15, 0, 2 },

  { (char_T *)(&Lab5_template2023_DW.HILReadAnalog_PWORK), 11, 0, 12 },

  { (char_T *)(&Lab5_template2023_DW.HILInitialize_ClockModes[0]), 6, 0, 45 },

  { (char_T *)(&Lab5_template2023_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&Lab5_template2023_DW.Integrator1_IWORK), 10, 0, 4 },

  { (char_T *)(&Lab5_template2023_DW.XYSuperimposed_IsFull), 8, 0, 1 },

  { (char_T *)(&Lab5_template2023_DW.BiasRemoval1.UnitDelay_DSTATE), 0, 0, 2 },

  { (char_T *)(&Lab5_template2023_DW.BiasRemoval1.SwitchCase_ActiveSubsystem), 2,
    0, 5 },

  { (char_T *)(&Lab5_template2023_DW.BiasRemoval1.EnabledMovingAverage_MODE), 8,
    0, 1 },

  { (char_T *)(&Lab5_template2023_DW.BiasRemoval.UnitDelay_DSTATE), 0, 0, 2 },

  { (char_T *)(&Lab5_template2023_DW.BiasRemoval.SwitchCase_ActiveSubsystem), 2,
    0, 5 },

  { (char_T *)(&Lab5_template2023_DW.BiasRemoval.EnabledMovingAverage_MODE), 8,
    0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Lab5_template2023_P.PDController_D[0]), 0, 0, 20 },

  { (char_T *)(&Lab5_template2023_P.XYSuperimposed_update_rate), 6, 0, 1 },

  { (char_T *)(&Lab5_template2023_P.HILReadAnalog_channels[0]), 7, 0, 8 },

  { (char_T *)(&Lab5_template2023_P.HILInitialize_OOTerminate), 0, 0, 49 },

  { (char_T *)(&Lab5_template2023_P.HILInitialize_EIInitial), 6, 0, 11 },

  { (char_T *)(&Lab5_template2023_P.HILInitialize_AOChannels), 7, 0, 35 },

  { (char_T *)(&Lab5_template2023_P.HILInitialize_Active), 8, 0, 74 },

  { (char_T *)(&Lab5_template2023_P.XYSuperimposed_Mode), 3, 0, 1 },

  { (char_T *)(&Lab5_template2023_P.BiasRemoval1.x_avg_n_Y0), 0, 0, 12 },

  { (char_T *)(&Lab5_template2023_P.BiasRemoval.x_avg_n_Y0), 0, 0, 12 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  10U,
  rtPTransitions
};

/* [EOF] Lab5_template2023_dt.h */
