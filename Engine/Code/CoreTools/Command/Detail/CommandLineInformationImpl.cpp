/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:24)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisCommandArgumentContainer.h"
#include "CommandLineInformationImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CommandLineInformationImpl::CommandLineInformationImpl(int argumentsNumber, char** arguments)
    : commandArgumentContainer{}
{
    const AnalysisCommandArgumentContainer analysisCommandArgumentContainer{ argumentsNumber, arguments };

    commandArgumentContainer = analysisCommandArgumentContainer.GetCommandArgumentContainer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandLineInformationImpl::CommandLineInformationImpl(const char* commandLine)
    : commandArgumentContainer{}
{
    const AnalysisCommandArgumentContainer analysisCommandArgumentContainer{ commandLine };

    commandArgumentContainer = analysisCommandArgumentContainer.GetCommandArgumentContainer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CommandLineInformationImpl::IsValid() const noexcept
{
    return commandArgumentContainer != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

std::string CoreTools::CommandLineInformationImpl::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->ExcessArguments();
}

bool CoreTools::CommandLineInformationImpl::GetBoolean(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->IsExist(name);
}

int CoreTools::CommandLineInformationImpl::GetInteger(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetInteger(name);
}

float CoreTools::CommandLineInformationImpl::GetFloat(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetFloat(name);
}

double CoreTools::CommandLineInformationImpl::GetDouble(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetDouble(name);
}

std::string CoreTools::CommandLineInformationImpl::GetString(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetString(name);
}

std::string CoreTools::CommandLineInformationImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetString("fileName");
}

void CoreTools::CommandLineInformationImpl::SetUsed(const std::string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    commandArgumentContainer->SetUsed(argumentsName);
}

void CoreTools::CommandLineInformationImpl::SetFileNameUsed()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    SetUsed("fileName");
}

int CoreTools::CommandLineInformationImpl::GetExcessArgumentsCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return commandArgumentContainer->GetExcessArgumentsCount();
}
