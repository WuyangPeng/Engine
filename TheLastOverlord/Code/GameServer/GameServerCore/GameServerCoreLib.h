///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 21:55)

#ifndef GAME_SERVER_CORE_LIB_H
#define GAME_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GAME_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "GameServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GameServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_GAME_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "GameServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GameServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_GAME_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GAME_SERVER_CORE_LIB_H
