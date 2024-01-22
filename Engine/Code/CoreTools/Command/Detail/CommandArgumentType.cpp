/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:34)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentType.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CommandArgumentType::CommandArgumentType(std::string argument) noexcept
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
        if (const auto firstArgument = argument.at(0); firstArgument != '-' && isdigit(static_cast<int>(firstArgument)))
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
