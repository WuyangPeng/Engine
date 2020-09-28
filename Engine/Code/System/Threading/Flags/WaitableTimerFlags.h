//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 14:32)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H
#define SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class CreateWaitableTimerReset
    {
        CheckOnly = CREATE_WAITABLE_TIMER_MANUAL_RESET,
        Default = 0x00000000,
    };

    enum class WaitableTimerSpecificAccess
    {
        Default = 0x0000,
        ModifyState = TIMER_MODIFY_STATE,
        AllAccess = TIMER_ALL_ACCESS,
        QueryState = TIMER_QUERY_STATE,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class CreateWaitableTimerReset
    {
        CheckOnly = 0x00000001,
        Default = 0x00000000,
    };

    enum class WaitableTimerSpecificAccess
    {
        Default = 0x0000,
        ModifyState = 0x0002,
        AllAccess = 0x000F0000L | 0x00100000L | 0x3,
        QueryState = 0x0001,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H