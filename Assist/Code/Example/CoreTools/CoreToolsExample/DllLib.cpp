///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/14 15:48)

#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleExport.h"

#include "Example/CoreTools/CoreToolsExample/CoreToolsExample.h"

#ifndef BUILDING_CORE_TOOLS_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_CORE_TOOLS_EXAMPLE_STATIC

namespace CoreToolsExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CORE_TOOLS_EXAMPLE_STATIC
