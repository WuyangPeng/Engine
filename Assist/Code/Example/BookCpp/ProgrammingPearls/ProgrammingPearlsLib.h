///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef PROGRAMMING_PEARLS_LIB_H
#define PROGRAMMING_PEARLS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROGRAMMING_PEARLS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingPearlsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingPearls.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROGRAMMING_PEARLS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingPearlsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingPearlsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROGRAMMING_PEARLS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROGRAMMING_PEARLS_LIB_H
