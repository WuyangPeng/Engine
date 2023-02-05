///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/03 11:13)

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