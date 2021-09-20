// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/08 23:50)

#include "GameClientCoreExport.h"

#include "GameClientCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_CLIENT_CORE_STATIC

	DLL_MAIN_FUNCTION(GameClientCore);

#else // !BUILDING_GAME_CLIENT_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(GameClientCore);

#endif // BUILDING_GAME_CLIENT_CORE_STATIC