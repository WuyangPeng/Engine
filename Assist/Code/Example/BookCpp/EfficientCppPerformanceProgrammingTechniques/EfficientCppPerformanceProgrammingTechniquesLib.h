///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_LIB_H
#define EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "EfficientCppPerformanceProgrammingTechniquesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EfficientCppPerformanceProgrammingTechniques.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "EfficientCppPerformanceProgrammingTechniquesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EfficientCppPerformanceProgrammingTechniquesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_LIB_H
