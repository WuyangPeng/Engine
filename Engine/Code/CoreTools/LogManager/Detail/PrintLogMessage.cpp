///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:57)

#include "CoreTools/CoreToolsExport.h"

#include "PrintLogMessage.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/Log.h"
#include "CoreTools/LogManager/LogFileName.h"
#include "CoreTools/LogManager/LogMessage.h"

CoreTools::PrintLogMessage::PrintLogMessage(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept
    : ParentType{ level, filter, functionDescribed }, logAppenderIOManageSign{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PrintLogMessage)

CoreTools::LogMessageImpl::LogMessageImplSharedPtr CoreTools::PrintLogMessage::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(char value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::MultiByteConversionStandard(std::string{ value }));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(wchar_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::WideCharConversionStandard(std::wstring{ value }));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const char* value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::MultiByteConversionStandard(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const wchar_t* value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::WideCharConversionStandard(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(int32_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(System::ToString(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(uint32_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(System::ToString(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(int64_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(System::ToString(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(uint64_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(System::ToString(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(float value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(System::ToString(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(double value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(System::ToString(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::MultiByteConversionStandard(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const std::string_view& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::MultiByteConversionStandard(value.data()));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const std::wstring& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::WideCharConversionStandard(value));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const std::wstring_view& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::WideCharConversionStandard(value.data()));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const Error& error)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(error.GetError());
    SetFunctionDescribed(error.GetFunctionDescribed());

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(const std::exception& error)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddMessage(StringConversion::MultiByteConversionStandard(error.what()));

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::PrintLogMessage::operator<<(LogAppenderIOManageSign sign)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    logAppenderIOManageSign.emplace_back(sign);

    return *this;
}

bool CoreTools::PrintLogMessage::IsDisabled() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

System::String CoreTools::PrintLogMessage::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    DisableNoexcept();

    return SYSTEM_TEXT("");
}

bool CoreTools::PrintLogMessage::HasAlwaysConsole() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::ranges::find(logAppenderIOManageSign, LogAppenderIOManageSign::AlwaysConsole) != logAppenderIOManageSign.cend();
}

bool CoreTools::PrintLogMessage::HasTriggerAssert() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::ranges::find(logAppenderIOManageSign, LogAppenderIOManageSign::TriggerAssert) != logAppenderIOManageSign.cend();
}