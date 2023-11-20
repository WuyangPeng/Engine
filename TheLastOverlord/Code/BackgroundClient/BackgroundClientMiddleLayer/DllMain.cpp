/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#include "BackgroundClientMiddleLayerExport.h"

#include "BackgroundClientMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(BackgroundClientMiddleLayer);

#else  // !BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(BackgroundClientMiddleLayer);

#endif  // BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC