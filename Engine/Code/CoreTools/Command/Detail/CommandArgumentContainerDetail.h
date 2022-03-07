///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 11:06)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H

#include "CommandArgumentContainer.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename R>
R CoreTools::CommandArgumentContainer::Find(const std::string& argumentsName, R (CommandArgument::*function)() const) const
{
    if (function != nullptr)
    {
        const auto iter = commandArgument.find(argumentsName);

        if (iter != commandArgument.cend())
        {
            const auto& argument = iter->second;

            return (argument.*function)();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到命令行索引！"s));
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
