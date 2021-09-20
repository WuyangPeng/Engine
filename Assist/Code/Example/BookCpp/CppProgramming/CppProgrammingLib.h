///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2020/12/31 23:05)

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
