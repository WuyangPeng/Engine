///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/07 11:19)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLORS_H
#define SYSTEM_CONSOLE_CONSOLE_COLORS_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // ����̨��ɫ�����á�

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTextAttribute(WindowsHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleDefaultTextAttribute(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutputAttribute(WindowsHandle consolehandle,
                                                                           WindowsWordPtr attribute,
                                                                           WindowsDWord length,
                                                                           const ConsoleCoord& readCoord,
                                                                           WindowsDWordPtr numberOfAttributesRead) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutputAttribute(WindowsHandle consolehandle,
                                                                            const WindowsWord* attribute,
                                                                            WindowsDWord length,
                                                                            const ConsoleCoord& writeCoord,
                                                                            WindowsDWordPtr numberOfAttributesWritten) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FillSystemConsoleOutputAttribute(WindowsHandle consolehandle,
                                                                           WindowsWord attribute,
                                                                           WindowsDWord length,
                                                                           const ConsoleCoord& writeCoord,
                                                                           WindowsDWordPtr numberOfAttributesWritten) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_COLORS_H