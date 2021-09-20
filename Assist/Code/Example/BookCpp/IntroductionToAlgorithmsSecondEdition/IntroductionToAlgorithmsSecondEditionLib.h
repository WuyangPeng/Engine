///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_LIB_H
#define INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsSecondEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsSecondEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsSecondEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsSecondEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_LIB_H