///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������Ϸ�汾��0.7.0.1 (2021/02/15 20:57)

#include "ThreadingCoreRenderEngineGame/ThreadingCoreRenderEngineGameExport.h"

#include "ThreadingCoreRenderEngineGameFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngineGame);

#else  // !BUILDING_GAME_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngineGame);

#endif  // !BUILDING_GAME_STATIC