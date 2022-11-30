///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:13)

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
