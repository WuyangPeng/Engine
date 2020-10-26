//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 16:42)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisCommandArgumentContainer.h"
#include "CommandLineInformationImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 

using std::string;

CoreTools::CommandLineInformationImpl::CommandLineInformationImpl(int argumentsNumber, char** arguments)
    : m_CommandArgumentContainer{}
{
    AnalysisCommandArgumentContainer analysisCommandArgumentContainer{ argumentsNumber, arguments };

    m_CommandArgumentContainer = analysisCommandArgumentContainer.GetCommandArgumentContainer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandLineInformationImpl::CommandLineInformationImpl(const char* commandLine)
    : m_CommandArgumentContainer{}
{
    AnalysisCommandArgumentContainer analysisCommandArgumentContainer{ commandLine };

    m_CommandArgumentContainer = analysisCommandArgumentContainer.GetCommandArgumentContainer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CommandLineInformationImpl::IsValid() const noexcept
{
    if (m_CommandArgumentContainer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

const string CoreTools::CommandLineInformationImpl::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CommandArgumentContainer->ExcessArguments();
}

bool CoreTools::CommandLineInformationImpl::GetBoolean(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (m_CommandArgumentContainer->IsExist(name))
        return true;
    else
        return false;
}

int CoreTools::CommandLineInformationImpl::GetInteger(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CommandArgumentContainer->GetInteger(name);
}

float CoreTools::CommandLineInformationImpl::GetFloat(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CommandArgumentContainer->GetFloat(name);
}

double CoreTools::CommandLineInformationImpl::GetDouble(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CommandArgumentContainer->GetDouble(name);
}

const string CoreTools::CommandLineInformationImpl::GetString(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CommandArgumentContainer->GetString(name);
}

const string CoreTools::CommandLineInformationImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetString(GetFileNameDescription());
}

void CoreTools::CommandLineInformationImpl::SetUsed(const string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_CommandArgumentContainer->SetUsed(argumentsName);
}

void CoreTools::CommandLineInformationImpl::SetFileNmaeUsed()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    SetUsed(GetFileNameDescription());
}

int CoreTools::CommandLineInformationImpl::GetExcessArgumentsCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_CommandArgumentContainer->GetExcessArgumentsCount();
}

const std::string CoreTools::CommandLineInformationImpl::GetFileNameDescription()
{
    return "fileName";
}
