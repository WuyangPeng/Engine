/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/06/20 15:12)

#include "ServerManagerCoreExport.h"

#include "ServerManagerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

DLL_MAIN_FUNCTION(ServerManagerCore);

#else  // !BUILDING_SERVER_MANAGER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(ServerManagerCore);

#endif  // BUILDING_SERVER_MANAGER_CORE_STATIC