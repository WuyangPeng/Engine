// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/04 23:43)

#include "ItemManager/ItemManagerExport.h"

#include "ItemManager/ItemManager.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_ITEM_MANAGER_STATIC

	#include "DllLib.h"

#else // !BUILDING_ITEM_MANAGER_STATIC

	namespace ItemManager
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ITEM_MANAGER_STATIC
	
