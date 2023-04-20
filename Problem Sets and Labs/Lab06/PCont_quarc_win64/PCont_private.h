/*
 * PCont_private.h
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

#ifndef RTW_HEADER_PCont_private_h_
#define RTW_HEADER_PCont_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "PCont.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern void PCont_BiasRemoval_Init(B_BiasRemoval_PCont_T *localB,
  DW_BiasRemoval_PCont_T *localDW, P_BiasRemoval_PCont_T *localP);
extern void PCont_BiasRemoval_Start(DW_BiasRemoval_PCont_T *localDW);
extern void PCont_BiasRemoval_Update(B_BiasRemoval_PCont_T *localB,
  DW_BiasRemoval_PCont_T *localDW);
extern void PCont_BiasRemoval(RT_MODEL_PCont_T * const PCont_M, real_T rtu_V,
  real_T rtp_switch_id, real_T rtp_start_time, real_T rtp_end_time,
  B_BiasRemoval_PCont_T *localB, DW_BiasRemoval_PCont_T *localDW,
  P_BiasRemoval_PCont_T *localP);

/* private model entry point functions */
extern void PCont_derivatives(void);

#endif                                 /* RTW_HEADER_PCont_private_h_ */
