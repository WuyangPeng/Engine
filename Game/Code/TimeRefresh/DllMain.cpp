///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 14:36)

#include "TimeRefresh/TimeRefreshExport.h"

#include "TimeRefreshFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ACTIVITY_STATIC

DLL_MAIN_FUNCTION(TimeRefresh);

#else  // !BUILDING_ACTIVITY_STATIC

CORE_TOOLS_MUTEX_INIT(TimeRefresh);

#endif  // BUILDING_ACTIVITY_STATIC
