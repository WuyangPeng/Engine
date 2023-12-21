/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:10)

#include "CorssServerMiddleLayerExport.h"

#include "CorssServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(CorssServerMiddleLayer);

#else  // !BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(CorssServerMiddleLayer);

#endif  // BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC