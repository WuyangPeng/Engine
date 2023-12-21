/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:10)

#include "CorssServerMiddleLayerExport.h"

#include "CorssServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(CorssServerMiddleLayer);

#else  // !BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(CorssServerMiddleLayer);

#endif  // BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC