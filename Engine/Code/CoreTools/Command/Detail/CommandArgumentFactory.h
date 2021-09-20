//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:47)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Command/CommandInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentFactory final
    {
    public:
        using ClassType = CommandArgumentFactory;
        using CommandArgumentSharedPtr = std::shared_ptr<CommandArgumentPackage>;

    public:
        [[nodiscard]] static CommandArgumentSharedPtr Create(int index, const std::string& arguments, const std::string& value);
        [[nodiscard]] static CommandArgumentSharedPtr Create(int index, const std::string& arguments);
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H
