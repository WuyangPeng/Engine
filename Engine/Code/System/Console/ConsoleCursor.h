// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_CURSOR_H
#define SYSTEM_CONSOLE_CONSOLE_CURSOR_H

#include "System/SystemDll.h"    

#include "Using/ConsoleCursorUsing.h"
#include "Using/ConsoleColoursUsing.h"

namespace System
{
	// 控制台光标信息的设置和获取。

	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleCursorInfo(WindowHandle consoleOutput, ConsoleCursorInfoPtr consoleCursorInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleCursorPosition(WindowHandle consoleOutput, const ConsoleCoord& cursorPosition) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleCursorInfo(WindowHandle consoleOutput, const ConsoleCursorInfo* consoleCursorInfo) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CURSOR_H