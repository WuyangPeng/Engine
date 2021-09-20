// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.0 (2019/10/09 23:37)

#include "RobotClientCoreExport.h"

#include "RobotClientCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ROBOT_CLIENT_CORE_STATIC

	DLL_MAIN_FUNCTION(RobotClientCore);

#else // !BUILDING_ROBOT_CLIENT_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(RobotClientCore);

#endif // BUILDING_ROBOT_CLIENT_CORE_STATIC
