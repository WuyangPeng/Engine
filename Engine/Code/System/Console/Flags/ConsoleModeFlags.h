/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:55)

#ifndef SYSTEM_CONSOLE_CONSOLE_MODE_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_MODE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ConsoleInputMode
    {
        ProcessedInput = ENABLE_PROCESSED_INPUT,
        LineInput = ENABLE_LINE_INPUT,
        EchoInput = ENABLE_ECHO_INPUT | LineInput,
        WindowInput = ENABLE_WINDOW_INPUT,
        MouseInput = ENABLE_MOUSE_INPUT,
        ExtendedFlags = ENABLE_EXTENDED_FLAGS,
        InsertMode = ENABLE_INSERT_MODE | ExtendedFlags,
        QuickEditMode = ENABLE_QUICK_EDIT_MODE | ExtendedFlags,
        AutoPosition = ENABLE_AUTO_POSITION | ExtendedFlags,
        VirtualTerminalInput = ENABLE_VIRTUAL_TERMINAL_INPUT
    };

    enum class ConsoleOutputMode
    {
        ProcessedOutput = ENABLE_PROCESSED_OUTPUT,
        WrapAtEolOutput = ENABLE_WRAP_AT_EOL_OUTPUT,
        VirtualTerminalProcessing = ENABLE_VIRTUAL_TERMINAL_PROCESSING,
        DisableNewlineAutoReturn = DISABLE_NEWLINE_AUTO_RETURN,
        LvbGridWorldwide = ENABLE_LVB_GRID_WORLDWIDE
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ConsoleInputMode
    {
        ProcessedInput = 0x0001,
        LineInput = 0x0002,
        EchoInput = 0x0004 | LineInput,
        WindowInput = 0x0008,
        MouseInput = 0x0010,
        ExtendedFlags = 0x0080,
        InsertMode = 0x0020 | ExtendedFlags,
        QuickEditMode = 0x0040 | ExtendedFlags,
        AutoPosition = 0x0100,
        VirtualTerminalInput = 0x0200
    };

    enum class ConsoleOutputMode
    {
        ProcessedOutput = 0x0001,
        WrapAtEolOutput = 0x0002,
        VirtualTerminalProcessing = 0x0004,
        DisableNewlineAutoReturn = 0x0008,
        LvbGridWorldwide = 0x0010
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_MODE_FLAGS_H
