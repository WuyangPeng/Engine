///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/09 19:55)

#ifndef INPUT_OUTPUT_TOOLSET_PLACEHOLDER_H
#define INPUT_OUTPUT_TOOLSET_PLACEHOLDER_H

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace InputOutputToolset
{
    class INPUT_OUTPUT_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // INPUT_OUTPUT_TOOLSET_PLACEHOLDER_H
