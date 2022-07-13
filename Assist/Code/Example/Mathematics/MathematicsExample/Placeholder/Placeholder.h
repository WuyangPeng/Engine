///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 15:08)

#ifndef MATHEMATICS_EXAMPLE_PLACEHOLDER_H
#define MATHEMATICS_EXAMPLE_PLACEHOLDER_H

#include "Example/Mathematics/MathematicsExample/MathematicsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MathematicsExample
{
    class MATHEMATICS_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MATHEMATICS_EXAMPLE_PLACEHOLDER_H
