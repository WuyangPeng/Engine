///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/02 16:52)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ����̨ģʽ�Ļ�ȡ�����á�
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowsHandle consoleHandle, WindowsDWordPtr mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleInputMode mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_MODE_H