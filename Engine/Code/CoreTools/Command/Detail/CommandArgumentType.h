//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:48)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_TYPE_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentType final
    {
    public:
        using ClassType = CommandArgumentType;

    public:
        explicit CommandArgumentType(const std::string& argument);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsArgumentsName() const;
        [[nodiscard]] bool IsDigit() const;
        [[nodiscard]] bool IsString() const;

    private:
        std::string m_Argument;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_TYPE_H
