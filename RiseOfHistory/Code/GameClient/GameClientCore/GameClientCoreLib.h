///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/18 17:45)

#ifndef GAME_CLIENT_CORE_LIB_H
#define GAME_CLIENT_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GAME_CLIENT_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "GameClientCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GameClientCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_GAME_CLIENT_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "GameClientCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GameClientCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_GAME_CLIENT_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GAME_CLIENT_CORE_LIB_H