// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 18:06)

#include "RechargeServerCoreExport.h"

#include "RechargeServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(RechargeServerCore);

#else // !BUILDING_RECHARGE_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(RechargeServerCore);

#endif // BUILDING_RECHARGE_SERVER_CORE_STATIC
