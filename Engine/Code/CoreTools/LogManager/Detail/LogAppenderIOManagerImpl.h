//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:00)

// 日志输出位置IO管理器基类内部接口
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
        using AppenderManagerPtr = std::shared_ptr<AppenderManager>;
        using String = System::String;

    public:
        LogAppenderIOManagerImpl(LogLevel logLevel, const AppenderManagerPtr& appenderManager) noexcept;
        LogAppenderIOManagerImpl(MAYBE_UNUSED int count) noexcept;
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

        void SetAppenderManager(const AppenderManagerPtr& appenderManager) noexcept;

    private:
        using LogFilterTypePtr = std::shared_ptr<LogFilter>;
        using LogFileNamePtr = std::shared_ptr<LogFileName>;
        using FunctionDescribedPtr = std::shared_ptr<FunctionDescribed>;

    private:
        void Refresh();
        [[nodiscard]] bool Write();
        void TriggerAssert();
        void Reset() noexcept;

    private:
        LogLevel m_logLevel;
        AppenderManagerPtr m_AppenderManager;
        LogFilterTypePtr m_FilterTypePtr;
        FunctionDescribedPtr m_FunctionDescribedPtr;
        LogFileNamePtr m_LogFileNamePtr;
        String m_Message;
        bool m_TriggerAssert;
        bool m_AlwaysConsole;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_H
