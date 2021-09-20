///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/03 12:44)

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
