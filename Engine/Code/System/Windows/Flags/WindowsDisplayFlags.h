///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 12:41)

#ifndef SYSTEM_WINDOWS_WINDOWS_DISPLAY_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_DISPLAY_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsDisplay
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

    enum class WindowsDisplay
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

#endif  // SYSTEM_WINDOWS_WINDOWS_DISPLAY_FLAGS_H
