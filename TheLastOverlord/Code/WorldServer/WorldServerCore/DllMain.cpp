// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:07)

#include "WorldServerCoreExport.h"

#include "WorldServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_WORLD_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(WorldServerCore);

#else // !BUILDING_WORLD_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(WorldServerCore);

#endif // BUILDING_WORLD_SERVER_CORE_STATIC
