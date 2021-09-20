///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:16)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_USING_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleFontInfo = CONSOLE_FONT_INFO;
    using ConsoleFontInfoPtr = PCONSOLE_FONT_INFO;
    using ConsoleFontInfoEx = CONSOLE_FONT_INFOEX;
    using ConsoleFontInfoExPtr = PCONSOLE_FONT_INFOEX;
    constexpr auto g_LogicalFontFaceSize = LF_FACESIZE;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleFontInfo
    {
        uint32_t nFont;
        ConsoleCoord dwFontSize;
    };
    using ConsoleFontInfoPtr = ConsoleFontInfo*;

    static constexpr auto g_LogicalFontFaceSize = 32;

    struct ConsoleFontInfoEx
    {
        uint32_t cbSize;
        uint32_t nFont;
        ConsoleCoord dwFontSize;
        uint32_t FontFamily;
        uint32_t FontWeight;
        wchar_t FaceName[g_LogicalFontFaceSize];
    };

    using ConsoleFontInfoExPtr = ConsoleFontInfoEx*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H