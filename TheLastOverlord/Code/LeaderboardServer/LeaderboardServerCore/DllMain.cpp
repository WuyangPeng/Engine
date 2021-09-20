// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 15:27)

#include "LeaderboardServerCoreExport.h"

#include "LeaderboardServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEADERBOARD_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(LeaderboardServerCore);

#else // !BUILDING_LEADERBOARD_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(LeaderboardServerCore);

#endif // BUILDING_LEADERBOARD_SERVER_CORE_STATIC
