/*
 * compliance.h
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

#ifndef RTW_HEADER_compliance_h_
#define RTW_HEADER_compliance_h_
#include <emmintrin.h>
#include <math.h>
#include <string.h>
#ifndef compliance_COMMON_INCLUDES_
#define compliance_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* compliance_COMMON_INCLUDES_ */

#include "compliance_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define compliance_rtModel             RT_MODEL_compliance_T

/* Block signals for system '<S57>/Bias Removal' */
typedef struct {
  real_T Switch;                       /* '<S61>/Switch' */
  real_T VVavg;                        /* '<S68>/V-Vavg' */
  real_T Vin;                          /* '<S67>/Vin' */
  real_T Constant;                     /* '<S66>/Constant' */
  real_T Count;                        /* '<S69>/Count' */
  real_T Sum;                          /* '<S65>/Sum' */
  real_T div;                          /* '<S65>/div' */
} B_BiasRemoval_compliance_T;

/* Block states (default storage) for system '<S57>/Bias Removal' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S69>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE;             /* '<S65>/Sum( k=1,n-1, x(k) )' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S61>/Switch Case' */
  int8_T SwitchCaseActionSubsystem2_Subs;
                                     /* '<S61>/Switch Case Action Subsystem2' */
  int8_T SwitchCaseActionSubsystem1_Subs;
                                     /* '<S61>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S61>/Switch Case Action Subsystem' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S61>/Enabled Moving Average' */
  boolean_T EnabledMovingAverage_MODE; /* '<S61>/Enabled Moving Average' */
} DW_BiasRemoval_compliance_T;

