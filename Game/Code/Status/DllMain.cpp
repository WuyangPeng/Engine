// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:45)

#include "Status/StatusExport.h"

#include "StatusFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_STATUSSTATIC

	DLL_MAIN_FUNCTION(Status);

#else // !BUILDING_STATUSSTATIC

	CORE_TOOLS_MUTEX_INIT(Status);

#endif // BUILDING_STATUSSTATIC
