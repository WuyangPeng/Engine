// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 14:43)

#include "RobotClientMiddleLayerExport.h"

#include "RobotClientMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

	namespace RobotClientMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC
