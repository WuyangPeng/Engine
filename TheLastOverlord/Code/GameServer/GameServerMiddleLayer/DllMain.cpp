// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 17:44)

#include "GameServerMiddleLayerExport.h"

#include "GameServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(GameServerMiddleLayer);

#else // !BUILDING_GAME_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(GameServerMiddleLayer);

#endif // BUILDING_GAME_SERVER_MIDDLE_LAYER_STATIC
