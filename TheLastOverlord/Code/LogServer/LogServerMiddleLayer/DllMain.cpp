///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 21:31)

#include "LogServerMiddleLayerExport.h"

#include "LogServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(LogServerMiddleLayer);

#else  // !BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(LogServerMiddleLayer);

#endif  // BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC
