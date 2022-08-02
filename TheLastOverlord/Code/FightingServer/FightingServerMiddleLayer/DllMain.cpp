///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/25 15:55)

#include "FightingServerMiddleLayerExport.h"

#include "FightingServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(FightingServerMiddleLayer);

#else  // !BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(FightingServerMiddleLayer);

#endif  // BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC
