//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:01)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H

#include "CoreTools/LogManager/LogManagerInternalFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <iosfwd>
#include <memory>

namespace CoreTools
{
    class LogConsoleTextColorsManagerFactory final
    {
    public:
        using ClassType = LogConsoleTextColorsManagerFactory;
        using LogConsoleTextColorsManagerPtr = std::shared_ptr<LogConsoleTextColorsManagerImpl>;

    public:
        [[nodiscard]] static LogConsoleTextColorsManagerPtr Create(LogLevel logLevel);
        [[nodiscard]] static LogConsoleTextColorsManagerPtr Create(const OStreamShared& osPtr, LogLevel logLevel);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H
