// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:27)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidNativeWindowUsing.h"

namespace System
{
	void SYSTEM_DEFAULT_DECLARE AndroidNativeWindowAcquire(AndroidNativeWindow* window) noexcept;
	void SYSTEM_DEFAULT_DECLARE AndroidNativeWindowRelease(AndroidNativeWindow* window) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowGetWidth(AndroidNativeWindow* window) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowGetHeight(AndroidNativeWindow* window) noexcept;
	WindowFormat SYSTEM_DEFAULT_DECLARE AndroidNativeWindowGetFormat(AndroidNativeWindow* window) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowSetBuffersGeometry(AndroidNativeWindow* window, int width, int height, WindowFormat format) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowLock(AndroidNativeWindow* window, AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidNativeWindowUnlockAndPost(AndroidNativeWindow* window) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_H
