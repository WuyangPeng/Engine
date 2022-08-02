///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 15:55)

#include "FightingServerMiddleLayerExport.h"

#include "FightingServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(FightingServerMiddleLayer);

#else  // !BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(FightingServerMiddleLayer);

#endif  // BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC
