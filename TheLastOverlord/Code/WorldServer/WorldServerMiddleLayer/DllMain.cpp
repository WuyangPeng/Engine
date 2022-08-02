///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 18:26)

#include "WorldServerMiddleLayerExport.h"

#include "WorldServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(WorldServerMiddleLayer);

#else  // !BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(WorldServerMiddleLayer);

#endif  // BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC
