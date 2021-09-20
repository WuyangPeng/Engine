///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:16)

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