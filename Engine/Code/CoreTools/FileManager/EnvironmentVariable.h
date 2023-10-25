///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:40)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EnvironmentVariableImpl);

namespace CoreTools
{
    // 获取字符串对应的环境变量。
    class CORE_TOOLS_DEFAULT_DECLARE EnvironmentVariable final
    {
    public:
        NON_COPY_TYPE_DECLARE(EnvironmentVariable);

        using String = System::String;

    public:
        explicit EnvironmentVariable(const String& variableName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetVariable() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
