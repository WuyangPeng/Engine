// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 18:26)

#include "RechargeServerMiddleLayerExport.h"

#include "RechargeServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(RechargeServerMiddleLayer);

#else // !BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(RechargeServerMiddleLayer);

#endif // BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC
