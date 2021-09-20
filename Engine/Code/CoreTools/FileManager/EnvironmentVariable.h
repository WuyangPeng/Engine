//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:27)

// ��ȡ�ַ�����Ӧ�Ļ���������
#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EnvironmentVariableImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EnvironmentVariable final
    {
    public:
        NON_COPY_TYPE_DECLARE(EnvironmentVariable);
        using String = System::String;

    public:
        explicit EnvironmentVariable(const String& variableName);
        ~EnvironmentVariable() noexcept = default;
        EnvironmentVariable(const EnvironmentVariable& rhs) noexcept = delete;
        EnvironmentVariable& operator=(const EnvironmentVariable& rhs) noexcept = delete;
        EnvironmentVariable(EnvironmentVariable&& rhs) noexcept = delete;
        EnvironmentVariable& operator=(EnvironmentVariable&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetVariable() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
