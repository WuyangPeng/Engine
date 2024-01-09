/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 15:59)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FLAGS_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ThreadLocalStorageIndexes : uint32_t
    {
        OutOfIndexes = TLS_OUT_OF_INDEXES,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ThreadLocalStorageIndexes : uint32_t
    {
        OutOfIndexes = (0xFFFFFFFF),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FLAGS_H