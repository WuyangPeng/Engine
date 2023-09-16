///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 18:14)

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