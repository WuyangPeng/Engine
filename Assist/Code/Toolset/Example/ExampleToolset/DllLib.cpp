///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:38)

#include "Toolset/Example/ExampleToolset/ExampleToolsetExport.h"

#include "Toolset/Example/ExampleToolset/ExampleToolset.h"

#ifndef BUILDING_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_EXAMPLE_STATIC

namespace ExampleToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EXAMPLE_STATIC
