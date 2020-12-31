//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:40)

#ifndef SYSTEM_CONSOLE_CONSOLE_CURSOR_H
#define SYSTEM_CONSOLE_CONSOLE_CURSOR_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleCursorUsing.h"

namespace System
{
    // ����̨�����Ϣ�����úͻ�ȡ��

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleCursorInfo(WindowHandle consoleOutput, ConsoleCursorInfoPtr consoleCursorInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleCursorPosition(WindowHandle consoleOutput, const ConsoleCoord& cursorPosition) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleCursorInfo(WindowHandle consoleOutput, const ConsoleCursorInfo* consoleCursorInfo) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CURSOR_H