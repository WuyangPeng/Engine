///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:02)

#include "CoreTools/CoreToolsExport.h"

#include "NullLogMessage.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogFileName.h"

CoreTools::NullLogMessage::NullLogMessage(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept
    : ParentType{ level, filter, functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullLogMessage)

CoreTools::LogMessageImpl::LogMessageImplSharedPtr CoreTools::NullLogMessage::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const char* value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const wchar_t* value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(int32_t value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(uint32_t value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(int64_t value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(uint64_t value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(float value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(double value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const std::string& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const std::string_view& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const std::wstring& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(value);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const Error& error) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(error);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(const std::exception& error) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(error);

    return *this;
}

CoreTools::LogMessageImpl& CoreTools::NullLogMessage::operator<<(LogAppenderIOManageSign sign) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(sign);

    return *this;
}

bool CoreTools::NullLogMessage::IsDisabled() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return true;
}

System::String CoreTools::NullLogMessage::GetFileName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT("");
}

bool CoreTools::NullLogMessage::HasAlwaysConsole() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

bool CoreTools::NullLogMessage::HasTriggerAssert() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}