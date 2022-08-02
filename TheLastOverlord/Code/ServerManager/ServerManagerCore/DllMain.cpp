///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 23:06)

#include "ServerManagerCoreExport.h"

#include "ServerManagerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

DLL_MAIN_FUNCTION(ServerManagerCore);

#else  // !BUILDING_SERVER_MANAGER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(ServerManagerCore);

#endif  // BUILDING_SERVER_MANAGER_CORE_STATIC
