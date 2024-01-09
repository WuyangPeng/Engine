/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 15:40)

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
