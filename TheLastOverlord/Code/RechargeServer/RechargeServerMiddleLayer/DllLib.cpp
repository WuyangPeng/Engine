// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 18:26)

#include "RechargeServerMiddleLayerExport.h"

#include "RechargeServerMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

	namespace RechargeServerMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC
