//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:49)

#ifndef SYSTEM_THREADING_DELTA_TIME_USING_H
#define SYSTEM_THREADING_DELTA_TIME_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_MACOS
    #include <sys/time.h>
#else  // !SYSTEM_PLATFORM_MACOS
    #include <sys/timeb.h>
    #ifdef SYSTEM_PLATFORM_WIN32
        #include <cstdlib>
    #endif  // SYSTEM_PLATFORM_WIN32
#endif  // SYSTEM_PLATFORM_MACOS

namespace System
{
#ifdef SYSTEM_PLATFORM_MACOS
    using DeltaTimeValue = timeval;
    using DeltaTimeB = timeval;
#else  // !SYSTEM_PLATFORM_MACOS
    struct DeltaTimeValue
    {
        int64_t tv_sec;
        int32_t tv_usec;
    };

    using DeltaTimeB = timeb;
#endif  // SYSTEM_PLATFORM_MACOS

    constexpr auto g_Microseconds = 1000000;
    constexpr auto g_Millisecond = 1000;
}

#endif  // SYSTEM_THREADING_DELTA_TIME_USING_H