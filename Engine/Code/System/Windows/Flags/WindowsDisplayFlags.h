///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:11)

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
