//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:40)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleFontUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����̨������Ϣ�����úͻ�ȡ��

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    [[nodiscard]] ConsoleCoord SYSTEM_DEFAULT_DECLARE GetSystemConsoleFontSize(WindowHandle consoleOutput, WindowDWord font) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FONT_H