/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:21)

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

        /// 返回第一个未处理参数的名字。
        NODISCARD std::string ExcessArguments() const;
        NODISCARD int GetExcessArgumentsCount() const noexcept;

        /// 设置数字参数的范围。
        /// 如果范围是必需的，他们必须为每个参数设置。
        CommandHandle& SetMinValue(double value) noexcept;
        CommandHandle& SetMaxValue(double value) noexcept;
        CommandHandle& SetInfValue(double value) noexcept;
        CommandHandle& SetSupValue(double value) noexcept;

        void ClearBoundary() noexcept;

        /// 下列方法每个的返回值是参数数组中的索引选项和值。

        /// 使用布尔方法在不采取任何参数的选项，例如下面的例子
        /// MyProgram -debug -x 10 -y 20 -fileName fileName
        /// 选项 -debug 没有参数。

        /// 返回存在的选项
        NODISCARD bool GetBoolean(const std::string& name) const;

        NODISCARD int GetInteger(const std::string& name) const;
        NODISCARD float GetFloat(const std::string& name) const;
        NODISCARD double GetDouble(const std::string& name) const;
        NODISCARD std::string GetString(const std::string& name) const;
        NODISCARD std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNameUsed();

    private:
        NODISCARD bool IsArgumentOutOfRange(double value) const noexcept;

    private:
        /// 命令行信息。
        CommandLineInformation commandLineInformation;

        /// 参数的边界检查。
        double small;  /// 数值参数的下界 (min 或 inf)
        double large;  /// 数值参数的上界 (max 或 sup)
        bool minSet;  /// 如果为真，比较：small <= arg
        bool maxSet;  /// 如果为真，比较：arg <= large
        bool infSet;  /// 如果为真，比较：small < arg
        bool supSet;  /// 如果为真，比较：arg < large
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_H
