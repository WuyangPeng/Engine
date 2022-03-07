///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 21:42)

#ifndef CORE_TOOLS_LOG_MANAGER_LOGGER_H
#define CORE_TOOLS_LOG_MANAGER_LOGGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(Logger, LoggerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Logger final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Logger);

    public:
        Logger(LogFilter logFilter, LogLevel logLevel);

        CLASS_INVARIANT_DECLARE;

        NODISCARD LogFilter GetLogFilterType() const noexcept;
        NODISCARD LogLevel GetLogLevel() const noexcept;

        void SetLogLevel(LogLevel level);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOGGER_H
