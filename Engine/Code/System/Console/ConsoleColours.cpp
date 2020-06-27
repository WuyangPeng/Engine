// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:37)

#include "System/SystemExport.h"

#include "ConsoleColours.h"
#include "Flags/ConsoleColoursFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/gsl_util>

bool System
	::SetSystemConsoleTextAttribute(WindowHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	auto attribute = gsl::narrow_cast<WindowWord>(EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon));

	if (::SetConsoleTextAttribute(handle, attribute) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(textColour);
	SYSTEM_UNUSED_ARG(backgroundColour);
	SYSTEM_UNUSED_ARG(consoleCommon);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleDefaultTextAttribute(WindowHandle handle) noexcept
{
	return SetSystemConsoleTextAttribute(handle, TextColour::White, BackgroundColour::Black, ConsoleCommon::Default);
}

bool System
	::ReadSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWordPtr attribute, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfAttributesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReadConsoleOutputAttribute(consolehandle, attribute, length, readCoord, numberOfAttributesRead) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consolehandle);
	SYSTEM_UNUSED_ARG(attribute);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(readCoord);
	SYSTEM_UNUSED_ARG(numberOfAttributesRead);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemConsoleOutputAttribute(WindowHandle consolehandle, const WindowWord* attribute, WindowDWord length, ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::WriteConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consolehandle);
	SYSTEM_UNUSED_ARG(attribute);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(writeCoord);
	SYSTEM_UNUSED_ARG(numberOfAttributesWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FillSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWord attribute, WindowDWord length, ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FillConsoleOutputAttribute(consolehandle, attribute, length, writeCoord, numberOfAttributesWritten) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consolehandle);
	SYSTEM_UNUSED_ARG(attribute);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(writeCoord);
	SYSTEM_UNUSED_ARG(numberOfAttributesWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
