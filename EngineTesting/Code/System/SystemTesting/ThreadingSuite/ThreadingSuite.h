///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/30 13:25)

#ifndef SYSTEM_THREADING_SUITE_H
#define SYSTEM_THREADING_SUITE_H

#include "ConditionVariable/ConditionVariableCriticalSectionTesting.h"
#include "ConditionVariable/ConditionVariableSlimReaderWriterLockTesting.h"
#include "CriticalSection/CriticalSectionTesting.h"
#include "CriticalSection/CriticalSectionThreadTesting.h"
#include "CriticalSection/SpecifyCriticalSectionAndSpinCountTesting.h"
#include "CriticalSection/SpecifyCriticalSectionTesting.h"
#include "Event/AutoEventThreadTesting.h"
#include "Event/CreateEventTesting.h"
#include "Event/CreateEventUseNameTesting.h"
#include "Event/ManualEventThreadTesting.h"
#include "Event/OpenEventTesting.h"
#include "Event/ResetEventTesting.h"
#include "Event/WaitForEventTesting.h"
#include "Event/WaitForMultipleEventTesting.h"
#include "InitOnce/InitOnceAsynchronousTesting.h"
#include "InitOnce/InitOnceSynchronousTesting.h"
#include "Interlocked/InterlockedBinaryTesting.h"
#include "Interlocked/InterlockedSubtractTesting.h"
#include "Interlocked/InterlockedTesting.h"
#include "Mutex/CreateDefaultMutexTesting.h"
#include "Mutex/CreateMutexTesting.h"
#include "Mutex/CreateMutexUseFlagsTesting.h"
#include "Mutex/CreateMutexUseNameTesting.h"
#include "Mutex/OpenMutexTesting.h"
#include "Mutex/PThreadMutexTesting.h"
#include "Mutex/ThreadMutexTesting.h"
#include "Mutex/WaitForMultipleMutexTesting.h"
#include "Mutex/WaitForMutexTesting.h"
#include "Process/CreateDefaultProcessTesting.h"
#include "Process/CreateProcessTesting.h"
#include "Process/ExitProcessTesting.h"
#include "Process/GetProcessHandleTesting.h"
#include "Process/OpenProcessTesting.h"
#include "Process/ProcessPriorityClassTesting.h"
#include "ProcessTools/ProcessTokenTesting.h"
#include "Semaphore/CreateSemaphoreThreadTesting.h"
#include "Semaphore/CreateSemaphoreThreadUseNameTesting.h"
#include "Semaphore/OpenSemaphoreTesting.h"
#include "Semaphore/ReleaseSemaphoreTesting.h"
#include "Semaphore/WaitMultipleSemaphoreTesting.h"
#include "Semaphore/WaitSemaphoreTesting.h"
#include "SlimReaderWriter/SlimReaderWriterInitializeTesting.h"
#include "SlimReaderWriter/SlimReaderWriterReaderTesting.h"
#include "SlimReaderWriter/SlimReaderWriterWriterTesting.h"
#include "SyncTools/SignalObjectAndWaitTesting.h"
#include "SyncTools/SleepTesting.h"
#include "Thread/CreateCThreadTesting.h"
#include "Thread/CreateDefaultThreadTesting.h"
#include "Thread/CreateSuspendedThreadTesting.h"
#include "Thread/GetCurrentThreadTesting.h"
#include "Thread/ThreadPriorityTesting.h"
#include "Thread/WaitForMultipleThreadTesting.h"
#include "Thread/WaitForThreadTesting.h"
#include "ThreadLocalStorageTesting.h"
#include "ThreadTools/OpenThreadTesting.h"
#include "ThreadTools/PriorityBoostTesting.h"
#include "ThreadTools/ThreadTimesTesting.h"
#include "ThreadTools/ThreadTokenTesting.h"
#include "WaitableTimer/CancelWaitableTimerTesting.h"
#include "WaitableTimer/CreateWaitableTimerManualTesting.h"
#include "WaitableTimer/CreateWaitableTimerManualUseFlagsTesting.h"
#include "WaitableTimer/CreateWaitableTimerSynchronizationTesting.h"
#include "WaitableTimer/CreateWaitableTimerSynchronizationUseFlagsTesting.h"
#include "WaitableTimer/CreateWaitableTimerUseNameTesting.h"
#include "WaitableTimer/OpenWaitableTimerTesting.h"
#include "WaitableTimer/SetWaitableTimerTesting.h"
#include "WaitableTimer/WaitForMultipleWaitableTimerTesting.h"
#include "WaitableTimer/WaitForWaitableTimerTesting.h"

#endif  // SYSTEM_THREADING_SUITE_H