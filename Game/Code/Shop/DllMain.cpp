///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 13:47)

#include "Shop/ShopExport.h"

#include "ShopFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SHOP_STATIC

DLL_MAIN_FUNCTION(Shop);

#else  // !BUILDING_SHOP_STATIC

CORE_TOOLS_MUTEX_INIT(Shop);

#endif  // BUILDING_SHOP_STATIC
