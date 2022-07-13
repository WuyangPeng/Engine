///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:54)

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
