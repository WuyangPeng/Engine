// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 21:35)

#include "Activity/ActivityExport.h"

#include "ActivityFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_ACTIVITY_STATIC

	DLL_MAIN_FUNCTION(Activity);

#else // !BUILDING_ACTIVITY_STATIC

	CORE_TOOLS_MUTEX_INIT(Activity);

#endif // BUILDING_ACTIVITY_STATIC
