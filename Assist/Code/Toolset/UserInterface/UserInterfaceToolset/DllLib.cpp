///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 19:55)

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolsetExport.h"

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolset.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

    #include "DllLib.h"

#else  // BUILDING_USER_INTERFACE_STATIC

namespace UserInterfaceToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_USER_INTERFACE_STATIC
