///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 20:56)

#ifndef USER_INTERFACE_EXAMPLE_LIB_H
#define USER_INTERFACE_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UserInterfaceExampleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UserInterfaceExample.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "UserInterfaceExampleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UserInterfaceExampleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_USER_INTERFACE_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // USER_INTERFACE_EXAMPLE_LIB_H
