// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 18:02)

#include "BackgroundClientMiddleLayerExport.h"

#include "BackgroundClientMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(BackgroundClientMiddleLayer);

#else // !BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(BackgroundClientMiddleLayer);

#endif // BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC
