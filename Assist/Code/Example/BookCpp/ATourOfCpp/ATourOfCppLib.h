///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:31)

#ifndef A_TOUR_OF_CPP_LIB_H
#define A_TOUR_OF_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_A_TOUR_OF_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ATourOfCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ATourOfCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_A_TOUR_OF_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ATourOfCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ATourOfCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_A_TOUR_OF_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // A_TOUR_OF_CPP_LIB_H
