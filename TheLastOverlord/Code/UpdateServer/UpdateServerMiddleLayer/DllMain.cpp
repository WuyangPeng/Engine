// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 19:03)

#include "UpdateServerMiddleLayerExport.h"

#include "UpdateServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(UpdateServerMiddleLayer);

#else // !BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(UpdateServerMiddleLayer);

#endif // BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC
