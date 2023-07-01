///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:19)

#include "GameClientMiddleLayerExport.h"

#include "GameClientMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(GameClientMiddleLayer);

#else  // !BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(GameClientMiddleLayer);

#endif  // BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC