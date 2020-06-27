// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 21:38)

#include "System/SystemExport.h"

#include "ConsoleInput.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::PeekSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::PeekConsoleInput(handle, buffer, length, numberOfEventsRead) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(numberOfEventsRead);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ReadSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReadConsoleInput(handle, buffer, length, numberOfEventsRead) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(numberOfEventsRead);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemConsoleInput(WindowHandle handle, const ConsoleInputRecord* buffer, WindowDWord length, WindowDWordPtr numberOfEventsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::WriteConsoleInput(handle, buffer, length, numberOfEventsWritten) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(numberOfEventsWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetNumberOfSystemConsoleInputEvents(WindowHandle handle, WindowDWordPtr numberOfEvents) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetNumberOfConsoleInputEvents(handle, numberOfEvents) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(numberOfEvents);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FlushSystemConsoleInputBuffer(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FlushConsoleInputBuffer(handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
