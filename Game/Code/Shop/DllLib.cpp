///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 13:48)

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
