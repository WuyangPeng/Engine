///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2020/12/31 23:05)

#ifndef CPP_PROGRAMMING_LIB_H
#define CPP_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_PROGRAMMING_LIB_H
