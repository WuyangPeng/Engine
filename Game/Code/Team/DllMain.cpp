///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 15:39)

#include "Team/TeamExport.h"

#include "TeamFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TEAM_STATIC

DLL_MAIN_FUNCTION(Team);

#else  // !BUILDING_TEAM_STATIC

CORE_TOOLS_MUTEX_INIT(Team);

#endif  // BUILDING_TEAM_STATIC
