// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/04 23:43)

#include "ItemManager/ItemManagerExport.h"

#include "ItemManagerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_ITEM_MANAGER_STATIC

	DLL_MAIN_FUNCTION(ItemManager);

#else // !BUILDING_ITEM_MANAGER_STATIC

	CORE_TOOLS_MUTEX_INIT(ItemManager);

#endif // BUILDING_ITEM_MANAGER_STATIC
