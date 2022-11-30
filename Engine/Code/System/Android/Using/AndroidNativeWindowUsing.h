///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/22 23:25)

#ifndef SYSTEM_ANDROID_ANDROID_WINDOW_USING_H
#define SYSTEM_ANDROID_ANDROID_WINDOW_USING_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/native_window.h>

#else  // !SYSTEM_PLATFORM_ANDROID

    #include <array>

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    using AndroidNativeWindow = ANativeWindow;
    using AndroidNativeWindowBuffer = ANativeWindow_Buffer;
    using AndroidRect = ARect;
}

#else  // !SYSTEM_PLATFORM_ANDROID

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidNativeWindow final
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
        int left;
        int top;
        int right;
        int bottom;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_WINDOW_USING_H
