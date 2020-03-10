// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:38)

#include "System/SystemExport.h"

#include "ConsoleMode.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h" 

bool System
	::GetSystemConsoleMode(WindowHandle consoleHandle, WindowDWordPtr mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetConsoleMode(consoleHandle, mode) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleHandle);
	SYSTEM_UNUSED_ARG(mode);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleInputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleHandle);
	SYSTEM_UNUSED_ARG(mode);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleOutputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleHandle);
	SYSTEM_UNUSED_ARG(mode);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}


