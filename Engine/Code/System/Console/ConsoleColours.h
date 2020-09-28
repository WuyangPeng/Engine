//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:39)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLORS_H
#define SYSTEM_CONSOLE_CONSOLE_COLORS_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 控制台颜色的设置。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTextAttribute(WindowHandle handle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleDefaultTextAttribute(WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWordPtr attribute, WindowDWord length,
                                                                               ConsoleCoord readCoord, WindowDWordPtr numberOfAttributesRead) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutputAttribute(WindowHandle consolehandle, const WindowWord* attribute, WindowDWord length,
                                                                                ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FillSystemConsoleOutputAttribute(WindowHandle consolehandle, WindowWord attribute, WindowDWord length,
                                                                               ConsoleCoord writeCoord, WindowDWordPtr numberOfAttributesWritten) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_COLORS_H