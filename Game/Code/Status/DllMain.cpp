///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 15:58)

#include "Status/StatusExport.h"

#include "StatusFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATUS_STATIC

DLL_MAIN_FUNCTION(Status);

#else  // !BUILDING_STATUS_STATIC

CORE_TOOLS_MUTEX_INIT(Status);

#endif  // BUILDING_STATUS_STATIC
