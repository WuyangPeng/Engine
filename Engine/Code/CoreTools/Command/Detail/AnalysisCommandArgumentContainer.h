//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:44)

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

        [[nodiscard]] CommandArgumentContainerSharedPtr GetCommandArgumentContainer() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        enum class ArgumentsType
        {
            FullArgument,
            NoValueArgument,
            EndArgumentValue,
        };

    private:
        void Init(char const* const* arguments);
        void Init(const char* commandLine);

        void AddCommandArguments();

        void AddArgumentValue(int index);
        void AddNoValueArgument(int index);
        void AddEndArgumentValue(int index);

        [[nodiscard]] ArgumentsType GetArgumentsType(int index);
        [[nodiscard]] ArgumentsType GetNextArgumentsType(int index);

    private:
        using ArgumentContainer = std::vector<std::string>;

    private:
        // ����0Ϊ��������
        static constexpr auto sm_FristCheckIndex = 1;

        ArgumentContainer m_Argument;
        CommandArgumentContainerSharedPtr m_CommandArgumentContainer;
    };
}

#endif  // CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H
