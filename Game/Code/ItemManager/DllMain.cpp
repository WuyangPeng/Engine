///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:58)

#include "ItemManager/ItemManagerExport.h"

#include "ItemManagerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ITEM_MANAGER_STATIC

DLL_MAIN_FUNCTION(ItemManager);

#else  // !BUILDING_ITEM_MANAGER_STATIC

CORE_TOOLS_MUTEX_INIT(ItemManager);

#endif  // BUILDING_ITEM_MANAGER_STATIC
