// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:37)

#include "System/SystemExport.h"

#include "ConsoleInfo.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::ConsoleCoord System
	::GetLargestSystemConsoleWindowSize(WindowHandle consoleOutput) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetLargestConsoleWindowSize(consoleOutput);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);

	return ConsoleCoord{};
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetConsoleHistoryInfo(consoleHistoryInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleHistoryInfo);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleHistoryInfo(consoleHistoryInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleHistoryInfo);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemConsoleSelectionInfo(ConsoleSelectionInfoPtr consoleSelectionInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetConsoleSelectionInfo(consoleSelectionInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleSelectionInfo);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetNumberOfSystemConsoleMouseButtons(WindowDWordPtr numberOfMouseButtons) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetNumberOfConsoleMouseButtons(numberOfMouseButtons) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(numberOfMouseButtons);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleWindowInfo(WindowHandle consoleOutput, bool absolute, const ConsoleSmallRect* consoleWindow) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleWindowInfo(consoleOutput, BoolConversion(absolute), consoleWindow) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(absolute);
	SYSTEM_UNUSED_ARG(consoleWindow);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
