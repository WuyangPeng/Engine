///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:25)

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