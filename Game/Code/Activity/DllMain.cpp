///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/19 14:33)

#include "Activity/ActivityExport.h"

#include "ActivityFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ACTIVITY_STATIC

DLL_MAIN_FUNCTION(Activity);

#else  // !BUILDING_ACTIVITY_STATIC

CORE_TOOLS_MUTEX_INIT(Activity);

#endif  // BUILDING_ACTIVITY_STATIC
