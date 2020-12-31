//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:40)

#ifndef SYSTEM_CONSOLE_CONSOLE_INFO_H
#define SYSTEM_CONSOLE_CONSOLE_INFO_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleInfoUsing.h"
#include "Using/ConsoleOutputUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����̨��Ϣ�Ļ�ȡ�����á�

    [[nodiscard]] ConsoleCoord SYSTEM_DEFAULT_DECLARE GetLargestSystemConsoleWindowSize(WindowHandle consoleOutput) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleSelectionInfo(ConsoleSelectionInfoPtr consoleSelectionInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetNumberOfSystemConsoleMouseButtons(WindowDWordPtr numberOfMouseButtons) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleWindowInfo(WindowHandle consoleOutput, bool absolute, const ConsoleSmallRect* consoleWindow) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_INFO_H