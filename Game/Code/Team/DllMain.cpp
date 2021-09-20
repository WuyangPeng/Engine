// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 22:52)

#include "Team/TeamExport.h"

#include "TeamFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_TEAM_STATIC

	DLL_MAIN_FUNCTION(Team);

#else // !BUILDING_TEAM_STATIC

	CORE_TOOLS_MUTEX_INIT(Team);

#endif // BUILDING_TEAM_STATIC
