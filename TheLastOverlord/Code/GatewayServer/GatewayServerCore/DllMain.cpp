// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 10:57)

#include "GatewayServerCoreExport.h"

#include "GatewayServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GATEWAY_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(GatewayServerCore);

#else // !BUILDING_GATEWAY_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(GatewayServerCore);

#endif // BUILDING_GATEWAY_SERVER_CORE_STATIC
