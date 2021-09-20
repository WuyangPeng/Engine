//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:44)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H

#include "CommandArgumentContainer.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename R>
R CoreTools::CommandArgumentContainer::Find(const std::string& argumentsName, R (CommandArgument::*function)() const) const
{
    if (function != nullptr)
    {
        const auto iter = m_CommandArgument.find(argumentsName);

        if (iter != m_CommandArgument.cend())
        {
            const auto& commandArgument = iter->second;

            return (commandArgument.*function)();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到命令行索引！"s));
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
