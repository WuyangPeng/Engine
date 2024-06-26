///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:14)

#include "ThreadingCoreRenderEngineGame/ThreadingCoreRenderEngineGameExport.h"

#include "ThreadingCoreRenderEngineGameFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngineGame);

#else  // !BUILDING_GAME_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngineGame);

#endif  // !BUILDING_GAME_STATIC