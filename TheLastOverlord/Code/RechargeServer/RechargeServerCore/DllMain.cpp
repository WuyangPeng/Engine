// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 18:06)

#include "RechargeServerCoreExport.h"

#include "RechargeServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(RechargeServerCore);

#else // !BUILDING_RECHARGE_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(RechargeServerCore);

#endif // BUILDING_RECHARGE_SERVER_CORE_STATIC
