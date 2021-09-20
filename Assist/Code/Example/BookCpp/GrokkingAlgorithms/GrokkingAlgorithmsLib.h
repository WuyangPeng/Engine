///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#ifndef GROKKING_ALGORITHMS_LIB_H
#define GROKKING_ALGORITHMS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GROKKING_ALGORITHMS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "GrokkingAlgorithmsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GrokkingAlgorithms.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_GROKKING_ALGORITHMS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "GrokkingAlgorithmsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GrokkingAlgorithmsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_GROKKING_ALGORITHMS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GROKKING_ALGORITHMS_LIB_H
