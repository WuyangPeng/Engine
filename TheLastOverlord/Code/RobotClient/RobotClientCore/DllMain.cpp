// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.0 (2019/10/09 23:37)

#include "RobotClientCoreExport.h"

#include "RobotClientCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ROBOT_CLIENT_CORE_STATIC

	DLL_MAIN_FUNCTION(RobotClientCore);

#else // !BUILDING_ROBOT_CLIENT_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(RobotClientCore);

#endif // BUILDING_ROBOT_CLIENT_CORE_STATIC
