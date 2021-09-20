///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#ifndef INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_LIB_H
#define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "IntroductionToTheDesignAndAnalysisOfAlgorithmsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IntroductionToTheDesignAndAnalysisOfAlgorithms.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "IntroductionToTheDesignAndAnalysisOfAlgorithmsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IntroductionToTheDesignAndAnalysisOfAlgorithmsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_LIB_H
