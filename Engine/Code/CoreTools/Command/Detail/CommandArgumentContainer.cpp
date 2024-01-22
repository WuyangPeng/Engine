/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:33)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentContainerDetail.h"
#include "CommandArgumentType.h"
#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <ranges>

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

void CoreTools::CommandArgumentContainer::AddArgument(int index, const std::string& argumentsName, const std::string& argumentsValue)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(0 < index && index < argumentsNumber, "��������");

    const CommandArgument argument{ index, argumentsName, argumentsValue };
    commandArgument.insert({ argumentsName, argument });
}

void CoreTools::CommandArgumentContainer::AddArgument(int index, const std::string& argumentsName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(0 < index && index < argumentsNumber, "��������");

    const CommandArgument argument{ index, argumentsName };
    commandArgument.insert({ argumentsName, argument });
}

int CoreTools::CommandArgumentContainer::GetArgumentsNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return argumentsNumber;
}

bool CoreTools::CommandArgumentContainer::IsUsed(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsUsed);
}

void CoreTools::CommandArgumentContainer::SetUsed(const std::string& argumentsName)
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
        THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�������������"s))
    }
}

int CoreTools::CommandArgumentContainer::GetIndex(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetIndex);
}

int CoreTools::CommandArgumentContainer::GetInteger(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetInteger);
}

float CoreTools::CommandArgumentContainer::GetFloat(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetFloat);
}

double CoreTools::CommandArgumentContainer::GetDouble(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetDouble);
}

const std::string CoreTools::CommandArgumentContainer::GetString(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::GetString);
}

bool CoreTools::CommandArgumentContainer::IsInteger(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsInteger);
}

bool CoreTools::CommandArgumentContainer::IsFloat(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsFloat);
}

bool CoreTools::CommandArgumentContainer::IsDouble(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsDouble);
}

bool CoreTools::CommandArgumentContainer::IsString(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return Find(argumentsName, &CommandArgument::IsString);
}

bool CoreTools::CommandArgumentContainer::IsExist(const std::string& argumentsName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return commandArgument.contains(argumentsName);
}

void CoreTools::CommandArgumentContainer::AddEndArgumentValue(const std::string& argumentsValue)
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
        THROW_EXCEPTION(SYSTEM_TEXT("�����в��������ַ�����ͷ��"s))
    }
}

std::string CoreTools::CommandArgumentContainer::ExcessArguments() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    for (const auto& element : commandArgument | std::views::values)
    {
        if (const auto& argument = element; !argument.IsUsed())
        {
            return argument.GetName();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("������û��δ����Ĳ�����"s))
}

int CoreTools::CommandArgumentContainer::GetExcessArgumentsCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto count = 0;

    for (const auto& element : commandArgument | std::views::values)
    {
        if (const auto& argument = element; !argument.IsUsed())
        {
            ++count;
        }
    }

    return count;
}
