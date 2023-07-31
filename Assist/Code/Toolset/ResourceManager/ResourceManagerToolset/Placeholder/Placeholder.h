///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:35)

#ifndef RESOURCE_MANAGER_TOOLSET_PLACEHOLDER_H
#define RESOURCE_MANAGER_TOOLSET_PLACEHOLDER_H

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ResourceManagerToolset
{
    class RESOURCE_MANAGER_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // RESOURCE_MANAGER_TOOLSET_PLACEHOLDER_H