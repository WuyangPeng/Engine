//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:40)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleFontUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 控制台字体信息的设置和获取。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoPtr consoleCurrentFont) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetCurrentSystemConsoleFont(WindowHandle consoleOutput, bool maximumWindow, ConsoleFontInfoExPtr consoleCurrentFontEx) noexcept;
    [[nodiscard]] ConsoleCoord SYSTEM_DEFAULT_DECLARE GetSystemConsoleFontSize(WindowHandle consoleOutput, WindowDWord font) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FONT_H