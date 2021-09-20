// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:52)

#include "GameMasterServerMiddleLayerExport.h"

#include "GameMasterServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(GameMasterServerMiddleLayer);

#else // !BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(GameMasterServerMiddleLayer);

#endif // BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC
