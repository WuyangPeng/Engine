//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:32)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_H
#define SYSTEM_THREADING_WAITABLE_TIMER_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/InitOnceUsing.h"
#include "Using/WaitableTimerUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 等待计时器的创建、销毁、等待和设置。

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, bool manualReset, const TChar* timerName) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemWaitableTimer(WindowSecurityAttributesPtr timerAttributes, const TChar* timerName, CreateWaitableTimerReset flag,
                                                                                MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemWaitableTimer(MutexStandardAccess desiredAccess, WaitableTimerSpecificAccess specificAccess, bool inheritHandle, const TChar* timerName) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CancelSystemWaitableTimer(WindowHandle timer) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemWaitableTimer(WindowHandle timer) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowHandle timer) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowHandle timer, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemWaitableTimer(WindowDWord count, const WindowHandle* timer, bool waitAll, WindowDWord milliseconds) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period, TimerApcRoutine completionRoutine,
                                                                     WindowVoidPtr argToCompletionRoutine, WaitableTimerReasonContextPtr wakeContext, WindowULong tolerableDelay) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemWaitableTimer(WindowHandle timer, const WindowLargeInteger* dueTime, WindowLong period,
                                                                     TimerApcRoutine completionRoutine, WindowVoidPtr argToCompletionRoutine, bool resume) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsWaitableTimerValid(WindowHandle handle) noexcept;
}

#endif  // SYSTEM_THREADING_WAITABLE_TIMER_H