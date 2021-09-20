// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:52)

#include "GameMasterServerMiddleLayerExport.h"

#include "GameMasterServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(GameMasterServerMiddleLayer);

#else // !BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(GameMasterServerMiddleLayer);

#endif // BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC
