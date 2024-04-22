/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:54)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(LogMessage, LogMessageImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogMessage final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(LogMessage);

        using String = System::String;
        using LogAppenderIOManageSignContainer = std::vector<LogAppenderIOManageSign>;

    public:
        LogMessage(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed);
        LogMessage(const LogFileName& fileName, LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetMessageDescribe() const;
        NODISCARD LogLevel GetLogLevel() const noexcept;
        NODISCARD LogFilter GetLogFilterType() const noexcept;
        NODISCARD int GetMessageSize() const;
        NODISCARD FunctionDescribed GetFunctionDescribed() const noexcept;

        NODISCARD bool IsDisabled() const noexcept;

        LogMessage& operator<<(char value);
        LogMessage& operator<<(wchar_t value);
        LogMessage& operator<<(const char* value);
        LogMessage& operator<<(const wchar_t* value);
        LogMessage& operator<<(int32_t value);
        LogMessage& operator<<(uint32_t value);
        LogMessage& operator<<(int64_t value);
        LogMessage& operator<<(uint64_t value);
        LogMessage& operator<<(float value);
        LogMessage& operator<<(double value);
        LogMessage& operator<<(const std::string& value);
        LogMessage& operator<<(const std::string_view& value);
        LogMessage& operator<<(const std::wstring& value);
        LogMessage& operator<<(const std::wstring_view& value);
        LogMessage& operator<<(const Error& error);
        LogMessage& operator<<(const std::exception& error);
        LogMessage& operator<<(LogAppenderIOManageSign sign);

        NODISCARD String GetFileName() const;

        NODISCARD bool HasAlwaysConsole() const noexcept;
        NODISCARD bool HasTriggerAssert() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_H
