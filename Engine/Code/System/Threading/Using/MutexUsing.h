//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 14:34)

#ifndef SYSTEM_THREADING_MUTEX_USING_H
#define SYSTEM_THREADING_MUTEX_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    struct PthreadMutexattrT
    {
    };

    using PthreadMutexT = WindowHandle;

#else  // !SYSTEM_PLATFORM_WIN32

    // Linux/Apple�Ļ��������͡�
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