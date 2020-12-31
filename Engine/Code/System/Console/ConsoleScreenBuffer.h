//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:41)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleOutputUsing.h"
#include "Using/ConsoleScreenBufferUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // ����̨�����������úͻ�ȡ��

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess, ConsoleScreenBufferShareMode shareMode, const WindowSecurityAttributes* securityAttributes) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemConsole(WindowHandle consoleHandle) noexcept;
    [[nodiscard]] void SYSTEM_DEFAULT_DECLARE SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetConsoleHandleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleScreenBufferSize(WindowHandle consoleOutput, ConsoleCoord size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ScrollSystemConsoleScreenBuffer(WindowHandle consoleOutput, const ConsoleSmallRect* scrollRectangle, const ConsoleSmallRect* clipRectangle,
                                                                              ConsoleCoord destinationOrigin, const ConsoleCharInfo* fill) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_H