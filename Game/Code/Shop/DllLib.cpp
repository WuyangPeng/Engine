///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:19)

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
