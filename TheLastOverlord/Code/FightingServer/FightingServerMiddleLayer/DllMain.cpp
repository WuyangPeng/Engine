// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:53)

#include "FightingServerMiddleLayerExport.h"

#include "FightingServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(FightingServerMiddleLayer);

#else // !BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(FightingServerMiddleLayer);

#endif // BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC
