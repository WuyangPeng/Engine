///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 13:48)

#include "Shop/ShopExport.h"

#include "Shop/Shop.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_SHOP_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SHOP_STATIC

namespace Shop
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SHOP_STATIC
