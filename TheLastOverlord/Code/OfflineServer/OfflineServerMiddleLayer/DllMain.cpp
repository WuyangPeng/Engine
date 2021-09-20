// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:09)

#include "OfflineServerMiddleLayerExport.h"

#include "OfflineServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(OfflineServerMiddleLayer);

#else // !BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(OfflineServerMiddleLayer);

#endif // BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC
