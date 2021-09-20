///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef MORE_PROGRAMMING_PEARLS_LIB_H
#define MORE_PROGRAMMING_PEARLS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MORE_PROGRAMMING_PEARLS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MoreProgrammingPearlsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MoreProgrammingPearls.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MORE_PROGRAMMING_PEARLS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "MoreProgrammingPearlsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MoreProgrammingPearlsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MORE_PROGRAMMING_PEARLS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MORE_PROGRAMMING_PEARLS_LIB_H
