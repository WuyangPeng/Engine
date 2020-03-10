// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:35)

#ifndef SYSTEM_WINDOW_WINDOW_DISPLAY_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_DISPLAY_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class WindowDisplay 
	{
		MaxHide = SIZE_MAXHIDE,
		Maximized = SIZE_MAXIMIZED,
		MaxShow = SIZE_MAXSHOW,
		Minimized = SIZE_MINIMIZED,
		Restored = SIZE_RESTORED,
		GLUTUnDefinition = 0xFF,
		AndroidUnDefinition = 0xFF,
		UnDefinition = 0xFF,
	};
	
#else // !SYSTEM_PLATFORM_WIN32

	enum class WindowDisplay 
	{
		MaxHide = 0,
		Maximized = 1,
		MaxShow = 2,
		Minimized = 3,
		Restored = 4,
		GLUTUnDefinition = 0xFF,
		AndroidUnDefinition = 0xFF,
		UnDefinition = 0xFF,
	};
#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_WINDOW_WINDOW_DISPLAY_FLAGS_H