/* Block signals (default storage) */
typedef struct {
  real_T XGainNV;                      /* '<S57>/X Gain (N//V)' */
  real_T YGainNV;                      /* '<S57>/Y Gain (N//V)' */
  real_T x0;                           /* '<S63>/x0' */
  real_T Integrator1;                  /* '<S63>/Integrator1' */
  real_T Product;                      /* '<S63>/Product' */
  real_T Product1;                     /* '<S63>/Product1' */
  real_T x0_i;                         /* '<S64>/x0' */
  real_T Integrator1_f;                /* '<S64>/Integrator1' */
  real_T Product_e;                    /* '<S64>/Product' */
  real_T Product1_p;                   /* '<S64>/Product1' */
  real_T EncoderGain[2];               /* '<S59>/Encoder Gain' */
  real_T Derivative[2];                /* '<Root>/Derivative' */
  real_T Sum2[2];                      /* '<Root>/Sum2' */
  real_T FilterCoefficient[2];         /* '<S43>/Filter Coefficient' */
  real_T current[2];                   /* '<S6>/inv motor gain' */
  real_T uAmpGain[2];                  /* '<S59>/1//AmpGain' */
  real_T uSenseGain[2];                /* '<S59>/1//Sense Gain' */
  real_T RateTransition[2];            /* '<Root>/Rate Transition' */
  real_T x[2];                         /* '<Root>/Trajectory  Generator' */
  real_T F0[2];                        /* '<S6>/Rotation to Base Frame' */
  real_T x_i[2];                       /* '<S6>/Forward Kinematics' */
  B_BiasRemoval_compliance_T BiasRemoval1;/* '<S57>/Bias Removal1' */
  B_BiasRemoval_compliance_T BiasRemoval;/* '<S57>/Bias Removal' */
} B_compliance_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOVoltages;     /* '<S57>/HIL Initialize' */
  real_T HILInitialize_AIMinimums[8];  /* '<S59>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[8];  /* '<S59>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[8];  /* '<S59>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[8];  /* '<S59>/HIL Initialize' */
  real_T HILInitialize_AOVoltages_a[8];/* '<S59>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[8];/* '<S59>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[8];/* '<S59>/HIL Initialize' */
  real_T HILInitialize_POValues[8];    /* '<S59>/HIL Initialize' */
  real_T HILReadAnalog_Buffer[2];      /* '<S57>/HIL Read Analog' */
  real_T TimeStampA;                   /* '<S59>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S59>/Derivative' */
  real_T TimeStampB;                   /* '<S59>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S59>/Derivative' */
  real_T TimeStampA_c;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeA_b[2];            /* '<Root>/Derivative' */
  real_T TimeStampB_p;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeB_p[2];            /* '<Root>/Derivative' */
  real_T TimeStampA_j;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_o[2];            /* '<Root>/Derivative1' */
  real_T TimeStampB_p5;                /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_m[2];            /* '<Root>/Derivative1' */
  real_T XYSuperimposed_XBuffer[20000];/* '<S8>/XY Superimposed' */
  real_T XYSuperimposed_YBuffer[20000];/* '<S8>/XY Superimposed' */
  real_T RateTransition_Buffer[2];     /* '<Root>/Rate Transition' */
  t_card HILInitialize_Card;           /* '<S57>/HIL Initialize' */
  t_card HILInitialize_Card_k;         /* '<S59>/HIL Initialize' */
  void *HILReadAnalog_PWORK;           /* '<S57>/HIL Read Analog' */
  void *HILReadEncoder_PWORK;          /* '<S59>/HIL Read Encoder' */
  void *HILWriteAnalog_PWORK;          /* '<S59>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } MotorCurrentCommands_PWORK;        /* '<S59>/Motor Current Commands' */

  void *HILReadAnalog_PWORK_a;         /* '<S59>/HIL Read Analog' */
  struct {
    void *LoggedData;
  } ActualMotorCurrents_PWORK;         /* '<S59>/Actual Motor Currents' */

  struct {
    void *LoggedData;
  } ForcesinEndEffectorFrame_PWORK;    /* '<S6>/Forces in End-Effector Frame' */

  struct {
    void *LoggedData;
  } F_PWORK;                           /* '<Root>/F' */

  struct {
    void *LoggedData;
  } XYErrors_PWORK;                    /* '<Root>/XY Errors' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S8>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S8>/To Workspace2' */

  struct {
    void *LoggedData;
  } Phi_PWORK;                         /* '<Root>/Phi' */

  int32_T HILInitialize_ClockModes[3]; /* '<S59>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[8];/* '<S59>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[8];/* '<S59>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[8];/* '<S59>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[8];/* '<S59>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[8];/* '<S59>/HIL Initialize' */
  int32_T HILReadEncoder_Buffer[2];    /* '<S59>/HIL Read Encoder' */
  uint32_T HILInitialize_POSortedChans[8];/* '<S59>/HIL Initialize' */
  int_T Integrator1_IWORK;             /* '<S63>/Integrator1' */
  int_T Integrator1_IWORK_f;           /* '<S64>/Integrator1' */
  int_T XYSuperimposed_IWORK[2];       /* '<S8>/XY Superimposed' */
  boolean_T XYSuperimposed_IsFull;     /* '<S8>/XY Superimposed' */
  DW_BiasRemoval_compliance_T BiasRemoval1;/* '<S57>/Bias Removal1' */
  DW_BiasRemoval_compliance_T BiasRemoval;/* '<S57>/Bias Removal' */
} DW_compliance_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S63>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S63>/Integrator2' */
  real_T Integrator1_CSTATE_d;         /* '<S64>/Integrator1' */
  real_T Integrator2_CSTATE_m;         /* '<S64>/Integrator2' */
  real_T yAdmittance1_CSTATE[2];       /* '<Root>/y Admittance1' */
  real_T Filter_CSTATE[2];             /* '<S35>/Filter' */
} X_compliance_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S63>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S63>/Integrator2' */
  real_T Integrator1_CSTATE_d;         /* '<S64>/Integrator1' */
  real_T Integrator2_CSTATE_m;         /* '<S64>/Integrator2' */
  real_T yAdmittance1_CSTATE[2];       /* '<Root>/y Admittance1' */
  real_T Filter_CSTATE[2];             /* '<S35>/Filter' */
} XDot_compliance_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S63>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S63>/Integrator2' */
  boolean_T Integrator1_CSTATE_d;      /* '<S64>/Integrator1' */
  boolean_T Integrator2_CSTATE_m;      /* '<S64>/Integrator2' */
  boolean_T yAdmittance1_CSTATE[2];    /* '<Root>/y Admittance1' */
  boolean_T Filter_CSTATE[2];          /* '<S35>/Filter' */
} XDis_compliance_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            compliance_B
#define BlockIO                        B_compliance_T
#define rtX                            compliance_X
#define ContinuousStates               X_compliance_T
#define rtXdot                         compliance_XDot
#define StateDerivatives               XDot_compliance_T
#define tXdis                          compliance_XDis
#define StateDisabled                  XDis_compliance_T
#define rtP                            compliance_P
#define Parameters                     P_compliance_T
#define rtDWork                        compliance_DW
#define D_Work                         DW_compliance_T

