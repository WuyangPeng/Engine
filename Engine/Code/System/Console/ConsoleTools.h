//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:42)

#ifndef SYSTEM_CONSOLE_CONSOLE_TOOLS_H
#define SYSTEM_CONSOLE_CONSOLE_TOOLS_H

#include "System/SystemDll.h"

#include "Using/ConsoleScreenBufferUsing.h"
#include "Using/ConsoleToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 控制台工具。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleActiveScreenBuffer(WindowHandle consoleOutput) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AddSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DeleteSystemConsoleCtrlHandler(ConsoleHandlerRoutine handlerRoutine) noexcept;
    [[nodiscard]] WindowHWnd SYSTEM_DEFAULT_DECLARE GetSystemConsoleWindow() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemConsole(WindowHandle consoleInput, WindowVoidPtr buffer, WindowDWord numberOfCharsToRead,
                                                                WindowDWordPtr numberOfCharsRead, ConsoleReadConsoleControlPtr inputControl) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemConsole(WindowHandle consoleOutput, const void* buffer, WindowDWord numberOfCharsToWrite, WindowDWordPtr numberOfCharsWritten) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_TOOLS_H