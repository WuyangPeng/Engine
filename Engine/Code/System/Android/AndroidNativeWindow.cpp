//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 23:36)

#include "System/SystemExport.h"

#include "AndroidNativeWindow.h"
#include "Flags/AndroidNativeWindowFlags.h"

void System::AndroidNativeWindowAcquire([[maybe_unused]] AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    ANativeWindow_acquire(window);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidNativeWindowRelease([[maybe_unused]] AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    ANativeWindow_release(window);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidNativeWindowGetWidth([[maybe_unused]] AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ANativeWindow_getWidth(window);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidNativeWindowGetHeight([[maybe_unused]] AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ANativeWindow_getHeight(window);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::WindowFormat System::AndroidNativeWindowGetFormat([[maybe_unused]] AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return WindowFormat(ANativeWindow_getFormat(window));
#else  // !SYSTEM_PLATFORM_ANDROID
    return WindowFormat::RGBA8888;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidNativeWindowSetBuffersGeometry([[maybe_unused]] AndroidNativeWindow* window, [[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] WindowFormat format) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ANativeWindow_setBuffersGeometry(window, width, height, format);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidNativeWindowLock([[maybe_unused]] AndroidNativeWindow* window, [[maybe_unused]] AndroidNativeWindowBuffer* outBuffer, [[maybe_unused]] AndroidRect* inOutDirtyBounds) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ANativeWindow_lock(window, outBuffer, inOutDirtyBounds);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidNativeWindowUnlockAndPost([[maybe_unused]] AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ANativeWindow_unlockAndPost(window);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}
