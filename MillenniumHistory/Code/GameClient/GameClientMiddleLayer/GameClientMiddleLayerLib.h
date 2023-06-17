///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/13 21:45)

#ifndef GAME_CLIENT_MIDDLE_LAYER_LIB_H
#define GAME_CLIENT_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "GameClientMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GameClientMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "GameClientMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "GameClientMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GAME_CLIENT_MIDDLE_LAYER_LIB_H