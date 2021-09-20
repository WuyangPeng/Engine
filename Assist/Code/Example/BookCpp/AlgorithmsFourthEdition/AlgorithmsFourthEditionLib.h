///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/07 0:26)

#ifndef ALGORITHMS_FOURTH_EDITION_LIB_H
#define ALGORITHMS_FOURTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsFourthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsFourthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsFourthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsFourthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ALGORITHMS_FOURTH_EDITION_LIB_H
