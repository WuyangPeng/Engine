///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 16:52)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H
#define SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class CreateWaitableTimerReset
    {
        ManualReset = CREATE_WAITABLE_TIMER_MANUAL_RESET,
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
        ManualReset = 0x00000001,
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