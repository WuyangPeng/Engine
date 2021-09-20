///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/07/28 15:18)

#ifndef CORE_TOOLS_EXAMPLE_LIB_H
#define CORE_TOOLS_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CORE_TOOLS_EXAMPLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CoreToolsExampleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CoreToolsExample.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CORE_TOOLS_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CoreToolsExampleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CoreToolsExampleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CORE_TOOLS_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_EXAMPLE_LIB_H
