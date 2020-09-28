//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:50)

#ifndef SYSTEM_WINDOW_WINDOW_DISPLAY_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_DISPLAY_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowDisplay
    {
        MaxHide = SIZE_MAXHIDE,
        Maximized = SIZE_MAXIMIZED,
        MaxShow = SIZE_MAXSHOW,
        Minimized = SIZE_MINIMIZED,
        Restored = SIZE_RESTORED,
        GLUTUnDefinition = 0xFF,
        AndroidUnDefinition = 0xFF,
        UnDefinition = 0xFF,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowDisplay
    {
        MaxHide = 0,
        Maximized = 1,
        MaxShow = 2,
        Minimized = 3,
        Restored = 4,
        GLUTUnDefinition = 0xFF,
        AndroidUnDefinition = 0xFF,
        UnDefinition = 0xFF,
    };
#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOW_WINDOW_DISPLAY_FLAGS_H
