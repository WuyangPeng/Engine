///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:02)

#ifndef CORE_TOOLS_LOG_MANAGER_NULL_LOG_MESSAGE_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_NULL_LOG_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "LogMessageImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE NullLogMessage : public LogMessageImpl
    {
    public:
        using ClassType = NullLogMessage;
        using ParentType = LogMessageImpl;

    public:
        NullLogMessage(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD LogMessageImplSharedPtr Clone() const override;

        LogMessageImpl& operator<<(const char* value) noexcept override;
        LogMessageImpl& operator<<(const wchar_t* value) noexcept override;
        LogMessageImpl& operator<<(int32_t value) noexcept override;
        LogMessageImpl& operator<<(uint32_t value) noexcept override;
        LogMessageImpl& operator<<(int64_t value) noexcept override;
        LogMessageImpl& operator<<(uint64_t value) noexcept override;
        LogMessageImpl& operator<<(float value) noexcept override;
        LogMessageImpl& operator<<(double value) noexcept override;
        LogMessageImpl& operator<<(const std::string& value) noexcept override;
        LogMessageImpl& operator<<(const std::string_view& value) noexcept override;
        LogMessageImpl& operator<<(const std::wstring& value) noexcept override;
        LogMessageImpl& operator<<(const Error& error) noexcept override;
        LogMessageImpl& operator<<(const std::exception& error) noexcept override;
        LogMessageImpl& operator<<(LogAppenderIOManageSign sign) noexcept override;

        NODISCARD bool IsDisabled() const noexcept override;

        NODISCARD String GetFileName() const noexcept override;

        NODISCARD bool HasAlwaysConsole() const noexcept override;
        NODISCARD bool HasTriggerAssert() const noexcept override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_NULL_LOG_MESSAGE_IMPL_H
