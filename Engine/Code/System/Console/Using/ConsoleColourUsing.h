/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:56)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLOUR_USING_H
#define SYSTEM_CONSOLE_CONSOLE_COLOUR_USING_H

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

#endif  // SYSTEM_CONSOLE_CONSOLE_COLOUR_USING_H