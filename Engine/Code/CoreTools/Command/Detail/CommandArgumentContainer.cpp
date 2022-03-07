///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 13:32)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentContainerDetail.h"
#include "CommandArgumentType.h"
#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using namespace std::literals;

CoreTools::CommandArgumentContainer::CommandArgumentContainer(int argumentsNumber)
    : argumentsNumber{ argumentsNumber }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CommandArgumentContainer::IsValid() const noexcept
{
    return 0 < argumentsNumber;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::CommandArgumentContainer::AddArgument(int index, const string& argumentsName, const string& argumentsValue)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(0 < index && index < argumentsNumber, "索引错误！");

    const CommandArgument argument{ index, argumentsName, argumentsValue };
    commandArgument.insert({ argumentsName, argument });
}

void CoreTools::CommandArgumentContainer::AddArgument(int index, const string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(0 < index && index < argumentsNumber, "索引错误！");

    const CommandArgument argument{ index, argumentsName };
    commandArgument.insert({ argumentsName, argument });
}

int CoreTools::CommandArgumentContainer::GetArgumentsNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return argumentsNumber;
}

bool CoreTools::CommandArgumentContainer::IsUsed(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsUsed);
}

void CoreTools::CommandArgumentContainer::SetUsed(const string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto iter = commandArgument.find(argumentsName);

    if (iter != commandArgument.cend())
    {
        auto& argument = iter->second;

        return argument.SetUsed();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到命令行索引！"s));
    }
}

int CoreTools::CommandArgumentContainer::GetIndex(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetIndex);
}

int CoreTools::CommandArgumentContainer::GetInteger(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetInteger);
}

float CoreTools::CommandArgumentContainer::GetFloat(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetFloat);
}

double CoreTools::CommandArgumentContainer::GetDouble(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetDouble);
}

const string CoreTools::CommandArgumentContainer::GetString(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetString);
}

bool CoreTools::CommandArgumentContainer::IsInteger(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsInteger);
}

bool CoreTools::CommandArgumentContainer::IsFloat(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsFloat);
}

bool CoreTools::CommandArgumentContainer::IsDouble(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsDouble);
}

bool CoreTools::CommandArgumentContainer::IsString(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsString);
}

bool CoreTools::CommandArgumentContainer::IsExist(const string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgument.find(argumentsName) != commandArgument.cend();
}

void CoreTools::CommandArgumentContainer::AddEndArgumentValue(const string& argumentsValue)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!commandArgument.empty())
    {
        auto iter = commandArgument.end();
        --iter;

        auto& argument = iter->second;

        argument.AddEndArgumentValue(argumentsValue);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("命令行不允许以字符串打头！"s));
    }
}

const string CoreTools::CommandArgumentContainer::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    for (const auto& value : commandArgument)
    {
        const auto& argument = value.second;
        if (!argument.IsUsed())
        {
            return argument.GetName();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("命令行没有未处理的参数！"s));
}

int CoreTools::CommandArgumentContainer::GetExcessArgumentsCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto count = 0;

    for (const auto& value : commandArgument)
    {
        const auto& argument = value.second;
        if (!argument.IsUsed())
        {
            ++count;
        }
    }

    return count;
}
