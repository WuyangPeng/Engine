///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:48)

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetExport.h"

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolset.h"

#ifndef BUILDING_MATHEMATICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_MATHEMATICS_STATIC

namespace MathematicsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MATHEMATICS_STATIC