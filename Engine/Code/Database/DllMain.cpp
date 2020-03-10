// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 09:31)

#include "Database/DatabaseExport.h"

#include "Database/DatabaseFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_STATIC

	DLL_MAIN_FUNCTION(Database);

#else // !BUILDING_DATABASE_STATIC

	CORE_TOOLS_MUTEX_INIT(Database);

#endif // !BUILDING_DATABASE_STATIC