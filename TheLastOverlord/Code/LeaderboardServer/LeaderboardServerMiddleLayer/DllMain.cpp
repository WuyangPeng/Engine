///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/26 21:18)

#include "LeaderboardServerMiddleLayerExport.h"

#include "LeaderboardServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(LeaderboardServerMiddleLayer);

#else  // !BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(LeaderboardServerMiddleLayer);

#endif  // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC
