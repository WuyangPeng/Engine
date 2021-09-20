///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/06 21:46)

#ifndef MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_LIB_H
#define MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MasteringComplexityWithACEAndPatternsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MasteringComplexityWithACEAndPatterns.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MasteringComplexityWithACEAndPatternsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MasteringComplexityWithACEAndPatternsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_LIB_H
