/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:43)

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
