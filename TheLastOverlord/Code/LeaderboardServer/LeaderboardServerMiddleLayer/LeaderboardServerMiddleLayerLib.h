///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 21:19)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_LIB_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

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
