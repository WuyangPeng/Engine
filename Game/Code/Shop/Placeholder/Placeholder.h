// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 21:01)

#ifndef SHOP_PLACEHOLDER_PLACEHOLDER_H
#define SHOP_PLACEHOLDER_PLACEHOLDER_H

#include "Shop/ShopDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace Shop
{
	 class SHOP_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // SHOP_PLACEHOLDER_PLACEHOLDER_H
