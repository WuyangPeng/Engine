///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:49)

#include "Team/TeamExport.h"

#include "TeamFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TEAM_STATIC

DLL_MAIN_FUNCTION(Team);

#else  // !BUILDING_TEAM_STATIC

CORE_TOOLS_MUTEX_INIT(Team);

#endif  // BUILDING_TEAM_STATIC
