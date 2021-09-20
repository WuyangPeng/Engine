///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.0 (2021/07/18 18:43)

#ifndef MULTIPLAYER_GAME_PROGRAMMING_LIB_H
#define MULTIPLAYER_GAME_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MultiplayerGameProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MultiplayerGameProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MultiplayerGameProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MultiplayerGameProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MULTIPLAYER_GAME_PROGRAMMING_LIB_H
