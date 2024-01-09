/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:29)

#include "System/SystemExport.h"

#include "AndroidNativeWindowFacade.h"
#include "Flags/AndroidNativeWindowFlags.h"
#include "System/Helper/Tools.h"

System::AndroidNativeWindowFacade::AndroidNativeWindowFacade(AndroidNativeWindow* androidNativeWindow) noexcept
    : androidNativeWindow{ androidNativeWindow }
{
}

void System::AndroidNativeWindowFacade::Acquire() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    ANativeWindow_acquire(androidNativeWindow);

#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidNativeWindowFacade::Release() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    ANativeWindow_release(androidNativeWindow);

#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowFacade::GetWidth() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_getWidth(androidNativeWindow);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowFacade::GetHeight() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_getHeight(androidNativeWindow);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::WindowFormat System::AndroidNativeWindowFacade::GetFormat() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<WindowFormat>(ANativeWindow_getFormat(androidNativeWindow));

#else  // !SYSTEM_PLATFORM_ANDROID

    return WindowFormat::RGBA8888;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowFacade::SetBuffersGeometry(int32_t width, int32_t height, WindowFormat format) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_setBuffersGeometry(androidNativeWindow, width, height, EnumCastUnderlying(format));

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(width, height, format);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowFacade::Lock(AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_lock(androidNativeWindow, outBuffer, inOutDirtyBounds);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(outBuffer, inOutDirtyBounds);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidNativeWindowFacade::UnlockAndPost() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ANativeWindow_unlockAndPost(androidNativeWindow);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}
