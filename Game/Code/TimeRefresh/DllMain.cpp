///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 14:36)

#include "TimeRefresh/TimeRefreshExport.h"

#include "TimeRefreshFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ACTIVITY_STATIC

DLL_MAIN_FUNCTION(TimeRefresh);

#else  // !BUILDING_ACTIVITY_STATIC

CORE_TOOLS_MUTEX_INIT(TimeRefresh);

#endif  // BUILDING_ACTIVITY_STATIC
