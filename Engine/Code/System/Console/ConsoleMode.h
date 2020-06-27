// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/09 21:15)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h" 

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// ����̨ģʽ�Ļ�ȡ�����á�

	bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowHandle consoleHandle, WindowDWordPtr mode) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleInputMode mode) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_MODE_H