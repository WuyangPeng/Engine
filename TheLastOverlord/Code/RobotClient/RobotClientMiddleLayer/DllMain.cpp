// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 14:43)

#include "RobotClientMiddleLayerExport.h"

#include "RobotClientMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(RobotClientMiddleLayer);

#else // !BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(RobotClientMiddleLayer);

#endif // BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC
