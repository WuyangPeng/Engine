// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:06)

#include "BackgroundServerCoreExport.h"

#include "BackgroundServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(BackgroundServerCore);

#else // !BUILDING_BACKGROUND_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(BackgroundServerCore);

#endif // BUILDING_BACKGROUND_SERVER_CORE_STATIC
