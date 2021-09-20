// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 23:13)

#include "Guild/GuildExport.h"

#include "GuildFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_GUILD_STATIC

	DLL_MAIN_FUNCTION(Guild);

#else // !BUILDING_GUILD_STATIC

	CORE_TOOLS_MUTEX_INIT(Guild);

#endif // BUILDING_GUILD_STATIC
