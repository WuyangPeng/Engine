/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "LeaderboardServerMiddleLayerExport.h"

#include "LeaderboardServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(LeaderboardServerMiddleLayer);

#else  // !BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(LeaderboardServerMiddleLayer);

#endif  // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC