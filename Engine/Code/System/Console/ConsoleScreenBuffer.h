/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:58)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColourUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// ����̨�����������úͻ�ȡ��
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