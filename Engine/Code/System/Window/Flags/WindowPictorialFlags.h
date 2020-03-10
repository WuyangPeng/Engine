// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:35)

#ifndef SYSTEM_WINDOW_WINDOW_PICTORIAL_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_PICTORIAL_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class WindowBrushTypes : uint32_t 
	{
		WhiteBrush = WHITE_BRUSH,
		LtgrayBrush = LTGRAY_BRUSH,
		GrayBrush =  GRAY_BRUSH,
		DkgrayBrush =  DKGRAY_BRUSH,
		BlackBrush = BLACK_BRUSH,
		NullBrush = NULL_BRUSH,
		Null = 0xFFFFFFFF,
	};	
		
#else // !SYSTEM_PLATFORM_WIN32

	enum class WindowBrushTypes : uint32_t 
	{
		WhiteBrush = 0,
		LtgrayBrush = 1,
		GrayBrush =  2,
		DkgrayBrush =  3,
		BlackBrush = 4,
		NullBrush = 5,
		Null = 0xFFFFFFFF,
	};	
			
#endif // SYSTEM_PLATFORM_WIN32
} 

#endif // SYSTEM_WINDOW_WINDOW_PICTORIAL_FLAGS_H
