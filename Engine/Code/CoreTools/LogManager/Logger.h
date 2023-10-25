///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:48)

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
