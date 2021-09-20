///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#ifndef PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_LIB_H
#define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "PracticalAlgorithmsForProgrammersD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "PracticalAlgorithmsForProgrammers.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "PracticalAlgorithmsForProgrammersStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "PracticalAlgorithmsForProgrammersStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_LIB_H
