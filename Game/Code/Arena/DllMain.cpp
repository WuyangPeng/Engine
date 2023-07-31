///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:21)

#include "Arena/ArenaExport.h"

#include "ArenaFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARENA_STATIC

DLL_MAIN_FUNCTION(Arena);

#else  // !BUILDING_ARENA_STATIC

CORE_TOOLS_MUTEX_INIT(Arena);

#endif  // BUILDING_ARENA_STATIC
