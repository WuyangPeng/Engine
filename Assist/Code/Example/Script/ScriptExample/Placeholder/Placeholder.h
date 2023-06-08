///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.11 (2023/05/29 15:36)

#ifndef SCRIPT_EXAMPLE_PLACEHOLDER_H
#define SCRIPT_EXAMPLE_PLACEHOLDER_H

#include "Example/Script/ScriptExample/ScriptExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ScriptExample
{
    class SCRIPT_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCRIPT_EXAMPLE_PLACEHOLDER_H
