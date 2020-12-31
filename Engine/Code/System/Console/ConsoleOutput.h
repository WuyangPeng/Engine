//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:41)

#ifndef SYSTEM_CONSOLE_CONSOLE_OUTPUT_H
#define SYSTEM_CONSOLE_CONSOLE_OUTPUT_H

#include "System/SystemDll.h"

#include "Using/ConsoleColoursUsing.h"
#include "Using/ConsoleOutputUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 控制台输出管理。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutput(WindowHandle handle, ConsoleCharInfoPtr buffer, ConsoleCoord bufferSize,
                                                                      ConsoleCoord bufferCoord, ConsoleSmallRectPtr readRegion) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutput(WindowHandle handle, const ConsoleCharInfo* buffer, ConsoleCoord bufferSize,
                                                                       ConsoleCoord bufferCoord, ConsoleSmallRectPtr writeRegion) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemConsoleOutputCharacter(WindowHandle handle, TChar* character, WindowDWord length,
                                                                               ConsoleCoord readCoord, WindowDWordPtr numberOfCharsRead) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemConsoleOutputCharacter(WindowHandle handle, const TChar* character, WindowDWord length,
                                                                                ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FillSystemConsoleOutputCharacter(WindowHandle handle, TChar character, WindowDWord length, ConsoleCoord readCoord, WindowDWordPtr numberOfCharsWritten) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_OUTPUT_H