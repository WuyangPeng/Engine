///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:19)

// 数学库（Mathematics）封装了引擎的数学功能。
// 数学库位于引擎的第三层，只允许调用引擎中的CoreTools库，并使用boost、stlsoft工具库。数学库封装了线性代数相关的计算。

#include "Mathematics/MathematicsExport.h"

#include "Mathematics/Mathematics.h"

#ifndef BUILDING_MATHEMATICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MATHEMATICS_STATIC
