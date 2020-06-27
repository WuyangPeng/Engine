// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 21:15)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H

#include "System/SystemDll.h"    

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleOutputUsing.h" 
#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 控制台缓冲区的设置和获取。

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess, ConsoleScreenBufferShareMode shareMode, const WindowSecurityAttributes* securityAttributes) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemConsole(WindowHandle consoleHandle) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetConsoleHandleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleScreenBufferSize(WindowHandle consoleOutput, ConsoleCoord size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ScrollSystemConsoleScreenBuffer(WindowHandle consoleOutput, const ConsoleSmallRect* scrollRectangle, const ConsoleSmallRect* clipRectangle,
																ConsoleCoord destinationOrigin, const ConsoleCharInfo* fill) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H