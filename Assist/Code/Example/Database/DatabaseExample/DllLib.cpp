///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 13:49)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "Example/Database/DatabaseExample/DatabaseExample.h"

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATABASE_EXAMPLE_STATIC

namespace DatabaseExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATABASE_EXAMPLE_STATIC
