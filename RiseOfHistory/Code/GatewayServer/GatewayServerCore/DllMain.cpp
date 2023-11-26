/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#include "GatewayServerCoreExport.h"

#include "GatewayServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GATEWAY_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(GatewayServerCore);

#else  // !BUILDING_GATEWAY_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(GatewayServerCore);

#endif  // BUILDING_GATEWAY_SERVER_CORE_STATIC