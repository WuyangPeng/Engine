// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_WINDOW_PICTORIAL_USING_H
#define SYSTEM_WINDOW_WINDOW_PICTORIAL_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using WindowHBrush = HBRUSH;
	using WindowHGdiObj = HGDIOBJ;
	using WindowHCursor = HCURSOR;
	using WindowHIcon = HICON;

#else // !SYSTEM_PLATFORM_WIN32

	using WindowHBrush = void*;
	using WindowHGdiObj = void*;
	using WindowHCursor = void*;
	using WindowHIcon = void*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_WINDOW_WINDOW_PICTORIAL_TYPEDEF_H
