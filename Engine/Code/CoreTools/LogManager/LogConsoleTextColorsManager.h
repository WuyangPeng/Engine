/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:53)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(LogConsoleTextColorsManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogConsoleTextColorsManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(LogConsoleTextColorsManager);

    public:
        explicit LogConsoleTextColorsManager(LogLevel logLevel);
        LogConsoleTextColorsManager(const OStreamShared& streamShared, LogLevel logLevel);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H
