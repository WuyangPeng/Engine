///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/10 20:50)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/looper.h>

namespace System
{
    using AndroidLooper = ALooper;
    using AndroidLooperCallbackFunc = ALooper_callbackFunc;
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    class AndroidLooper
    {
    };

    using AndroidLooperCallbackFunc = int (*)(int fd, int events, void* data);
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_LOOPER_TYPEDEF_H
