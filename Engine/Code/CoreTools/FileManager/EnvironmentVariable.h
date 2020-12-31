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

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(EnvironmentVariableImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EnvironmentVariable final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(EnvironmentVariable);
        using String = System::String;

    public:
        explicit EnvironmentVariable(const String& variableName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetVariable() const;

    private:
        IMPL_TYPE_DECLARE(EnvironmentVariable);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
