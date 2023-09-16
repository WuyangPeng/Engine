///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 18:16)

#ifndef SYSTEM_THREADING_MUTEX_USING_H
#define SYSTEM_THREADING_MUTEX_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    struct PThreadMutexAttrT
    {
    };

    using PThreadMutexT = WindowsHandle;

#else  // !SYSTEM_PLATFORM_WIN32

    // Linux/Apple的互斥锁类型。
    using PThreadMutexAttrT = pthread_mutexattr_t;
    using PThreadMutexT = pthread_mutex_t;

#endif  // SYSTEM_PLATFORM_WIN32

    struct MutexType
    {
        PThreadMutexAttrT attribute;
        PThreadMutexT mutex;
    };
}

#endif  // SYSTEM_THREADING_MUTEX_USING_H