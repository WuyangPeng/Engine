/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:32)

#ifndef CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H
#define CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentContainer.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AnalysisCommandArgumentContainer final
    {
    public:
        using ClassType = AnalysisCommandArgumentContainer;

        using CommandArgumentContainerSharedPtr = std::shared_ptr<CommandArgumentContainer>;

    public:
        AnalysisCommandArgumentContainer(int argumentsNumber, char** arguments);
        explicit AnalysisCommandArgumentContainer(const char* commandLine);

        NODISCARD CommandArgumentContainerSharedPtr GetCommandArgumentContainer() const noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        using ArgumentContainer = std::vector<std::string>;

    private:
        enum class ArgumentsType
        {
            FullArgument,
            NoValueArgument,
            EndArgumentValue,
        };

    private:
        void Init(const char* const* arguments);
        void Init(const char* commandLine);

        void AddCommandArguments();

        void AddArgumentValue(int index);
        void AddNoValueArgument(int index);
        void AddEndArgumentValue(int index);

        NODISCARD ArgumentsType GetArgumentsType(int index) const;
        NODISCARD ArgumentsType GetNextArgumentsType(int index) const;

    private:
        // 索引0为程序名。
        static constexpr auto firstCheckIndex = 1;

        ArgumentContainer argumentContainer;
        CommandArgumentContainerSharedPtr commandArgumentContainer;
    };
}

#endif  // CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H
