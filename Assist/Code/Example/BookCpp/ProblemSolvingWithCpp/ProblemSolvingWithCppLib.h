///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:31)

#ifndef PROBLEM_SOLVING_WITH_CPP_LIB_H
#define PROBLEM_SOLVING_WITH_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROBLEM_SOLVING_WITH_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProblemSolvingWithCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProblemSolvingWithCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROBLEM_SOLVING_WITH_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ProblemSolvingWithCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProblemSolvingWithCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROBLEM_SOLVING_WITH_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROBLEM_SOLVING_WITH_CPP_LIB_H
