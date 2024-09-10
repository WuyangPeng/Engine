/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/06/20 15:15)

#include "ServerManagerMiddleLayerExport.h"

#include "ServerManagerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(ServerManagerMiddleLayer);

#else  // !BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(ServerManagerMiddleLayer);

#endif  // BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC