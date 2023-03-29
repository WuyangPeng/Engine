///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:11)

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
        LogConsoleTextColorsManager(const OStreamShared& osPtr, LogLevel logLevel);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_H
