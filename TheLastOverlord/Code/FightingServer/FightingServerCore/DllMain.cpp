// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 09:37)

#include "FightingServerCoreExport.h"

#include "FightingServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FIGHTING_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(FightingServerCore);

#else // !BUILDING_FIGHTING_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(FightingServerCore);

#endif // BUILDING_FIGHTING_SERVER_CORE_STATIC
