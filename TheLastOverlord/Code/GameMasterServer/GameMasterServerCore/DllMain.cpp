// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:45)

#include "GameMasterServerCoreExport.h"

#include "GameMasterServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_MASTER_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(GameMasterServerCore);

#else // !BUILDING_GAME_MASTER_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(GameMasterServerCore);

#endif // BUILDING_GAME_MASTER_SERVER_CORE_STATIC
