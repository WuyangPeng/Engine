///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 15:06)

#include "Example/Mathematics/MathematicsExample/MathematicsExampleExport.h"

#include "Example/Mathematics/MathematicsExample/MathematicsExample.h"

#ifndef BUILDING_MATHEMATICS_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_MATHEMATICS_EXAMPLE_STATIC

namespace MathematicsExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MATHEMATICS_EXAMPLE_STATIC
