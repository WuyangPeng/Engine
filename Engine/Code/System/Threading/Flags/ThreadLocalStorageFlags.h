///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/04/25 11:22)

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