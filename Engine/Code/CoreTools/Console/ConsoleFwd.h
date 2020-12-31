//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 15:08)

#ifndef CORE_TOOLS_CONSOLE_FWD_H
#define CORE_TOOLS_CONSOLE_FWD_H

#include "Flags/ConsoleColorsFlags.h"

namespace CoreTools
{
    enum class ConsoleAllocType;

    template <StandardHandle Handle>
    class ConsoleInstance;

    template <StandardHandle Handle>
    class ConsoleColors;

    template <StandardHandle Handle>
    class ConsoleTextColorsManager;

    class ConsoleAlloc;
}

#endif  // CORE_TOOLS_CONSOLE_FWD_H