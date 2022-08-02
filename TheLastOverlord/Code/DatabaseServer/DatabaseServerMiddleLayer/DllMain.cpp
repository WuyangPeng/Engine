///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 20:57)

#include "DatabaseServerMiddleLayerExport.h"

#include "DatabaseServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(DatabaseServerMiddleLayer);

#else  // !BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseServerMiddleLayer);

#endif  // BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC