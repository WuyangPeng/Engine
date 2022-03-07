///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 11:48)

#ifndef CORE_TOOLS_COMMAND_STRING_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_STRING_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentPackage.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StringCommandArgument final : public CommandArgumentPackage
    {
    public:
        using ClassType = StringCommandArgument;
        using ParentType = CommandArgumentPackage;

    public:
        StringCommandArgument(int index, const std::string& name, const std::string& value);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetInteger() const final;
        NODISCARD float GetFloat() const final;
        NODISCARD double GetDouble() const final;
        NODISCARD const std::string GetString() const final;

        NODISCARD bool IsInteger() const noexcept final;
        NODISCARD bool IsFloat() const noexcept final;
        NODISCARD bool IsDouble() const noexcept final;
        NODISCARD bool IsString() const noexcept final;
        NODISCARD bool IsNoValue() const noexcept final;

        NODISCARD CommandArgumentSharedPtr Clone() const final;

        void AddArgumentValue(const std::string& value) final;

    private:
        std::string m_String;
    };
}

#endif  // CORE_TOOLS_COMMAND_STRING_COMMAND_ARGUMENT_H
