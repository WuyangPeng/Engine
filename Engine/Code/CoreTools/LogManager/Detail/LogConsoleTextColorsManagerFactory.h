///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 15:23)

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
        NODISCARD static LogConsoleTextColorsManagerPtr Create(LogLevel logLevel);
        NODISCARD static LogConsoleTextColorsManagerPtr Create(const OStreamShared& streamShared, LogLevel logLevel);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLORS_MANAGER_FACTORY_H
