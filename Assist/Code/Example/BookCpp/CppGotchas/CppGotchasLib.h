///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef CPP_GOTCHAS_LIB_H
#define CPP_GOTCHAS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_GOTCHAS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppGotchasD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppGotchas.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_GOTCHAS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppGotchasStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppGotchasStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_GOTCHAS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_GOTCHAS_LIB_H