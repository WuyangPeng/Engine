// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:37)

#include "System/SystemExport.h"

#include "ConsoleFont.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System
	::GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetCurrentConsoleFont(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFont) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(maximumWindow);
	SYSTEM_UNUSED_ARG(consoleCurrentFont);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(maximumWindow);
	SYSTEM_UNUSED_ARG(consoleCurrentFontEx);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetCurrentConsoleFontEx(consoleOutput, BoolConversion(maximumWindow), consoleCurrentFontEx) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(maximumWindow);
	SYSTEM_UNUSED_ARG(consoleCurrentFontEx);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ConsoleCoord System
	::GetSystemConsoleFontSize(WindowHandle consoleOutput, WindowDWord font) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleFontSize(consoleOutput, font);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(font);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
