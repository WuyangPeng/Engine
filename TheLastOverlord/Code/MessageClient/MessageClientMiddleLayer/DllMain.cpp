// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:55)

#include "MessageClientMiddleLayerExport.h"

#include "MessageClientMiddleLayerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

	DLL_MAIN_FUNCTION(MessageClientMiddleLayer);

#else // !BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

	CORE_TOOLS_MUTEX_INIT(MessageClientMiddleLayer);

#endif // BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC
