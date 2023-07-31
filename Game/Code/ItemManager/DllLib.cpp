///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:58)

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
