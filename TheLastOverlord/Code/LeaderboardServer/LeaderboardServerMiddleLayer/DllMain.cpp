// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:34)

#include "LeaderboardServerMiddleLayerExport.h"

#include "LeaderboardServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(LeaderboardServerMiddleLayer);

#else // !BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(LeaderboardServerMiddleLayer);

#endif // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC
