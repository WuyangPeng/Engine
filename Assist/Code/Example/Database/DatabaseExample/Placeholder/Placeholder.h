///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 13:51)

#ifndef DATABASE_EXAMPLE_PLACEHOLDER_H
#define DATABASE_EXAMPLE_PLACEHOLDER_H

#include "Example/Database/DatabaseExample/DatabaseExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace DatabaseExample
{
    class DATABASE_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // DATABASE_EXAMPLE_PLACEHOLDER_H
