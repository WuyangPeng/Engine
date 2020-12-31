//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 18:44)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidNativeWindowUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE AndroidNativeWindowAcquire(AndroidNativeWindow* window) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidNativeWindowRelease(AndroidNativeWindow* window) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowGetWidth(AndroidNativeWindow* window) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowGetHeight(AndroidNativeWindow* window) noexcept;
    [[nodiscard]] WindowFormat SYSTEM_DEFAULT_DECLARE AndroidNativeWindowGetFormat(AndroidNativeWindow* window) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowSetBuffersGeometry(AndroidNativeWindow* window, int width, int height, WindowFormat format) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowLock(AndroidNativeWindow* window, AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowUnlockAndPost(AndroidNativeWindow* window) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_H
