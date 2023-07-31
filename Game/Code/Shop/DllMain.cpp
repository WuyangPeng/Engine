///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:18)

#include "Shop/ShopExport.h"

#include "ShopFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SHOP_STATIC

DLL_MAIN_FUNCTION(Shop);

#else  // !BUILDING_SHOP_STATIC

CORE_TOOLS_MUTEX_INIT(Shop);

#endif  // BUILDING_SHOP_STATIC