/* Parameters for system: '<S57>/Bias Removal' */
struct P_BiasRemoval_compliance_T_ {
  real_T x_avg_n_Y0;                   /* Computed Parameter: x_avg_n_Y0
                                        * Referenced by: '<S65>/x_avg_n'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S69>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S69>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S65>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S66>/zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S67>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S68>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S61>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S61>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S61>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S61>/Step: end_time'
                                        */
};

/* Parameters (default storage) */
struct P_compliance_T_ {
  real_T PDController_D[2];            /* Mask Parameter: PDController_D
                                        * Referenced by: '<S34>/Derivative Gain'
                                        */
  real_T PDController_InitialConditionFo;
                              /* Mask Parameter: PDController_InitialConditionFo
                               * Referenced by: '<S35>/Filter'
                               */
  real_T PDController_N;               /* Mask Parameter: PDController_N
                                        * Referenced by: '<S43>/Filter Coefficient'
                                        */
  real_T PDController_P[2];            /* Mask Parameter: PDController_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S57>/Bias Removal'
                                        */
  real_T BiasRemoval1_end_time;        /* Mask Parameter: BiasRemoval1_end_time
                                        * Referenced by: '<S57>/Bias Removal1'
                                        */
  real_T SecondOrderLowPassFilter_input_;
                              /* Mask Parameter: SecondOrderLowPassFilter_input_
                               * Referenced by: '<S63>/wn'
                               */
  real_T SecondOrderLowPassFilter1_input;
                              /* Mask Parameter: SecondOrderLowPassFilter1_input
                               * Referenced by: '<S64>/wn'
                               */
  real_T SecondOrderLowPassFilter_inpu_o;
                              /* Mask Parameter: SecondOrderLowPassFilter_inpu_o
                               * Referenced by: '<S63>/zt'
                               */
  real_T SecondOrderLowPassFilter1_inp_b;
                              /* Mask Parameter: SecondOrderLowPassFilter1_inp_b
                               * Referenced by: '<S64>/zt'
                               */
  real_T XYSuperimposed_maximum_x;   /* Mask Parameter: XYSuperimposed_maximum_x
                                      * Referenced by: '<S8>/XY Superimposed'
                                      */
  real_T XYSuperimposed_maximum_y;   /* Mask Parameter: XYSuperimposed_maximum_y
                                      * Referenced by: '<S8>/XY Superimposed'
                                      */
  real_T XYSuperimposed_minimum_x;   /* Mask Parameter: XYSuperimposed_minimum_x
                                      * Referenced by: '<S8>/XY Superimposed'
                                      */
  real_T XYSuperimposed_minimum_y;   /* Mask Parameter: XYSuperimposed_minimum_y
                                      * Referenced by: '<S8>/XY Superimposed'
                                      */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S57>/Bias Removal'
                                        */
  real_T BiasRemoval1_start_time;     /* Mask Parameter: BiasRemoval1_start_time
                                       * Referenced by: '<S57>/Bias Removal1'
                                       */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S57>/Bias Removal'
                                        */
  real_T BiasRemoval1_switch_id;       /* Mask Parameter: BiasRemoval1_switch_id
                                        * Referenced by: '<S57>/Bias Removal1'
                                        */
  int32_T XYSuperimposed_update_rate;
                                   /* Mask Parameter: XYSuperimposed_update_rate
                                    * Referenced by: '<S8>/XY Superimposed'
                                    */
  uint32_T HILReadAnalog_channels[2];  /* Mask Parameter: HILReadAnalog_channels
                                        * Referenced by: '<S57>/HIL Read Analog'
                                        */
  uint32_T HILReadEncoder_channels[2];/* Mask Parameter: HILReadEncoder_channels
                                       * Referenced by: '<S59>/HIL Read Encoder'
                                       */
  uint32_T HILWriteAnalog_channels[2];/* Mask Parameter: HILWriteAnalog_channels
                                       * Referenced by: '<S59>/HIL Write Analog'
                                       */
  uint32_T HILReadAnalog_channels_c[2];
                                     /* Mask Parameter: HILReadAnalog_channels_c
                                      * Referenced by: '<S59>/HIL Read Analog'
                                      */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<S57>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;    /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S57>/HIL Initialize'
                                        */
  real_T HILInitialize_OOTerminate_j;
                                   /* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<S59>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit_d;  /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart_h;      /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter_i;  /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<S59>/HIL Initialize'
                                    */
  real_T HILInitialize_AOFinal_m;      /* Expression: final_analog_outputs
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal_c;      /* Expression: final_pwm_outputs
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh_p;       /* Expression: analog_input_maximums
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow_m;        /* Expression: analog_input_minimums
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh_n;       /* Expression: analog_output_maximums
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow_n;        /* Expression: analog_output_minimums
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial_b;    /* Expression: initial_analog_outputs
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency_c;  /* Expression: pwm_frequency
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_POLeading;      /* Expression: pwm_leading_deadband
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_POTrailing;     /* Expression: pwm_trailing_deadband
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial_g;    /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S59>/HIL Initialize'
                                        */
  real_T XGainNV_Gain;                 /* Expression: 4000
                                        * Referenced by: '<S57>/X Gain (N//V)'
                                        */
  real_T YGainNV_Gain;                 /* Expression: 4000
                                        * Referenced by: '<S57>/Y Gain (N//V)'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S63>/x0'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S63>/Integrator2'
                                        */
  real_T Constant_Value_m;             /* Expression: 2
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T x0_Value_a;                   /* Expression: input_init
                                        * Referenced by: '<S64>/x0'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S64>/Integrator2'
                                        */
  real_T HomePosition_Value[2];        /* Expression: [1024;0]
                                        * Referenced by: '<S59>/Home Position'
                                        */
  real_T EncoderGain_Gain[2];          /* Expression: [2*pi/4096 ; -2*pi/4096]
                                        * Referenced by: '<S59>/Encoder Gain'
                                        */
  real_T Speed_Value;                  /* Expression: 0.2
                                        * Referenced by: '<Root>/Speed'
                                        */
  real_T xAdmittance_Gain;             /* Expression: 0
                                        * Referenced by: '<Root>/x Admittance'
                                        */
  real_T yAdmittance1_A[2];            /* Computed Parameter: yAdmittance1_A
                                        * Referenced by: '<Root>/y Admittance1'
                                        */
  real_T yAdmittance1_C[2];            /* Computed Parameter: yAdmittance1_C
                                        * Referenced by: '<Root>/y Admittance1'
                                        */
  real_T invmotorgain_Gain;            /* Expression: 1/.539
                                        * Referenced by: '<S6>/inv motor gain'
                                        */
  real_T AmpBiasTuneforeachampifneeded_B[2];/* Expression: [-0.035; 0.039]
                                             * Referenced by: '<S59>/Amp Bias Tune for each amp if needed'
                                             */
  real_T uAmpGain_Gain[2];             /* Expression: [10;-10]
                                        * Referenced by: '<S59>/1//AmpGain'
                                        */
  real_T uSenseGain_Gain;              /* Expression: 2
                                        * Referenced by: '<S59>/1//Sense Gain'
                                        */
  int32_T HILInitialize_EIInitial;/* Computed Parameter: HILInitialize_EIInitial
                                   * Referenced by: '<S57>/HIL Initialize'
                                   */
  int32_T HILInitialize_POModes;    /* Computed Parameter: HILInitialize_POModes
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  int32_T HILInitialize_CKChannels[3];
                                 /* Computed Parameter: HILInitialize_CKChannels
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  int32_T HILInitialize_DOWatchdog;
                                 /* Computed Parameter: HILInitialize_DOWatchdog
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  int32_T HILInitialize_EIInitial_d;
                                /* Computed Parameter: HILInitialize_EIInitial_d
                                 * Referenced by: '<S59>/HIL Initialize'
                                 */
  int32_T HILInitialize_POModes_k;/* Computed Parameter: HILInitialize_POModes_k
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  int32_T HILInitialize_POConfiguration;
                            /* Computed Parameter: HILInitialize_POConfiguration
                             * Referenced by: '<S59>/HIL Initialize'
                             */
  int32_T HILInitialize_POAlignment;
                                /* Computed Parameter: HILInitialize_POAlignment
                                 * Referenced by: '<S59>/HIL Initialize'
                                 */
  int32_T HILInitialize_POPolarity;
                                 /* Computed Parameter: HILInitialize_POPolarity
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  uint32_T HILInitialize_AOChannels;
                                 /* Computed Parameter: HILInitialize_AOChannels
                                  * Referenced by: '<S57>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature;
                               /* Computed Parameter: HILInitialize_EIQuadrature
                                * Referenced by: '<S57>/HIL Initialize'
                                */
  uint32_T HILInitialize_AIChannels[8];
                                 /* Computed Parameter: HILInitialize_AIChannels
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  uint32_T HILInitialize_AOChannels_p[8];
                               /* Computed Parameter: HILInitialize_AOChannels_p
                                * Referenced by: '<S59>/HIL Initialize'
                                */
  uint32_T HILInitialize_EIChannels[8];
                                 /* Computed Parameter: HILInitialize_EIChannels
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature_e;
                             /* Computed Parameter: HILInitialize_EIQuadrature_e
                              * Referenced by: '<S59>/HIL Initialize'
                              */
  uint32_T HILInitialize_POChannels[8];
                                 /* Computed Parameter: HILInitialize_POChannels
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<S57>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<S57>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<S57>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<S57>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<S57>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<S57>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<S57>/HIL Initialize'
                                      */
  boolean_T HILInitialize_CKPStart;/* Computed Parameter: HILInitialize_CKPStart
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPEnter;/* Computed Parameter: HILInitialize_CKPEnter
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKStart;  /* Computed Parameter: HILInitialize_CKStart
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_CKEnter;  /* Computed Parameter: HILInitialize_CKEnter
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AIPStart;/* Computed Parameter: HILInitialize_AIPStart
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AIPEnter;/* Computed Parameter: HILInitialize_AIPEnter
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPStart;/* Computed Parameter: HILInitialize_AOPStart
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPEnter;/* Computed Parameter: HILInitialize_AOPEnter
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOStart;  /* Computed Parameter: HILInitialize_AOStart
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOEnter;  /* Computed Parameter: HILInitialize_AOEnter
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOReset;  /* Computed Parameter: HILInitialize_AOReset
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOPStart;/* Computed Parameter: HILInitialize_DOPStart
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOPEnter;/* Computed Parameter: HILInitialize_DOPEnter
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOStart;  /* Computed Parameter: HILInitialize_DOStart
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOEnter;  /* Computed Parameter: HILInitialize_DOEnter
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOReset;  /* Computed Parameter: HILInitialize_DOReset
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIPStart;/* Computed Parameter: HILInitialize_EIPStart
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIPEnter;/* Computed Parameter: HILInitialize_EIPEnter
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIStart;  /* Computed Parameter: HILInitialize_EIStart
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIEnter;  /* Computed Parameter: HILInitialize_EIEnter
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POPStart;/* Computed Parameter: HILInitialize_POPStart
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POPEnter;/* Computed Parameter: HILInitialize_POPEnter
                                    * Referenced by: '<S57>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POStart;  /* Computed Parameter: HILInitialize_POStart
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POEnter;  /* Computed Parameter: HILInitialize_POEnter
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POReset;  /* Computed Parameter: HILInitialize_POReset
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_OOReset;  /* Computed Parameter: HILInitialize_OOReset
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<S57>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOInitial;
                                  /* Computed Parameter: HILInitialize_DOInitial
                                   * Referenced by: '<S57>/HIL Initialize'
                                   */
  boolean_T HILInitialize_Active_e;/* Computed Parameter: HILInitialize_Active_e
                                    * Referenced by: '<S59>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOTerminate_g;
                              /* Computed Parameter: HILInitialize_AOTerminate_g
                               * Referenced by: '<S59>/HIL Initialize'
                               */
  boolean_T HILInitialize_AOExit_e;/* Computed Parameter: HILInitialize_AOExit_e
                                    * Referenced by: '<S59>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOTerminate_c;
                              /* Computed Parameter: HILInitialize_DOTerminate_c
                               * Referenced by: '<S59>/HIL Initialize'
                               */
  boolean_T HILInitialize_DOExit_m;/* Computed Parameter: HILInitialize_DOExit_m
                                    * Referenced by: '<S59>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POTerminate_a;
                              /* Computed Parameter: HILInitialize_POTerminate_a
                               * Referenced by: '<S59>/HIL Initialize'
                               */
  boolean_T HILInitialize_POExit_l;/* Computed Parameter: HILInitialize_POExit_l
                                    * Referenced by: '<S59>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPStart_b;
                                 /* Computed Parameter: HILInitialize_CKPStart_b
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_CKPEnter_o;
                                 /* Computed Parameter: HILInitialize_CKPEnter_o
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_CKStart_i;
                                  /* Computed Parameter: HILInitialize_CKStart_i
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_CKEnter_p;
                                  /* Computed Parameter: HILInitialize_CKEnter_p
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_AIPStart_j;
                                 /* Computed Parameter: HILInitialize_AIPStart_j
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_AIPEnter_e;
                                 /* Computed Parameter: HILInitialize_AIPEnter_e
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_AOPStart_b;
                                 /* Computed Parameter: HILInitialize_AOPStart_b
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_AOPEnter_p;
                                 /* Computed Parameter: HILInitialize_AOPEnter_p
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_AOStart_k;
                                  /* Computed Parameter: HILInitialize_AOStart_k
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_AOEnter_m;
                                  /* Computed Parameter: HILInitialize_AOEnter_m
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_AOReset_b;
                                  /* Computed Parameter: HILInitialize_AOReset_b
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_DOPStart_m;
                                 /* Computed Parameter: HILInitialize_DOPStart_m
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_DOPEnter_m;
                                 /* Computed Parameter: HILInitialize_DOPEnter_m
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_DOStart_e;
                                  /* Computed Parameter: HILInitialize_DOStart_e
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_DOEnter_l;
                                  /* Computed Parameter: HILInitialize_DOEnter_l
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_DOReset_h;
                                  /* Computed Parameter: HILInitialize_DOReset_h
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_EIPStart_j;
                                 /* Computed Parameter: HILInitialize_EIPStart_j
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_EIPEnter_i;
                                 /* Computed Parameter: HILInitialize_EIPEnter_i
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_EIStart_a;
                                  /* Computed Parameter: HILInitialize_EIStart_a
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_EIEnter_h;
                                  /* Computed Parameter: HILInitialize_EIEnter_h
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_POPStart_a;
                                 /* Computed Parameter: HILInitialize_POPStart_a
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_POPEnter_b;
                                 /* Computed Parameter: HILInitialize_POPEnter_b
                                  * Referenced by: '<S59>/HIL Initialize'
                                  */
  boolean_T HILInitialize_POStart_n;
                                  /* Computed Parameter: HILInitialize_POStart_n
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_POEnter_n;
                                  /* Computed Parameter: HILInitialize_POEnter_n
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_POReset_d;
                                  /* Computed Parameter: HILInitialize_POReset_d
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_OOReset_p;
                                  /* Computed Parameter: HILInitialize_OOReset_p
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_DOFinal_l;
                                  /* Computed Parameter: HILInitialize_DOFinal_l
                                   * Referenced by: '<S59>/HIL Initialize'
                                   */
  boolean_T HILInitialize_DOInitial_d;
                                /* Computed Parameter: HILInitialize_DOInitial_d
                                 * Referenced by: '<S59>/HIL Initialize'
                                 */
  boolean_T HILReadAnalog_Active;    /* Computed Parameter: HILReadAnalog_Active
                                      * Referenced by: '<S57>/HIL Read Analog'
                                      */
  boolean_T HILReadEncoder_Active;  /* Computed Parameter: HILReadEncoder_Active
                                     * Referenced by: '<S59>/HIL Read Encoder'
                                     */
  boolean_T HILWriteAnalog_Active;  /* Computed Parameter: HILWriteAnalog_Active
                                     * Referenced by: '<S59>/HIL Write Analog'
                                     */
  boolean_T HILReadAnalog_Active_c;/* Computed Parameter: HILReadAnalog_Active_c
                                    * Referenced by: '<S59>/HIL Read Analog'
                                    */
  uint8_T XYSuperimposed_Mode;        /* Computed Parameter: XYSuperimposed_Mode
                                       * Referenced by: '<S8>/XY Superimposed'
                                       */
  P_BiasRemoval_compliance_T BiasRemoval1;/* '<S57>/Bias Removal1' */
  P_BiasRemoval_compliance_T BiasRemoval;/* '<S57>/Bias Removal' */
};

