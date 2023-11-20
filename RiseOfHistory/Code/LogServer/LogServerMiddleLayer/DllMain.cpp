/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#include "LogServerMiddleLayerExport.h"

#include "LogServerMiddleLayerFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

DLL_MAIN_FUNCTION(LogServerMiddleLayer);

#else  // !BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

CORE_TOOLS_MUTEX_INIT(LogServerMiddleLayer);

#endif  // BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC