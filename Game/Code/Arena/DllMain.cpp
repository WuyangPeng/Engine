///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/19 11:20)

#include "Arena/ArenaExport.h"

#include "ArenaFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARENA_STATIC

DLL_MAIN_FUNCTION(Arena);

#else  // !BUILDING_ARENA_STATIC

CORE_TOOLS_MUTEX_INIT(Arena);

#endif  // BUILDING_ARENA_STATIC
