// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:00)

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
	
