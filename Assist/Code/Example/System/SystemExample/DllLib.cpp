///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 19:45)

#include "Example/System/SystemExample/SystemExampleExport.h"

#include "Example/System/SystemExample/SystemExample.h"

#ifndef BUILDING_SYSTEM_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_SYSTEM_EXAMPLE_STATIC

namespace SystemExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_EXAMPLE_STATIC
