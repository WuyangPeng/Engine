// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 10:57)

#include "GatewayServerCoreExport.h"

#include "GatewayServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_GATEWAY_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_GATEWAY_SERVER_CORE_STATIC

	namespace GatewayServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_GATEWAY_SERVER_CORE_STATIC
