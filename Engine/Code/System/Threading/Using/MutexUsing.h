///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:03)

#ifndef SYSTEM_THREADING_MUTEX_USING_H
#define SYSTEM_THREADING_MUTEX_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    struct PthreadMutexattrT
    {
    };

    using PthreadMutexT = WindowsHandle;

#else  // !SYSTEM_PLATFORM_WIN32

    // Linux/Apple的互斥锁类型。
    using PthreadMutexattrT = pthread_mutexattr_t;
    using PthreadMutexT = pthread_mutex_t;

#endif  // SYSTEM_PLATFORM_WIN32

    struct MutexType
    {
        PthreadMutexattrT attribute;
        PthreadMutexT mutex;
    };
}

#endif  // SYSTEM_THREADING_MUTEX_USING_H