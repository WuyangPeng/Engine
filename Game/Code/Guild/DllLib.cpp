///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:36)

#include "Guild/GuildExport.h"

#include "Guild/Guild.h"

#ifndef BUILDING_GUILD_STATIC

    #include "DllLib.h"

#else  // !BUILDING_GUILD_STATIC

namespace Guild
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_GUILD_STATIC
