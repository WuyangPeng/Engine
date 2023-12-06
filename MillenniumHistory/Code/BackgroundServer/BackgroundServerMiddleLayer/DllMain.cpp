/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "BackgroundServerMiddleLayerExport.h"

#include "BackgroundServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(BackgroundServerMiddleLayer);

#else  // !BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(BackgroundServerMiddleLayer);

#endif  // BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC