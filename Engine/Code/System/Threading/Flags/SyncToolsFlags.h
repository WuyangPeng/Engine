//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 14:32)

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