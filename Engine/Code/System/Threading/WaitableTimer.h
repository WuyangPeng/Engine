/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:15)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_H
#define SYSTEM_THREADING_WAITABLE_TIMER_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/WaitableTimerUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// �ȴ���ʱ���Ĵ��������١��ȴ������á�
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes,
                                                                                 bool manualReset,
                                                                                 const TChar* timerName) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes,
                                                                                 const TChar* timerName,
                                                                                 CreateWaitableTimerReset flag,
                                                                                 MutexStandardAccess desiredAccess,
                                                                                 WaitableTimerSpecificAccess specificAccess) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenSystemWaitableTimer(MutexStandardAccess desiredAccess,
                                                                               WaitableTimerSpecificAccess specificAccess,
                                                                               bool inheritHandle,
                                                                               const TChar* timerName) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CancelSystemWaitableTimer(WindowsHandle timer) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemWaitableTimer(WindowsHandle timer) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowsHandle timer) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowsHandle timer,
                                                                                WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowsHandle timer,
                                                                                WindowsDWord milliseconds,
                                                                                bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowsDWord count,
                                                                                const WindowsHandle* timer,
                                                                                bool waitAll,
                                                                                WindowsDWord milliseconds,
                                                                                bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowsDWord count,
                                                                                const WindowsHandle* timer,
                                                                                bool waitAll,
                                                                                WindowsDWord milliseconds) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemWaitableTimer(WindowsHandle timer,
                                                                 const WindowsLargeInteger* dueTime,
                                                                 WindowsLong period,
                                                                 TimerApcRoutine completionRoutine,
                                                                 WindowsVoidPtr argToCompletionRoutine,
                                                                 WaitableTimerReasonContextPtr wakeContext,
                                                                 WindowsULong tolerableDelay) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemWaitableTimer(WindowsHandle timer,
                                                                 const WindowsLargeInteger* dueTime,
                                                                 WindowsLong period,
                                                                 TimerApcRoutine completionRoutine,
                                                                 WindowsVoidPtr argToCompletionRoutine,
                                                                 bool resume) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsWaitableTimerValid(WindowsHandle handle) noexcept;
}

#endif  // SYSTEM_THREADING_WAITABLE_TIMER_H