/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:07)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessage.h"
#include "Detail/LogMessageFactory.h"
#include "Detail/LogMessageImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(CoreTools, LogMessage)

CoreTools::LogMessage::LogMessage(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed)
    : impl{ ImplCreateUseFactory::Default, level, filter, functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogMessage::LogMessage(const LogFileName& fileName, LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed)
    : impl{ ImplCreateUseFactory::Default, fileName, level, filter, functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessage)

CoreTools::LogMessage::String CoreTools::LogMessage::GetMessageDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetMessageDescribe();
}

CoreTools::LogLevel CoreTools::LogMessage::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetLogLevel();
}

CoreTools::LogFilter CoreTools::LogMessage::GetLogFilterType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetLogFilterType();
}

int CoreTools::LogMessage::GetMessageSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetMessageSize();
}

CoreTools::FunctionDescribed CoreTools::LogMessage::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFunctionDescribed();
}

bool CoreTools::LogMessage::IsDisabled() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsDisabled();
}

CoreTools::LogMessage::String CoreTools::LogMessage::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFileName();
}

bool CoreTools::LogMessage::HasAlwaysConsole() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->HasAlwaysConsole();
}

bool CoreTools::LogMessage::HasTriggerAssert() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->HasTriggerAssert();
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(char value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(wchar_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const char* value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const wchar_t* value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(int32_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(uint32_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(int64_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(uint64_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(float value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(double value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const std::string_view& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const std::wstring& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const std::wstring_view& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << value;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const Error& error)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << error;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(const std::exception& error)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << error;

    return *this;
}

CoreTools::LogMessage& CoreTools::LogMessage::operator<<(LogAppenderIOManageSign sign)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << sign;

    return *this;
}