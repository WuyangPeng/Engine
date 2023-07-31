///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:36)

#ifndef GUILD_LIB_H
#define GUILD_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GUILD_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "GuildD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Guild.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_GUILD_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "GuildStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GuildStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_GUILD_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GUILD_LIB_H
