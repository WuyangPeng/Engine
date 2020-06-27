// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 21:38)

#include "System/SystemExport.h"

#include "ConsoleOutput.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::ReadSystemConsoleOutput(WindowHandle handle, ConsoleCharInfoPtr buffer, ConsoleCoord bufferSize, ConsoleCoord bufferCoord, ConsoleSmallRectPtr readRegion) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReadConsoleOutput(handle, buffer, bufferSize, bufferCoord, readRegion) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(bufferSize);
	SYSTEM_UNUSED_ARG(bufferCoord);
	SYSTEM_UNUSED_ARG(readRegion);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemConsoleOutput(WindowHandle handle, const ConsoleCharInfo* buffer, ConsoleCoord bufferSize, ConsoleCoord bufferCoord, ConsoleSmallRectPtr writeRegion) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::WriteConsoleOutput(handle, buffer, bufferSize, bufferCoord, writeRegion) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(bufferSize);
	SYSTEM_UNUSED_ARG(bufferCoord);
	SYSTEM_UNUSED_ARG(writeRegion);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ReadSystemConsoleOutputCharacter(WindowHandle handle, TChar* character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReadConsoleOutputCharacter(handle, character, length, readCoord, numberOfCharsRead) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(character);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(readCoord);
	SYSTEM_UNUSED_ARG(numberOfCharsRead);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemConsoleOutputCharacter(WindowHandle handle, const TChar* character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::WriteConsoleOutputCharacter(handle, character, length, readCoord, numberOfCharsWritten) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(character);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(readCoord);
	SYSTEM_UNUSED_ARG(numberOfCharsWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FillSystemConsoleOutputCharacter(WindowHandle handle, TChar character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FillConsoleOutputCharacter(handle, character, length, readCoord, numberOfCharsWritten) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(character);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(readCoord);
	SYSTEM_UNUSED_ARG(numberOfCharsWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
