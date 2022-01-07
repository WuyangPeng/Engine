///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 16:50)

#ifndef SYSTEM_THREADING_INIT_ONCE_FLAGS_H
#define SYSTEM_THREADING_INIT_ONCE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class InitOnceBeginInitialize
    {
        CheckOnly = INIT_ONCE_CHECK_ONLY,
        Async = INIT_ONCE_ASYNC,
        InitFailed = INIT_ONCE_INIT_FAILED,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class InitOnceBeginInitialize
    {
        CheckOnly = 0x00000001UL,
        Async = 0x00000002UL,
        InitFailed = 0x00000004UL,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_INIT_ONCE_FLAGS_H