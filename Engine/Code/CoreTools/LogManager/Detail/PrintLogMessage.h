///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:46)

#ifndef CORE_TOOLS_LOG_MANAGER_PRINT_LOG_MESSAGE_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_PRINT_LOG_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "LogMessageImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE PrintLogMessage : public LogMessageImpl
    {
    public:
        using ClassType = PrintLogMessage;
        using ParentType = LogMessageImpl;

    public:
        PrintLogMessage(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD LogMessageImplSharedPtr Clone() const override;

        LogMessageImpl& operator<<(char value) override;
        LogMessageImpl& operator<<(wchar_t value) override;
        LogMessageImpl& operator<<(const char* value) override;
        LogMessageImpl& operator<<(const wchar_t* value) override;
        LogMessageImpl& operator<<(int32_t value) override;
        LogMessageImpl& operator<<(uint32_t value) override;
        LogMessageImpl& operator<<(int64_t value) override;
        LogMessageImpl& operator<<(uint64_t value) override;
        LogMessageImpl& operator<<(float value) override;
        LogMessageImpl& operator<<(double value) override;
        LogMessageImpl& operator<<(const std::string& value) override;
        LogMessageImpl& operator<<(const std::string_view& value) override;
        LogMessageImpl& operator<<(const std::wstring& value) override;
        LogMessageImpl& operator<<(const std::wstring_view& value) override;
        LogMessageImpl& operator<<(const Error& error) override;
        LogMessageImpl& operator<<(const std::exception& error) override;
        LogMessageImpl& operator<<(LogAppenderIOManageSign sign) override;

        NODISCARD bool IsDisabled() const noexcept override;

        NODISCARD String GetFileName() const override;

        NODISCARD bool HasAlwaysConsole() const noexcept override;
        NODISCARD bool HasTriggerAssert() const noexcept override;

    private:
        LogAppenderIOManageSignContainer logAppenderIOManageSign;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_PRINT_LOG_MESSAGE_IMPL_H
