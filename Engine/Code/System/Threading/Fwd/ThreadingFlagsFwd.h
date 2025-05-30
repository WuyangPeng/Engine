/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:08)

#ifndef SYSTEM_THREADING_THREADING_FLAGS_FWD_H
#define SYSTEM_THREADING_THREADING_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// ConditionVariable
    enum class ConditionVariableLockMode : int8_t;

    /// CriticalSection
    enum class CriticalSectionInfo;

    /// Event
    enum class EventSpecificAccess;
    enum class CreateEventType;

    /// InitOnce
    enum class InitOnceBeginInitialize : int8_t;

    /// Mutex
    enum class MutexCreate;
    enum class MutexSpecificAccess;
    enum class PThreadResult : uint32_t;
    enum class PThreadMutexCompatibility;

    /// Process
    enum class ProcessCreation : uint32_t;
    enum class ProcessStandardAccess;
    enum class ProcessSpecificAccess;

    /// Semaphore
    enum class MutexWait : uint32_t;
    enum class MutexWaitReturn : uint32_t;
    enum class MutexStandardAccess;
    enum class SemaphoreSpecificAccess;

    /// SyncTools
    enum class SleepReturn;

    /// Thread
    enum class ThreadCreation;
    enum class ThreadPriority;

    /// ThreadLocalStorage
    enum class ThreadLocalStorageIndexes : uint32_t;

    /// ThreadTools
    enum class ThreadStandardAccess;
    enum class ThreadSpecificAccess;
    enum class TokenStandardAccess;
    enum class TokenSpecificAccess;
    enum class ThreadContextState;

    /// WaitableTimer
    enum class CreateWaitableTimerReset;
    enum class WaitableTimerSpecificAccess;
}

#endif  // SYSTEM_THREADING_THREADING_FLAGS_FWD_H