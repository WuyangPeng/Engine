// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:45)

#include "GameMasterServerCoreExport.h"

#include "GameMasterServerCoreFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_MASTER_SERVER_CORE_STATIC

	DLL_MAIN_FUNCTION(GameMasterServerCore);

#else // !BUILDING_GAME_MASTER_SERVER_CORE_STATIC

	CORE_TOOLS_MUTEX_INIT(GameMasterServerCore);

#endif // BUILDING_GAME_MASTER_SERVER_CORE_STATIC
