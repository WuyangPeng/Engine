///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/07 11:32)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // ����̨�����������úͻ�ȡ��

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess, ConsoleScreenBufferShareMode shareMode, const WindowSecurityAttributes* securityAttributes) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemConsole(WindowsHandle consoleHandle) noexcept;
    NODISCARD void SYSTEM_DEFAULT_DECLARE SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetConsoleHandleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleScreenBufferSize(WindowsHandle consoleOutput, ConsoleCoord size) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H