///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/21 09:34)

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

    THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�������������"s))
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_DETAIL_H
