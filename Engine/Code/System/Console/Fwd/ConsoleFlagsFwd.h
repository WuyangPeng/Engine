/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:56)

#ifndef SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H
#define SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// ConsoleColour
    enum class TextColour;
    enum class BackgroundColour;
    enum class ConsoleCommon;

    /// ConsoleHandle
    enum class StandardHandle : uint32_t;

    /// ConsoleMode
    enum class ConsoleInputMode;
    enum class ConsoleOutputMode;

    /// ConsoleScreenBuffer
    enum class DesiredAccessGeneric : uint32_t;
    enum class ConsoleScreenBufferShareMode;
    enum class ConsoleScreenBuffer;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_FLAGS_FWD_H