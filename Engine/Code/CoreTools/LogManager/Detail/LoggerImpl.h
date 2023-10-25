///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:45)

#ifndef CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LoggerImpl final
    {
    public:
        using ClassType = LoggerImpl;

    public:
        LoggerImpl(LogFilter logFilter, LogLevel logLevel) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD LogFilter GetLogFilterType() const noexcept;
        NODISCARD LogLevel GetLogLevel() const noexcept;
        void SetLogLevel(LogLevel level) noexcept;

    private:
        LogFilter logFilter;
        LogLevel logLevel;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H
