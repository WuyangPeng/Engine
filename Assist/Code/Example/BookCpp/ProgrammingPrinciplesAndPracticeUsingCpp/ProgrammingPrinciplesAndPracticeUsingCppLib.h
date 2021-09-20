///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 20:20)

#ifndef PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_LIB_H
#define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingPrinciplesAndPracticeUsingCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingPrinciplesAndPracticeUsingCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingPrinciplesAndPracticeUsingCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingPrinciplesAndPracticeUsingCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_LIB_H
