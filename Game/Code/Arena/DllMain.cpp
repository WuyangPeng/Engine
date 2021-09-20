// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/06 20:42)

#include "Arena/ArenaExport.h"

#include "ArenaFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_ARENA_STATIC

	DLL_MAIN_FUNCTION(Arena);

#else // !BUILDING_ARENA_STATIC

	CORE_TOOLS_MUTEX_INIT(Arena);

#endif // BUILDING_ARENA_STATIC
