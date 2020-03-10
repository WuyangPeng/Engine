// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using ConsoleColorref = COLORREF;
	using ConsoleScreenBufferInfo = CONSOLE_SCREEN_BUFFER_INFO;
	using ConsoleScreenBufferInfoPtr = PCONSOLE_SCREEN_BUFFER_INFO;
	using ConsoleScreenBufferInfoEx = CONSOLE_SCREEN_BUFFER_INFOEX;
	using ConsoleScreenBufferInfoExPtr = PCONSOLE_SCREEN_BUFFER_INFOEX;

#else // !SYSTEM_PLATFORM_WIN32

	using ConsoleColorref = uint32_t;

	struct ConsoleScreenBufferInfo
	{
		ConsoleCoord dwSize;
		ConsoleCoord dwCursorPosition;
		WindowWord  wAttributes;
		ConsoleSmallRect srWindow;
		ConsoleCoord dwMaximumWindowSize;
	};

	using ConsoleScreenBufferInfoPtr = ConsoleScreenBufferInfo*;

	struct ConsoleScreenBufferInfoEx
	{
		uint32_t cbSize;
		ConsoleCoord dwSize;
		ConsoleCoord dwCursorPosition;
		WindowWord wAttributes;
		ConsoleSmallRect srWindow;
		ConsoleCoord dwMaximumWindowSize;
		WindowWord wPopupAttributes;
		int bFullscreenSupported;
		ConsoleColorref ColorTable[16];
	};

	using ConsoleScreenBufferInfoExPtr = ConsoleScreenBufferInfoEx*;

#endif // SYSTEM_PLATFORM_WIN32    	
}

#endif // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H