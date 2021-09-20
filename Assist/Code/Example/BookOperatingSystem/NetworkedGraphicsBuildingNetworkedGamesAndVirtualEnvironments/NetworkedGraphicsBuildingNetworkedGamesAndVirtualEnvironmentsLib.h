///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.0 (2021/07/18 18:43)

#ifndef NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_LIB_H
#define NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "NetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironments.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "NetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // NETWORKED_GRAPHICS_BUILDING_NETWORKED_GAMES_AND_VIRTUAL_ENVIRONMENTS_LIB_H
