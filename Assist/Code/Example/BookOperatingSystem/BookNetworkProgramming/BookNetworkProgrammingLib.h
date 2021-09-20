///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.6 (2021/07/10 13:14)

#ifndef BOOK_NETWORK_PROGRAMMING_LIB_H
#define BOOK_NETWORK_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookNetworkProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookNetworkProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookNetworkProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookNetworkProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_NETWORK_PROGRAMMING_LIB_H
