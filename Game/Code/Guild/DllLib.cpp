// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 23:13)

#include "Guild/GuildExport.h"

#include "Guild/Guild.h"

#include "CoreTools/CoreToolsLib.h"

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
