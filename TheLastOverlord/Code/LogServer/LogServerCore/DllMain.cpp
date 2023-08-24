/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:43)

#include "LogServerCoreExport.h"

#include "LogServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LOG_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(LogServerCore);

#else  // !BUILDING_LOG_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(LogServerCore);

#endif  // BUILDING_LOG_SERVER_CORE_STATIC