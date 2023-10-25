///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:46)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogMessageImpl
    {
    public:
        using ClassType = LogMessageImpl;
        using FactoryType = LogMessageFactory;

        using String = System::String;
        using LogMessageImplSharedPtr = std::shared_ptr<LogMessageImpl>;
        using LogAppenderIOManageSignContainer = std::vector<LogAppenderIOManageSign>;

    public:
        LogMessageImpl(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept;

        virtual ~LogMessageImpl() noexcept = default;
        LogMessageImpl(const LogMessageImpl& rhs) = default;
        LogMessageImpl& operator=(const LogMessageImpl& rhs) = default;
        LogMessageImpl(LogMessageImpl&& rhs) noexcept = default;
        LogMessageImpl& operator=(LogMessageImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD String GetMessageDescribe() const;
        NODISCARD LogLevel GetLogLevel() const noexcept;
        NODISCARD LogFilter GetLogFilterType() const noexcept;
        NODISCARD int GetMessageSize() const;
        NODISCARD FunctionDescribed GetFunctionDescribed() const noexcept;

        NODISCARD virtual LogMessageImplSharedPtr Clone() const = 0;

        virtual LogMessageImpl& operator<<(char value) = 0;
        virtual LogMessageImpl& operator<<(wchar_t value) = 0;
        virtual LogMessageImpl& operator<<(const char* value) = 0;
        virtual LogMessageImpl& operator<<(const wchar_t* value) = 0;
        virtual LogMessageImpl& operator<<(int32_t value) = 0;
        virtual LogMessageImpl& operator<<(uint32_t value) = 0;
        virtual LogMessageImpl& operator<<(int64_t value) = 0;
        virtual LogMessageImpl& operator<<(uint64_t value) = 0;
        virtual LogMessageImpl& operator<<(float value) = 0;
        virtual LogMessageImpl& operator<<(double value) = 0;
        virtual LogMessageImpl& operator<<(const std::string& value) = 0;
        virtual LogMessageImpl& operator<<(const std::string_view& value) = 0;
        virtual LogMessageImpl& operator<<(const std::wstring& value) = 0;
        virtual LogMessageImpl& operator<<(const std::wstring_view& value) = 0;
        virtual LogMessageImpl& operator<<(const Error& error) = 0;
        virtual LogMessageImpl& operator<<(const std::exception& error) = 0;
        virtual LogMessageImpl& operator<<(LogAppenderIOManageSign sign) = 0;

        NODISCARD virtual bool IsDisabled() const noexcept = 0;

        NODISCARD virtual String GetFileName() const = 0;

        NODISCARD virtual bool HasAlwaysConsole() const noexcept = 0;
        NODISCARD virtual bool HasTriggerAssert() const noexcept = 0;

    protected:
        void AddMessage(const String& value);
        void SetFunctionDescribed(const FunctionDescribed& aFunctionDescribed) noexcept;

    private:
        LogLevel logLevel;
        LogFilter filter;
        String message;
        FunctionDescribed functionDescribed;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H
