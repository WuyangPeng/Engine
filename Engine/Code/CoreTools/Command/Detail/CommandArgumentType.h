///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 11:35)

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
        explicit CommandArgumentType(std::string argument) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsArgumentsName() const;
        NODISCARD bool IsDigit() const;
        NODISCARD bool IsString() const;

    private:
        std::string argument;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_TYPE_H
