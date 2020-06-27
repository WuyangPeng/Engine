// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 21:15)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h" 

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台模式的获取和设置。

	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowHandle consoleHandle, WindowDWordPtr mode) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleInputMode mode) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_MODE_H