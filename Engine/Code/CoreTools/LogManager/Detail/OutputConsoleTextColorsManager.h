///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:46)

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
