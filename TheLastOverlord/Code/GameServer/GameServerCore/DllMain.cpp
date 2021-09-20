// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 16:59)

#include "GameServerCoreExport.h"

#include "GameServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(GameServerCore);

#else // !BUILDING_GAME_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(GameServerCore);

#endif // BUILDING_GAME_SERVER_CORE_STATIC
