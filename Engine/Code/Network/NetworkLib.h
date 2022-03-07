///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/15 13:25)

#ifndef NETWORK_LIB_H
#define NETWORK_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_NETWORK_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "NetworkD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Network.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_NETWORK_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "NetworkStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NetworkStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_NETWORK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // NETWORK_LIB_H
