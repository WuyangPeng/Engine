///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:55)

#include "Guild/GuildExport.h"

#include "GuildFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GUILD_STATIC

DLL_MAIN_FUNCTION(Guild);

#else  // !BUILDING_GUILD_STATIC

CORE_TOOLS_MUTEX_INIT(Guild);

#endif  // BUILDING_GUILD_STATIC
