// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 18:06)

#include "RechargeServerCoreExport.h"

#include "RechargeServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_RECHARGE_SERVER_CORE_STATIC

	namespace RechargeServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_RECHARGE_SERVER_CORE_STATIC
