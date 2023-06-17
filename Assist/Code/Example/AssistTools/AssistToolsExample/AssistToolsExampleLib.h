///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 10:26)

#ifndef ASSIST_TOOLS_EXAMPLE_LIB_H
#define ASSIST_TOOLS_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "AssistToolsExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AssistToolsExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "AssistToolsExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AssistToolsExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ASSIST_TOOLS_EXAMPLE_LIB_H
