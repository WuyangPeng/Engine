///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 14:54)

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
        LogAppenderIOManagerImpl(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager) noexcept;
        LogAppenderIOManagerImpl() noexcept;
        ~LogAppenderIOManagerImpl() noexcept;

        LogAppenderIOManagerImpl(const LogAppenderIOManagerImpl&) = delete;
        LogAppenderIOManagerImpl operator=(const LogAppenderIOManagerImpl&) = delete;
        LogAppenderIOManagerImpl(LogAppenderIOManagerImpl&&) noexcept = delete;
        LogAppenderIOManagerImpl operator=(LogAppenderIOManagerImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        template <typename T>
        LogAppenderIOManagerImpl& operator<<(T value) noexcept;

        LogAppenderIOManagerImpl& operator<<(const char* message) noexcept;
        LogAppenderIOManagerImpl& operator<<(const wchar_t* message) noexcept;
        LogAppenderIOManagerImpl& operator<<(const std::string& message) noexcept;
        LogAppenderIOManagerImpl& operator<<(const std::string_view& message) noexcept;
        LogAppenderIOManagerImpl& operator<<(const std::wstring& message) noexcept;
        LogAppenderIOManagerImpl& operator<<(const FunctionDescribed& functionDescribed) noexcept;
        LogAppenderIOManagerImpl& operator<<(const Error& error) noexcept;
        LogAppenderIOManagerImpl& operator<<(const std::exception& error) noexcept;
        LogAppenderIOManagerImpl& operator<<(LogFilter filterType) noexcept;
        LogAppenderIOManagerImpl& operator<<(LogAppenderIOManageSign sign) noexcept;
        LogAppenderIOManagerImpl& operator<<(const LogFileName& logFileName) noexcept;

        void SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept;

    private:
        using LogFilterSharedPtr = std::shared_ptr<LogFilter>;
        using LogFileNameSharedPtr = std::shared_ptr<LogFileName>;
        using FunctionDescribedSharedPtr = std::shared_ptr<FunctionDescribed>;

    private:
        template <typename T>
        void AddMessage(T value);

        void Refresh();
        NODISCARD bool Write();
        void TriggerAssert();
        void Reset() noexcept;
        NODISCARD bool IsDisabled() const;

    private:
        LogLevel logLevel;
        AppenderManagerSharedPtr currentAppenderManager;
        LogFilterSharedPtr currentFilterType;
        FunctionDescribedSharedPtr currentFunctionDescribed;
        LogFileNameSharedPtr currentLogFileName;
        String logMessage;
        bool triggerAssert;
        bool alwaysConsole;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_H
