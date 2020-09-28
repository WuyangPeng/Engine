//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:52)

#ifndef SYSTEM_WINDOW_WINDOW_PICTORIAL_USING_H
#define SYSTEM_WINDOW_WINDOW_PICTORIAL_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WindowHBrush = HBRUSH;
    using WindowHGdiObj = HGDIOBJ;
    using WindowHCursor = HCURSOR;
    using WindowHIcon = HICON;

#else  // !SYSTEM_PLATFORM_WIN32

    using WindowHBrush = void*;
    using WindowHGdiObj = void*;
    using WindowHCursor = void*;
    using WindowHIcon = void*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOW_WINDOW_PICTORIAL_TYPEDEF_H
