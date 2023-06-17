///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:55)

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
