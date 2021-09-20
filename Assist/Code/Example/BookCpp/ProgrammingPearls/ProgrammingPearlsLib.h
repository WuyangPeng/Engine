///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/30 11:02)

#ifndef PROGRAMMING_PEARLS_LIB_H
#define PROGRAMMING_PEARLS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROGRAMMING_PEARLS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingPearlsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingPearls.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROGRAMMING_PEARLS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingPearlsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingPearlsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROGRAMMING_PEARLS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROGRAMMING_PEARLS_LIB_H
