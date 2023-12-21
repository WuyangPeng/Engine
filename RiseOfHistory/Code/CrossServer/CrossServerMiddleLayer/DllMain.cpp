/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#include "CrossServerMiddleLayerExport.h"

#include "CrossServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CROSS_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(CrossServerMiddleLayer);

#else  // !BUILDING_CROSS_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(CrossServerMiddleLayer);

#endif  // BUILDING_CROSS_SERVER_MIDDLE_LAYER_STATIC