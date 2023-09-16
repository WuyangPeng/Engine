///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/21 10:19)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisCommandArgumentContainer.h"
#include "CommandArgumentType.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

CoreTools::AnalysisCommandArgumentContainer::AnalysisCommandArgumentContainer(int argumentsNumber, char** arguments)
    : argumentContainer{}, commandArgumentContainer{ std::make_shared<CommandArgumentContainer>(argumentsNumber) }
{
    Init(arguments);
    AddCommandArguments();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisCommandArgumentContainer::Init(const char* const* arguments)
{
    if (arguments != nullptr)
    {
        const auto argumentsNumber = commandArgumentContainer->GetArgumentsNumber();

        for (auto i = 0; i < argumentsNumber; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            if (arguments[i] != nullptr)
            {
                std::string argument{ arguments[i] != nullptr ? arguments[i] : "" };

                argumentContainer.emplace_back(argument);
            }

#include SYSTEM_WARNING_POP
        }
    }
}

CoreTools::AnalysisCommandArgumentContainer::AnalysisCommandArgumentContainer(const char* commandLine)
    : argumentContainer{}, commandArgumentContainer{}
{
    Init(commandLine);
    AddCommandArguments();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisCommandArgumentContainer::Init(const char* commandLine)
{
    std::string trimCommandLine{ commandLine };
    boost::algorithm::trim(trimCommandLine);
    split(argumentContainer, trimCommandLine, boost::is_any_of(" \t"), boost::token_compress_on);

    auto argumentsNumber = boost::numeric_cast<int>(argumentContainer.size());

    commandArgumentContainer = std::make_shared<CommandArgumentContainer>(argumentsNumber);
}

// private
void CoreTools::AnalysisCommandArgumentContainer::AddCommandArguments()
{
    // 从1开始索引
    auto index = firstCheckIndex;
    const auto argumentsNumber = boost::numeric_cast<int>(argumentContainer.size());
    while (index < argumentsNumber)
    {
        switch (const auto argumentsType = GetArgumentsType(index); argumentsType)
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

CoreTools::AnalysisCommandArgumentContainer::ArgumentsType CoreTools::AnalysisCommandArgumentContainer::GetArgumentsType(int index) const
{
    const auto& argumentsName = argumentContainer.at(index);

    if (const CommandArgumentType argumentsNameType{ argumentsName }; argumentsNameType.IsArgumentsName())
    {
        return GetNextArgumentsType(index);
    }
    else
    {
        return ArgumentsType::EndArgumentValue;
    }
}

CoreTools::AnalysisCommandArgumentContainer::ArgumentsType CoreTools::AnalysisCommandArgumentContainer::GetNextArgumentsType(int index) const
{
    const auto argumentsNumber = boost::numeric_cast<int>(argumentContainer.size());

    if (const auto nextIndex = index + 1; nextIndex < argumentsNumber)
    {
        const auto& argumentsValue = argumentContainer.at(nextIndex);

        if (const CommandArgumentType argumentsValueType{ argumentsValue }; !argumentsValueType.IsArgumentsName())
        {
            return ArgumentsType::FullArgument;
        }
    }

    return ArgumentsType::NoValueArgument;
}

void CoreTools::AnalysisCommandArgumentContainer::AddArgumentValue(int index)
{
    const auto& arguments = argumentContainer.at(index);

    const auto argumentsName = arguments.substr(1, arguments.size() - 1);

    const auto nextIndex = index + 1;

    const auto argumentsValue = argumentContainer.at(nextIndex);

    commandArgumentContainer->AddArgument(index, argumentsName, argumentsValue);
}

void CoreTools::AnalysisCommandArgumentContainer::AddNoValueArgument(int index)
{
    const auto& arguments = argumentContainer.at(index);

    if (const CommandArgumentType commandArgumentType{ arguments }; commandArgumentType.IsArgumentsName())
    {
        const auto argumentsName = arguments.substr(1, arguments.size() - 1);
        commandArgumentContainer->AddArgument(index, argumentsName);
    }
}

void CoreTools::AnalysisCommandArgumentContainer::AddEndArgumentValue(int index)
{
    const auto& argumentsName = argumentContainer.at(index);

    commandArgumentContainer->AddEndArgumentValue(argumentsName);
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::AnalysisCommandArgumentContainer::IsValid() const noexcept
{
    if (commandArgumentContainer != nullptr && commandArgumentContainer->GetArgumentsNumber() == gsl::narrow_cast<int>(argumentContainer.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::AnalysisCommandArgumentContainer::CommandArgumentContainerSharedPtr CoreTools::AnalysisCommandArgumentContainer::GetCommandArgumentContainer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return commandArgumentContainer;
}
