///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/05 15:00)

#ifndef CORE_TOOLS_EXAMPLE_PLACEHOLDER_H
#define CORE_TOOLS_EXAMPLE_PLACEHOLDER_H

#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreToolsExample
{
    class CORE_TOOLS_EXAMPLE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CORE_TOOLS_EXAMPLE_PLACEHOLDER_H
