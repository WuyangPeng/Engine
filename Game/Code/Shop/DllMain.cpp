// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:00)

#include "Shop/ShopExport.h"

#include "ShopFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SHOP_STATIC

	DLL_MAIN_FUNCTION(Shop);

#else // !BUILDING_SHOP_STATIC

	CORE_TOOLS_MUTEX_INIT(Shop);

#endif // BUILDING_SHOP_STATIC
