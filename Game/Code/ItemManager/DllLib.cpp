///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/16 16:45)

#include "ItemManager/ItemManagerExport.h"

#include "ItemManager/ItemManager.h"

#ifndef BUILDING_ITEM_MANAGER_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ITEM_MANAGER_STATIC

namespace ItemManager
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ITEM_MANAGER_STATIC
