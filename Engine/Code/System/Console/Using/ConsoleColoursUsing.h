///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/07 11:16)

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