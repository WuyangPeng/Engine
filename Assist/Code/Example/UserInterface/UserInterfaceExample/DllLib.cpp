///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:45)

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleExport.h"

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExample.h"

#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_USER_INTERFACE_EXAMPLE_STATIC

namespace UserInterfaceExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC
