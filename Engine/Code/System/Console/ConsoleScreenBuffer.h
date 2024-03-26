/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:58)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColourUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// 控制台缓冲区的设置和获取。
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess,
                                                                                       ConsoleScreenBufferShareMode shareMode,
                                                                                       const WindowSecurityAttributes* securityAttributes) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemConsole(WindowsHandle consoleHandle) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleScreenBufferSize(WindowsHandle consoleOutput, ConsoleCoord size) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H