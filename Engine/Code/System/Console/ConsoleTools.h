// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:36)

#ifndef SYSTEM_CONSOLE_CONSOLE_TOOLS_H
#define SYSTEM_CONSOLE_CONSOLE_TOOLS_H

#include "System/SystemDll.h"   

#include "Using/ConsoleToolsUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"  
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台工具。

	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleActiveScreenBuffer(WindowHandle consoleOutput) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DeleteSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept;
	WindowHWnd SYSTEM_DEFAULT_DECLARE GetSystemConsoleWindow() noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReadSystemConsole(WindowHandle consoleInput, WindowVoidPtr buffer, WindowDWord numberOfCharsToRead,
												  WindowDWordPtr numberOfCharsRead, ConsoleReadConsoleControlPtr inputControl) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemConsole(WindowHandle consoleOutput, const void* buffer, WindowDWord numberOfCharsToWrite, WindowDWordPtr numberOfCharsWritten) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_TOOLS_H