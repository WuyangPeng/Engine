// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 11:49)

#include "GatewayServerMiddleLayerExport.h"

#include "GatewayServerMiddleLayer.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

	#include "DllLib.h"

#else // !BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

	namespace GatewayServerMiddleLayer
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC
