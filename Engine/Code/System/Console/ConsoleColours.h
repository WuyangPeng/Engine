// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLORS_H
#define SYSTEM_CONSOLE_CONSOLE_COLORS_H

#include "System/SystemDll.h" 

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台颜色的设置。

	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTextAttribute(WindowHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleDefaultTextAttribute(WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWordPtr attribute, WindowDWord length,
																 ConsoleCoord readCoord, WindowDWordPtr numberOfAttributesRead) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutputAttribute(WindowHandle consolehandle, const WindowWord* attribute, WindowDWord length,
																  ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FillSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWord attribute, WindowDWord length,
																 ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_COLORS_H