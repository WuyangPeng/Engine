///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/07 11:36)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleFontUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // ����̨������Ϣ�����úͻ�ȡ��

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    NODISCARD ConsoleCoord SYSTEM_DEFAULT_DECLARE GetSystemConsoleFontSize(WindowsHandle consoleOutput, WindowsDWord font) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FONT_H