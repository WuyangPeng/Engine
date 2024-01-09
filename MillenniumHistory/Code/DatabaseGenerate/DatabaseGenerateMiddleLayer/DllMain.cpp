/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:48)

#include "DatabaseGenerateMiddleLayerExport.h"

#include "DatabaseGenerateMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(DatabaseGenerateMiddleLayer);

#else  // !BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseGenerateMiddleLayer);

#endif  // BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC