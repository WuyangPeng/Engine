/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:42)

#include "RobotClientCoreExport.h"

#include "RobotClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ROBOT_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(RobotClientCore);

#else  // !BUILDING_ROBOT_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(RobotClientCore);

#endif  // BUILDING_ROBOT_CLIENT_CORE_STATIC