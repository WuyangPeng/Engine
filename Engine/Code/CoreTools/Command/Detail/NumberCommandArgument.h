//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:53)

#ifndef CORE_TOOLS_COMMAND_NUMBER_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_NUMBER_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE NumberCommandArgument final : public CommandArgumentImpl
    {
    public:
        using ClassType = NumberCommandArgument;
        using ParentType = CommandArgumentImpl;

    public:
        NumberCommandArgument(int index, const std::string& name, const std::string& value);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] int GetInteger() const final;
        [[nodiscard]] float GetFloat() const final;
        [[nodiscard]] double GetDouble() const final;
        [[nodiscard]] const std::string GetString() const final;

        [[nodiscard]] bool IsInteger() const noexcept final;
        [[nodiscard]] bool IsFloat() const noexcept final;
        [[nodiscard]] bool IsDouble() const noexcept final;
        [[nodiscard]] bool IsString() const noexcept final;
        [[nodiscard]] bool IsNoValue() const noexcept final;

        [[nodiscard]] CommandArgumentSharedPtr Clone() const final;

        void AddArgumentValue(const std::string& value) final;

    private:
        std::string m_Value;
    };
}

#endif  // CORE_TOOLS_COMMAND_NUMBER_COMMAND_ARGUMENT_H
