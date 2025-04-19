/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:56)

#ifndef SYSTEM_CONSOLE_CONSOLE_FONT_USING_H
#define SYSTEM_CONSOLE_CONSOLE_FONT_USING_H

#include "System/Helper/Platform.h"

#include "ConsoleColourUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleFontInfo = CONSOLE_FONT_INFO;
    using ConsoleFontInfoPtr = PCONSOLE_FONT_INFO;
    using ConsoleFontInfoEx = CONSOLE_FONT_INFOEX;
    using ConsoleFontInfoExPtr = PCONSOLE_FONT_INFOEX;
    constexpr auto gLogicalFontFaceSize = LF_FACESIZE;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleFontInfo
    {
        uint32_t nFont;
        ConsoleCoord dwFontSize;
    };
    using ConsoleFontInfoPtr = ConsoleFontInfo*;

    static constexpr auto gLogicalFontFaceSize = 32;

    struct ConsoleFontInfoEx
    {
        uint32_t cbSize;
        uint32_t nFont;
        ConsoleCoord dwFontSize;
        uint32_t FontFamily;
        uint32_t FontWeight;
        wchar_t FaceName[gLogicalFontFaceSize];
    };
    using ConsoleFontInfoExPtr = ConsoleFontInfoEx*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_USING_H