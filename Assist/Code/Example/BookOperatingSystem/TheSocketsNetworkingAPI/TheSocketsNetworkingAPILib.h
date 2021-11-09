///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#ifndef THE_SOCKETS_NETWORKING_API_LIB_H
#define THE_SOCKETS_NETWORKING_API_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_SOCKETS_NETWORKING_API_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheSocketsNetworkingAPID.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheSocketsNetworkingAPI.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_SOCKETS_NETWORKING_API_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "TheSocketsNetworkingAPIStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheSocketsNetworkingAPIStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_SOCKETS_NETWORKING_API_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_SOCKETS_NETWORKING_API_LIB_H
