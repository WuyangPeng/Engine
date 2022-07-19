///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 18:44)
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
