///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:50)

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
