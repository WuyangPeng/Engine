/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#include "GameClientMiddleLayerExport.h"

#include "GameClientMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(GameClientMiddleLayer);

#else  // !BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(GameClientMiddleLayer);

#endif  // BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC