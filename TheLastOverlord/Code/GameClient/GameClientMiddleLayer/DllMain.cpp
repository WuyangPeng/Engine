// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:37)

#include "GameClientMiddleLayerExport.h"

#include "GameClientMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(GameClientMiddleLayer);

#else // !BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(GameClientMiddleLayer);

#endif // BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC