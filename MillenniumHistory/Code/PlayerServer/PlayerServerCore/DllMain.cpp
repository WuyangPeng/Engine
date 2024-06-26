/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/17 20:09)

#include "PlayerServerCoreExport.h"

#include "PlayerServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PLAYER_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(PlayerServerCore);

#else  // !BUILDING_PLAYER_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(PlayerServerCore);

#endif  // BUILDING_PLAYER_SERVER_CORE_STATIC