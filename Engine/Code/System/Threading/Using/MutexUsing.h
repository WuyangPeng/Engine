/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:01)

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

    // Linux/Apple�Ļ��������͡�
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