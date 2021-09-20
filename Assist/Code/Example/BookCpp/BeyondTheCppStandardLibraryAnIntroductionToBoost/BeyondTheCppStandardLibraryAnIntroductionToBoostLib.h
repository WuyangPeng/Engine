///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_LIB_H
#define BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BeyondTheCppStandardLibraryAnIntroductionToBoostD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BeyondTheCppStandardLibraryAnIntroductionToBoost.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "BeyondTheCppStandardLibraryAnIntroductionToBoostStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BeyondTheCppStandardLibraryAnIntroductionToBoostStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_LIB_H
