//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 17:40)

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
        static constexpr auto sm_Size = 6;

    private:
        int width;
        int height;
        int stride;
        int format;
        void* bits;
        std::array<uint32_t, sm_Size> reserved;
    };

    class SYSTEM_DEFAULT_DECLARE AndroidRect final
    {
    public:
        using ClassType = AndroidRect;

    public:
        AndroidRect() noexcept;

        [[nodiscard]] int GetLeft() const noexcept;
        [[nodiscard]] int GetTop() const noexcept;
        [[nodiscard]] int GetRight() const noexcept;
        [[nodiscard]] int GetBottom() const noexcept;

    private:
        int left;
        int top;
        int right;
        int bottom;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_WINDOW_TYPEDEF_H
