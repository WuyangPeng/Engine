// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.0 (2019/10/09 23:37)

#include "RobotClientCoreExport.h"

#include "RobotClientCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_ROBOT_CLIENT_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_ROBOT_CLIENT_CORE_STATIC

	namespace RobotClientCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ROBOT_CLIENT_CORE_STATIC
