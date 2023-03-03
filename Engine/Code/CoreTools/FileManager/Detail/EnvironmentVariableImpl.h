///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 09:44)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

// ��ȡ�ַ�����Ӧ�Ļ���������
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
