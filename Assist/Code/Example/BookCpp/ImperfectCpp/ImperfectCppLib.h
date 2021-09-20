///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef IMPERFECT_CPP_LIB_H
#define IMPERFECT_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IMPERFECT_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ImperfectCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ImperfectCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_IMPERFECT_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ImperfectCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ImperfectCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_IMPERFECT_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IMPERFECT_CPP_LIB_H
