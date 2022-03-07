///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 13:45)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisCommandArgumentContainer.h"
#include "CommandLineInformationImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

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
    if (commandArgumentContainer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

string CoreTools::CommandLineInformationImpl::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->ExcessArguments();
}

bool CoreTools::CommandLineInformationImpl::GetBoolean(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (commandArgumentContainer->IsExist(name))
        return true;
    else
        return false;
}

int CoreTools::CommandLineInformationImpl::GetInteger(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetInteger(name);
}

float CoreTools::CommandLineInformationImpl::GetFloat(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetFloat(name);
}

double CoreTools::CommandLineInformationImpl::GetDouble(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetDouble(name);
}

string CoreTools::CommandLineInformationImpl::GetString(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgumentContainer->GetString(name);
}

string CoreTools::CommandLineInformationImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetString("fileName");
}

void CoreTools::CommandLineInformationImpl::SetUsed(const string& argumentsName)
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
