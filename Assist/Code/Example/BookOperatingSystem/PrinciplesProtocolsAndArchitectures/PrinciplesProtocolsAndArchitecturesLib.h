///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 8:44)

#ifndef PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_LIB_H
#define PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "PrinciplesProtocolsAndArchitecturesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "PrinciplesProtocolsAndArchitectures.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "PrinciplesProtocolsAndArchitecturesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "PrinciplesProtocolsAndArchitecturesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_LIB_H
