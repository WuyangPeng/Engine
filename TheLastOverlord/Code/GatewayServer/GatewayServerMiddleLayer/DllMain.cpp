// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:49)

#include "GatewayServerMiddleLayerExport.h"

#include "GatewayServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(GatewayServerMiddleLayer);

#else // !BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(GatewayServerMiddleLayer);

#endif // BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC
