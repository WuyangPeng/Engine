///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 13:29)

#include "TimeRefresh/TimeRefreshExport.h"

#include "TimeRefreshFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TIME_REFRESH_STATIC

DLL_MAIN_FUNCTION(TimeRefresh);

#else  // !BUILDING_TIME_REFRESH_STATIC

CORE_TOOLS_MUTEX_INIT(TimeRefresh);

#endif  // BUILDING_TIME_REFRESH_STATIC
