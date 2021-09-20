///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/28 12:57)

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
