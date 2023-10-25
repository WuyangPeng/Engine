///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:01)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H

#include "CommandArgumentContainer.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename R>
R CoreTools::CommandArgumentContainer::Find(const std::string& argumentsName, R (CommandArgument::*function)() const) const
{
    if (function != nullptr)
    {
        if (const auto iter = commandArgument.find(argumentsName); iter != commandArgument.cend())
        {
            const auto& argument = iter->second;

            return (argument.*function)();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到命令行索引！"s))
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
