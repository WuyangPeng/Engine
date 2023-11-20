/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#include "RobotClientCoreExport.h"

#include "RobotClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ROBOT_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(RobotClientCore);

#else  // !BUILDING_ROBOT_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(RobotClientCore);

#endif  // BUILDING_ROBOT_CLIENT_CORE_STATIC