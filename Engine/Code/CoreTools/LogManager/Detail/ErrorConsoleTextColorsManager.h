/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:36)

#ifndef CORE_TOOLS_LOG_MANAGER_ERROR_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_ERROR_CONSOLE_TEXT_COLOR_MANAGER_H

#include "LogConsoleTextColorsManagerImpl.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleTextColorsManager.h"

namespace CoreTools
{
    class ErrorConsoleTextColorsManager final : public LogConsoleTextColorsManagerImpl
    {
    public:
        using ClassType = ErrorConsoleTextColorsManager;
        using ParentType = LogConsoleTextColorsManagerImpl;

    public:
        explicit ErrorConsoleTextColorsManager(LogLevel logLevel);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ErrorManager = ConsoleTextColorsManager<System::StandardHandle::Error>;

    private:
        ErrorManager consoleTextColorsManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_ERROR_CONSOLE_TEXT_COLOR_MANAGER_H
