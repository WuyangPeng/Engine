/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:32)

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
