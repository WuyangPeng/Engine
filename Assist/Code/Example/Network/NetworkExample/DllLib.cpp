///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 15:44)

#include "Example/Network/NetworkExample/NetworkExampleExport.h"

#include "Example/Network/NetworkExample/NetworkExample.h"

#ifndef BUILDING_NETWORK_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_NETWORK_EXAMPLE_STATIC

namespace NetworkExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_NETWORK_EXAMPLE_STATIC
