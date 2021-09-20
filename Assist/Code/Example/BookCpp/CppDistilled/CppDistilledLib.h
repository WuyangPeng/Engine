///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2020/12/31 23:05)

#ifndef CPP_DISTILLED_LIB_H
#define CPP_DISTILLED_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_DISTILLED_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppDistilledD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppDistilled.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_DISTILLED_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppDistilledStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppDistilledStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_DISTILLED_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_DISTILLED_LIB_H
