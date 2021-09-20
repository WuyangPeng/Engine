// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/04 23:43)

#ifndef ITEM_MANAGER_PLACEHOLDER_PLACEHOLDER_H
#define ITEM_MANAGER_PLACEHOLDER_PLACEHOLDER_H

#include "ItemManager/ItemManagerDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace ItemManager
{
	 class ITEM_MANAGER_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // ITEM_MANAGER_PLACEHOLDER_PLACEHOLDER_H
