//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:41)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 控制台模式的获取和设置。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowHandle consoleHandle, WindowDWordPtr mode) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleInputMode mode) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_MODE_H