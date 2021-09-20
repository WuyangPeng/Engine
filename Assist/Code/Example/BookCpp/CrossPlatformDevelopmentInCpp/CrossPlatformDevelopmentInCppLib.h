///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:51)

#ifndef CROSS_PLATFORM_DEVELOPMENT_IN_CPP_LIB_H
#define CROSS_PLATFORM_DEVELOPMENT_IN_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CrossPlatformDevelopmentInCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CrossPlatformDevelopmentInCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CrossPlatformDevelopmentInCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CrossPlatformDevelopmentInCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CROSS_PLATFORM_DEVELOPMENT_IN_CPP_LIB_H
