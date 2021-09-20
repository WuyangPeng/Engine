// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:13)

#include "BackgroundServerMiddleLayerExport.h"

#include "BackgroundServerMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(BackgroundServerMiddleLayer);

#else // !BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(BackgroundServerMiddleLayer);

#endif // BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC
