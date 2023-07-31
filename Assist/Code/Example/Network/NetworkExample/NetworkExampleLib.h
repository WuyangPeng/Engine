///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:18)

#ifndef NETWORK_EXAMPLE_LIB_H
#define NETWORK_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_NETWORK_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "NetworkExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "NetworkExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_NETWORK_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "NetworkExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "NetworkExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_NETWORK_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // NETWORK_EXAMPLE_LIB_H
