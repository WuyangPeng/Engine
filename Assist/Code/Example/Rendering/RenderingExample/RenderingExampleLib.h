///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:10)

#ifndef RENDERING_EXAMPLE_LIB_H
#define RENDERING_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RENDERING_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "RenderingExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "RenderingExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_RENDERING_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "RenderingExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "RenderingExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_RENDERING_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RENDERING_EXAMPLE_LIB_H
