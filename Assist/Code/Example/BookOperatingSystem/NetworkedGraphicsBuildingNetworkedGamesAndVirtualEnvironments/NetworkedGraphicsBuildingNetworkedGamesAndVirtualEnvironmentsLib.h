///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/18 18:43)

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
