// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:56)

#include "UpdateServerCoreExport.h"

#include "UpdateServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_UPDATE_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(UpdateServerCore);

#else // !BUILDING_UPDATE_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(UpdateServerCore);

#endif // BUILDING_UPDATE_SERVER_CORE_STATIC
