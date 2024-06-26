/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#include "GameServerCoreExport.h"

#include "GameServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(GameServerCore);

#else  // !BUILDING_GAME_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(GameServerCore);

#endif  // BUILDING_GAME_SERVER_CORE_STATIC