///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:57)

#ifndef ALGORITHMS_LIB_H
#define ALGORITHMS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ALGORITHMS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Algorithms.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ALGORITHMS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ALGORITHMS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ALGORITHMS_LIB_H
