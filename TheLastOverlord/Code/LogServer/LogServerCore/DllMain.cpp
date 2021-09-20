// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/12 22:55)

#include "LogServerCoreExport.h"

#include "LogServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LOG_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(LogServerCore);

#else // !BUILDING_LOG_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(LogServerCore);

#endif // BUILDING_LOG_SERVER_CORE_STATIC
