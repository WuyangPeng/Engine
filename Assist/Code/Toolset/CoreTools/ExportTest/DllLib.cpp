///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.2 (2022/09/18 14:44)

#ifndef BUILDING_STATIC

    #include "DllLib.h"

#else  // BUILDING_STATIC

namespace ExportTest
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_STATIC