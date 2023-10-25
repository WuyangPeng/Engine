///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:00)

#ifndef CORE_TOOLS_CONSOLE_FWD_H
#define CORE_TOOLS_CONSOLE_FWD_H

#include "Flags/ConsoleColorsFlags.h"

namespace CoreTools
{
    template <StandardHandle Handle>
    class ConsoleInstance;

    template <StandardHandle Handle>
    class ConsoleColors;

    template <StandardHandle Handle>
    class ConsoleTextColorsManager;

    class ConsoleAlloc;
}

#endif  // CORE_TOOLS_CONSOLE_FWD_H