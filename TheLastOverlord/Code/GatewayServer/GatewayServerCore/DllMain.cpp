// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 10:57)

#include "GatewayServerCoreExport.h"

#include "GatewayServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GATEWAY_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(GatewayServerCore);

#else // !BUILDING_GATEWAY_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(GatewayServerCore);

#endif // BUILDING_GATEWAY_SERVER_CORE_STATIC
