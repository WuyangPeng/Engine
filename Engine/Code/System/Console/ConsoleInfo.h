//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:40)

#ifndef SYSTEM_CONSOLE_CONSOLE_INFO_H
#define SYSTEM_CONSOLE_CONSOLE_INFO_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleInfoUsing.h"
#include "Using/ConsoleOutputUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 控制台信息的获取和设置。

    [[nodiscard]] ConsoleCoord SYSTEM_DEFAULT_DECLARE GetLargestSystemConsoleWindowSize(WindowHandle consoleOutput) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleHistoryInfo(ConsoleHistoryInfoPtr consoleHistoryInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleSelectionInfo(ConsoleSelectionInfoPtr consoleSelectionInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetNumberOfSystemConsoleMouseButtons(WindowDWordPtr numberOfMouseButtons) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleWindowInfo(WindowHandle consoleOutput, bool absolute, const ConsoleSmallRect* consoleWindow) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_INFO_H