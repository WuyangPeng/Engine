/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:37)

#ifndef CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogConsoleTextColorsManagerImpl.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleTextColorsManager.h"

namespace CoreTools
{
    class OutputConsoleTextColorsManager final : public LogConsoleTextColorsManagerImpl
    {
    public:
        using ClassType = OutputConsoleTextColorsManager;
        using ParentType = LogConsoleTextColorsManagerImpl;

    public:
        explicit OutputConsoleTextColorsManager(LogLevel logLevel);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using OutputManager = ConsoleTextColorsManager<System::StandardHandle::Output>;

    private:
        OutputManager consoleTextColorsManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H
