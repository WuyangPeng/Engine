///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/10 14:09)

#ifndef RESOURCE_MANAGER_EXAMPLE_LIB_H
#define RESOURCE_MANAGER_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ResourceManagerExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ResourceManagerExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ResourceManagerExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ResourceManagerExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RESOURCE_MANAGER_EXAMPLE_LIB_H
