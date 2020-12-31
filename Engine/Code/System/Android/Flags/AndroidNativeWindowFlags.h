//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 17:21)

#ifndef SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/native_window.h>

namespace System
{
    enum class WindowFormat
    {
        RGBA8888 = WINDOW_FORMAT_RGBA_8888,
        RGBX8888 = WINDOW_FORMAT_RGBX_8888,
        RGB565 = WINDOW_FORMAT_RGB_565,
    };
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class WindowFormat
    {
        RGBA8888 = 1,
        RGBX8888 = 2,
        RGB565 = 4,
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H
