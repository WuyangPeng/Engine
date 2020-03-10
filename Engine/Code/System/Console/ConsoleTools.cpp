// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:38)

#include "System/SystemExport.h"

#include "ConsoleTools.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::SetSystemConsoleActiveScreenBuffer(WindowHandle consoleOutput) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleActiveScreenBuffer(consoleOutput) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleCtrlHandler(handlerRoutine, g_True) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handlerRoutine);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DeleteSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleCtrlHandler(handlerRoutine, g_False) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handlerRoutine);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHWnd System
	::GetSystemConsoleWindow() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleWindow();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ReadSystemConsole(WindowHandle consoleInput, WindowVoidPtr buffer, WindowDWord numberOfCharsToRead,
						WindowDWordPtr numberOfCharsRead, ConsoleReadConsoleControlPtr inputControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReadConsole(consoleInput, buffer, numberOfCharsToRead, numberOfCharsRead, inputControl) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleInput);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfCharsToRead);
	SYSTEM_UNUSED_ARG(numberOfCharsRead);
	SYSTEM_UNUSED_ARG(inputControl);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemConsole(WindowHandle consoleOutput, const void* buffer, WindowDWord numberOfCharsToWrite, WindowDWordPtr numberOfCharsWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::WriteConsole(consoleOutput, buffer, numberOfCharsToWrite, numberOfCharsWritten, nullptr) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleInput);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfCharsToWrite);
	SYSTEM_UNUSED_ARG(numberOfCharsWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
