///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.8 (2023/05/10 18:19)

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
