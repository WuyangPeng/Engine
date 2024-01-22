/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:36)

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
