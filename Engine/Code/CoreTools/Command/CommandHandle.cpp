///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/21 11:36)

#include "CoreTools/CoreToolsExport.h"

#include "CommandHandle.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CommandHandle::CommandHandle(int argumentsNumber, char** arguments)
    : commandLineInformation{ argumentsNumber, arguments },
      small{ 0.0 },
      large{ 0.0 },
      minSet{ false },
      maxSet{ false },
      infSet{ false },
      supSet{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CommandHandle::CommandHandle(const char* commandLine)
    : commandLineInformation{ commandLine },
      small{ 0.0 },
      large{ 0.0 },
      minSet{ false },
      maxSet{ false },
      infSet{ false },
      supSet{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandHandle)

std::string CoreTools::CommandHandle::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return commandLineInformation.ExcessArguments();
}

CoreTools::CommandHandle& CoreTools::CommandHandle::SetMinValue(double value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    small = value;
    minSet = true;

    return *this;
}

CoreTools::CommandHandle& CoreTools::CommandHandle::SetMaxValue(double value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    large = value;
    maxSet = true;

    return *this;
}

CoreTools::CommandHandle& CoreTools::CommandHandle::SetInfValue(double value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    small = value;
    infSet = true;

    return *this;
}

CoreTools::CommandHandle& CoreTools::CommandHandle::SetSupValue(double value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    large = value;
    supSet = true;

    return *this;
}

bool CoreTools::CommandHandle::GetBoolean(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return commandLineInformation.GetBoolean(name);
}

int CoreTools::CommandHandle::GetInteger(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto value = commandLineInformation.GetInteger(name);

    if (IsArgumentOutOfRange(value))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("参数超出范围！"s))
    }

    return value;
}

float CoreTools::CommandHandle::GetFloat(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto value = commandLineInformation.GetFloat(name);

    if (IsArgumentOutOfRange(value))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("参数超出范围！"s))
    }

    return value;
}

double CoreTools::CommandHandle::GetDouble(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto value = commandLineInformation.GetDouble(name);

    if (IsArgumentOutOfRange(value))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("参数超出范围！"s))
    }

    return value;
}

std::string CoreTools::CommandHandle::GetString(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return commandLineInformation.GetString(name);
}

std::string CoreTools::CommandHandle::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return commandLineInformation.GetFileName();
}

// private
bool CoreTools::CommandHandle::IsArgumentOutOfRange(double value) const noexcept
{
    if ((minSet && value < small) || (maxSet && large < value) || (infSet && value <= small) || (supSet && large <= value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CoreTools::CommandHandle::ClearBoundary() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    minSet = false;
    maxSet = false;
    infSet = false;
    supSet = false;
    large = 0.0;
    small = 0.0;
}

void CoreTools::CommandHandle::SetFileNameUsed()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return commandLineInformation.SetFileNameUsed();
}

void CoreTools::CommandHandle::SetUsed(const std::string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return commandLineInformation.SetUsed(argumentsName);
}

int CoreTools::CommandHandle::GetExcessArgumentsCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return commandLineInformation.GetExcessArgumentsCount();
}
