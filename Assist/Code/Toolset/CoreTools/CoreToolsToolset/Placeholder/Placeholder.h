///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.3 (2023/03/02 11:27)

#ifndef CORE_TOOLS_TOOLSET_PLACEHOLDER_H
#define CORE_TOOLS_TOOLSET_PLACEHOLDER_H

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreToolsToolset
{
    class CORE_TOOLS_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CORE_TOOLS_TOOLSET_PLACEHOLDER_H
