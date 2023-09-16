///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:17)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleColorRef = COLORREF;
    using ConsoleScreenBufferInfo = CONSOLE_SCREEN_BUFFER_INFO;
    using ConsoleScreenBufferInfoPtr = PCONSOLE_SCREEN_BUFFER_INFO;
    using ConsoleScreenBufferInfoEx = CONSOLE_SCREEN_BUFFER_INFOEX;
    using ConsoleScreenBufferInfoExPtr = PCONSOLE_SCREEN_BUFFER_INFOEX;

#else  // !SYSTEM_PLATFORM_WIN32

    using ConsoleColorRef = uint32_t;

    struct ConsoleSmallRect
    {
        int16_t Left;
        int16_t Top;
        int16_t Right;
        int16_t Bottom;
    };

    struct ConsoleScreenBufferInfo
    {
        ConsoleCoord dwSize;
        ConsoleCoord dwCursorPosition;
        uint16_t wAttributes;
        ConsoleSmallRect srWindow;
        ConsoleCoord dwMaximumWindowSize;
    };
    using ConsoleScreenBufferInfoPtr = ConsoleScreenBufferInfo*;

    struct ConsoleScreenBufferInfoEx
    {
        uint32_t cbSize;
        ConsoleCoord dwSize;
        ConsoleCoord dwCursorPosition;
        uint16_t wAttributes;
        ConsoleSmallRect srWindow;
        ConsoleCoord dwMaximumWindowSize;
        uint16_t wPopupAttributes;
        int bFullscreenSupported;
        ConsoleColorRef ColorTable[16];
    };
    using ConsoleScreenBufferInfoExPtr = ConsoleScreenBufferInfoEx*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H