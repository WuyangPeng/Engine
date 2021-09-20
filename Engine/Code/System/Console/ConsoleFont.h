///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:36)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleFontUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 控制台字体信息的设置和获取。

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetCurrentSystemConsoleFont(WindowsHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    NODISCARD ConsoleCoord SYSTEM_DEFAULT_DECLARE GetSystemConsoleFontSize(WindowsHandle consoleOutput, WindowsDWord font) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FONT_H