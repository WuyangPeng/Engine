// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_TOOLS_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_TOOLS_FWD_H 

#include "System/Window/Using/WindowUsing.h"
#include "System/Console/Using/ConsoleToolsUsing.h"
#include "System/Console/Using/ConsoleScreenBufferUsing.h"

namespace System
{
	bool SetSystemConsoleActiveScreenBuffer(WindowHandle consoleOutput) noexcept;
	bool AddSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept;
	bool DeleteSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept;
	WindowHWnd GetSystemConsoleWindow() noexcept;
	bool ReadSystemConsole(WindowHandle consoleInput, WindowVoidPtr buffer, WindowDWord numberOfCharsToRead, WindowDWordPtr numberOfCharsRead, ConsoleReadConsoleControlPtr inputControl) noexcept;
	bool WriteSystemConsole(WindowHandle consoleOutput, const void* buffer, WindowDWord numberOfCharsToWrite, WindowDWordPtr numberOfCharsWritten) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_TOOLS_FWD_H