// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 17:48)

#include "BackgroundClientCoreExport.h"

#include "BackgroundClientCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

	DLL_MAIN_FUNCTION(BackgroundClientCore);

#else // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(BackgroundClientCore);

#endif // BUILDING_BACKGROUND_CLIENT_CORE_STATIC
