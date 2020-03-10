// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:21)

#ifndef SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/native_window.h>

namespace System
{
	enum class WindowFormat 
	{
		RGBA8888 = WINDOW_FORMAT_RGBA_8888,
		RGBX8888 = WINDOW_FORMAT_RGBX_8888,
		RGB565 = WINDOW_FORMAT_RGB_565,
	};		
}

#else // !SYSTEM_PLATFORM_ANDROID

namespace System
{
	enum class WindowFormat 
	{
		RGBA8888 = 1,
		RGBX8888 = 2,
		RGB565 = 4,
	};		
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_WINDOW_FLAGS_H
