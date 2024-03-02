/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 17:45)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_USING_H
#define SYSTEM_THREADING_WAITABLE_TIMER_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using TimerApcRoutine = PTIMERAPCROUTINE;
    using WaitableTimerReasonContext = REASON_CONTEXT;
    using WaitableTimerReasonContextPtr = PREASON_CONTEXT;

#else  // !SYSTEM_PLATFORM_WIN32

    using TimerApcRoutine = void (*)(void* argToCompletionRoutine, uint32_t timerLowValue, uint32_t timerHighValue);

    struct WaitableTimerReasonContext
    {
        WindowsULong Version;
        uint32_t Flags;
        union
        {
            struct
            {
                void* LocalizedReasonModule;
                uint32_t LocalizedReasonId;
                uint32_t ReasonStringCount;
                TChar* ReasonStrings;
            } Detailed;

            TChar* SimpleReasonString;
        } Reason;
    };
    using WaitableTimerReasonContextPtr = WaitableTimerReasonContext*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_WAITABLE_TIMER_USING_H