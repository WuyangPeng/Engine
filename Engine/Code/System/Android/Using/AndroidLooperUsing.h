///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/26 15:31)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_USING_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_USING_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/looper.h>

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    using AndroidLooper = ALooper;
    using AndroidLooperCallbackFunction = ALooper_callbackFunc;
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidLooper final
    {
    public:
        using ClassType = AndroidLooper;
    };

    using AndroidLooperCallbackFunction = int (*)(int fd, int events, void* data);
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_LOOPER_USING_H
