///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/23 13:26)

#include "GatewayServerCoreExport.h"

#include "GatewayServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GATEWAY_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(GatewayServerCore);

#else  // !BUILDING_GATEWAY_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(GatewayServerCore);

#endif  // BUILDING_GATEWAY_SERVER_CORE_STATIC
