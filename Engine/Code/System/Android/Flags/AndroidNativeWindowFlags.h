/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:16)

#ifndef SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/native_window.h>

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class WindowFormat
    {
        Rgba8888 = WINDOW_FORMAT_RGBA_8888,
        RgbX8888 = WINDOW_FORMAT_RGBX_8888,
        Rgb565 = WINDOW_FORMAT_RGB_565,
    };
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    enum class WindowFormat
    {
        Rgba8888 = 1,
        RgbX8888 = 2,
        Rgb565 = 4,
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H
