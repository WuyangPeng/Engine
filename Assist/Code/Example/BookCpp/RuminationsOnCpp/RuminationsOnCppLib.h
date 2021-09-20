///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef RUMINATIONS_ON_CPP_LIB_H
#define RUMINATIONS_ON_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RUMINATIONS_ON_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RuminationsOnCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RuminationsOnCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_RUMINATIONS_ON_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "RuminationsOnCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RuminationsOnCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_RUMINATIONS_ON_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RUMINATIONS_ON_CPP_LIB_H
