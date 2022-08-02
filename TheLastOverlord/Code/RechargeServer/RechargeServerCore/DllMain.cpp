///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 22:08)

#include "RechargeServerCoreExport.h"

#include "RechargeServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(RechargeServerCore);

#else  // !BUILDING_RECHARGE_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(RechargeServerCore);

#endif  // BUILDING_RECHARGE_SERVER_CORE_STATIC
