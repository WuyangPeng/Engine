///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 15:02)

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
