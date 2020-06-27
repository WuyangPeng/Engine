// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 21:23)

#include "System/SystemExport.h"

#include "ConsoleCursor.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::GetSystemConsoleCursorInfo(WindowHandle consoleOutput, ConsoleCursorInfoPtr consoleCursorInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetConsoleCursorInfo(consoleOutput, consoleCursorInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(consoleCursorInfo);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleCursorPosition(WindowHandle consoleOutput, const ConsoleCoord& cursorPosition) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleCursorPosition(consoleOutput, cursorPosition) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(cursorPosition);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleCursorInfo(WindowHandle consoleOutput, const ConsoleCursorInfo* consoleCursorInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleCursorInfo(consoleOutput, consoleCursorInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(consoleCursorInfo);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
