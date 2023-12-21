/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#include "RechargeServerMiddleLayerExport.h"

#include "RechargeServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(RechargeServerMiddleLayer);

#else  // !BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(RechargeServerMiddleLayer);

#endif  // BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC