///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/18 18:43)

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
