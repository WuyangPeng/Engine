//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 15:30)

#ifndef SYSTEM_CONSOLE_CONSOLE_OUTPUT_USING_H
#define SYSTEM_CONSOLE_CONSOLE_OUTPUT_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleSmallRect = SMALL_RECT;
    using ConsoleSmallRectPtr = PSMALL_RECT;
    using ConsoleCharInfo = CHAR_INFO;
    using ConsoleCharInfoPtr = PCHAR_INFO;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleSmallRect
    {
        int16_t Left;
        int16_t Top;
        int16_t Right;
        int16_t Bottom;
    };
    using ConsoleSmallRectPtr = ConsoleSmallRect*;
    struct ConsoleCharInfo
    {
        union
        {
            wchar_t UnicodeChar;
            char AsciiChar;
        } Char;
        uint16_t Attributes;
    };
    using ConsoleCharInfoPtr = ConsoleCharInfo*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_INPUT_USING_H