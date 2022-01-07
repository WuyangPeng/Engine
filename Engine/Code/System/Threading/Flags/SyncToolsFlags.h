///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 16:51)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_FLAGS_H
#define SYSTEM_THREADING_SYNC_TOOLS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class SleepReturn
    {
        Succeed = 0,
        WaitIOCompletion = WAIT_IO_COMPLETION,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class SleepReturn
    {
        Succeed = 0,
        WaitIOCompletion = 0x000000C0L,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_SYNC_TOOLS_FLAGS_H