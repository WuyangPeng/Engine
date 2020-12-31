//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:04)

// 记录器类内部接口
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

        [[nodiscard]] LogFilter GetLogFilterType() const noexcept;
        [[nodiscard]] LogLevel GetLogLevel() const noexcept;
        void SetLogLevel(LogLevel level) noexcept;

    private:
        LogFilter m_LogFilter;
        LogLevel m_Level;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOGGER_IMPL_H
