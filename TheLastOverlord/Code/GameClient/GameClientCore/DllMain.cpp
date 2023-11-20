/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#include "GameClientCoreExport.h"

#include "GameClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(GameClientCore);

#else  // !BUILDING_GAME_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(GameClientCore);

#endif  // BUILDING_GAME_CLIENT_CORE_STATIC