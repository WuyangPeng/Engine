///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 13:39)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentType.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentType::CommandArgumentType(string argument) noexcept
    : argument{ std::move(argument) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandArgumentType)

bool CoreTools::CommandArgumentType::IsArgumentsName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!argument.empty() && argument.at(0) == '-' && 1 < argument.size())
        return true;
    else
        return false;
}

bool CoreTools::CommandArgumentType::IsDigit() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!argument.empty())
    {
        const auto firstArgument = argument.at(0);
        if (firstArgument != '-' && isdigit(static_cast<int>(firstArgument)))
        {
            return true;
        }
    }

    return false;
}

bool CoreTools::CommandArgumentType::IsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!argument.empty() && argument.at(0) != '-')
        return true;
    else
        return false;
}
