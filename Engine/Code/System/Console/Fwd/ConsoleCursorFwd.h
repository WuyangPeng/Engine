// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:32)

#ifndef SYSTEM_CONSOLE_CONSOLE_CURSOR_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_CURSOR_FWD_H

#include "System/Console/Using/ConsoleCursorUsing.h"

namespace System
{
	bool GetSystemConsoleCursorInfo(WindowHandle consoleOutput, ConsoleCursorInfoPtr consoleCursorInfo) noexcept;
	bool SetSystemConsoleCursorPosition(WindowHandle consoleOutput, const ConsoleCoord& cursorPosition) noexcept;
	bool SetSystemConsoleCursorInfo(WindowHandle consoleOutput, const ConsoleCursorInfo* consoleCursorInfo) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_CURSOR_FWD_H