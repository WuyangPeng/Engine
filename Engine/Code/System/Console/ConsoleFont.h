// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_H

#include "System/SystemDll.h"    

#include "Using/ConsoleFontUsing.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台字体信息的设置和获取。

	bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
	ConsoleCoord SYSTEM_DEFAULT_DECLARE GetSystemConsoleFontSize(WindowHandle consoleOutput, WindowDWord font) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_FONT_H