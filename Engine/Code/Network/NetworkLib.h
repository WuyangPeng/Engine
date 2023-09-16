///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 10:50)

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
