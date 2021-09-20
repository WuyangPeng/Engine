///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 23:16)

#ifndef ESSENTIAL_CPP_LIB_H
#define ESSENTIAL_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ESSENTIAL_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "EssentialCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EssentialCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ESSENTIAL_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "EssentialCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EssentialCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ESSENTIAL_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ESSENTIAL_CPP_LIB_H
