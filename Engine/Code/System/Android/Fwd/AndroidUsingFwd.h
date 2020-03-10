// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/03 09:52)

#ifndef SYSTEM_ANDROID_ANDROID_USING_FWD_H
#define SYSTEM_ANDROID_ANDROID_USING_FWD_H  

#include "System/Helper/ConfigMacro.h"
 
#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/input.h>
#include <android/native_window.h>

namespace System
{
	using AndroidInputEvent = AInputEvent;
	using AndroidInputQueue = AInputQueue;
	using AndroidApp = android_app;
	using AndroidNativeWindow = ANativeWindow;
}

#else // SYSTEM_PLATFORM_ANDROID

namespace System
{
	struct AndroidInputEvent;
	struct AndroidInputQueue;
	struct AndroidApp;
	struct AndroidNativeWindow;
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_USING_FWD_H