//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:07)

#ifndef CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H

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
        OutputManager m_ConsoleTextColorsManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_OUTPUT_CONSOLE_TEXT_COLOR_MANAGER_H
