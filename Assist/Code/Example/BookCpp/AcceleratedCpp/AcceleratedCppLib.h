///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:31)

#ifndef ACCELERATED_CPP_LIB_H
#define ACCELERATED_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ACCELERATED_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AcceleratedCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AcceleratedCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ACCELERATED_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AcceleratedCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AcceleratedCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ACCELERATED_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ACCELERATED_CPP_LIB_H
