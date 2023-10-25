///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:06)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentFactory.h"
#include "CommandArgumentImpl.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentPackage : public CommandArgumentImpl
    {
    public:
        using ClassType = CommandArgumentPackage;
        using FactoryType = CommandArgumentFactory;

    public:
        CommandArgumentPackage(int index, std::string name) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetIndex() const noexcept override;
        NODISCARD std::string GetName() const override;

        NODISCARD bool IsUsed() const noexcept override;
        void SetUsed() noexcept override;

    private:
        int index;
        std::string name;
        bool used;  // 跟踪已处理的参数
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H
