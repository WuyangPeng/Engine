// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:22)

#ifndef SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FWD_H
#define SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FWD_H 

#include "AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidNativeWindowUsing.h"

namespace System
{
	void AndroidNativeWindowAcquire(AndroidNativeWindow* window) noexcept;
	void AndroidNativeWindowRelease(AndroidNativeWindow* window) noexcept;
	int AndroidNativeWindowGetWidth(AndroidNativeWindow* window) noexcept;
	int AndroidNativeWindowGetHeight(AndroidNativeWindow* window) noexcept;
	WindowFormat AndroidNativeWindowGetFormat(AndroidNativeWindow* window) noexcept;
	int AndroidNativeWindowSetBuffersGeometry(AndroidNativeWindow* window, int width, int height, WindowFormat format) noexcept;
	int AndroidNativeWindowLock(AndroidNativeWindow* window, AndroidNativeWindowBuffer* outBuffer, AndroidRect* inOutDirtyBounds) noexcept;
	int AndroidNativeWindowUnlockAndPost(AndroidNativeWindow* window) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_NATIVE_WINDOW_FWD_H