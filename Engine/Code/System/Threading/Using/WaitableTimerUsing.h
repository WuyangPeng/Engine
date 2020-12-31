//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:16)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_USING_H
#define SYSTEM_THREADING_WAITABLE_TIMER_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using TimerApcRoutine = PTIMERAPCROUTINE;
    using WaitableTimerReasonContext = REASON_CONTEXT;
    using WaitableTimerReasonContextPtr = PREASON_CONTEXT;

#else  // !SYSTEM_PLATFORM_WIN32

    uisng TimerApcRoutine = void(*)(void* argToCompletionRoutine, uint32_t timerLowValue, uint32_t timerHighValue);

    struct WaitableTimerReasonContext
    {
        WindowULong Version;
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