// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 16:39)

#include "ServerManagerCoreExport.h"

#include "ServerManagerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

	DLL_MAIN_FUNCTION(ServerManagerCore);

#else // !BUILDING_SERVER_MANAGER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(ServerManagerCore);

#endif // BUILDING_SERVER_MANAGER_CORE_STATIC