/* Real-time Model Data Structure */
struct tag_RTM_compliance_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][8];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_compliance_T compliance_P;

/* Block signals (default storage) */
extern B_compliance_T compliance_B;

/* Continuous states (default storage) */
extern X_compliance_T compliance_X;

/* Block states (default storage) */
extern DW_compliance_T compliance_DW;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void compliance_initialize(void);
extern void compliance_output0(void);
extern void compliance_update0(void);
extern void compliance_output2(void);
extern void compliance_update2(void);
extern void compliance_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern compliance_rtModel *compliance(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_compliance_T *const compliance_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'compliance'
 * '<S1>'   : 'compliance/Feedback Comp'
 * '<S2>'   : 'compliance/Hx Matrix'
 * '<S3>'   : 'compliance/Jacobian Transpose'
 * '<S4>'   : 'compliance/Jacobiandot'
 * '<S5>'   : 'compliance/PD Controller'
 * '<S6>'   : 'compliance/Robot and Environment Subsystem'
 * '<S7>'   : 'compliance/Trajectory  Generator'
 * '<S8>'   : 'compliance/XY Plotter'
 * '<S9>'   : 'compliance/PD Controller/Anti-windup'
 * '<S10>'  : 'compliance/PD Controller/D Gain'
 * '<S11>'  : 'compliance/PD Controller/Filter'
 * '<S12>'  : 'compliance/PD Controller/Filter ICs'
 * '<S13>'  : 'compliance/PD Controller/I Gain'
 * '<S14>'  : 'compliance/PD Controller/Ideal P Gain'
 * '<S15>'  : 'compliance/PD Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'compliance/PD Controller/Integrator'
 * '<S17>'  : 'compliance/PD Controller/Integrator ICs'
 * '<S18>'  : 'compliance/PD Controller/N Copy'
 * '<S19>'  : 'compliance/PD Controller/N Gain'
 * '<S20>'  : 'compliance/PD Controller/P Copy'
 * '<S21>'  : 'compliance/PD Controller/Parallel P Gain'
 * '<S22>'  : 'compliance/PD Controller/Reset Signal'
 * '<S23>'  : 'compliance/PD Controller/Saturation'
 * '<S24>'  : 'compliance/PD Controller/Saturation Fdbk'
 * '<S25>'  : 'compliance/PD Controller/Sum'
 * '<S26>'  : 'compliance/PD Controller/Sum Fdbk'
 * '<S27>'  : 'compliance/PD Controller/Tracking Mode'
 * '<S28>'  : 'compliance/PD Controller/Tracking Mode Sum'
 * '<S29>'  : 'compliance/PD Controller/Tsamp - Integral'
 * '<S30>'  : 'compliance/PD Controller/Tsamp - Ngain'
 * '<S31>'  : 'compliance/PD Controller/postSat Signal'
 * '<S32>'  : 'compliance/PD Controller/preSat Signal'
 * '<S33>'  : 'compliance/PD Controller/Anti-windup/Disabled'
 * '<S34>'  : 'compliance/PD Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'compliance/PD Controller/Filter/Cont. Filter'
 * '<S36>'  : 'compliance/PD Controller/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'compliance/PD Controller/I Gain/Disabled'
 * '<S38>'  : 'compliance/PD Controller/Ideal P Gain/Passthrough'
 * '<S39>'  : 'compliance/PD Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'compliance/PD Controller/Integrator/Disabled'
 * '<S41>'  : 'compliance/PD Controller/Integrator ICs/Disabled'
 * '<S42>'  : 'compliance/PD Controller/N Copy/Disabled'
 * '<S43>'  : 'compliance/PD Controller/N Gain/Internal Parameters'
 * '<S44>'  : 'compliance/PD Controller/P Copy/Disabled'
 * '<S45>'  : 'compliance/PD Controller/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'compliance/PD Controller/Reset Signal/Disabled'
 * '<S47>'  : 'compliance/PD Controller/Saturation/Passthrough'
 * '<S48>'  : 'compliance/PD Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'compliance/PD Controller/Sum/Sum_PD'
 * '<S50>'  : 'compliance/PD Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'compliance/PD Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'compliance/PD Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'compliance/PD Controller/Tsamp - Integral/Disabled wSignal Specification'
 * '<S54>'  : 'compliance/PD Controller/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'compliance/PD Controller/postSat Signal/Forward_Path'
 * '<S56>'  : 'compliance/PD Controller/preSat Signal/Forward_Path'
 * '<S57>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem'
 * '<S58>'  : 'compliance/Robot and Environment Subsystem/Forward Kinematics'
 * '<S59>'  : 'compliance/Robot and Environment Subsystem/Robot Subsystem'
 * '<S60>'  : 'compliance/Robot and Environment Subsystem/Rotation to Base Frame'
 * '<S61>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal'
 * '<S62>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal1'
 * '<S63>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Second-Order Low-Pass Filter'
 * '<S64>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Second-Order Low-Pass Filter1'
 * '<S65>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal/Enabled Moving Average'
 * '<S66>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal/Switch Case Action Subsystem'
 * '<S67>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal/Switch Case Action Subsystem1'
 * '<S68>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal/Switch Case Action Subsystem2'
 * '<S69>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal/Enabled Moving Average/Increment'
 * '<S70>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal1/Enabled Moving Average'
 * '<S71>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal1/Switch Case Action Subsystem'
 * '<S72>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal1/Switch Case Action Subsystem1'
 * '<S73>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal1/Switch Case Action Subsystem2'
 * '<S74>'  : 'compliance/Robot and Environment Subsystem/Force Sensor Subsystem/Bias Removal1/Enabled Moving Average/Increment'
 */
#endif                                 /* RTW_HEADER_compliance_h_ */
