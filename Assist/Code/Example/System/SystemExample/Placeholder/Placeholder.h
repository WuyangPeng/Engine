///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 19:46)

#ifndef SYSTEM_EXAMPLE_PLACEHOLDER_H
#define SYSTEM_EXAMPLE_PLACEHOLDER_H

#include "Example/System/SystemExample/SystemExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace SystemExample
{
    class SYSTEM_EXAMPLE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SYSTEM_EXAMPLE_PLACEHOLDER_H
