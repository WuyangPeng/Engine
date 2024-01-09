/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:20)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_H

#include "System/SystemDll.h"

#include "Using/ConsoleColourUsing.h"
#include "Using/ConsoleFontUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// 控制台字体信息的设置和获取。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    NODISCARD ConsoleCoord SYSTEM_DEFAULT_DECLARE GetSystemConsoleFontSize(WindowsHandle consoleOutput, WindowsDWord font) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FONT_H