//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 17:30)

// ��ȡ�ַ�����Ӧ�Ļ���������
#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

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

        EnvironmentVariableImpl(const EnvironmentVariableImpl&) = delete;
        EnvironmentVariableImpl& operator=(const EnvironmentVariableImpl&) = delete;
        EnvironmentVariableImpl(EnvironmentVariableImpl&&) noexcept = delete;
        EnvironmentVariableImpl& operator=(EnvironmentVariableImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetVariable() const;

    private:
        void GainEnv(const String& variableName);

    private:
        TChar* m_EnvironmentVariable;
        String m_EnvironmentVariableFromJson;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_IMPL_H
