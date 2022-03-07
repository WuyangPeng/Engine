///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 11:06)

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

        NODISCARD ArgumentsType GetArgumentsType(int index);
        NODISCARD ArgumentsType GetNextArgumentsType(int index);

    private:
        // ����0Ϊ��������
        static constexpr auto firstCheckIndex = 1;

        ArgumentContainer argumentContainer;
        CommandArgumentContainerSharedPtr commandArgumentContainer;
    };
}

#endif  // CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H
