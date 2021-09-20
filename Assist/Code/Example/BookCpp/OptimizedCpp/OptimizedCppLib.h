///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef OPTIMIZED_CPP_LIB_H
#define OPTIMIZED_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_OPTIMIZED_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "OptimizedCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "OptimizedCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_OPTIMIZED_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "OptimizedCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "OptimizedCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_OPTIMIZED_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // OPTIMIZED_CPP_LIB_H
