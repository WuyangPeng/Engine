///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:06)

#ifndef CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H
#define CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Command/CommandInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandLineInformationImpl final
    {
    public:
        using ClassType = CommandLineInformationImpl;

    public:
        CommandLineInformationImpl(int argumentsNumber, char** arguments);
        explicit CommandLineInformationImpl(const char* commandLine);

        CLASS_INVARIANT_DECLARE;

        // 返回第一个未处理参数的名字。
        NODISCARD std::string ExcessArguments() const;
        NODISCARD int GetExcessArgumentsCount() const noexcept;

        NODISCARD bool GetBoolean(const std::string& name) const;  // 返回存在的选项

        NODISCARD int GetInteger(const std::string& name) const;
        NODISCARD float GetFloat(const std::string& name) const;
        NODISCARD double GetDouble(const std::string& name) const;
        NODISCARD std::string GetString(const std::string& name) const;
        NODISCARD std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNameUsed();

    private:
        using CommandArgumentContainerSharedPtr = std::shared_ptr<CommandArgumentContainer>;

    private:
        CommandArgumentContainerSharedPtr commandArgumentContainer;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H
