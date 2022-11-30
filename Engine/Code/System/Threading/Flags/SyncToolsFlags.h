///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:02)

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