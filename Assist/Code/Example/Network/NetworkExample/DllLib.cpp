///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:18)

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
