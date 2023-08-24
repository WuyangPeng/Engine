/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_LIB_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "GameMasterServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GameMasterServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "GameMasterServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GameMasterServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GAME_MASTER_SERVER_MIDDLE_LAYER_LIB_H