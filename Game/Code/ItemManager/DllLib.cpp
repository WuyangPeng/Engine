///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 11:04)

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
