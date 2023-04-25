///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 09:41)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessage.h"
#include "Detail/LogMessageFactory.h"
#include "Detail/LogMessageImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/LogManager/LogFileName.h"

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetMessageDescribe, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetLogFilterType, CoreTools::LogFilter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetMessageSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetFunctionDescribed, CoreTools::FunctionDescribed)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, IsDisabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetFileName, System::String)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, HasAlwaysConsole, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, HasTriggerAssert, bool)

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