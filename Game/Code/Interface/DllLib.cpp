///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:53)

#include "Interface/InterfaceExport.h"

#include "Interface/Interface.h"

#ifndef BUILDING_INTERFACE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_INTERFACE_STATIC

namespace Interface
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INTERFACE_STATIC
