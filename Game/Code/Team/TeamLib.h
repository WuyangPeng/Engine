///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:50)

#ifndef TEAM_LIB_H
#define TEAM_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_TEAM_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "TeamD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Team.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_TEAM_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "TeamStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TeamStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_TEAM_STATIC

#endif  // TCRE_USE_MSVC

#endif  // TEAM_LIB_H
