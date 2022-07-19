///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 14:32)

#include "Status/StatusExport.h"

#include "StatusFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATUSSTATIC

DLL_MAIN_FUNCTION(Status);

#else  // !BUILDING_STATUSSTATIC

CORE_TOOLS_MUTEX_INIT(Status);

#endif  // BUILDING_STATUSSTATIC
