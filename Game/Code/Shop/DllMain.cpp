// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:00)

#include "Shop/ShopExport.h"

#include "ShopFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SHOP_STATIC

	DLL_MAIN_FUNCTION(Shop);

#else // !BUILDING_SHOP_STATIC

	CORE_TOOLS_MUTEX_INIT(Shop);

#endif // BUILDING_SHOP_STATIC
