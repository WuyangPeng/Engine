/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#include "LeaderboardServerCoreExport.h"

#include "LeaderboardServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEADERBOARD_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(LeaderboardServerCore);

#else  // !BUILDING_LEADERBOARD_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(LeaderboardServerCore);

#endif  // BUILDING_LEADERBOARD_SERVER_CORE_STATIC