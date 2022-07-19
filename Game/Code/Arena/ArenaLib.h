///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/19 11:21)

#ifndef ARENA_LIB_H
#define ARENA_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ARENA_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ArenaD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Arena.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ARENA_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ArenaStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ArenaStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ARENA_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ARENA_LIB_H
