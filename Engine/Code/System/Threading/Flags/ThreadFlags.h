///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:00)

#ifndef SYSTEM_THREADING_THREAD_FLAGS_H
#define SYSTEM_THREADING_THREAD_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ThreadCreation
    {
        Default = 0x00000000,
        CreateSuspended = CREATE_SUSPENDED,
        StackSizeParamIsAReservation = STACK_SIZE_PARAM_IS_A_RESERVATION,
    };

    enum class ThreadPriority
    {
        ModeBackgroundBegin = THREAD_MODE_BACKGROUND_BEGIN,
        ModeBackgroundEnd = THREAD_MODE_BACKGROUND_END,
        AboveNormal = THREAD_PRIORITY_ABOVE_NORMAL,
        BelowNormal = THREAD_PRIORITY_BELOW_NORMAL,
        Highest = THREAD_PRIORITY_HIGHEST,
        Idle = THREAD_PRIORITY_IDLE,
        Lowest = THREAD_PRIORITY_LOWEST,
        Normal = THREAD_PRIORITY_NORMAL,
        TimeCritical = THREAD_PRIORITY_TIME_CRITICAL,
        ErrorReturn = THREAD_PRIORITY_ERROR_RETURN,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ThreadCreation
    {
        Default = 0x00000000,
        CreateSuspended = 0x00000004,
        StackSizeParamIsAReservation = 0x00010000,
    };

    enum class ThreadPriority
    {
        ModeBackgroundBegin = 0x00010000,
        ModeBackgroundEnd = 0x00020000,
        AboveNormal = 1,
        BelowNormal = -1,
        Highest = 2,
        Idle = -15,
        Lowest = -2,
        Normal = 0,
        TimeCritical = 15,
        ErrorReturn = 0x7fffffff,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_THREAD_FLAGS_H