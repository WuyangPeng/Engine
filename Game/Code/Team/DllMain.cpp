///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 17:09)

#include "Team/TeamExport.h"

#include "TeamFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TEAM_STATIC

DLL_MAIN_FUNCTION(Team);

#else  // !BUILDING_TEAM_STATIC

CORE_TOOLS_MUTEX_INIT(Team);

#endif  // BUILDING_TEAM_STATIC
