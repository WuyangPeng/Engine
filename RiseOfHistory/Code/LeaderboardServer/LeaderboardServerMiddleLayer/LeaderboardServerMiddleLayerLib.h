/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_LIB_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "LeaderboardServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LeaderboardServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "LeaderboardServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LeaderboardServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LEADERBOARD_SERVER_MIDDLE_LAYER_LIB_H