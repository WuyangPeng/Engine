/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 22:48)

#include "DatabaseGenerateMiddleLayerExport.h"

#include "DatabaseGenerateMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(DatabaseGenerateMiddleLayer);

#else  // !BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseGenerateMiddleLayer);

#endif  // BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC