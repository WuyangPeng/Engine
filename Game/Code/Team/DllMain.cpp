// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 22:52)

#include "Team/TeamExport.h"

#include "TeamFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_TEAM_STATIC

	DLL_MAIN_FUNCTION(Team);

#else // !BUILDING_TEAM_STATIC

	CORE_TOOLS_MUTEX_INIT(Team);

#endif // BUILDING_TEAM_STATIC
