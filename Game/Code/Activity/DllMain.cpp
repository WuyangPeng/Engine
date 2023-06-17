///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 17:11)

#include "Activity/ActivityExport.h"

#include "ActivityFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ACTIVITY_STATIC

DLL_MAIN_FUNCTION(Activity);

#else  // !BUILDING_ACTIVITY_STATIC

CORE_TOOLS_MUTEX_INIT(Activity);

#endif  // BUILDING_ACTIVITY_STATIC
