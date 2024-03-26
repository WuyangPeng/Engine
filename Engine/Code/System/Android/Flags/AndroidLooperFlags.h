/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:16)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/looper.h>

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class AndroidLooperPrepareAllow
    {
        NonCallbacks = ALOOPER_PREPARE_ALLOW_NON_CALLBACKS
    };

    enum class AndroidLooperPoll
    {
        Wake = ALOOPER_POLL_WAKE,
        Callback = ALOOPER_POLL_CALLBACK,
        Timeout = ALOOPER_POLL_TIMEOUT,
        Error = ALOOPER_POLL_ERROR,
    };

    enum class AndroidLooperEvent
    {
        Null = 0,

        Input = ALOOPER_EVENT_INPUT,
        Output = ALOOPER_EVENT_OUTPUT,
        Error = ALOOPER_EVENT_ERROR,
        Hangup = ALOOPER_EVENT_HANGUP,
        Invalid = ALOOPER_EVENT_INVALID,
    };
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class AndroidLooperPrepareAllow
    {
        NonCallbacks = 1 << 0
    };

    enum class AndroidLooperPoll
    {
        Wake = -1,
        Callback = -2,
        Timeout = -3,
        Error = -4,
    };

    enum class AndroidLooperEvent
    {
        Null = 0,

        Input = 1 << 0,
        Output = 1 << 1,
        Error = 1 << 2,
        Hangup = 1 << 3,
        Invalid = 1 << 4,
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_LOOPER_FLAGS_H
