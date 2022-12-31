///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/02 16:52)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// 控制台缓冲区的设置和获取。
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess,
                                                                                       ConsoleScreenBufferShareMode shareMode,
                                                                                       const WindowSecurityAttributes* securityAttributes) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemConsole(WindowsHandle consoleHandle) noexcept;
    NODISCARD void SYSTEM_DEFAULT_DECLARE SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetConsoleHandleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleScreenBufferSize(WindowsHandle consoleOutput, ConsoleCoord size) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H