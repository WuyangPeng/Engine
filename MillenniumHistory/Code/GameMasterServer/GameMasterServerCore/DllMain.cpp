/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#include "GameMasterServerCoreExport.h"

#include "GameMasterServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_MASTER_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(GameMasterServerCore);

#else  // !BUILDING_GAME_MASTER_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(GameMasterServerCore);

#endif  // BUILDING_GAME_MASTER_SERVER_CORE_STATIC