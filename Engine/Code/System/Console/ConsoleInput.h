// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_INPUT_H
#define SYSTEM_CONSOLE_CONSOLE_INPUT_H

#include "System/SystemDll.h" 

#include "Using/ConsoleInputUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 控制台输入管理。

	bool SYSTEM_DEFAULT_DECLARE PeekSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleInput(WindowHandle handle, const ConsoleInputRecord* buffer, WindowDWord length, WindowDWordPtr numberOfEventsWritten) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetNumberOfSystemConsoleInputEvents(WindowHandle handle, WindowDWordPtr numberOfEvents) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FlushSystemConsoleInputBuffer(WindowHandle handle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_INPUT_H