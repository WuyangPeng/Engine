// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/09 19:18)

#include "Network/NetworkExport.h"

#include "Network/NetworkFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_NETWORK_STATIC

	DLL_MAIN_FUNCTION(Network);

#else // !BUILDING_NETWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(Network);

#endif // !BUILDING_NETWORK_STATIC