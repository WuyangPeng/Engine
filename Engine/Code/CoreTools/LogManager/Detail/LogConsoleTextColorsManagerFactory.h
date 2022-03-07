///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 16:14)

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
