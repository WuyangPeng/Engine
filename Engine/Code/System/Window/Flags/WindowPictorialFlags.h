//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 10:51)

#ifndef SYSTEM_WINDOW_WINDOW_PICTORIAL_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_PICTORIAL_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowBrushTypes : uint32_t
    {
        WhiteBrush = WHITE_BRUSH,
        LtgrayBrush = LTGRAY_BRUSH,
        GrayBrush = GRAY_BRUSH,
        DkgrayBrush = DKGRAY_BRUSH,
        BlackBrush = BLACK_BRUSH,
        NullBrush = NULL_BRUSH,
        Null = 0xFFFFFFFF,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowBrushTypes : uint32_t
    {
        WhiteBrush = 0,
        LtgrayBrush = 1,
        GrayBrush = 2,
        DkgrayBrush = 3,
        BlackBrush = 4,
        NullBrush = 5,
        Null = 0xFFFFFFFF,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOW_WINDOW_PICTORIAL_FLAGS_H
