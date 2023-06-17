///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:55)

#include "Guild/GuildExport.h"

#include "GuildFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GUILD_STATIC

DLL_MAIN_FUNCTION(Guild);

#else  // !BUILDING_GUILD_STATIC

CORE_TOOLS_MUTEX_INIT(Guild);

#endif  // BUILDING_GUILD_STATIC
