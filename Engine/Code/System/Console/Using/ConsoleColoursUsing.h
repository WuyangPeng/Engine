//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 15:29)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLOURS_USING_H
#define SYSTEM_CONSOLE_CONSOLE_COLOURS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleCoord = COORD;
    using ConsoleCoordPtr = PCOORD;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleCoord
    {
        int16_t X;
        int16_t Y;
    };
    using ConsoleCoordPtr = ConsoleCoord*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_COLOURS_USING_H