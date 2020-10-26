//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:45)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Command/CommandArgument.h"

#include <map>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentContainer final
    {
    public:
        using ClassType = CommandArgumentContainer;

    public:
        explicit CommandArgumentContainer(int argumentsNumber);

        CLASS_INVARIANT_DECLARE;

        void AddArgument(int index, const std::string& argumentsName);
        void AddArgument(int index, const std::string& argumentsName, const std::string& argumentsValue);
        void AddEndArgumentValue(const std::string& argumentsValue);

        [[nodiscard]] int GetArgumentsNumber() const noexcept;

        [[nodiscard]] bool IsUsed(const std::string& argumentsName) const;
        void SetUsed(const std::string& argumentsName);

        [[nodiscard]] int GetIndex(const std::string& argumentsName) const;

        [[nodiscard]] int GetInteger(const std::string& argumentsName) const;
        [[nodiscard]] float GetFloat(const std::string& argumentsName) const;
        [[nodiscard]] double GetDouble(const std::string& argumentsName) const;
        [[nodiscard]] const std::string GetString(const std::string& argumentsName) const;

        [[nodiscard]] bool IsInteger(const std::string& argumentsName) const;
        [[nodiscard]] bool IsFloat(const std::string& argumentsName) const;
        [[nodiscard]] bool IsDouble(const std::string& argumentsName) const;
        [[nodiscard]] bool IsString(const std::string& argumentsName) const;
        [[nodiscard]] bool IsExist(const std::string& argumentsName) const;

        // ���ص�һ��δ������������֡�
        [[nodiscard]] const std::string ExcessArguments() const;
        [[nodiscard]] int GetExcessArgumentsCount() const;

    private:
        using CommandArgumentUsedContainer = std::map<std::string, CommandArgument>;

    private:
        template <typename R>
        R Find(const std::string& argumentsName, R (CommandArgument::*function)() const) const;

    private:
        int m_ArgumentsNumber;
        CommandArgumentUsedContainer m_CommandArgument;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H
