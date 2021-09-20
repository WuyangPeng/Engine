// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:00)

#include "Shop/ShopExport.h"

#include "Shop/Shop.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_SHOP_STATIC

	#include "DllLib.h"

#else // !BUILDING_SHOP_STATIC

	namespace Shop
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SHOP_STATIC
	
