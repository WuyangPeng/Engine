///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 16:53)

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
        PthreadMutexattrT m_Attribute;
        PthreadMutexT m_Mutex;
    };
}

#endif  // SYSTEM_THREADING_MUTEX_USING_H