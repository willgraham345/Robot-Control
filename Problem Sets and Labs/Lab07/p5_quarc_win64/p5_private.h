/*
 * p5_private.h
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

#ifndef RTW_HEADER_p5_private_h_
#define RTW_HEADER_p5_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "p5.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern void p5_JacobianTranspose1(const real_T rtu_F[2], const real_T rtu_phi[2],
  B_JacobianTranspose1_p5_T *localB);

/* private model entry point functions */
extern void p5_derivatives(void);

#endif                                 /* RTW_HEADER_p5_private_h_ */
