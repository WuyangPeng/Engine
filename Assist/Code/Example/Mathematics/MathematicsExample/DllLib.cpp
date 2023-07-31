///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 11:28)

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
