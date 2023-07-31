///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:21)

#include "Arena/ArenaExport.h"

#include "ArenaFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARENA_STATIC

DLL_MAIN_FUNCTION(Arena);

#else  // !BUILDING_ARENA_STATIC

CORE_TOOLS_MUTEX_INIT(Arena);

#endif  // BUILDING_ARENA_STATIC
