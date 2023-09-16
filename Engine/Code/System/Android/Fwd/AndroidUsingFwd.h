///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/26 15:31)

#ifndef SYSTEM_ANDROID_ANDROID_USING_FWD_H
#define SYSTEM_ANDROID_ANDROID_USING_FWD_H

#include "System/Helper/ConfigMacro.h"

#ifndef SYSTEM_PLATFORM_ANDROID

namespace System
{
    // AndroidInput
    class AndroidInputEvent;
    class AndroidInputQueue;

    // AndroidLooper
    class AndroidLooper;

    // AndroidNativeAppGlue
    class AndroidNativeActivity;
    class AndroidConfiguration;
    class AndroidApp;
    class AndroidPollSource;

    // AndroidNativeWindow
    class AndroidNativeWindow;
    class AndroidNativeWindowBuffer;
    class AndroidRect;
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_USING_FWD_H