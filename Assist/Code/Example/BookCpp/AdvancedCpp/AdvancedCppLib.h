///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.1.0 (2021/01/21 23:03)

#ifndef ADVANCED_CPP_LIB_H
#define ADVANCED_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ADVANCED_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ADVANCED_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ADVANCED_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ADVANCED_CPP_LIB_H
