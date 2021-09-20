///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:28)

#ifndef CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_LIB_H
#define CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppFootprintAndPerformanceOptimizationD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppFootprintAndPerformanceOptimization.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppFootprintAndPerformanceOptimizationStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppFootprintAndPerformanceOptimizationStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_LIB_H
