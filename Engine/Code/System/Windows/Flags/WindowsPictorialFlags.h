/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 16:18)

#ifndef SYSTEM_WINDOWS_WINDOWS_PICTORIAL_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_PICTORIAL_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsBrushTypes : uint32_t
    {
        WhiteBrush = WHITE_BRUSH,
        LightGrayBrush = LTGRAY_BRUSH,
        GrayBrush = GRAY_BRUSH,
        DarkGrayBrush = DKGRAY_BRUSH,
        BlackBrush = BLACK_BRUSH,
        NullBrush = NULL_BRUSH,
        Null = 0xFFFFFFFF,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsBrushTypes : uint32_t
    {
        WhiteBrush = 0,
        LightGrayBrush = 1,
        GrayBrush = 2,
        DarkGrayBrush = 3,
        BlackBrush = 4,
        NullBrush = 5,
        Null = 0xFFFFFFFF,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_WINDOWS_WINDOWS_PICTORIAL_FLAGS_H
