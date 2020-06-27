// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 21:06)

#ifndef SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H
#define SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using ConsoleCursorInfo = CONSOLE_CURSOR_INFO;
	using ConsoleCursorInfoPtr = PCONSOLE_CURSOR_INFO;

#else // !SYSTEM_PLATFORM_WIN32

	struct ConsoleCursorInfo
	{
		uint32_t dwSize;
		WindowBool bVisible;
	};

	using ConsoleCursorInfoPtr = ConsoleCursorInfo*;

#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H