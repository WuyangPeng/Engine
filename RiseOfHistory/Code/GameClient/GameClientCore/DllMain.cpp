///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 11:03)

#include "GameClientCoreExport.h"

#include "GameClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GAME_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(GameClientCore);

#else  // !BUILDING_GAME_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(GameClientCore);

#endif  // BUILDING_GAME_CLIENT_CORE_STATIC