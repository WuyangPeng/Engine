/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef WORLD_SERVER_MIDDLE_LAYER_LIB_H
#define WORLD_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "WorldServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "WorldServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "WorldServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "WorldServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // WORLD_SERVER_MIDDLE_LAYER_LIB_H