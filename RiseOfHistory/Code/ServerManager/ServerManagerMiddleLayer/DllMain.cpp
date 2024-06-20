/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/20 15:15)

#include "ServerManagerMiddleLayerExport.h"

#include "ServerManagerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(ServerManagerMiddleLayer);

#else  // !BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(ServerManagerMiddleLayer);

#endif  // BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC