//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:55)

#ifndef CORE_TOOLS_COMMAND_COMMAND_H
#define CORE_TOOLS_COMMAND_COMMAND_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandLineInformation.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandHandle final
    {
    public:
        using ClassType = CommandHandle;

    public:
        CommandHandle(int argumentsNumber, char** arguments);
        explicit CommandHandle(const char* commandLine);

        CLASS_INVARIANT_DECLARE;

        // 返回第一个未处理参数的名字。
        [[nodiscard]] const std::string ExcessArguments() const;
        [[nodiscard]] int GetExcessArgumentsCount() const noexcept;

        // 设置数字参数的范围。
        // 如果范围是必需的，他们必须为每个参数设置。
        CommandHandle& SetMinValue(double value) noexcept;
        CommandHandle& SetMaxValue(double value) noexcept;
        CommandHandle& SetInfValue(double value) noexcept;
        CommandHandle& SetSupValue(double value) noexcept;

        void ClearBoundary() noexcept;

        // 下列方法每个的返回值是参数数组中的索引选项和值。

        // 使用布尔方法在不采取任何参数的选项，例如下面的例子
        // MyProgram -debug -x 10 -y 20 -fileName fileName
        // 选项 -debug 没有参数。

        // 返回存在的选项
        [[nodiscard]] bool GetBoolean(const std::string& name) const;

        [[nodiscard]] int GetInteger(const std::string& name) const;
        [[nodiscard]] float GetFloat(const std::string& name) const;
        [[nodiscard]] double GetDouble(const std::string& name) const;
        [[nodiscard]] const std::string GetString(const std::string& name) const;
        [[nodiscard]] const std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNmaeUsed();

    private:
        [[nodiscard]] bool IsArgumentOutOfRange(double value) const noexcept;

    private:
        // 命令行信息。
        CommandLineInformation m_CommandLineInformation;

        // 参数的边界检查。
        double m_Small;  // 数值参数的下界 (min 或 inf)
        double m_Large;  // 数值参数的上界 (max 或 sup)
        bool m_MinSet;  // 如果为真，比较：m_Small <= arg
        bool m_MaxSet;  // 如果为真，比较：arg <= m_Large
        bool m_InfSet;  // 如果为真，比较：m_Small < arg
        bool m_SupSet;  // 如果为真，比较：arg < m_Large
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_H
