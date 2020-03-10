// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:09)

#include "System/SystemExport.h"

#include "AndroidNativeWindow.h"
#include "Flags/AndroidNativeWindowFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
void System
	::AndroidNativeWindowAcquire(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	ANativeWindow_acquire(window);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);
#endif // SYSTEM_PLATFORM_ANDROID
}

void System
	::AndroidNativeWindowRelease(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	ANativeWindow_release(window);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidNativeWindowGetWidth(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ANativeWindow_getWidth(window);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidNativeWindowGetHeight(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ANativeWindow_getHeight(window);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::WindowFormat System
	::AndroidNativeWindowGetFormat(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return WindowFormat(ANativeWindow_getFormat(window));
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);

	return WindowFormat::RGBA8888;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidNativeWindowSetBuffersGeometry(AndroidNativeWindow* window, int width, int height, WindowFormat format) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ANativeWindow_setBuffersGeometry(window, width, height, format);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);
	SYSTEM_UNUSED_ARG(width);
	SYSTEM_UNUSED_ARG(height);
	SYSTEM_UNUSED_ARG(format);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidNativeWindowLock(AndroidNativeWindow* window, AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ANativeWindow_lock(window, outBuffer, inOutDirtyBounds);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);
	SYSTEM_UNUSED_ARG(outBuffer);
	SYSTEM_UNUSED_ARG(inOutDirtyBounds);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidNativeWindowUnlockAndPost(AndroidNativeWindow* window) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ANativeWindow_unlockAndPost(window);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(window);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}
#include STSTEM_WARNING_POP 
