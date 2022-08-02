///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 21:13)

#include "LeaderboardServerCoreExport.h"

#include "LeaderboardServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEADERBOARD_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(LeaderboardServerCore);

#else  // !BUILDING_LEADERBOARD_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(LeaderboardServerCore);

#endif  // BUILDING_LEADERBOARD_SERVER_CORE_STATIC
