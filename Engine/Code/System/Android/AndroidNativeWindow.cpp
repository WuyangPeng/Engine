///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 23:02)

#include "System/SystemExport.h"

#include "AndroidNativeWindow.h"
#include "Flags/AndroidNativeWindowFlags.h"
#include "System/Helper/WindowsMacro.h"

void System::AndroidNativeWindowAcquire(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    ANativeWindow_acquire(window);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window);

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidNativeWindowRelease(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    ANativeWindow_release(window);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window);

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowGetWidth(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_getWidth(window);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowGetHeight(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_getHeight(window);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::WindowFormat System::AndroidNativeWindowGetFormat(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return WindowFormat(ANativeWindow_getFormat(window));

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window);

    return WindowFormat::RGBA8888;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowSetBuffersGeometry(AndroidNativeWindow* window, int32_t width, int32_t height, WindowFormat format) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_setBuffersGeometry(window, width, height, format);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window, width, height, format);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowLock(AndroidNativeWindow* window, AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_lock(window, outBuffer, inOutDirtyBounds);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(window, outBuffer, inOutDirtyBounds);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowUnlockAndPost(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_unlockAndPost(window);

#else  // !SYSTEM_PLATFORM_ANDROID
     
    UnusedFunction(window);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}
