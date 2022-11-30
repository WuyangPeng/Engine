///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/15 21:58)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLORS_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_COLORS_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class TextColour
    {
        Black = 0,
        Red = FOREGROUND_RED,
        Green = FOREGROUND_GREEN,
        Blue = FOREGROUND_BLUE,
        Intensified = FOREGROUND_INTENSITY,
        Yellow = Red | Green,
        Cyan = Green | Blue,
        Magenta = Red | Blue,
        White = Red | Green | Blue,

        IntensifiedBlack = Black | Intensified,
        IntensifiedRed = Red | Intensified,
        IntensifiedGreen = Green | Intensified,
        IntensifiedBlue = Blue | Intensified,
        IntensifiedYellow = Yellow | Intensified,
        IntensifiedCyan = Cyan | Intensified,
        IntensifiedMagenta = Magenta | Intensified,
        IntensifiedWhite = White | Intensified,
    };

    enum class BackgroundColour
    {
        Black = 0x0000,
        Red = BACKGROUND_RED,
        Green = BACKGROUND_GREEN,
        Blue = BACKGROUND_BLUE,
        Intensified = BACKGROUND_INTENSITY,
        Yellow = Red | Green,
        Cyan = Green | Blue,
        Magenta = Red | Blue,
        White = Red | Green | Blue,

        IntensifiedBlack = Black | Intensified,
        IntensifiedRed = Red | Intensified,
        IntensifiedGreen = Green | Intensified,
        IntensifiedBlue = Blue | Intensified,
        IntensifiedYellow = Yellow | Intensified,
        IntensifiedCyan = Cyan | Intensified,
        IntensifiedMagenta = Magenta | Intensified,
        IntensifiedWhite = White | Intensified,
    };

    enum class ConsoleCommon
    {
        Default = 0x0000,
        LeadingByte = COMMON_LVB_LEADING_BYTE,
        TrailingByte = COMMON_LVB_TRAILING_BYTE,
        GridHorizontal = COMMON_LVB_GRID_HORIZONTAL,
        GridLvertical = COMMON_LVB_GRID_LVERTICAL,
        GridRvertical = COMMON_LVB_GRID_RVERTICAL,
        ReverseVideo = COMMON_LVB_REVERSE_VIDEO,
        Underscore = COMMON_LVB_UNDERSCORE,

        SbcsDbcs = COMMON_LVB_SBCSDBCS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class TextColour
    {
        Black = 0,
        Red = 0x0004,
        Green = 0x0002,
        Blue = 0x0001,
        Intensified = 0x0008,
        Yellow = Red | Green,
        Cyan = Green | Blue,
        Magenta = Red | Blue,
        White = Red | Green | Blue,

        IntensifiedBlack = Black | Intensified,
        IntensifiedRed = Red | Intensified,
        IntensifiedGreen = Green | Intensified,
        IntensifiedBlue = Blue | Intensified,
        IntensifiedYellow = Yellow | Intensified,
        IntensifiedCyan = Cyan | Intensified,
        IntensifiedMagenta = Magenta | Intensified,
        IntensifiedWhite = White | Intensified,
    };

    enum class BackgroundColour
    {
        Black = 0x0000,
        Red = 0x0004,
        Green = 0x0002,
        Blue = 0x0001,
        Intensified = 0x0008,
        Yellow = Red | Green,
        Cyan = Green | Blue,
        Magenta = Red | Blue,
        White = Red | Green | Blue,

        IntensifiedBlack = Black | Intensified,
        IntensifiedRed = Red | Intensified,
        IntensifiedGreen = Green | Intensified,
        IntensifiedBlue = Blue | Intensified,
        IntensifiedYellow = Yellow | Intensified,
        IntensifiedCyan = Cyan | Intensified,
        IntensifiedMagenta = Magenta | Intensified,
        IntensifiedWhite = White | Intensified,
    };

    enum class ConsoleCommon
    {
        Default = 0x0000,
        LeadingByte = 0x0100,
        TrailingByte = 0x0200,
        GridHorizontal = 0x0400,
        GridLvertical = 0x0800,
        GridRvertical = 0x1000,
        ReverseVideo = 0x4000,
        Underscore = 0x8000,
        SbcsDbcs = 0x0300,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    ENUM_ORABLE_OPERATOR_DEFINE(TextColour);
    ENUM_ORABLE_OPERATOR_DEFINE(BackgroundColour);
}

#endif  // SYSTEM_CONSOLE_CONSOLE_COLORS_FLAGS_H
