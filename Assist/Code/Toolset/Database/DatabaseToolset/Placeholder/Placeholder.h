///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.9 (2023/05/25 11:27)

#ifndef DATABASE_TOOLSET_PLACEHOLDER_H
#define DATABASE_TOOLSET_PLACEHOLDER_H

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace DatabaseToolset
{
    class DATABASE_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // DATABASE_TOOLSET_PLACEHOLDER_H
