///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/27 22:21)

#ifndef COMPUTER_NETWORKS_LIB_H
#define COMPUTER_NETWORKS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_COMPUTER_NETWORKS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ComputerNetworksD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputerNetworks.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_COMPUTER_NETWORKS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ComputerNetworksStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputerNetworksStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_COMPUTER_NETWORKS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // COMPUTER_NETWORKS_LIB_H
