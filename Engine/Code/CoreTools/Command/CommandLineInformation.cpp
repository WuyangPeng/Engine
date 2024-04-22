/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:25)

#include "CoreTools/CoreToolsExport.h"

#include "CommandLineInformation.h"
#include "Detail/CommandLineInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CommandLineInformation)

CoreTools::CommandLineInformation::CommandLineInformation(int argumentsNumber, char** arguments)
    : impl{ argumentsNumber, arguments }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CommandLineInformation::CommandLineInformation(const char* commandLine)
    : impl{ commandLine }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandLineInformation)

std::string CoreTools::CommandLineInformation::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->ExcessArguments();
}

int CoreTools::CommandLineInformation::GetExcessArgumentsCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetExcessArgumentsCount();
}

bool CoreTools::CommandLineInformation::GetBoolean(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBoolean(name);
}

int CoreTools::CommandLineInformation::GetInteger(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetInteger(name);
}

float CoreTools::CommandLineInformation::GetFloat(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFloat(name);
}

double CoreTools::CommandLineInformation::GetDouble(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDouble(name);
}

std::string CoreTools::CommandLineInformation::GetString(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetString(name);
}

std::string CoreTools::CommandLineInformation::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileName();
}

void CoreTools::CommandLineInformation::SetUsed(const std::string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetUsed(argumentsName);
}

void CoreTools::CommandLineInformation::SetFileNameUsed()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetFileNameUsed();
}
