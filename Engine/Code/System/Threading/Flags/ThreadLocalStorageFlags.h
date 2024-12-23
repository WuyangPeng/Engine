/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:07)

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