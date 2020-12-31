//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:41)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����̨ģʽ�Ļ�ȡ�����á�

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowHandle consoleHandle, WindowDWordPtr mode) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleInputMode mode) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_MODE_H