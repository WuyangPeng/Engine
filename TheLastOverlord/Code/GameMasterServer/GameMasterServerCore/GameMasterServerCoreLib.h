///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 22:17)

#ifndef GAME_MASTER_SERVER_CORE_LIB_H
#define GAME_MASTER_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GAME_MASTER_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "GameMasterServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GameMasterServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_GAME_MASTER_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "GameMasterServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GameMasterServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_GAME_MASTER_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GAME_MASTER_SERVER_CORE_LIB_H
