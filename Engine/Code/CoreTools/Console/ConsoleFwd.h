///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/11 14:52)

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