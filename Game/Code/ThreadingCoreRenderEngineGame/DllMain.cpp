///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/13 17:04)

#include "ThreadingCoreRenderEngineGame/ThreadingCoreRenderEngineGameExport.h"

#include "ThreadingCoreRenderEngineGameFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngineGame);

#else  // !BUILDING_GAME_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngineGame);

#endif  // !BUILDING_GAME_STATIC