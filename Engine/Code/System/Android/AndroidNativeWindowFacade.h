/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:19)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FACADE_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FACADE_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidNativeWindowUsing.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidNativeWindowFacade final
    {
    public:
        using ClassType = AndroidNativeWindowFacade;

    public:
        explicit AndroidNativeWindowFacade(AndroidNativeWindow* window) noexcept;

        void Acquire() noexcept;
        void Release() noexcept;
        NODISCARD int32_t GetWidth() const noexcept;
        NODISCARD int32_t GetHeight() const noexcept;
        NODISCARD WindowFormat GetFormat() const noexcept;
        NODISCARD int32_t SetBuffersGeometry(int32_t width, int32_t height, WindowFormat format) noexcept;
        NODISCARD int32_t Lock(AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept;
        NODISCARD int32_t UnlockAndPost() noexcept;

    private:
        AndroidNativeWindow* androidNativeWindow;
    };
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FACADE_H
