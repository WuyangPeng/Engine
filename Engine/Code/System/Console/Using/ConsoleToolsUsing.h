//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 15:31)

#ifndef SYSTEM_CONSOLE_CONSOLE_TOOLS_USING_H
#define SYSTEM_CONSOLE_CONSOLE_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleHandlerRoutine = PHANDLER_ROUTINE;
    using ConsoleReadConsoleControl = CONSOLE_READCONSOLE_CONTROL;
    using ConsoleReadConsoleControlPtr = PCONSOLE_READCONSOLE_CONTROL;

#else  // !SYSTEM_PLATFORM_WIN32

    using ConsoleHandlerRoutine = int (*)(uint32_t ctrlType);

    struct ConsoleReadConsoleControl
    {
        WindowULong nLength;
        WindowULong nInitialChars;
        WindowULong dwCtrlWakeupMask;
        WindowULong dwControlKeyState;
    };

    using ConsoleReadConsoleControlPtr = ConsoleReadConsoleControl*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_TOOLS_USING_H