///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:38)

#ifndef NETWORK_TOOLSET_LIB_H
#define NETWORK_TOOLSET_LIB_H

#include "Network/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_NETWORK_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "NetworkToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "NetworkToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_NETWORK_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "NetworkToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "NetworkToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_NETWORK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // NETWORK_TOOLSET_LIB_H
