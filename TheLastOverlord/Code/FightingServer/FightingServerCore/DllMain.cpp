// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:37)

#include "FightingServerCoreExport.h"

#include "FightingServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FIGHTING_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(FightingServerCore);

#else // !BUILDING_FIGHTING_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(FightingServerCore);

#endif // BUILDING_FIGHTING_SERVER_CORE_STATIC
