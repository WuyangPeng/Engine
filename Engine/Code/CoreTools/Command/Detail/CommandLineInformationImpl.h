//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:49)

// 命令行信息。
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
        [[nodiscard]] const std::string ExcessArguments() const;
        [[nodiscard]] int GetExcessArgumentsCount() const noexcept;

        [[nodiscard]] bool GetBoolean(const std::string& name) const;  // 返回存在的选项

        [[nodiscard]] int GetInteger(const std::string& name) const;
        [[nodiscard]] float GetFloat(const std::string& name) const;
        [[nodiscard]] double GetDouble(const std::string& name) const;
        [[nodiscard]] const std::string GetString(const std::string& name) const;
        [[nodiscard]] const std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNmaeUsed();

    private:
        using CommandArgumentContainerSharedPtr = std::shared_ptr<CommandArgumentContainer>;

    private:
        static const std::string GetFileNameDescription();

        CommandArgumentContainerSharedPtr m_CommandArgumentContainer;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_IMPL_H
