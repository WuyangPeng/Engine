// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_USING_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using ConsoleFontInfo = CONSOLE_FONT_INFO;
	using ConsoleFontInfoPtr = PCONSOLE_FONT_INFO;
	using ConsoleFontInfoEx = CONSOLE_FONT_INFOEX;
	using ConsoleFontInfoExPtr = PCONSOLE_FONT_INFOEX;
	constexpr int g_LogicalFontFaceSize{ LF_FACESIZE };

#else // !SYSTEM_PLATFORM_WIN32

	struct ConsoleFontInfo
	{
		WindowDWord nFont;
		ConsoleCoord dwFontSize;
	};
	using ConsoleFontInfoPtr = ConsoleFontInfo*;

	static constexpr int g_LogicalFontFaceSize{ 32 };

	struct ConsoleFontInfoEx
	{
		uint32_t cbSize;
		uint32_t nFont;
		ConsoleCoord dwFontSize;
		uint32_t FontFamily;
		uint32_t FontWeight;
		wchar_t FaceName[g_LogicalFontFaceSize];
	};

	using ConsoleFontInfoExPtr = ConsoleFontInfoEx*;

#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H