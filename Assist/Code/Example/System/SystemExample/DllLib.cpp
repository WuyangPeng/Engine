///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/17 11:37)

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
