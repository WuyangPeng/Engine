///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:39)

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