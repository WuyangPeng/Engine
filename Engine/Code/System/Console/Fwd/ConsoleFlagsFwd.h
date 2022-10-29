///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/15 20:23)

#ifndef SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // ConsoleColours
    enum class TextColour;
    enum class BackgroundColour;
    enum class ConsoleCommon;

    // ConsoleHandle
    enum class StandardHandle : uint32_t;

    // ConsoleMode
    enum class ConsoleInputMode;
    enum class ConsoleOutputMode;

    // ConsoleScreenBuffer
    enum class DesiredAccessGeneric : uint32_t;
    enum class ConsoleScreenBufferShareMode;
    enum class ConsoleScreenBuffer;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H