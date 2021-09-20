//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 16:23)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisCommandArgumentContainer.h"
#include "CommandArgumentType.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

using std::make_pair;
using std::make_shared;
using std::string;

CoreTools::AnalysisCommandArgumentContainer::AnalysisCommandArgumentContainer(int argumentsNumber, char** arguments)
    : m_Argument{}, m_CommandArgumentContainer{ make_shared<CommandArgumentContainer>(argumentsNumber) }
{
    Init(arguments);
    AddCommandArguments();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisCommandArgumentContainer::Init(char const* const* arguments)
{
    const auto argumentsNumber = m_CommandArgumentContainer->GetArgumentsNumber();

    if (arguments != nullptr)
    {
        for (auto i = 0; i < argumentsNumber; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            if (arguments[i] != nullptr)
            {
                string argument{ arguments[i] != nullptr ? arguments[i] : "" };

                m_Argument.emplace_back(argument);
            }
#include STSTEM_WARNING_POP
        }
    }
}

CoreTools::AnalysisCommandArgumentContainer::AnalysisCommandArgumentContainer(const char* commandLine)
    : m_Argument{}, m_CommandArgumentContainer{}
{
    Init(commandLine);
    AddCommandArguments();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisCommandArgumentContainer::Init(const char* commandLine)
{
    string trimCommandLine{ commandLine };
    boost::algorithm::trim(trimCommandLine);
    boost::algorithm::split(m_Argument, trimCommandLine, boost::is_any_of(" \t"), boost::token_compress_on);

    auto argumentsNumber = boost::numeric_cast<int>(m_Argument.size());

    m_CommandArgumentContainer = make_shared<CommandArgumentContainer>(argumentsNumber);
}

// private
void CoreTools::AnalysisCommandArgumentContainer::AddCommandArguments()
{
    // 从1开始索引
    auto index = sm_FristCheckIndex;
    auto argumentsNumber = boost::numeric_cast<int>(m_Argument.size());
    while (index < argumentsNumber)
    {
        const auto argumentsType = GetArgumentsType(index);

        switch (argumentsType)
        {
            case ArgumentsType::FullArgument:
                AddArgumentValue(index);
                index += 2;
                break;
            case ArgumentsType::NoValueArgument:
                AddNoValueArgument(index);
                ++index;
                break;
            case ArgumentsType::EndArgumentValue:
                AddEndArgumentValue(index);
                ++index;
                break;
            default:
                break;
        }
    }
}

CoreTools::AnalysisCommandArgumentContainer::ArgumentsType CoreTools::AnalysisCommandArgumentContainer::GetArgumentsType(int index)
{
    const auto& argumentsName = m_Argument.at(index);

    CommandArgumentType argumentsNameType{ argumentsName };

    if (argumentsNameType.IsArgumentsName())
    {
        return GetNextArgumentsType(index);
    }
    else
    {
        return ArgumentsType::EndArgumentValue;
    }
}

CoreTools::AnalysisCommandArgumentContainer::ArgumentsType CoreTools::AnalysisCommandArgumentContainer::GetNextArgumentsType(int index)
{
    auto argumentsNumber = boost::numeric_cast<int>(m_Argument.size());

    const auto nextIndex = index + 1;

    if (nextIndex < argumentsNumber)
    {
        const auto& argumentsValue = m_Argument.at(nextIndex);

        CommandArgumentType argumentsValueType{ argumentsValue };

        if (!argumentsValueType.IsArgumentsName())
        {
            return ArgumentsType::FullArgument;
        }
    }

    return ArgumentsType::NoValueArgument;
}

void CoreTools::AnalysisCommandArgumentContainer::AddArgumentValue(int index)
{
    const auto& arguments = m_Argument.at(index);

    auto argumentsName = arguments.substr(1, arguments.size() - 1);

    const auto nextIndex = index + 1;

    string argumentsValue{ m_Argument.at(nextIndex) };

    m_CommandArgumentContainer->AddArgument(index, argumentsName, argumentsValue);
}

void CoreTools::AnalysisCommandArgumentContainer::AddNoValueArgument(int index)
{
    const auto& arguments = m_Argument.at(index);

    CommandArgumentType commandArgumentType{ arguments };

    if (commandArgumentType.IsArgumentsName())
    {
        auto argumentsName = arguments.substr(1, arguments.size() - 1);
        m_CommandArgumentContainer->AddArgument(index, argumentsName);
    }
}

void CoreTools::AnalysisCommandArgumentContainer::AddEndArgumentValue(int index)
{
    const auto& argumentsName = m_Argument.at(index);

    m_CommandArgumentContainer->AddEndArgumentValue(argumentsName);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::AnalysisCommandArgumentContainer::IsValid() const noexcept
{
    if (m_CommandArgumentContainer != nullptr && m_CommandArgumentContainer->GetArgumentsNumber() == gsl::narrow_cast<int>(m_Argument.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::AnalysisCommandArgumentContainer::CommandArgumentContainerSharedPtr CoreTools::AnalysisCommandArgumentContainer::GetCommandArgumentContainer() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_CommandArgumentContainer;
}
