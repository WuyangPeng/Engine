/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:42)

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
