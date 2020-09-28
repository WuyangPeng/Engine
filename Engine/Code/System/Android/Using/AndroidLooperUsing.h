//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 17:36)

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
