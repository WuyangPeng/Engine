///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:54)

#include "TimeRefresh/TimeRefreshExport.h"

#include "TimeRefreshFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TIME_REFRESH_STATIC

DLL_MAIN_FUNCTION(TimeRefresh);

#else  // !BUILDING_TIME_REFRESH_STATIC

CORE_TOOLS_MUTEX_INIT(TimeRefresh);

#endif  // BUILDING_TIME_REFRESH_STATIC
