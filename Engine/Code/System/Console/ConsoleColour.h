/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:57)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLOUR_H
#define SYSTEM_CONSOLE_CONSOLE_COLOUR_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColourUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

/// ����̨��ɫ�����á�
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTextAttribute(WindowsHandle handle,
                                                                        TextColour textColour,
                                                                        BackgroundColour backgroundColour,
                                                                        ConsoleCommon consoleCommon) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleDefaultTextAttribute(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutputAttribute(WindowsHandle consoleHandle,
                                                                           WindowsWordPtr attribute,
                                                                           WindowsDWord length,
                                                                           const ConsoleCoord& readCoord,
                                                                           WindowsDWordPtr numberOfAttributesRead) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutputAttribute(WindowsHandle consoleHandle,
                                                                            const WindowsWord* attribute,
                                                                            WindowsDWord length,
                                                                            const ConsoleCoord& writeCoord,
                                                                            WindowsDWordPtr numberOfAttributesWritten) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FillSystemConsoleOutputAttribute(WindowsHandle consoleHandle,
                                                                           WindowsWord attribute,
                                                                           WindowsDWord length,
                                                                           const ConsoleCoord& writeCoord,
                                                                           WindowsDWordPtr numberOfAttributesWritten) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_COLOUR_H