/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:50)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <boost/format/format_fwd.hpp>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogAppenderIOManagerImpl
    {
    public:
        using ClassType = LogAppenderIOManagerImpl;

        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;
        using String = System::String;

    public:
        LogAppenderIOManagerImpl(LogLevel logLevel, AppenderManagerSharedPtr appenderManager) noexcept;
        LogAppenderIOManagerImpl() noexcept;
        ~LogAppenderIOManagerImpl() noexcept = default;

        LogAppenderIOManagerImpl(const LogAppenderIOManagerImpl&) = delete;
        LogAppenderIOManagerImpl operator=(const LogAppenderIOManagerImpl&) = delete;
        LogAppenderIOManagerImpl(LogAppenderIOManagerImpl&&) noexcept = delete;
        LogAppenderIOManagerImpl operator=(LogAppenderIOManagerImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        LogAppenderIOManagerImpl& operator<<(const LogMessage& message);

        void SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept;

    private:
        using LogFilterSharedPtr = std::shared_ptr<LogFilter>;
        using LogFileNameSharedPtr = std::shared_ptr<LogFileName>;
        using FunctionDescribedSharedPtr = std::shared_ptr<FunctionDescribed>;
        using LogMessageSharedPtr = std::shared_ptr<LogMessage>;

    private:
        NODISCARD bool Write(const LogMessage& message);
        void TriggerAssert(const LogMessage& message);

    private:
        LogLevel logLevel;
        AppenderManagerSharedPtr currentAppenderManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_H
