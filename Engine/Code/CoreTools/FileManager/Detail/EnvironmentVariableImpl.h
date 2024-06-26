/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:32)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

/// 获取字符串对应的环境变量。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnvironmentVariableImpl final
    {
    public:
        using ClassType = EnvironmentVariableImpl;

        using TChar = System::TChar;
        using String = System::String;

    public:
        explicit EnvironmentVariableImpl(const String& variableName);
        ~EnvironmentVariableImpl() noexcept;

        EnvironmentVariableImpl(const EnvironmentVariableImpl& rhs) = delete;
        EnvironmentVariableImpl& operator=(const EnvironmentVariableImpl& rhs) = delete;
        EnvironmentVariableImpl(EnvironmentVariableImpl&& rhs) noexcept = delete;
        EnvironmentVariableImpl& operator=(EnvironmentVariableImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetVariable() const;

    private:
        void GainEnv(const String& variableName);

    private:
        TChar* environmentVariable;
        String environmentVariableFromJson;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
