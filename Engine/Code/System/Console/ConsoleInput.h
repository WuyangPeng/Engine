//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:41)

#ifndef SYSTEM_CONSOLE_CONSOLE_INPUT_H
#define SYSTEM_CONSOLE_CONSOLE_INPUT_H

#include "System/SystemDll.h"

#include "Using/ConsoleInputUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����̨�������

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE PeekSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleInput(WindowHandle handle, ConsoleInputRecordPtr buffer, WindowDWord length, WindowDWordPtr numberOfEventsRead) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleInput(WindowHandle handle, const ConsoleInputRecord* buffer, WindowDWord length, WindowDWordPtr numberOfEventsWritten) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetNumberOfSystemConsoleInputEvents(WindowHandle handle, WindowDWordPtr numberOfEvents) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FlushSystemConsoleInputBuffer(WindowHandle handle) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_INPUT_H