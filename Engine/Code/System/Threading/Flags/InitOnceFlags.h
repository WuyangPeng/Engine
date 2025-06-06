/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 16:51)

#ifndef SYSTEM_THREADING_INIT_ONCE_FLAGS_H
#define SYSTEM_THREADING_INIT_ONCE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class InitOnceBeginInitialize : int8_t
    {
        CheckOnly = INIT_ONCE_CHECK_ONLY,
        Async = INIT_ONCE_ASYNC,
        InitFailed = INIT_ONCE_INIT_FAILED,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class InitOnceBeginInitialize : int8_t
    {
        CheckOnly = 0x00000001UL,
        Async = 0x00000002UL,
        InitFailed = 0x00000004UL,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_INIT_ONCE_FLAGS_H