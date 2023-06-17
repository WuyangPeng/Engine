///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 10:27)

#ifndef ASSIST_TOOLS_EXAMPLE_PLACEHOLDER_H
#define ASSIST_TOOLS_EXAMPLE_PLACEHOLDER_H

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AssistToolsExample
{
    class ASSIST_TOOLS_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ASSIST_TOOLS_EXAMPLE_PLACEHOLDER_H
