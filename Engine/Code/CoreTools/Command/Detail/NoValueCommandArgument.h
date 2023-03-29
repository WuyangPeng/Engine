///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/21 09:42)

#ifndef CORE_TOOLS_COMMAND_NO_VALUE_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_NO_VALUE_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentPackage.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE NoValueCommandArgument final : public CommandArgumentPackage
    {
    public:
        using ClassType = NoValueCommandArgument;
        using ParentType = CommandArgumentPackage;

    public:
        NoValueCommandArgument(int index, const std::string& name);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetInteger() const override;
        NODISCARD float GetFloat() const override;
        NODISCARD double GetDouble() const override;
        NODISCARD std::string GetString() const override;

        NODISCARD bool IsInteger() const noexcept override;
        NODISCARD bool IsFloat() const noexcept override;
        NODISCARD bool IsDouble() const noexcept override;
        NODISCARD bool IsString() const noexcept override;
        NODISCARD bool IsNoValue() const noexcept override;

        NODISCARD CommandArgumentSharedPtr Clone() const override;

        void AddArgumentValue(const std::string& value) override;
    };
}

#endif  // CORE_TOOLS_COMMAND_NO_VALUE_COMMAND_ARGUMENT_H
