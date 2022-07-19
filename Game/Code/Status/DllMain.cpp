///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 14:32)

#include "Status/StatusExport.h"

#include "StatusFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATUSSTATIC

DLL_MAIN_FUNCTION(Status);

#else  // !BUILDING_STATUSSTATIC

CORE_TOOLS_MUTEX_INIT(Status);

#endif  // BUILDING_STATUSSTATIC
