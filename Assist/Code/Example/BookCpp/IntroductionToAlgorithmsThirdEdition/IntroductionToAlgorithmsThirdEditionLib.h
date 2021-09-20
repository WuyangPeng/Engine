///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/30 11:02)

#ifndef INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_LIB_H
#define INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsThirdEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsThirdEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsThirdEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IntroductionToAlgorithmsThirdEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INTRODUCTION_TO_ALGORITHMS_THIRD_EDITION_LIB_H
