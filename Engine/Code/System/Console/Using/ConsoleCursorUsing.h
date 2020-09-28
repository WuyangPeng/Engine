//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 15:30)

#ifndef SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H
#define SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleCursorInfo = CONSOLE_CURSOR_INFO;
    using ConsoleCursorInfoPtr = PCONSOLE_CURSOR_INFO;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleCursorInfo
    {
        uint32_t dwSize;
        WindowBool bVisible;
    };

    using ConsoleCursorInfoPtr = ConsoleCursorInfo*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H