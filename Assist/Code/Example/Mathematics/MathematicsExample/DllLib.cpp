///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:28)

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
