///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:13)

#ifndef SYSTEM_WINDOWS_WINDOWS_PICTORIAL_USING_H
#define SYSTEM_WINDOWS_WINDOWS_PICTORIAL_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WindowsHBrush = HBRUSH;
    using WindowsHGdiObj = HGDIOBJ;
    using WindowsHCursor = HCURSOR;
    using WindowsHIcon = HICON;

#else  // !SYSTEM_PLATFORM_WIN32

    using WindowsHBrush = void*;
    using WindowsHGdiObj = void*;
    using WindowsHCursor = void*;
    using WindowsHIcon = void*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_PICTORIAL_USING_H
