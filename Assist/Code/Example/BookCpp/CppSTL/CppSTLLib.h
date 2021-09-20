///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:44)

#ifndef CPP_STL_LIB_H
#define CPP_STL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_STL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppSTLD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppSTL.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_STL_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppSTLStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppSTLStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_STL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_STL_LIB_H
