/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:58)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

/// 控制台模式的获取和设置。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleMode(WindowsHandle consoleHandle, WindowsDWordPtr mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleInputMode mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleOutputMode mode) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_MODE_H