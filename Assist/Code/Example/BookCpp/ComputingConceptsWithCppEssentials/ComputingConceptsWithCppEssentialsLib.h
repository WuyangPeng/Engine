///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/01 14:26)

#ifndef COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_LIB_H
#define COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ComputingConceptsWithCppEssentialsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputingConceptsWithCppEssentials.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ComputingConceptsWithCppEssentialsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputingConceptsWithCppEssentialsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_LIB_H
