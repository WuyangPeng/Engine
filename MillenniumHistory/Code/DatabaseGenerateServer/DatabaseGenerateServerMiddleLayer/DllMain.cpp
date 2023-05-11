///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:48)

#include "DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(DatabaseGenerateServerMiddleLayer);

#else  // !BUILDING_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseGenerateServerMiddleLayer);

#endif  // BUILDING_DATABASE_GENERATE_SERVER_MIDDLE_LAYER_STATIC