///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#ifndef DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_LIB_H
#define DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DataAbstractionAndProblemSolvingWithCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DataAbstractionAndProblemSolvingWithCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "DataAbstractionAndProblemSolvingWithCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DataAbstractionAndProblemSolvingWithCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_LIB_H
