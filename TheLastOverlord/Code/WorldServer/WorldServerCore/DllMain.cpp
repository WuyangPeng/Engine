///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2023/06/17 15:25)

#include "WorldServerCoreExport.h"

#include "WorldServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_WORLD_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(WorldServerCore);

#else  // !BUILDING_WORLD_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(WorldServerCore);

#endif  // BUILDING_WORLD_SERVER_CORE_STATIC
