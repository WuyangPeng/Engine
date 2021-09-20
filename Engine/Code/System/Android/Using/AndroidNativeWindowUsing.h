///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/10 20:51)

#ifndef SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/native_window.h>

namespace System
{
    using AndroidNativeWindow = ANativeWindow;
    using AndroidNativeWindowBuffer = ANativeWindow_Buffer;
    using AndroidRect = ARect;
}

#else  // !SYSTEM_PLATFORM_ANDROID

    #include <array>

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidNativeWindow
    {
    };

    class SYSTEM_DEFAULT_DECLARE AndroidNativeWindowBuffer final
    {
    public:
        using ClassType = AndroidNativeWindowBuffer;

    public:
        AndroidNativeWindowBuffer() noexcept;

    private:
        static constexpr auto size = 6;

    private:
        int32_t width;
        int32_t height;
        int32_t stride;
        int32_t format;
        void* bits;
        std::array<uint32_t, size> reserved;
    };

    class SYSTEM_DEFAULT_DECLARE AndroidRect final
    {
    public:
        using ClassType = AndroidRect;

    public:
        AndroidRect() noexcept;

        NODISCARD int GetLeft() const noexcept;
        NODISCARD int GetTop() const noexcept;
        NODISCARD int GetRight() const noexcept;
        NODISCARD int GetBottom() const noexcept;

    private:
        int32_t left;
        int32_t top;
        int32_t right;
        int32_t bottom;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H
