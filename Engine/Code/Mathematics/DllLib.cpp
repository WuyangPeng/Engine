///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 11:10)

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
