///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 16:52)

#ifndef SYSTEM_THREADING_THREADING_FLAGS_FWD_H
#define SYSTEM_THREADING_THREADING_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // ConditionVariable
    enum class ConditionVariableLockMode;

    // CriticalSection
    enum class CriticalSectionInfo;

    // Event
    enum class EventSpecificAccess;
    enum class CreateEventType;

    // HandleTools
    enum class HandleInformation;
    enum class DuplicateOptions;

    // InitOnce
    enum class InitOnceBeginInitialize;

    // Mutex
    enum class MutexCreate;
    enum class MutexSpecificAccess;
    enum class PthreadResult : uint32_t;
    enum class PthreadMutexCompatibility;

    // Proces
    enum class ProcessCreation : uint32_t;
    enum class ProcessStandardAccess;
    enum class ProcessSpecificAccess;

    // ProcessTools
    enum class ProcessAffinity;
    enum class ProcessorFeature;
    enum class ProcessShutdownParameters;
    enum class ProcessThreadAttribute;
    enum class CtrlEvent;
    enum class ProcessAttachConsole : uint32_t;
    enum class ProcessExitCode;

    // Semaphore
    enum class MutexWait : uint32_t;
    enum class MutexWaitReturn : uint32_t;
    enum class MutexStandardAccess;
    enum class SemaphoreSpecificAccess;

    // SyncTools
    enum class SleepReturn;

    // Thread
    enum class ThreadCreation;
    enum class ThreadPriority;

    // ThreadLocalStorage
    enum class ThreadLocalStorageIndexes : uint32_t;

    // ThreadTools
    enum class ThreadStandardAccess;
    enum class ThreadSpecificAccess;
    enum class TokenStandardAccess;
    enum class TokenSpecificAccess;
    enum class ThreadContextState;

    // WaitableTimer
    enum class CreateWaitableTimerReset;
    enum class WaitableTimerSpecificAccess;
}

#endif  // SYSTEM_THREADING_THREADING_FLAGS_FWD_H