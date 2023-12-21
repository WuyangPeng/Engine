/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#include "PlayerServerCoreExport.h"

#include "PlayerServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PLAYER_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(PlayerServerCore);

#else  // !BUILDING_PLAYER_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(PlayerServerCore);

#endif  // BUILDING_PLAYER_SERVER_CORE_STATIC