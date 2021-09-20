///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:51)

#ifndef THE_ART_OF_CPP_LIB_H
#define THE_ART_OF_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_ART_OF_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheArtOfCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheArtOfCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_ART_OF_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheArtOfCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheArtOfCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_ART_OF_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_ART_OF_CPP_LIB_H
