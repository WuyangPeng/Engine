/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:54)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLORS_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_COLORS_FLAGS_H

#include "System/Helper/EnumOperator.h"
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
        GridLVertical = COMMON_LVB_GRID_LVERTICAL,
        GridRVertical = COMMON_LVB_GRID_RVERTICAL,
        ReverseVideo = COMMON_LVB_REVERSE_VIDEO,
        Underscore = COMMON_LVB_UNDERSCORE,

        SingleByteCharacterSetDoubleByteCharacterSet = COMMON_LVB_SBCSDBCS,
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
        GridLVertical = 0x0800,
        GridRVertical = 0x1000,
        ReverseVideo = 0x4000,
        Underscore = 0x8000,
        SingleByteCharacterSetDoubleByteCharacterSet = 0x0300,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_CONSOLE_CONSOLE_COLORS_FLAGS_H
