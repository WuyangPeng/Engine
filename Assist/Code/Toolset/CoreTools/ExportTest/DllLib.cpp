///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/15 19:11)

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