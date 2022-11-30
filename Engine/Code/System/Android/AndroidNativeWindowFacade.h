///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/12 10:01)

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
        NODISCARD int32_t GetWidth() noexcept;
        NODISCARD int32_t GetHeight() noexcept;
        NODISCARD WindowFormat GetFormat() noexcept;
        NODISCARD int32_t SetBuffersGeometry(int32_t width, int32_t height, WindowFormat format) noexcept;
        NODISCARD int32_t Lock(AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept;
        NODISCARD int32_t UnlockAndPost() noexcept;

    private:
        AndroidNativeWindow* androidNativeWindow;
    };
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FACADE_H
