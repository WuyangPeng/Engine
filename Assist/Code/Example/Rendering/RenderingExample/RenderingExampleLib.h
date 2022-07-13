///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 18:00)

#ifndef RENDERING_EXAMPLE_LIB_H
#define RENDERING_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

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
