///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/15 22:01)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 控制台模式的获取和设置。

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowsHandle consoleHandle, WindowsDWordPtr mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleInputMode mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_MODE_H