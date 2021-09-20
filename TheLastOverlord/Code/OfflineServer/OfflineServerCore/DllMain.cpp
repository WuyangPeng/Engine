// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:03)

#include "OfflineServerCoreExport.h"

#include "OfflineServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OFFLINE_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(OfflineServerCore);

#else // !BUILDING_OFFLINE_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(OfflineServerCore);

#endif // BUILDING_OFFLINE_SERVER_CORE_STATIC
