/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "RechargeServerCoreExport.h"

#include "RechargeServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(RechargeServerCore);

#else  // !BUILDING_RECHARGE_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(RechargeServerCore);

#endif  // BUILDING_RECHARGE_SERVER_CORE_STATIC