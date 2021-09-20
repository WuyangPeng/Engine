///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:31)

#ifndef BEGINNING_CPP_17_LIB_H
#define BEGINNING_CPP_17_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BEGINNING_CPP_17_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BeginningCpp17D.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BeginningCpp17.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BEGINNING_CPP_17_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "BeginningCpp17StaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BeginningCpp17Static.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BEGINNING_CPP_17_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BEGINNING_CPP_17_LIB_H