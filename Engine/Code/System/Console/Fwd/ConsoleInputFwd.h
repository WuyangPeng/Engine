// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_INPUT_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_INPUT_FWD_H 

#include "System/Console/Using/ConsoleInputUsing.h"

namespace System
{
	bool PeekSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept;
	bool ReadSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept;
	bool WriteSystemConsoleInput(WindowHandle handle, const ConsoleInputRecord* buffer, WindowDWord length, WindowDWordPtr numberOfEventsWritten) noexcept;
	bool GetNumberOfSystemConsoleInputEvents(WindowHandle handle, WindowDWordPtr numberOfEvents) noexcept;
	bool FlushSystemConsoleInputBuffer(WindowHandle handle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_COLORS_FWD_H