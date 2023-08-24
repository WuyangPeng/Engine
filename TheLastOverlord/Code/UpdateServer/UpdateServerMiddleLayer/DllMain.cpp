/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#include "UpdateServerMiddleLayerExport.h"

#include "UpdateServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(UpdateServerMiddleLayer);

#else  // !BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(UpdateServerMiddleLayer);

#endif  // BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC