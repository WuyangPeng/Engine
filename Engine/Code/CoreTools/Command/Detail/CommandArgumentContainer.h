/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:32)

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

        NODISCARD int GetArgumentsNumber() const noexcept;

        NODISCARD bool IsUsed(const std::string& argumentsName) const;
        void SetUsed(const std::string& argumentsName);

        NODISCARD int GetIndex(const std::string& argumentsName) const;

        NODISCARD int GetInteger(const std::string& argumentsName) const;
        NODISCARD float GetFloat(const std::string& argumentsName) const;
        NODISCARD double GetDouble(const std::string& argumentsName) const;
        NODISCARD const std::string GetString(const std::string& argumentsName) const;

        NODISCARD bool IsInteger(const std::string& argumentsName) const;
        NODISCARD bool IsFloat(const std::string& argumentsName) const;
        NODISCARD bool IsDouble(const std::string& argumentsName) const;
        NODISCARD bool IsString(const std::string& argumentsName) const;
        NODISCARD bool IsExist(const std::string& argumentsName) const;

        // 返回第一个未处理参数的名字。
        NODISCARD std::string ExcessArguments() const;
        NODISCARD int GetExcessArgumentsCount() const noexcept;

    private:
        using CommandArgumentUsedContainer = std::map<std::string, CommandArgument>;

    private:
        template <typename R>
        NODISCARD R Find(const std::string& argumentsName, R (CommandArgument::*function)() const) const;

    private:
        int argumentsNumber;
        CommandArgumentUsedContainer commandArgument;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H
